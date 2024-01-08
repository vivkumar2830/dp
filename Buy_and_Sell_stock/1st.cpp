#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr){
    int profit = 0;
    int mini = arr[0];

    for(int i = 1; i < arr.size() ; i++){
        int curr_profit = arr[i] - mini;
        profit = max(profit , curr_profit);
        mini = min(mini , arr[i]);
    }

    return profit;
}
int main(){
    vector<int> Arr  ={7,1,5,3,6,4};
    cout<<solve(Arr);
    return 0;
}