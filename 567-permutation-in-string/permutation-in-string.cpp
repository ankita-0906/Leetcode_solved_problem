class Solution {
public:
bool match(int hash1[],int hash2[]){
for(int i=0;i<26;i++){
    if(hash1[i]!=hash2[i]) return false;
}
return true;
}
    bool checkInclusion(string s1, string s2) {

       int hash1[26]={0};
       

       int n1=s1.length();
       int n2=s2.length();

       if(n1>n2) return false;

       for(int i=0;i<n1;i++){
        hash1[s1[i]-'a']++;
       } 

       for(int i=0;i<=n2-n1;i++){
        int hash2[26]={0};
           for(int j=i;j<i+n1;j++){
            hash2[s2[j]-'a']++;
           }
           if(match(hash1,hash2)) return true;
       }
       return false;
    }
};