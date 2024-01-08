#include<bits/stdc++.h>
using namespace std;

// bool f(int ind , int target , vector<int> &arr, vector<vector<int>> &dp){
//     if(target == 0 ){
//         return dp[ind][target] = true;
//     }
//     if( ind == 0){
//         return dp[ind][target] = (arr[0] == target);
//     }
//     if(dp[ind][target] != -1){
//         return dp[ind][target];
//     }
//     bool notTake = f(ind-1, target , arr , dp);
//     bool take = false;

//     if(arr[ind] <= target){
//         take = f(ind-1 , target - arr[ind] , arr , dp);
//     } 

//     return dp[ind][target] = take | notTake;
// }

// int solve(vector<int> &arr, int &n){
//     int sum = 0;
//     for(auto it:arr){
//         sum+=it;
//     }
//     vector<vector<int>> dp(n , vector<int>(sum+1,-1));
//     for(int i = 0; i<=sum; i++){
//         bool flag = f(n-1,i,arr,dp);
//     }

//     int mini = 1e9;
//     for(int i = 0 ; i<=sum ; i++){
//         if(dp[n-1][i] == true){
//             int diff = abs( i - (sum-i));
//             mini = min(mini , diff);
//         }
//     }

//     return mini;
// }

int solve2(vector<int> &arr, int &n){
    int sum = 0;
    for(auto it:arr){
        sum+=it;
    }
    vector<vector<int>> dp(n , vector<int>(sum+1,-0));
    for(int i = 0 ;i < n ; i++){
        dp[i][0] = true;
    }
    if( arr[0] <= sum){
        dp[0][sum] = true;
    }

    for(int i = 1 ; i < n ; i++){
        for( int target = 1 ; target <= sum ; target++){
            bool notTake = dp[i-1][target];
            bool take = false;
        
            if(arr[i] <= target){
                take = dp[i-1][target - arr[i]];
            } 
        
            dp[i][target] = take | notTake;
        }
    }


    int mini = 1e9;
    for(int i = 0 ; i<=sum ; i++){
        if(dp[n-1][i] == true){
            int diff = abs( i - (sum-i));
            mini = min(mini , diff);
        }
    }

    return mini;
}

int main(){
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();

    //cout<<solve(arr,n);
    cout<<solve2(arr,n);
    return 0;
}