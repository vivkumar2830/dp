#include<bits/stdc++.h>
using namespace std;

// int me(vector<int> &arr , int ind , int buy , int n ,int cap , vector<vector<vector<<<int>>> &dp){
//     if( ind == n || cap == 0){
//         return 0;
//     }

//     if(dp[ind][buy][cap] == -1){
//         return dp[ind][buy];
//     }

//     long profit = 0;
//     if( buy == 0){
//         profit = max( me(arr, ind + 1 , 0 , n ,cap, dp) , -arr[ind] + me(arr , ind + 1 , 1 ,n,cap ,dp));
//     }
//     if(buy == 1){
//         profit = max(0 + me(arr, ind + 1, 1, n,cap,  dp), arr[ind] + me(arr, ind + 1, 0, n,cap-1, dp));
//     }

//     return dp[ind][buy][cap] = profit;
// }

// int solve(vector<int> &arr , n){
//     int n = arr.size();
//     vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(3,-1)));

//     return me(arr, 0 , 0 , n ,2 , dp);
// }

// int solve(vector<int> &arr , int n){
//     vector<vector<vector<int>>> dp(n+1 , vector<vector<int>>(2 , vector<int>(3,0)));

//     for(int ind = n-1 ; ind >= 0 ; ind--){
//         for(int buy = 0 ; buy <= 1; buy++){
//             for(int cap = 1; cap <= 2; cap++){
//                 if( buy == 0){
//                     dp[ind][buy][cap] = max(dp[ind+1][0][cap] , -arr[ind] + dp[ind+1][1][cap]);
//                 }
//                 if( buy == 1){
//                     dp[ind][buy][cap] = max(dp[ind+1][1][cap] , arr[ind] + dp[ind+1][0][cap-1]);
//                 }
//             }
//         }
//     }
//     return dp[0][0][2];
// }




//--------------- space optimization ---------------------

int solve(vector<int> &arr , int n){
    vector<vector<int>> ahead(2 , vector<int>(3 , 0));
    vector<vector<int>> curr(2 , vector<int>(3 , 0));

    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int buy = 0 ; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                if( buy == 0){
                    curr[buy][cap] = max(ahead[0][cap] , -arr[ind] + ahead[1][cap]);
                }
                if( buy == 1){
                    curr[buy][cap] = max(ahead[1][cap] , arr[ind] + ahead[0][cap-1]);
                }
            }
        }
        ahead = curr;
    }
    return ahead[0][2];
}

int main(){
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    cout<<solve(prices , n);
    return 0;
}