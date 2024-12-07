#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int a[N],n,m,s;

bool check(int x){
    if(a[x] >= s) return true;
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < m;i++){
        cin >> s;
        int l = 1,r = n;
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid;
            else {
                l = mid+1;
            }
        }
        if(a[l] != s) cout << -1 << " ";
        else cout << l << " "; 
    }
    return 0;
}
