#include<bits/stdc++.h>
using namespace std;

int solve(int i , int j , vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(i == 0 && j == 0){
        return matrix[0][0];
    }
    if( i < 0  ||  j < 0){
        return 1e8;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int up = matrix[i][j] + solve(i-1 , j ,matrix, dp);
    int left = matrix[i][j] + solve(i , j - 1 ,matrix, dp);

    return dp[i][j] = min(up ,left);

}

int main(){
    vector<vector<int>> matrix{
        {5, 9, 6},
        {11, 5, 2}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n , vector<int> (m,-1));

    cout<<solve(n-1,m-1,matrix , dp);
    return 0;
}