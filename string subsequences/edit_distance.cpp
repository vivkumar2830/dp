#include<bits/stdc++.h>
using namespace std;

// int ed(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp){
//     if( i < 0) return j+1;
//     if( j < 0) return i+1;

//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }

//     if( s1[i] == s2[j] ){
//         return dp[i][j] = ed(i-1 , j-1 ,  s1 , s2, dp);
//     }
//     else{
//         // Minimum of three choices:
//         // 1. Replace the character at S1[i] with the character at S2[j]
//         // 2. Delete the character at S1[i]
//         // 3. Insert the character at S2[j] into S1
//         return dp[i][j] = 1 + min( ed(i-1 , j -1 , s1 ,s2 , dp) , min(ed(i-1 , j , s1 ,s2 , dp) , 
//                                        ed(i , j-1 , s1 ,s2 , dp)));
//     }
// }

// int solve(string &s1 , string &s2){
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n , vector<int>(m , -1));
//     return ed(n-1 , m-1 , s1 ,s2 , dp);
// }


//-------------------------------------- Tabulation Method ----------------------------------
int solve(string &s1 , string &s2){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1 , vector<int>(m +1, 0));
    
    for(int i = 0 ; i<=n ; i++){
        dp[i][0] = i;
    }
    for(int j = 0 ; j <= m ; j++){
        dp[0][j] = j;
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                 dp[i][j] = 1 + min( dp[i-1][j -1] , min( dp[i-1][j] , dp[i][j-1]));
            }
        }
    }

    return dp[n][m];
}


int main(){
    string s1 = "horse";
    string s2 = "ros";

    cout<<solve(s1,s2);
    return 0;
}