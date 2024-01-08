#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr , int n){
    vector<int> dp1(n,1) , dp2(n,1);
    for(int i = 0 ; i <= n-1 ; i++){
        for(int prev = 0 ; prev <= i-1 ; prev++){
            if( arr[prev] < arr[i]){
                dp1[i] = max(dp1[i] , 1 + dp1[prev]);
            }
        }
    }

// Reverse the direction of nested loops to calculate the longest decreasing subsequence
    for(int i = n-1 ; i >= 0 ; i--){
        for(int prev = n-1 ; prev > i ; prev--){
            if( arr[prev] < arr[i]){
                dp2[i] = max(dp2[i] , 1 + dp2[prev]);
            }
        }
    }
    int ans = -1;
    for(int i = 0 ; i < n ; i++){
        ans = max(ans , dp1[i] + dp2[i] - 1);
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = arr.size();

    cout<<solve(arr , n);
    return 0;
}