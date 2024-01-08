#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i , int j , string &str){
    while ( i < j){
        /* code */
        if(str[i] != str[j]) return false;
        i++;
        j--;
    }
    return true;
    
}

// int pp(int i , int n, string &str , vector<int> &dp){
//     if( i == n) return 0;

//     if(dp[i] != -1){
//         return dp[i];
//     }

//     int mini = 1e8;
//     for(int j = i ; j < n ; j++){
//         if(isPalindrome(i,j,str)){
//             int cost = 1 + pp(j+1 , n , str , dp);
//             mini = min(cost , mini);
//         }
//     }
//     return dp[i] = mini;
// }

// int solve(string &str){
//     int n = str.size();

//     vector<int> dp(n,-1);

//     return pp(0,n,str,dp) - 1;
// }

// ------------------------ tabulation approach -------------------------
int solve(string &str){
    int n = str.size();
    vector<int> dp(n+1 , 0);

    dp[n] = 0;
    for(int i = n-1 ; i>=0 ; i--){
        int mini = 1e8;
        for(int j = i ; j < n ; j++){
            if(isPalindrome(i,j,str)){
                int cost = 1 + dp[j+1];
                mini = min(cost , mini);
            }
        }
        dp[i] = mini;
    }
    return dp[0] - 1;
}

int main(){
    string str = "BABABCBADCEDE";
    cout<<solve(str);
    return 0;
}