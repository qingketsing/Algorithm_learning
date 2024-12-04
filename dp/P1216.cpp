#include <bits/stdc++.h>
using namespace std;

int r,a[1005][1005],dp[1005][1005];

int main(){
    cin >> r;
    for(int i =1;i <= r;i++){
        for(int j = 1;j <= i;j++){
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];
    for(int i = 2;i <= r;i++){
        for(int j = 1;j <= i;j++){
            dp[i][j] = max(dp[i-1][j]+a[i][j],dp[i-1][j-1]+a[i][j]);
        }
    }
    int maxi = 0;
    for(int i = 1;i <= r;i++){
        maxi = max(maxi,dp[r][i]);
    }
    cout << maxi;
    return 0;
}