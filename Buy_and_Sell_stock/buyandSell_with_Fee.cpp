#include<bits/stdc++.h>
using namespace std;

// int me(long *arr , int ind , int buy , int n ,int fee,  vector<vector<int>> &dp){
//     if( ind == n){
//         return 0;
//     }

//     if(dp[ind][buy] == -1){
//         return dp[ind][buy];
//     }

//     long profit = 0;
//     if( buy == 0){
//         profit = max( me(arr, ind + 1 , 0 , n ,fee, dp) , -arr[ind] + me(arr , ind + 1 , 1 , n,fee ,dp));
//     }
//     if(buy == 1){
//         profit = max(0 + me(arr, ind + 1, 1, n,fee, dp), arr[ind]-fee + me(arr, ind + 1, 0, n,fee, dp));
//     }

//     return dp[ind][buy] = profit;
// }

// int solve(long *arr , int n , int fee){
//     if( n== 0){
//         return 0;
//     }
//     vector<vector<int>> dp( n , vector<int>(2, -1));
//     return me(arr , 0 , 0 , n ,fee, dp);
// }

// -----------------  Tabulation Method  -------------------------

int solve(long *arr , int n , int fee){
    if(n==0){
        return 0;
    }

    vector<vector<long>> dp( n+1  , vector<long>(2, 0));
    

    long profit;

    for(int ind = n-1 ; ind >= 0 ; ind--){
        for(int buy = 0; buy <= 1; buy++){
            if( buy == 0){
                profit = max(dp[ind+1][0] , -arr[ind] + dp[ind+1][1]);
            }
            if(buy == 1){
                profit = max(dp[ind+1][1] , arr[ind] - fee + dp[ind+1][0]);
            }

            dp[ind][buy] = profit;
        }
    }

    return dp[0][0];
}


// ------------- space optimization -----------

// int solve(long *arr , int n , int fee){
//     vector<long> ahead(2,0);
//     vector<long> curr(2,0);

//     long profit;

//     for(int ind = n-1 ; ind >= 0 ; ind--){
//         for(int buy = 0; buy <= 1; buy++){
//             if( buy == 0){
//                 profit = max(ahead[0] , -arr[ind] + ahead[1]);
//             }
//             if(buy == 1){
//                 profit = max(ahead[1] , arr[ind] - fee + ahead[0]);
//             }

//             curr[buy] = profit;
//         }
//         ahead = curr;
//     }

//     return curr[0];
// }

int main(){
    int n = 6;
    long Arr[n] = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout<<solve(Arr , n , fee);
    return 0;
}