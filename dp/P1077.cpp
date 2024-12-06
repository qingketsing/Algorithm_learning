#include <bits/stdc++.h>
using namespace std;

int n,m,a[105];
long long f[105][105];
const int mod = 1e6+7;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    f[0][0] = 1;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j <= m;j++){
            for(int k = 0;k <= min(j,a[i]);k++){
                f[i][j] = (f[i][j]+f[i-1][j-k]) % mod;
            }
        }
    }
    cout << f[n][m] << endl;
    return 0;
}