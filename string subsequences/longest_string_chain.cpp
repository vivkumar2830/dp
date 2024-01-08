#include<bits/stdc++.h>
using namespace std;

bool compare(string &s1 , string &s2){
    if(s1.size() != s2.size() + 1) return false;

    int first = 0 , second = 0;
    while( first < s1.size()){
        if( second < s2.size() && s1[first] == s2[second]){
            first++; second++;
        }
        else{
            first++;
        }
    }
    if( first == s1.size() && second == s2.size()) return true;
    else{
        return false;
    }
}

bool comp(string &s1 , string &s2){
    return s1.size() < s2.size();
}

int solve(vector<string> &arr, int n){

    vector<int> dp(n,1);

    sort(arr.begin() , arr.end() , comp);

    int maxi = 1;
    for(int i = 0 ; i <= n-1 ; i++){
        for(int prev = 0 ; prev <= i-1 ; prev++){
            if( compare(arr[i] ,  arr[prev]) && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
        }
    }
    
    return maxi;
}
int main(){
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    int n = words.size();

    cout<<solve(words , n);
    return 0;
}