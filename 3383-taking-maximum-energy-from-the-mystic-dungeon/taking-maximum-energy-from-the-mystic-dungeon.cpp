class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size(),maxi=INT_MIN,submax=INT_MIN;
        for(int i=n-1;i>=n-k;i--){
            int j=i-k,sum=energy[i];
            while(j>=0){
            submax=max(submax,sum);
            sum=sum+energy[j];
             j=j-k;
            }
            submax=max(submax,sum);
           maxi=max(maxi,submax);
        }
        return maxi;
    }
};