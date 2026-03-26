class Solution {
public:
    bool static comp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];

    }
    int scheduleCourse(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end(),comp); int n=arr.size();
        int cnt=0,time=0;
        priority_queue<int>maxheap;
        for(int i=0;i<n;i++){
           if(time+arr[i][0]<=arr[i][1]) {
            cnt++; maxheap.push(arr[i][0]);
            time=time+arr[i][0];
           }
           else if(maxheap.size()!=0 &&arr[i][0]<maxheap.top()){
            time=time-maxheap.top()+arr[i][0];
            maxheap.pop(); 
            maxheap.push(arr[i][0]);
           }

           }
        return cnt;
    }
};