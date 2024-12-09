#include <bits/stdc++.h>
#include <queue>
using namespace std;

int n,m;
queue<int> q;

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        q.push(i);
    }
    int count = 1;
    while(q.size()){
        if(count == m){
            cout << q.front() << " ";
            q.pop();
            count = 1;
        }else{
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return 0;
}