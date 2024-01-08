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
    vector<int> arr{1,5,1,2,6};
    int n = arr.size();

    vector<int> temp1 , temp2;

    for(int i = 0 ; i<n ; i++){
        if( i!=0){
            temp1.push_back(arr[i]);
        }
        if(i != n-1){
            temp2.push_back(arr[i]);
        }
    }
    vector<int> dp(n-1,-1);

    int ans = solve(n-2 , temp1 , dp);
    dp.assign(n-1, -1);
    ans = max(ans, solve(n-2 , temp2 , dp));
    cout<<ans;
    return 0;
}