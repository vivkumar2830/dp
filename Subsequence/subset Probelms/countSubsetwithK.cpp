#include<bits/stdc++.h>
using namespace std;

// int f(int ind , int target , vector<int> &arr, vector<vector<int>> &dp){
//     if(target == 0 ){
//         return 1;
//     }
//     if( ind == 0){
//         return (arr[0] == target) ? 1 : 0;
//     }
//     if(dp[ind][target] != -1){
//         return dp[ind][target];
//     }
//     int notTake = f(ind-1, target , arr , dp);
//     int take = 0;

//     if(arr[ind] <= target){
//         take = f(ind-1 , target - arr[ind] , arr , dp);
//     } 

//     return dp[ind][target] = take + notTake;
// }

// int solve(vector<int>  &arr , int &k){
//     int n = arr.size();
//     vector<vector<int>> dp(n , vector<int>(k+1 , -1));

//     return f(n-1,k,arr,dp);
// }

// Tabulation method

int solve(vector<int> &arr, int &k){
    int n = arr.size();
    vector<vector<int>> dp(n , vector<int>(k+1 , 0));

    for(int i =0 ; i<n ; i++){
        dp[i][0] = 1;
    }

    if( arr[0] <= k){
        dp[0][arr[0]] = 1;
    }

    for(int i = 1 ; i<n ; i++){
        for(int target = 1 ; target <=k ; target++){
                int notTake = dp[i-1][target];
                int take = 0;
            
                if(arr[i] <= target){
                    take = dp[i-1][target-arr[i]];
                } 
            
                dp[i][target] = take + notTake;
        }
    }

    return dp[n-1][k];
}

int main(){
    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout<<solve(arr, k);
    
    return 0;
}