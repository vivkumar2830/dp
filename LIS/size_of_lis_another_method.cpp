#include<bits/stdc++.h>
using namespace std;

int solve(int arr[] , int n){
    vector<int> dp(n,1);
    for(int i = 0 ; i <= n-1 ; i++){
        for(int prev = 0 ; prev <= i-1 ; prev++){
            if( arr[prev] < arr[i]){
                dp[i] = max(dp[i] , 1 + dp[prev]);
            }
        }
    }
    int ans = -1;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans , dp[i]);
    }
    return ans;
}
int main(){
    int arr[] = {10,9,2,5,3,7,101,18};
	
	int n = sizeof(arr)/sizeof(arr[0]);

    cout<<solve(arr , n);
    return 0;
}