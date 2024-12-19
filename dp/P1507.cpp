#include <bits/stdc++.h>
using namespace std;

int h,t,n,f[55][405][405];

struct node{
    int hi,ti,ki;
}a[55];

int main(){
    cin >> h >> t;
    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> a[i].hi >> a[i].ti >> a[i].ki;
    }
    for(int i = 1;i <= n;i++){
        for(int j = h;j > 0;--j){
            for(int p = t;p > 0;--p){
                if(j >= a[i].hi && p >= a[i].ti){
                    f[i][j][p] = max(f[i-1][j][p],f[i-1][j-a[i].hi][p-a[i].ti]+a[i].ki);
                }else{
                    f[i][j][p] = f[i-1][j][p];
                }
            }
        }
    }
    cout << f[n][h][t] << endl;
    return 0;
}