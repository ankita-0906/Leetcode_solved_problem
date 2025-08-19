class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0,j=0,cnt=0;
        for(i=0;i<k;i++) {
            if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='i' || s[i]=='u') cnt++;
        }
        j=i;i=0; int ans=cnt;
        while(j<n){
         if(s[i]=='a' || s[i]=='o' || s[i]=='e' || s[i]=='i' || s[i]=='u') cnt--;
         if(s[j]=='a' || s[j]=='o' || s[j]=='e' || s[j]=='i' || s[j]=='u')  cnt++;
         ans=max(ans,cnt);
         j++;i++;
        }
        return ans;
    }
};