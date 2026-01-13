class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
          unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        // Normalize paragraph
        for (char &c : paragraph) {
            if (ispunct(c)) c = ' ';
            else c = tolower(c);
        }

        string word;
        stringstream ss(paragraph);

        // Count frequencies
        while (ss >> word) {
            if (bannedSet.find(word) == bannedSet.end()) {
                freq[word]++;
            }
        }

        // Find most frequent word
        string ans;
        int maxCount = 0;

        for (auto &p : freq) {
            if (p.second > maxCount) {
                maxCount = p.second;
                ans = p.first;
            }
        }

        return ans;
    }
};