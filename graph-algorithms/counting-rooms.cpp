#include<bits/stdc++.h>
using namespace std;
long long n,m,d[1009][1009],ans;
char a[1009][1009];
struct ii {
    int x,y;
};
queue <ii> q;
void dfs(int x,int y) {
    d[x][y]=1;
    if (a[x-1][y]=='.'&&!d[x-1][y]) {
        dfs(x-1,y);
    }
    if (a[x][y-1]=='.'&&!d[x][y-1]) {
        dfs(x,y-1);
    }
    if (!d[x+1][y]&&a[x+1][y]=='.') {
        dfs(x+1,y);
    }
    if (!d[x][y+1]&&a[x][y+1]=='.') {
        dfs(x,y+1);
    }
}
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            if (a[i][j]=='.') {
                q.push({i,j});
            }
        }
    }
    while (q.size()) {
        int x=q.front().x,y=q.front().y;
        q.pop();
        if (d[x][y]) {
            continue;
        }
        ans++;
        dfs(x,y);
    }
    cout<<ans;
}
