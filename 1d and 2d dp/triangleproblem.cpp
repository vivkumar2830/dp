#include<bits/stdc++.h>
using namespace std;

int solve(int &n, int i , int j , vector<vector<int>> &matrix, vector<vector<int>> &dp){
    if(i == n-1){
        return matrix[n-1][j];
    }
   
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int down = matrix[i][j] + solve(n,i+1 , j ,matrix, dp);
    int diag = matrix[i][j] + solve(n, i + 1 , j + 1 ,matrix, dp);

    return dp[i][j] = min(down , diag);

}


                           // Tabulation Method 
// int solve2(int n , vector<vector<int>> &matrix){
//     vector<vector<int>> dp(n , vector<int>(n,0));
    
//     for(int j = 0 ; j < n ; j++){
//         dp[n-1][j] = matrix[n-1][j];
//     }

//     for(int i = n-2 ; i>=0 ; i--){
//         for(int j = i ; j>=0 ; j--){
//             int down = matrix[i][j] + dp[i+1][j];
//             int diag = matrix[i][j] + dp[i+1][j+1];

//             dp[i][j] = min(down , diag);
//         }
//     }

//     return dp[0][0];
// }

int main(){
    // vector<vector<int>> matrix{{1},
    //                                {2, 3},
    //                                {3, 6, 7},
    //                                {8, 9, 6, 10}};

    vector<vector<int>> matrix{{2},
                                {3,4},
                                {5,6,7},
                                {4,1,8,3}};

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m,-1));
    cout<<solve(n,0,0,matrix,dp);

   // cout<<solve2( n , matrix);
    return 0;
}