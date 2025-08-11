class Solution {
public:
    bool isAnagram(string s, string t) {
        string s1=s;
        sort(s1.begin(),s1.end());
        string t1=t;
         sort(t1.begin(),t1.end());
         return s1==t1;
    }
};