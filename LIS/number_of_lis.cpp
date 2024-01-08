#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int n){
    vector<int> dp(n,1);
    vector<int> ct(n,1);

    int maxi = -1;
    for(int i = 0 ; i <= n-1 ; i++){
        for(int prev = 0 ; prev <= i-1 ; prev++){
            if( arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                dp[i] = max(dp[i] , 1 + dp[prev]);
                ct[i] = ct[prev];
            }
            else if(arr[prev] < arr[i] && 1 + dp[prev] == dp[i]){
                ct[i] = ct[prev] + ct[i];
            }
        }
        maxi = max(maxi , dp[i]);
    }
    int N_lis = 0;
    for(int i = 0 ; i < n ; i++){
        if(dp[i] == maxi){
            N_lis += ct[i];
        }
    }
    return N_lis;
}

int main(){
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};
	
	int n = sizeof(arr)/sizeof(arr[0]);

    cout<<solve(arr , n);
    return 0;
}