class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int sum=skill[0]+skill[n-1]; int add;
        int i=1,j=n-2;
        while(i<=j){
         add=skill[i]+skill[j];
         if(add!=sum) return -1;
         i++;j--;
        }
        i=0,j=n-1;long long multi=0; long long chem=0;

        while(i<=j){
        multi=skill[i]*skill[j];
        chem=chem+multi;
        i++;j--;
        }
        return chem;
    }
};