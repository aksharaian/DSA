class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int findMin(int i,int j,string &s1,string &s2) {

        if(i==n && j==m) return dp[i][j]=0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(i < n && j == m) {
            return dp[i][j]=findMin(i+1,j,s1,s2) + s1[i];
        }
        if(j < m && i == n) {
            return dp[i][j]=findMin(i,j+1,s1,s2) + s2[j];
        }

        if(s1[i] == s2[j]) {
            return dp[i][j]=findMin(i+1,j+1,s1,s2);
        }

        return dp[i][j]=min({findMin(i+1,j+1,s1,s2) + (int)s1[i] +  (int)s2[j],findMin(i+1,j,s1,s2) +  (int)s1[i],findMin(i,j+1,s1,s2) +  (int)s2[j]});
    }


    int minimumDeleteSum(string s1, string s2) {
        int i = 0, j = 0;
        n = s1.length(),m = s2.length();
        dp = vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return findMin(i,j,s1,s2);
    }
};