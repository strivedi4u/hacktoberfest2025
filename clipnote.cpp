#include <bits/stdc++.h>
using namespace std;

const string DB_FILE = "clipnotes.db";

void printUsage() {
    cout << "Usage:\n"
         << "  clipnote add \"<note>\"    - Add a note\n"
         << "  clipnote list             - List all notes\n"
         << "  clipnote clear            - Clear all notes\n"
         << "  clipnote search \"<term>\" - Search notes by keyword\n";
}

// Utility to safely open the database file
fstream openFile(const string &path, ios::openmode mode) {
    fstream file(path, mode);
    if (!file.is_open()) {
        cerr << "Error: Cannot open file '" << path << "'\n";
        exit(1);
    }
    return file;
}

// Add a new note
void addNote(const string &note) {
    fstream db = openFile(DB_FILE, ios::app);
    db << note << "\n";
    db.close();
    cout << "✅ Note added successfully!\n";
}

// List all notes
void listNotes() {
    fstream db = openFile(DB_FILE, ios::in);
    string line;
    int count = 0;
    cout << "\n📒 Your Notes:\n";
    while (getline(db, line)) {
        count++;
        cout << setw(2) << count << ". " << line << "\n";
    }
    db.close();
    if (count == 0)
        cout << "(No notes found)\n";
    cout << endl;
}

// Search notes by keyword
void searchNotes(const string &term) {
    fstream db = openFile(DB_FILE, ios::in);
    string line;
    int count = 0, matches = 0;
    cout << "\n🔍 Search results for \"" << term << "\":\n";
    while (getline(db, line)) {
        count++;
        if (line.find(term) != string::npos) {
            matches++;
            cout << setw(2) << count << ". " << line << "\n";
        }
    }
    db.close();
    if (matches == 0)
        cout << "(No matching notes found)\n";
    cout << endl;
}

// Clear all notes
void clearNotes() {
    fstream db = openFile(DB_FILE, ios::out | ios::trunc);
    db.close();
    cout << "🧹 All notes cleared!\n";
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);

    if (argc < 2) {
        printUsage();
        return 1;
    }

    string command = argv[1];

    if (command == "add") {
        if (argc < 3) {
            cerr << "Error: Missing note text.\n";
            printUsage();
            return 1;
        }
        string note = argv[2];
        addNote(note);
    } else if (command == "list") {
        listNotes();
    } else if (command == "search") {
        if (argc < 3) {
            cerr << "Error: Missing search term.\n";
            printUsage();
            return 1;
        }
        string term = argv[2];
        searchNotes(term);
    } else if (command == "clear") {
        clearNotes();
    } else {
        cerr << "Error: Invalid command.\n";
        printUsage();
        return 1;
    }

    return 0;
}
