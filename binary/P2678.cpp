#include <bits/stdc++.h>
using namespace std;

int L,N,M;
int a[50005];

bool check(int x){
    int n = 0;
    int index = 0;
    for(int i = 1;i <= N+1;i++){
        if(x > (a[i] - a[index])){
            n++;
            continue;
        }else{
            index = i;
        }
    }
    if(n > M) return true;
    else return false;
}

int main(){
    cin >> L >> N >> M;
    for(int i =1;i <= N;i++){
        cin >> a[i];
    }
    a[0] = 0; a[N+1] = L;
    int l = 0;int r = 1e9+10;
    int ans = 0;
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid)){
            r = mid;
            
        }
        else{
            l = mid + 1;
            ans = mid;
        }
    }
    cout << ans; 
    return 0;   
}