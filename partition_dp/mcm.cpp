#include<bits/stdc++.h>
using namespace std;

// int mcm(int i, int j , vector<int> &arr , vector<vector<int>> &dp){
//     if(i == j)
//         return 0;
        
//     if(dp[i][j]!=-1)
//         return dp[i][j];
    
//     int mini = 1e9;
    
//     // partioning loop
//     for(int k = i; k<= j-1; k++){
        
//         int ans = mcm(i,k,arr,dp) + mcm(k+1,j,arr,dp) + arr[i-1]*arr[k]*arr[j];
        
//         mini = min(mini,ans);
        
//     }
    
//     return dp[i][j] = mini;
// }

// int solve(vector<int> &arr , int n){
//     vector<vector<int>> dp(n, vector<int>(n,-1));
//     return mcm(1,n-1,arr,dp);
// }


// -------------------------------- tabulation method ---------------------------------------
int solve(vector<int> &arr , int  n){
    vector<vector<int>> dp(n , vector<int>(n , 0));
    for(int i = 1 ; i<n ; i++){
        dp[i][i] = 0;
    }

    for(int i = n-1 ; i >= 1; i--){
        for(int j = i+1 ; j < n ; j++){
            int mini = 1e9;
    
            for(int k = i; k < j; k++){
                
                int ans = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                mini = min(mini,ans);
                
            }
            
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}


int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();

    cout<<solve(arr,n);
    return 0;
}



