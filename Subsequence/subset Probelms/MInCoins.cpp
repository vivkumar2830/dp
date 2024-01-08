#include<bits/stdc++.h>
using namespace std;


int f(vector<int> &arr , int ind , int T , vector<vector<int>> &dp){
    if(ind == 0){
       if(T % arr[0] == 0 ){
        return T/arr[0];
       }
       return 1e9;
    }

    if( dp[ind][T] != -1){
        return dp[ind][T];
    }

    int notTaken = f(arr , ind-1 , T , dp);
    int taken = 1e9;
    if(arr[ind] <= T){
        taken = 1 + f(arr, ind , T-arr[ind] , dp);
    }

    return dp[ind][T] = min(notTaken , taken);
}
int solve(vector<int> &arr , int T){
    int n = arr.size();

    vector<vector<int>> dp(n , vector<int> (T + 1, -1));

    int ans = f(arr, n-1 , T , dp);

    if( ans >= 1e9){
        return -1;
    }
    else{
        return ans;
    }
}
int main(){
    vector<int> arr = {1, 2, 3};
    int T = 7;

    cout<<solve(arr, T);
    return 0;
}