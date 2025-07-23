// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
        int n=N;
        vector<int>coins={ 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };
        int ind=coins.size()-1;
        vector<int>ans;
        while(true){
            if(coins[ind]>n) ind--;
            else{
                n-=coins[ind];
                ans.push_back(coins[ind]);
            }
            if(n==0) break;
        }
        return ans;
    }
};