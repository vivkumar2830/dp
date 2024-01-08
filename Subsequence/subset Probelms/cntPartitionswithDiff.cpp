#include<bits/stdc++.h>
using namespace std;


int mod =(int)1e9+7;

int f(int ind , int target , vector<int> &arr, vector<vector<int>> &dp){
    if( ind == 0){
        if( target == 0 && arr[0] == 0){
            return 2;
        }
        if( target == 0 || target == arr[0]){
            return 1;
        }
        return 0;
    }
    if(dp[ind][target] != -1){
        return dp[ind][target];
    }
    int notTake = f(ind-1, target , arr , dp);
    int take = 0;

    if(arr[ind] <= target){
        take = f(ind-1 , target - arr[ind] , arr , dp);
    } 

    return dp[ind][target] = (take + notTake) % mod;
}

int solve(vector<int>  &arr , int &d){
    int n = arr.size();
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum += arr[i];
    }

    if( sum - d < 0 || (sum-d)&1){
        return 0;
    }
    int s2 = (sum-d)/2;
    vector<vector<int>> dp(n , vector<int>(s2+1 , -1));

    return f(n-1,s2,arr,dp);
}


int main(){
    vector<int> arr = {5,2,6,4};
    int d=3;
    cout<<solve(arr,d);
    
    return 0;
}