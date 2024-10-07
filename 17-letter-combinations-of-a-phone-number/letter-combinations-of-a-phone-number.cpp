class Solution {
    private:
    void solve(string digits,int  index,string output,string mapping[],vector<string>&ans)
    {
        if(index>=digits.length())
        {
          ans.push_back(output);
          return;
        }
        int no=digits[index]-'0';//2
        string value=mapping[no];//abc
        for(int i =0;i<value.length();i++)
        {
          output.push_back(value[i]);
          solve(digits,index+1,output,mapping,ans);
          output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output="";
        if(digits.length()==0) return ans ;
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,index,output,mapping,ans);
        return ans;
        
    }
};