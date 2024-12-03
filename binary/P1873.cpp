#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n,m,a[N];

bool check(int x){
    long long total = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] > x){
            total += a[i] - x;
        }
    }
    if(total < m) return true;
    else return false;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int l = 0;int r = 4e5+5;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l - 1;
    return 0;
}