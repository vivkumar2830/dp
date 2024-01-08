#include<bits/stdc++.h>
using namespace std;

vector<int> lis(int arr[] , int n){
    vector<int> dp(n,1) , hash(n,1);
    sort(arr , arr+n);

    for(int i = 0 ; i <= n-1 ; i++){
        hash[i] = i;
        for(int prev = 0 ; prev <= i-1 ; prev++){
            if( arr[i] % arr[prev] == 0 &&  1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }
    int ans = -1 , lastIndex = -1;
    for(int i = 0 ; i<=n-1 ; i++){
        if(dp[i] > ans){
            ans = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while( hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(),temp.end());
        
    return temp;
}
int main(){

    int arr[] = {1, 16, 7, 8, 4};
	int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> ans = lis(arr,n);

    cout << "The longest divisible subset elements are: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}