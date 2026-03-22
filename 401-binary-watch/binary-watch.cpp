class Solution {
public:
  void rec(int turnedOn,vector<string>&ans,int hour,int min,int cnt,int index){
      if(hour>11 || min>59 || cnt>turnedOn) return;
      if(index==10){
        if(cnt==turnedOn){
            string s=to_string(hour)+":";
            string time;
            if(min<10) time="0";
            s=s+time+to_string(min);
            ans.push_back(s);
        }
        return;
      }
      // skip 
      rec(turnedOn,ans,hour,min,cnt,index+1);

      //hour
      if(index<4)
       rec(turnedOn,ans,hour+(1<<index),min,cnt+1,index+1);
       else
        rec(turnedOn,ans,hour,min+(1<<(index-4)),cnt+1,index+1);
  }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
    
        rec(turnedOn,ans,0,0,0,0);
        return ans;
    }
};