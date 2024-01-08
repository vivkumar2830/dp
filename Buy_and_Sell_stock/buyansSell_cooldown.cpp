#include<bits/stdc++.h>
using namespace std;

// int me(long *arr , int ind , int buy , int n ,  vector<vector<int>> &dp){
//     if( ind >= n){
//         return 0;
//     }

//     if(dp[ind][buy] == -1){
//         return dp[ind][buy];
//     }

//     long profit = 0;
//     if( buy == 0){
//         profit = max( me(arr, ind + 1 , 0 , n , dp) , -arr[ind] + me(arr , ind + 1 , 1 , n ,dp));
//     }
//     if(buy == 1){
//         profit = max(0 + me(arr, ind + 1, 1, n, dp), arr[ind] + me(arr, ind + 1, 0, n, dp));
//     }

//     return dp[ind][buy] = profit;
// }

// int solve(long *arr , int n){
//     if( n== 0){
//         return 0;
//     }
//     vector<vector<int>> dp( n , vector<int>(2, -1));
//     return me(arr , 0 , 0 , n , dp);
// }

// -----------------  Tabulation Method  -------------------------

int solve(long *arr , int n){

    vector<vector<long>> dp( n+2  , vector<long>(2, 0));

    long profit;

    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int buy = 0; buy <= 1; buy++){
            if( buy == 0){
                profit = max(dp[ind+1][0] , -arr[ind] + dp[ind+1][1]);
            }
            if(buy == 1){
                profit = max(dp[ind+1][1] , arr[ind] + dp[ind+2][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}


int main(){
    int n = 5;
    long Arr[n] = {4, 9, 0, 4, 10};
    cout<<solve(Arr , n);
    return 0;
}