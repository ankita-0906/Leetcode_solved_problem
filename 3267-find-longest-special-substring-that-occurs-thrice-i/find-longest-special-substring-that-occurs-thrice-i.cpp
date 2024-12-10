class Solution {
public:
    int maximumLength(string s) {
            unordered_map<string, int> substringCount;
    int n = s.size();

  
    for (int i = 0; i < n; i++) {
        string current = "";
        for (int j = i; j < n; j++) {
            if (s[j] == s[i]) {
                current += s[j];
                substringCount[current]++;
            } else {
                break;
            }
        }
    }

   
    int maxLength = -1;
    for (const auto& [substring, count] : substringCount) {
        if (count >= 3) {
            maxLength = max(maxLength, (int)substring.size());
        }
    }

    return maxLength;
    }
};