// bank_system.cpp
// A simple console Bank Management System
// Features:
// - Create account (auto account number)
// - Login (account number + pin)
// - Deposit, Withdraw, Transfer
// - View transaction history
// - Admin mode to list all accounts / search / delete
// - Persistence to files: accounts.dat and txns.dat
//
// Compile: g++ -std=c++17 bank_system.cpp -o bank_system
// Run: ./bank_system

#include <bits/stdc++.h>
using namespace std;

static const string ACCOUNTS_FILE = "accounts.dat";
static const string TRANSACTIONS_FILE = "txns.dat";

struct Transaction {
    long long txnId;
    long long accFrom;    // 0 if deposit/credit
    long long accTo;      // 0 if withdrawal/debit
    double amount;
    string type;          // "DEPOSIT", "WITHDRAW", "TRANSFER"
    string timestamp;

    Transaction() = default;

    string toCSV() const {
        // for easy persistence
        ostringstream oss;
        oss << txnId << ',' << accFrom << ',' << accTo << ',' << amount << ',' << type << ',' << timestamp;
        return oss.str();
    }

    static Transaction fromCSV(const string &line) {
        Transaction t;
        stringstream ss(line);
        string token;
        getline(ss, token, ','); t.txnId = stoll(token);
        getline(ss, token, ','); t.accFrom = stoll(token);
        getline(ss, token, ','); t.accTo = stoll(token);
        getline(ss, token, ','); t.amount = stod(token);
        getline(ss, token, ','); t.type = token;
        getline(ss, token); t.timestamp = token;
        return t;
    }
};

struct Account {
    long long accNo;
    string name;
    string email;
    string pin;          // 4-digit pin stored as string (not secure for production)
    double balance;
    bool active;

    Account() = default;

    string toCSV() const {
        ostringstream oss;
        // escape commas in name/email? keep simple
        oss << accNo << ',' << name << ',' << email << ',' << pin << ',' << balance << ',' << (active ? 1 : 0);
        return oss.str();
    }

    static Account fromCSV(const string &line) {
        Account a;
        stringstream ss(line);
        string token;
        getline(ss, token, ','); a.accNo = stoll(token);
        getline(ss, token, ','); a.name = token;
        getline(ss, token, ','); a.email = token;
        getline(ss, token, ','); a.pin = token;
        getline(ss, token, ','); a.balance = stod(token);
        getline(ss, token); a.active = (token == "1");
        return a;
    }
};

// Global in-memory storage (loaded at startup)
unordered_map<long long, Account> accounts;
vector<Transaction> transactions;

// helpers for timestamps and ids
long long nextAccountNumber() {
    // generate account number using timestamp + random component
    static long long base = chrono::system_clock::now().time_since_epoch().count() % 1000000;
    return 1000000000LL + (base++ % 9000000);
}

long long nextTxnId() {
    static long long id = 1;
    if (!transactions.empty()) {
        id = max(id, transactions.back().txnId + 1);
    }
    return id++;
}

string nowStr() {
    auto t = chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t(t);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&tt));
    return string(buf);
}

void saveAccounts() {
    ofstream ofs(ACCOUNTS_FILE, ios::trunc);
    if (!ofs) {
        cerr << "Error saving accounts to file\n";
        return;
    }
    for (auto &p : accounts) {
        ofs << p.second.toCSV() << "\n";
    }
}

void loadAccounts() {
    accounts.clear();
    ifstream ifs(ACCOUNTS_FILE);
    if (!ifs) return; // first run
    string line;
    while (getline(ifs, line)) {
        if (line.empty()) continue;
        Account a = Account::fromCSV(line);
        accounts[a.accNo] = a;
    }
}

void saveTransactions() {
    ofstream ofs(TRANSACTIONS_FILE, ios::trunc);
    if (!ofs) {
        cerr << "Error saving transactions to file\n";
        return;
    }
    for (auto &t : transactions) {
        ofs << t.toCSV() << "\n";
    }
}

