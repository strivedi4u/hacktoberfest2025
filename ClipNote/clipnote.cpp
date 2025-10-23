#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

string getTimestamp() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    stringstream ss;
    ss << 1900 + ltm->tm_year << "-"
       << 1 + ltm->tm_mon << "-"
       << ltm->tm_mday << " "
       << 1 + ltm->tm_hour << ":"
       << 1 + ltm->tm_min;
    return ss.str();
}

void saveNote(const string &note) {
    ofstream file("clipnotes.db", ios::app);
    if (!file) {
        cerr << "❌ Error: Could not open file.\n";
        return;
    }
    file << getTimestamp() << " | " << note << "\n";
    file.close();
    cout << "✅ Note saved!\n";
}

void listNotes() {
    ifstream file("clipnotes.db");
    if (!file) {
        cout << "⚠️  No notes yet.\n";
        return;
    }
    string line;
    int count = 0;
    cout << "\n🗒️  Your Notes:\n";
    cout << "-------------------------\n";
    while (getline(file, line)) {
        cout << ++count << ". " << line << "\n";
    }
    cout << "-------------------------\n";
    file.close();
}

void deleteNotes() {
    ofstream file("clipnotes.db", ios::trunc);
    file.close();
    cout << "🧹 All notes cleared.\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "📋 Usage:\n";
        cout << "  clipnote add \"Your note\"\n";
        cout << "  clipnote list\n";
        cout << "  clipnote clear\n";
        return 0;
    }

    string command = argv[1];

    if (command == "add") {
        if (argc < 3) {
            cerr << "❌ Please provide a note.\n";
            return 1;
        }
        string note = argv[2];
        saveNote(note);
    } else if (command == "list") {
        listNotes();
    } else if (command == "clear") {
        deleteNotes();
    } else {
        cerr << "❌ Unknown command.\n";
    }

    return 0;
}
