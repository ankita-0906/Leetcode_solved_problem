class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int>arr(26);
        for(int i=0;i<tasks.size();i++){
            arr[tasks[i]-'A']++;
        }
        int maxfreq=*max_element(arr.begin(),arr.end());
        int gap=maxfreq-1;
        
        int cnt=0;
        for(int i=0;i<26;i++){
            if(arr[i]==maxfreq) cnt++;
        }

        int interval=(maxfreq-1)*(n+1)+cnt;
        return max(interval,(int)tasks.size());
    }
};
       