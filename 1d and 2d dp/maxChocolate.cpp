#include<bits/stdc++.h>
using namespace std;


// i is taking single because alice and bob move at same time in row but different in column so j1 and j2
int solve(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp , int &n , int &m){
    if( j1 < 0 || j1 >= m || j2 < 0 || j2 >= m){
        return -1e8;
    }
    if( i == n-1){
        if( j1== j2){
            return grid[i][j1]; // taking any grid[i][j1] or grid[i][j2] because same column
        }
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }
    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }
    int maxi = -1e8;

    for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
        for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
            int value = 0;
            if(j1 == j2){
                value += grid[i][j1];
            }
            else{
                value += grid[i][j2] + grid[i][j1];
            }

            value += solve(i+1, j1+dj1 , j2+dj2 , grid , dp , n , m);

            maxi = max(maxi , value);
        }
    }

    return dp[i][j1][j2] = maxi;
}


// Tabulation Method
int solve(int n, int m, vector<vector<int>> &grid){
    vector<vector<vector<int>>> dp(n , vector<vector<int>>(m,vector<int>(m,0)));
    for(int j1 = 0 ; j1 < m ; j1++){
        for(int j2 = 0 ; j2 < m ; j2++){
            if(j1 == j2){
                dp[n-1][j1][j2] = grid[n-1][j1];
            }
            else{
                dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
            }
        }
    }

    for(int i = n-2 ; i >= 0 ; i--){
        for(int j1 = 0 ; j1 < m ;j1++){
            for(int j2 = 0 ; j2 < m ; j2++){
                int maxi = -1e8;

                for(int dj1 = -1 ; dj1 <= 1 ; dj1++){
                    for(int dj2 = -1 ; dj2 <= 1 ; dj2++){
                        int value = 0;
                        if(j1 == j2){
                            value += grid[i][j1];
                        }
                        else{
                            value += grid[i][j2] + grid[i][j1];
                        }
            
                        value += solve(i+1, j1+dj1 , j2+dj2 , grid , dp , n , m);
            
                        maxi = max(maxi , value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m-1];
}


int main(){
    vector<vector<int>> matrix{
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };

    int n = matrix.size();
    int m = matrix[0].size();
    
    //vector<vector<vector<int>>> dp(n , vector<vector<int>>(m,vector<int>(m,-1)));
    //cout<<solve(0,0,m-1,matrix,dp , n , m);
    cout<<solve(n,m,matrix);
    return 0;
}