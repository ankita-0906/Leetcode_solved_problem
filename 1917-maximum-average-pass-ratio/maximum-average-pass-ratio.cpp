class Solution {
public:
    double gain(int pass,int total){
        return (double)(pass+1)/(double)(total+1)-(double)(pass)/(double)(total);
    }
    double maxAverageRatio(vector<vector<int>>& arr, int extraStudents) {
        priority_queue<pair<double,pair<int,int>>>pq;

        for(int i=0;i<arr.size();i++){
            int pass=arr[i][0],total=arr[i][1];
            double profit=gain(pass,total);
            pq.push({profit,{pass,total}});
        }
        while(extraStudents>0){
            auto[g,it]=pq.top();
             int pass=it.first,total=it.second; pq.pop();
             pass++; total++;
             double profit=gain(pass,total);
              pq.push({profit,{pass,total}});
              extraStudents--;
        }
        double sum=0;
        while(pq.size()>0){
            auto[g,it]=pq.top();
            int pass=it.first,total=it.second; pq.pop();
            sum=sum+(double)pass/total;
        }
        return sum/arr.size();
    }
};