void loadTransactions() {
    transactions.clear();
    ifstream ifs(TRANSACTIONS_FILE);
    if (!ifs) return;
    string line;
    while (getline(ifs, line)) {
        if (line.empty()) continue;
        Transaction t = Transaction::fromCSV(line);
        transactions.push_back(t);
    }
}

void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printHeader(const string &title) {
    cout << "========================================\n";
    cout << title << "\n";
    cout << "========================================\n";
}

// Create a new account
void createAccount() {
    printHeader("Create Account");
    string name, email, pin;
    double initialDeposit;

    cout << "Full Name: ";
    getline(cin, name);
    cout << "Email: ";
    getline(cin, email);

    while (true) {
        cout << "Choose 4-digit PIN: ";
        getline(cin, pin);
        if (pin.size() == 4 && all_of(pin.begin(), pin.end(), ::isdigit)) break;
        cout << "PIN must be 4 digits.\n";
    }
    cout << "Initial deposit (>=0): ";
    while (!(cin >> initialDeposit) || initialDeposit < 0) {
        cout << "Enter valid amount: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Account acc;
    acc.accNo = nextAccountNumber();
    acc.name = name;
    acc.email = email;
    acc.pin = pin;
    acc.balance = initialDeposit;
    acc.active = true;
    accounts[acc.accNo] = acc;

    // transaction record for initial deposit if > 0
    if (initialDeposit > 0) {
        Transaction t;
        t.txnId = nextTxnId();
        t.accFrom = 0;
        t.accTo = acc.accNo;
        t.amount = initialDeposit;
        t.type = "DEPOSIT";
        t.timestamp = nowStr();
        transactions.push_back(t);
    }

    saveAccounts();
    saveTransactions();

    cout << "\nAccount created successfully!\n";
    cout << "Account Number: " << acc.accNo << "\n";
    cout << "Name: " << acc.name << "\n";
    cout << "Balance: " << acc.balance << "\n";
    pause();
}

// authenticate and return account pointer (or nullptr)
Account* login() {
    printHeader("User Login");
    long long accNo; string pin;
    cout << "Account Number: ";
    if (!(cin >> accNo)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return nullptr;
    }
    cout << "PIN: ";
    cin >> pin;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    auto it = accounts.find(accNo);
    if (it == accounts.end() || !it->second.active) {
        cout << "Account not found or inactive.\n";
        pause();
        return nullptr;
    }
    if (it->second.pin != pin) {
        cout << "Invalid PIN.\n";
        pause();
        return nullptr;
    }
    return &it->second;
}

void showBalance(Account &acc) {
    printHeader("Account Balance");
    cout << "Account: " << acc.accNo << "\n";
    cout << "Name: " << acc.name << "\n";
    cout << "Balance: " << acc.balance << "\n";
    pause();
}

void addTransaction(long long from, long long to, double amount, const string &type) {
    Transaction t;
    t.txnId = nextTxnId();
    t.accFrom = from;
    t.accTo = to;
    t.amount = amount;
    t.type = type;
    t.timestamp = nowStr();
    transactions.push_back(t);
    saveTransactions();
}

void deposit(Account &acc) {
    printHeader("Deposit Money");
    double amt;
    cout << "Amount to deposit: ";
    while (!(cin >> amt) || amt <= 0) {
        cout << "Enter a positive amount: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    acc.balance += amt;
    addTransaction(0, acc.accNo, amt, "DEPOSIT");
    saveAccounts();
    cout << "Deposit successful. New balance: " << acc.balance << "\n";
    pause();
}

void withdraw(Account &acc) {
    printHeader("Withdraw Money");
    double amt;
    cout << "Amount to withdraw: ";
    while (!(cin >> amt) || amt <= 0) {
        cout << "Enter a positive amount: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (amt > acc.balance) {
        cout << "Insufficient funds. Current balance: " << acc.balance << "\n";
        pause();
        return;
    }
    acc.balance -= amt;
    addTransaction(acc.accNo, 0, amt, "WITHDRAW");
    saveAccounts();
    cout << "Withdrawal successful. New balance: " << acc.balance << "\n";
    pause();
}

void transfer(Account &acc) {
    printHeader("Transfer Money");
    long long toAcc; double amt;
    cout << "To Account Number: ";
    if (!(cin >> toAcc)) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid account\n";
        pause();
        return;
    }
    cout << "Amount to transfer: ";
    while (!(cin >> amt) || amt <= 0) {
        cout << "Enter a positive amount: ";
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (toAcc == acc.accNo) {
        cout << "Cannot transfer to same account.\n";
        pause();
        return;
    }
    auto it = accounts.find(toAcc);
    if (it == accounts.end() || !it->second.active) {
        cout << "Recipient account not found or inactive.\n";
        pause();
        return;
    }
    if (amt > acc.balance) {
        cout << "Insufficient funds.\n";
        pause();
        return;
    }
    acc.balance -= amt;
    it->second.balance += amt;
    addTransaction(acc.accNo, toAcc, amt, "TRANSFER");
    saveAccounts();
    cout << "Transfer successful. New balance: " << acc.balance << "\n";
    pause();
}

void viewTransactions(const Account &acc) {
    printHeader("Transaction History");
    cout << "Transactions for account " << acc.accNo << " (" << acc.name << ")\n\n";
    cout << left << setw(10) << "TXN ID" << setw(12) << "TYPE" << setw(12) << "FROM" << setw(12) << "TO" << setw(12) << "AMOUNT" << setw(22) << "TIMESTAMP" << "\n";
    cout << string(80, '-') << "\n";
    for (auto &t : transactions) {
        if (t.accFrom == acc.accNo || t.accTo == acc.accNo) {
            cout << left << setw(10) << t.txnId << setw(12) << t.type
                 << setw(12) << t.accFrom << setw(12) << t.accTo
                 << setw(12) << t.amount << setw(22) << t.timestamp << "\n";
        }
    }
    pause();
}

void userMenu(Account &acc) {
    while (true) {
        printHeader("User Dashboard");
        cout << "Welcome, " << acc.name << " (" << acc.accNo << ")\n";
        cout << "1) View Balance\n2) Deposit\n3) Withdraw\n4) Transfer\n5) Transaction History\n6) Logout\nChoose: ";
        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (ch) {
            case 1: showBalance(acc); break;
            case 2: deposit(acc); break;
            case 3: withdraw(acc); break;
            case 4: transfer(acc); break;
            case 5: viewTransactions(acc); break;
            case 6: saveAccounts(); cout << "Logged out.\n"; pause(); return;
            default: cout << "Invalid choice\n"; pause();
        }
    }
}

// Admin features
bool isAdminPassword(const string &pw) {
    // Simple admin password - change for your usage.
    return pw == "admin@123";
}

void adminListAccounts() {
    printHeader("All Accounts");
    cout << left << setw(12) << "AccNo" << setw(28) << "Name" << setw(28) << "Email" << setw(12) << "Balance" << "Active\n";
    cout << string(90, '-') << "\n";
    for (auto &p : accounts) {
        auto &a = p.second;
        cout << left << setw(12) << a.accNo << setw(28) << a.name << setw(28) << a.email << setw(12) << a.balance << (a.active ? "Yes" : "No") << "\n";
    }
    pause();
}

void adminSearchAccount() {
    printHeader("Search Account");
    cout << "Enter account number: ";
    long long accNo;
    if (!(cin >> accNo)) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n";
        pause();
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    auto it = accounts.find(accNo);
    if (it == accounts.end()) {
        cout << "Account not found\n";
    } else {
        auto &a = it->second;
        cout << "Account: " << a.accNo << "\nName: " << a.name << "\nEmail: " << a.email << "\nBalance: " << a.balance << "\nActive: " << (a.active ? "Yes" : "No") << "\n";
    }
    pause();
}

void adminDeleteAccount() {
    printHeader("Delete Account");
    cout << "Enter account number to delete: ";
    long long accNo;
    if (!(cin >> accNo)) {
        cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input\n";
        pause();
        return;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    auto it = accounts.find(accNo);
    if (it == accounts.end()) {
        cout << "Account not found\n";
        pause();
        return;
    }
    cout << "Are you sure you want to delete account " << accNo << " (y/n)? ";
    char c; cin >> c; cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (c == 'y' || c == 'Y') {
        accounts.erase(it);
        saveAccounts();
        cout << "Account deleted.\n";
    } else {
        cout << "Aborted.\n";
    }
    pause();
}

void adminTransactionReport() {
    printHeader("Transaction Report");
    cout << left << setw(10) << "TXN ID" << setw(12) << "TYPE" << setw(12) << "FROM" << setw(12) << "TO" << setw(12) << "AMOUNT" << setw(22) << "TIMESTAMP" << "\n";
    cout << string(80, '-') << "\n";
    for (auto &t : transactions) {
        cout << left << setw(10) << t.txnId << setw(12) << t.type
             << setw(12) << t.accFrom << setw(12) << t.accTo
             << setw(12) << t.amount << setw(22) << t.timestamp << "\n";
    }
    pause();
}

void adminMenu() {
    cout << "Enter admin password: ";
    string pw;
    getline(cin, pw);
    if (!isAdminPassword(pw)) {
        cout << "Access denied.\n";
        pause();
        return;
    }
    while (true) {
        printHeader("Admin Dashboard");
        cout << "1) List Accounts\n2) Search Account\n3) Delete Account\n4) Transaction Report\n5) Back to Main Menu\nChoose: ";
        int ch;
        if (!(cin >> ch)) { cin.clear(); cin.ignore(numeric_limits<streamsize>::max(), '\n'); continue; }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (ch) {
            case 1: adminListAccounts(); break;
            case 2: adminSearchAccount(); break;
            case 3: adminDeleteAccount(); break;
            case 4: adminTransactionReport(); break;
            case 5: return;
            default: cout << "Invalid\n"; pause();
        }
    }
}

void seedDemoDataIfEmpty() {
    if (!accounts.empty()) return;
    // create a couple of demo accounts for convenience
    Account a1; a1.accNo = nextAccountNumber(); a1.name = "Alice Johnson"; a1.email = "alice@example.com"; a1.pin = "1111"; a1.balance = 15000; a1.active = true;
    Account a2; a2.accNo = nextAccountNumber(); a2.name = "Bob Kumar"; a2.email = "bob@example.com"; a2.pin = "2222"; a2.balance = 8000; a2.active = true;
    accounts[a1.accNo] = a1;
    accounts[a2.accNo] = a2;
    transactions.clear();
    Transaction t1; t1.txnId = nextTxnId(); t1.accFrom = 0; t1.accTo = a1.accNo; t1.amount = a1.balance; t1.type = "DEPOSIT"; t1.timestamp = nowStr();
    Transaction t2; t2.txnId = nextTxnId(); t2.accFrom = 0; t2.accTo = a2.accNo; t2.amount = a2.balance; t2.type = "DEPOSIT"; t2.timestamp = nowStr();
    transactions.push_back(t1); transactions.push_back(t2);
    saveAccounts();
    saveTransactions();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // load persistent data
    loadAccounts();
    loadTransactions();

    // seed demo data if first run
    seedDemoDataIfEmpty();

    while (true) {
        printHeader("Bank Management System - Mini Demo");
        cout << "1) Create Account\n2) Login\n3) Admin\n4) Exit\nChoose: ";
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
            case 1: createAccount(); break;
            case 2: {
                Account* acc = login();
                if (acc) userMenu(*acc);
                break;
            }
            case 3: adminMenu(); break;
            case 4:
                cout << "Goodbye!\n";
                saveAccounts();
                saveTransactions();
                return 0;
            default:
                cout << "Invalid choice\n";
                pause();
        }
    }
    return 0;
}
