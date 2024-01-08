#include<bits/stdc++.h>
using namespace std;

// int maxSum(int ind , int n, int k , vector<int> &arr , vector<int> &dp){
//     if( ind == n){
//         return 0;
//     }

//     if(dp[ind] != -1){
//         return dp[ind];
//     }

//     int len = 0;
//     int maxi = -1e8 , maxAns = -1e8;

//     for(int j = ind ; j < min(ind+k , n) ; j++){
//         len++;
//         maxi = max(maxi , arr[j]);
//         int sum = len*maxi + maxSum(j+1 , n , k , arr , dp);
//         maxAns = max(sum , maxAns);
//     }

//     return dp[ind] = maxAns;
// }

// int solve(vector<int> &arr , int k){
//     int n = arr.size();
//     vector<int> dp(n,-1);

//     return maxSum(0 , n , k , arr , dp);
// }

int solve(vector<int> &arr , int k){
    int n = arr.size();
    vector<int> dp(n+1,0);

    for(int ind = n-1 ; ind >= 0 ; ind--){
        int len = 0;
        int maxi = -1e8 , maxAns = -1e8;

        for(int j = ind ; j < min(ind+k , n) ; j++){
            len++;
            maxi = max(maxi , arr[j]);
            int sum = len*maxi + dp[j+1];
            maxAns = max(sum , maxAns);
        }

        dp[ind] = maxAns;
    }
    return dp[0];
}

int main(){
    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout<<solve(num , k);
    return 0;
}