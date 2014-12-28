/*
题目描述：从字典dict中找某些子串来组合成s
思路：用dp来记录以序号i为结尾的字符串能否在字典中匹配成功。
当有字符s[i]匹配不成功，而该字符前面的dp[j]出现了true，那么可以看是否有分割字符，即该j+1到i的子串看是否可以在字典中匹配。
例如s="abcd" dict=[a,b,abc,cd]
*/
class Solution {
public:
    string getSubStr(int start,int end,string s){
		return s.substr(start,end-start+1);
	}
    bool wordBreak(string s, unordered_set<string> &dict) {
        int len=s.size();
        int i=0,j=0;
        vector<bool> dp(len,false);
        
        for(i=0;i<len;++i)
        {
            dp[i]=dict.count(getSubStr(0,i,s));
            if(dp[i]) continue;
            else
            {
                for(j=0;j<i;++j)
                {
                    if(dp[i]) break;
                    if(dp[j]）dp[i]=dict.count(getSubStr(j+1,i,s));
                }
            }
        }
        return dp[len-1];
    }
};
