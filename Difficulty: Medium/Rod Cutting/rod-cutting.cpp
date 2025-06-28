// User function Template for C++

class Solution {
  public:
  int dp[1001];
    int func(vector<int> &price,int len){
        if(len==0) return 0;   
        if(dp[len]!=-1) return dp[len];
        int ans=0;
        for(int cut=1;cut<=price.size();cut++){
            if(len-cut>=0) ans=max(ans,func(price,len-cut)+price[cut-1]);
        }
        return dp[len]=ans;
    }
    
    int cutRod(vector<int> &price) {
        // code here
        memset(dp,-1,sizeof(dp));
        int len=price.size();
        return func(price,len);
    }
};