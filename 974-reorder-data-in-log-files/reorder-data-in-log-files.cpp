class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> letterLogs, digitLogs;

        // Separate letter logs and digit logs
        for (string &log : logs) {
            int pos = log.find(' ');
            if (isdigit(log[pos + 1])) {
                digitLogs.push_back(log);
            } else {
                letterLogs.push_back(log);
            }
        }

        // Sort letter logs
        sort(letterLogs.begin(), letterLogs.end(), [](string &a, string &b) {
            int posA = a.find(' ');
            int posB = b.find(' ');

            string idA = a.substr(0, posA);
            string idB = b.substr(0, posB);

            string contentA = a.substr(posA + 1);
            string contentB = b.substr(posB + 1);

            if (contentA == contentB)
                return idA < idB;
            return contentA < contentB;
        });

        // Combine result
        letterLogs.insert(letterLogs.end(), digitLogs.begin(), digitLogs.end());
        return letterLogs;
    }
};