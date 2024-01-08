#include<bits/stdc++.h>
using namespace std;

int solve(int ind , vector<int> &h , vector<int> &dp){
    
    if(ind == 0) return 0;
    if(dp[ind] != -1){
        return dp[ind];
    }
    int jump_2 = INT_MAX;
    int jump_1 = solve(ind-1 , h, dp) + abs(h[ind] - h[ind-1]);
    if(ind > 1){
         jump_2 = solve(ind-2 , h, dp) + abs(h[ind] - h[ind-2]);
    }
    return dp[ind] = min(jump_1 , jump_2);

}

int main(){
    vector<int> height{30,10,60 , 10 , 60 , 50};
    int n = height.size();
    vector<int> dp(n,-1);
    cout<<solve(n-1, height, dp);
    return 0;
}


