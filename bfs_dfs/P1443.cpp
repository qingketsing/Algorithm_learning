#include <bits/stdc++.h>
#include <queue>
using namespace std;

struct PII{
    int x,y,s;
};
int n,m,x,y,f[405][405];
queue<PII> q;

int xx[8] = {2,2,-2,-2,1,1,-1,-1};
int yy[8] = {1,-1,1,-1,2,-2,2,-2};


int bfs(int x,int y){
    memset(f, -1, sizeof(f));
    f[x][y] = 0;
    q.push((PII){x,y,0});
    
    while(q.size()){
        PII t = q.front();
        q.pop();

        for(int i = 0;i < 8;i++){
            int ax = t.x + xx[i];
            int ay = t.y + yy[i];
            
            if(ax <= n && ax > 0 && ay <= m && ay > 0 && f[ax][ay] == -1){
                f[ax][ay] = t.s + 1;
                q.push((PII){ax,ay,t.s+1});
            }
        }
    }
    return 0;
}

int main(){

    cin >> n >> m >> x >> y;
    bfs(x,y);
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            printf("%-5d",f[i][j]);
        }
        cout << endl;
    }
    return 0;
}