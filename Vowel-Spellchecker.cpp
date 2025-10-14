class Solution {
public:
    unordered_set<string> exactWords;          // stores original words
    unordered_map<string, string> caseMap;     // lowercase : original word
    unordered_map<string, string> vowelMap;    // masked vowels : original word
    
    string toLower(const string& s) {
        string res = s;
        for (char& c : res) {
            c = tolower(c);
        }
        return res;
    }

    string maskVowels(const string& s) {
        string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }

    string checkForMatch(const string& query) {
        if (exactWords.count(query)) {
            return query;
        }

        string lowerQuery = toLower(query);
        if (caseMap.count(lowerQuery)) {
            return caseMap[lowerQuery];
        }

        string maskedQuery = maskVowels(lowerQuery);
        if (vowelMap.count(maskedQuery)) {
            return vowelMap[maskedQuery];
        }

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        exactWords.clear();
        caseMap.clear();
        vowelMap.clear();

        for (string word : wordlist) {
            exactWords.insert(word);

            string lowerWord = toLower(word);
            if (caseMap.find(lowerWord) == caseMap.end()) { //Add only 1st occurrence
                caseMap[lowerWord] = word;
            }

            string maskedWord = maskVowels(lowerWord);
            if (vowelMap.find(maskedWord) == vowelMap.end()) { //Add only 1st occurrence
                vowelMap[maskedWord] = word;
            }
        }

        vector<string> result;
        for (string query : queries) {
            result.push_back(checkForMatch(query));
        }
        return result;
    }
};
