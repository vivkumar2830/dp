#include<bits/stdc++.h>
using namespace std;

// int mcs(int i , int j , vector<int> &cuts , vector<vector<int>> &dp){
//     if( i > j){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }

//     int mini = 1e8;
//     for(int ind = i ; ind <= j ; ind++){
//         int cost = cuts[j+1] - cuts[i-1] + mcs( i , ind-1 , cuts , dp) + mcs(ind+1 , j , cuts , dp);
//         mini = min(cost , mini);
//     }

//     return dp[i][j] = mini;
// }

// int solve(vector<int> &cuts , int c , int n){
//     cuts.push_back(n);
//     cuts.insert(cuts.begin() , 0);
//     sort(cuts.begin() , cuts.end());

//     vector<vector<int>> dp(c+1 , vector<int> (c+1 , -1));
//     return mcs(1 , c , cuts , dp);
// }

int solve(vector<int> &cuts , int c , int n){
    cuts.push_back(n);
    cuts.insert(cuts.begin() , 0);
    sort(cuts.begin() , cuts.end());

    vector<vector<int>> dp(c+2 , vector<int> (c+2 , 0));

    for(int i = c ; i >= 1 ; i--){
        for(int j = 1; j <= c ; j++){
            if( i > j){
                continue;
            }
            int mini = 1e8;
            for(int ind = i ; ind <= j ; ind++){
                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(cost , mini);
            }

            dp[i][j] = mini;

        }
    }
    return dp[1][c];
    
}

int main(){
    vector<int> cuts = {3, 5, 1, 4};
    int c = cuts.size();
    int n = 7;
    cout<<solve(cuts, c , n);
    return 0;
}