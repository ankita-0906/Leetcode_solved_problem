class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
       
        int n=capital.size();
        vector<pair<int,int>>arr;

        for(int i=0;i<n;i++){
            arr.push_back({capital[i],profits[i]});
        }
       sort(arr.begin(),arr.end());
        priority_queue<int> maxheap; 
         int i =0;
      for(int j=0;j<k;j++){
       while(i<n && w>=arr[i].first){

        maxheap.push(arr[i].second);
        i++;
       }
       if(maxheap.empty()) break;
       w=w+maxheap.top();
      
        maxheap.pop();
      }
      return w;
    }
};