#include<bits/stdc++.h>
using namespace std;


// ---------------   Memoization Approach  ----------------------
// int ds(int ind1 , int ind2 , string &s1 , string &s2 , vector<vector<int>> &dp){
//     if(ind2 == 0){
//         return 1;
//     }
//     if(ind1 == 0){
//         return 0;
//     }

//     if( dp[ind1][ind2] != -1){
//         return dp[ind1][ind2];
//     }

//     int result = 0;
//     if( s1[ind1-1] == s2[ind2-1]){
//         int leaveOne = ds(ind1-1 , ind2-1 , s1 , s2 , dp);
//         int stay = ds(ind1-1 , ind2 , s1 , s2 , dp);
//         result = leaveOne + stay;
//     }
//     else{
//         result = ds(ind1-1 , ind2 , s1 ,s2 , dp);
//     }
//     return dp[ind1][ind2] = result;
// }


// int solve(string &s1 , string &s2){
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n+1  , vector<int>(m+1 , -1));
//     return ds(n , m , s1 , s2 , dp);
// }


// Tabulation Method 
int solve2(string &s1 , string &s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1  , vector<int>(m+1 , 0));
    for( int i = 0 ; i <= n ; i++){
        dp[i][0] = 1;
    }
    for(int i = 1 ; i <= m ; i++){
        dp[0][i] = 0;
    }

    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if( s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }

    }

    return dp[n][m];
}

int main(){
    string s1 = "babgbag";
    string s2 = "bag";

    // cout<<solve(s1,s2);
    cout<<solve2(s1,s2);
    return 0;
}