class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>minheap;
        int n=costs.size();int i=0;int j=n-1;

        while(i<candidates && j>=n-candidates && i<=j){
            if(i==j){
                 minheap.push({costs[i],0}); 
                 i++;break;
            }
            minheap.push({costs[i],0});
             minheap.push({costs[j],1});
             i++;j--;
        }
        i--;j++;

       // 0 for left and 1 for right

        long long total=0;
        for(int m=0;m<k;m++){
            auto[ele,index]=minheap.top();
            total=total+(long long)ele;
            minheap.pop();
         
             if(index==0 && i+1<j){
                i++;
                  minheap.push({costs[i],0});
                  
            }
            else if(index==1 && j-1>i){
                j--;
                  minheap.push({costs[j],1});
                  
            }
        }
        return total;
    }
};