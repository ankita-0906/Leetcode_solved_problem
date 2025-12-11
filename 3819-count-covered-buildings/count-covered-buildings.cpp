class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& arr) {
        vector<int>minx(n+1,n+1);
        vector<int>maxx(n+1,0);
        vector<int>miny(n+1,n+1);
        vector<int>maxy(n+1,0);

        for(int i=0;i<arr.size();i++){
            int a=arr[i][0],b=arr[i][1];
            minx[b]=min(a,minx[b]);
            maxx[b]=max(a,maxx[b]);
            miny[a]=min(b,miny[a]);
            maxy[a]=max(b,maxy[a]);
        }
        int cover=0;
        for(int i=0;i<arr.size();i++){
            int a=arr[i][0],b=arr[i][1];
            if(a>minx[b] && a<maxx[b] && b>miny[a] && b<maxy[a]) 
            cover++;
        }
        return cover;
    }
};