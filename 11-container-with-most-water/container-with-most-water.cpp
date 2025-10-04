class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
        long long maxarea=0,area;
        while(left<right){
         area=(right-left)*min(height[right],height[left]) *1ll;
         maxarea=max(area,maxarea);
         if(height[left]<height[right]) left++;
         else right--;
        }
      return maxarea;
 
    }
};