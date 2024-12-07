#include <bits/stdc++.h>
using namespace std;

int n,m,a[100005];

bool check(int x){
    int sum = 0;
    int total = 0;
    for(int i =0; i < n;i++){
        if(sum + a[i] < x){
            sum += a[i];
        }else if(sum + a[i] == x){
            sum = 0;
            total++;
        }else if(sum + a[i] > x){
            sum = a[i];
            total++;
        }
    }
    if(sum) total++;
    if(total <= m) return true;
    else return false;
}

int main(){
    cin >> n >> m;
    int l = 0;int r = 1e9+5;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        l = max(l,a[i]);
    }
    
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else {
            l = mid +1;
        }
    }
    cout << r << endl;
    return 0;
}