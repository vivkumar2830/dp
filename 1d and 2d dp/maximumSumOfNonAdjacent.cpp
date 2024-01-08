#include<bits/stdc++.h>
using namespace std;

int solve(int ind , vector<int> &arr, vector<int> &dp){
    if( ind == 0) {
        return arr[0];
    }
    if(ind < 0){
        return 0;
    }

    if( dp[ind] != -1){
        return dp[ind];
    }
    int pick = arr[ind] + solve(ind - 2 , arr, dp);
    int notPick = 0 + solve(ind-1, arr , dp);

    return dp[ind] = max(pick , notPick);
}

int main(){
    vector<int> arr{2, 1, 4, 9};
    int n = arr.size();
    vector<int> dp(n,-1);
    cout<<solve(n - 1,arr, dp);
    return 0;
}
