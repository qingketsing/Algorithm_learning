#include <bits/stdc++.h>
using namespace std;

int n,a[305][305],f[305][305],nx,ny;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct PII{
    int x,y,t;
}p;
queue<PII> q;

int main(){
    cin >> n;
    for(int i=0; i<=304; i++){
        for(int j=0; j<=304; j++){
            a[i][j]=-1;
        }
    }
    for(int i = 0;i < n;i++){
        int x,y,t;
        cin >> x >> y >> t;
        if(a[x][y] == -1 || a[x][y] > t){
            a[x][y] = t;
        }
        for(int j = 0;j < 4;j++){
            if(x+dx[j] >= 0 && y+dy[j] >= 0){
                if(a[x+dx[j]][y+dy[j]] == -1 || a[x+dx[j]][y+dy[j]] > t){
                    a[x+dx[j]][y+dy[j]] = t;
                }
            }
            
        }
    }
    q.push((PII){0,0,0});
    f[0][0] = 1;
    while(q.size()){
        p = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            nx = p.x+dx[i];
            ny = p.y+dy[i];
            if(nx >= 0 && ny >= 0 && f[nx][ny] == 0 && (a[nx][ny] > p.t+1 || a[nx][ny] == -1)){
                f[nx][ny] = 1;
                q.push((PII){nx,ny,p.t+1});
                if(a[nx][ny] == -1){
                    cout << p.t+1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1  << endl;
    return 0;
}