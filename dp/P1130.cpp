#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int m,n,a[N][N],f[N][N];

int main(){
    memset(a,-1,sizeof(a));
    cin >> n >> m;
    for(int i = 1;i <= m;++i){
        for(int j = 1;j <= n;j++){
            cin >> a[i][j];
        }
    }
    for(int i =1;i <= m;i++){
        f[i][1] = a[i][1];
    }
    for(int j = 2;j <= n;j++){
        for(int i = 1;i <= m;i++){
            //row is i, col is j
            if(i >= 2){
                f[i][j] = a[i][j] + min(f[i][j-1],f[i-1][j-1]);
            }else{
                f[i][j] = a[i][j] + min(f[i][j-1],f[m][j-1]);
            }
        }
    }
    int minx = 1e9 + 1;
    for(int i = 1;i <= m;i++){
        minx = min(minx,f[i][n]);
    }
    cout << minx << endl;
    return 0;
}