#include <bits/stdc++.h>
using namespace std;

int n,c[30],m1[30],m2[30],row[15];
int t = 0;

int dfs(int x){
    if(x == n+1){
        t++;
        if(t <= 3){
            for(int j = 1;j <= n;j++){
                cout << row[j] << " ";
            }
            cout << endl;
        }
        return 0;
    }

    for(int i = 1;i <= n;i++){
        if(c[i] || m1[x+i] || m2[x-i+n]){
            continue;
        }else{
            c[i] = 1;
            m1[x+i] = 1;
            m2[x-i+n] = 1;
            row[x] = i;
        }
        dfs(x+1);
        c[i] = 0;
        m1[x+i] = 0;
        m2[x-i+n] = 0;
    }
    return 0;
}

int main(){
    cin >> n;
    dfs(1);
    cout << t << endl;
    return 0;
}