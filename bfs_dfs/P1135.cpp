#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct PII{
    int x,y,s;
};
int f[210],a[210];

int N,A,B;
queue<PII> q;

int bfs(int x){
    q.push({x,a[x],0});
    while(q.size()){
        int floor = q.front().x;
        int k = q.front().y;
        int step = q.front().s;
        q.pop();
        if(floor == B){
            return step;
        }
        if(floor + k <= N && f[floor + k] == -1){
            f[floor + k] = step + 1;
            q.push({floor+k,a[floor+k],step+1});
        }
        if(floor - k > 0 && f[floor - k] == -1){
            f[floor - k] = step + 1;
            q.push({floor-k,a[floor-k],step+1});
        }
    }
    return -1;
}

int main(){
    cin >> N >> A >> B;
    for(int i = 1;i <= N;i++){
        cin >> a[i];
    }
    memset(f,-1,sizeof(f));
    int ans = bfs(A);
    cout << ans << endl;
    return 0;
}