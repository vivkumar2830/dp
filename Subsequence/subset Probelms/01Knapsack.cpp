#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> &wt , vector<int> &val , int ind, int W,vector<vector<int>> &dp){
    if( ind == 0 || W == 0 ){
        if(wt[0] <= W){
            return val[0];
        }
        return 0;
    }
    if(dp[ind][W] != -1){
        return dp[ind][W];
    }

    int notTaken = 0 + solve(wt, val, ind-1 , W , dp);
    int taken = -1e8;
    if(wt[ind] <= W){
        taken = val[ind] + solve(wt, val , ind-1 , W-wt[ind], dp);
    }

    return dp[ind][W] = max(notTaken , taken);
}

int knap(vector<int> &wt , vector<int> &val , int n, int W){
    vector<vector<int>> dp(n, vector<int>(W+1 , -1));
    return solve(wt, val , n-1 , W , dp);
}
int main(){
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};

    int n = val.size();
    int W = 5;
    cout<<knap(wt,val,n,W);
    return 0;
}