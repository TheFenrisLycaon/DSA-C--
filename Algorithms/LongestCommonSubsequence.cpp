class Solution {
public:
  //Longest Common Subsequence-leetcode
  //TC O(n*m)
  //Dynamic Programming Memoisation
    int longestCommonSubsequence(string text1, string text2) {
       
        int n=text1.size(),m=text2.size();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j==0)
                  t[i][j]=0;
                else if(text1[i-1]==text2[j-1])
                  t[i][j]=1+t[i-1][j-1];
                else
                  t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[n][m];
        
    }
};
