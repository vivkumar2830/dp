#include<bits/stdc++.h>
using namespace std;

// int lis(int ind , int prev , int n , int arr[] , vector<vector<int>> &dp){
//     if( ind == n){
//         return 0;
//     }

//     if(dp[ind][prev+1] != -1){
//         return dp[ind][prev+1];
//     }

//     int notTake = 0 + lis(ind+1 , prev , n , arr , dp);
//     int take = 0;
//     if( prev == -1 || arr[ind] > arr[prev]){
//         take = 1 + lis(ind+1 , ind , n , arr , dp);
//     }

//     return dp[ind][prev+1] = max(take , notTake);
// }

// int solve(int arr[] , int n){
//     vector<vector<int>> dp(n, vector<int>(n+1, -1));

//     return lis(0, -1 , n , arr , dp );
// }


//-------------------------- tabulation method -----------------------

int solve2(int arr[] , int n){
    vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));

    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int prev = ind-1 ; prev >= -1 ; prev--){
            int notTake = 0 + dp[ind+1][prev+1];
            int take = 0;
            if( prev == -1 || arr[ind] > arr[prev]){
                take = 1 + dp[ind+1][ind+1];
            }

            dp[ind][prev+1] = max(take , notTake);
        }
    }

    return dp[0][0];
}

int main(){
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<<solve2(arr,n);
    return 0;
}