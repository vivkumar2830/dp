#include<bits/stdc++.h>
using namespace std;

// bool solve(int idx ,vector<int> &arr , vector<vector<int>> &dp , int k){
//     if( k == 0){
//         return true;
//     }
//     if(idx == 0){
//         return arr[0] == k;
//     }
//     if(dp[idx][k] != -1){
//         return dp[idx][k];
//     }

//     bool notTake = solve(idx-1, arr , dp , k);
//     bool take = false;

//     if(arr[idx] <= k){
//         take = solve(idx-1 , arr , dp , k-arr[idx]);
//     }

//     return dp[idx][k] = take || notTake;
// }


// Tabulation Method
bool solve1(int n , vector<int> &arr , int &k){
    vector<vector<bool>> dp(n, vector<bool>(k+1, 0));

    for(int i = 0 ; i<n ; i++){
        dp[i][0] = true;
    }
    if(arr[0] <= k){
        dp[0][arr[0]] = true;
    }

    for(int i = 1 ; i < n ; i++){
        for(int target = 1 ; target <= k ; target++){
            bool notTake = dp[i-1][target];
            bool take = false;
        
            if(arr[i] <= target){
                take = dp[i-1][target-arr[i]];
            }
            dp[i][target] = take || notTake;
        }
    }
    return dp[n-1][k];

}

int main(){
    vector<int> arr = {1, 5, 11, 5};
    int k = 11;
    int n = arr.size();

    // vector<vector<int>> dp(n, vector<int>(k+1, -1));

    // if (solve(n-1, arr , dp , k))
    //     cout << "Subset with the given target found";
    // else
    //     cout << "Subset with the given target not found";
    
    if (solve1(n , arr , k))
        cout << "Subset with the given target found";
    else
        cout << "Subset with the given target not found";
    
    return 0;
}


