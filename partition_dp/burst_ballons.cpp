#include<bits/stdc++.h>
using namespace std;

// int bsb(int i , int j , vector<int> &arr , vector<vector<int>> &dp){
//     if( i > j) return 0;

//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }

//     int maxi = -1e8;
//     for(int k = i ; k <= j ; k++){
//         int coins = arr[i-1]*arr[k]*arr[j+1] + bsb(i , k-1 , arr, dp) + bsb(k+1 , j , arr, dp);
//         maxi = max(maxi, coins);
//     }
//     return dp[i][j] = maxi;
// }

// int solve(vector<int> &arr){
//     int n = arr.size();
//     arr.insert(arr.begin() , 1);
//     arr.push_back(1);

//     vector<vector<int>> dp(n+2 , vector<int>(n+2 , -1));

//     return bsb(1, n , arr , dp);
// }

//----------------------- tabulation method ---------------------------
int solve(vector<int> &arr){
    int n = arr.size();
    arr.insert(arr.begin() , 1);
    arr.push_back(1);

    vector<vector<int>> dp(n+2 , vector<int>(n+2 , 0));

    for(int i = n ; i >= 1; i--){
        for(int j = 1 ; j <= n ; j++){
            if(i > j){
                continue;
            }
            int maxi = -1e8;
            for(int k = i ; k <= j ; k++){
                int coins = arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j];
                maxi = max(maxi, coins);
            }
            dp[i][j] = maxi;

        }
    }
    return dp[1][n];
}

int main(){
    vector<int> nums = {3, 1, 5, 8};
    cout<<solve(nums);
    return 0;
}