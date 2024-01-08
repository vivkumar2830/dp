#include<bits/stdc++.h>
using namespace std;

// int lcs(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp){
//     if( i < 0 || j < 0){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     if(s1[i] == s2[j]){
//         return dp[i][j] = 1 + lcs(i-1 , j-1 , s1 , s2 , dp);
//     }
//     return dp[i][j] = max(lcs(i-1 , j , s1 , s2 , dp) , lcs(i , j-1 , s1 ,s2 , dp));
// }

// int solve(string &s1 , string &s2){
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n , vector<int>(m,-1));
//     return lcs(n-1 , m-1 , s1,s2 , dp);
// }




// tabulation appraoch
int lcs2(string &s1 , string &s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1 , vector<int>(m+1,0));
    for(int i = 0 ; i <= n ; i++){
        dp[i][0] = 0;
    }
    for(int j = 0 ; j <= m ; j++){
        dp[0][j] = 0;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }

    return dp[n][m];

}



int main(){
    string s1 = "acd";
    string s2 = "ced";

    // cout<<solve(s1,s2);
    cout<<lcs2(s1,s2);
    return 0;
}