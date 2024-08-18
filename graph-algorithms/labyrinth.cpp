#include<bits/stdc++.h>
using namespace std;
long long m,n,d[1009][1009],u,v,o,e;
char a[1009][1009];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
struct ii {
    int x,y;
};
queue <ii> q;
stack <char> s;
int main() {
    cin>>m>>n;
    for (int i=0;i<=m;i++) {
        for (int j=0;j<=n;j++) {
            d[i][j]=1e9;
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            if (a[i][j]=='B') {
                u=i;
                v=j;
            }
            if (a[i][j]=='A') {
                q.push({i,j});
                d[i][j]=0;
                o=i,e=j;
            }
        }
    }
    while (q.size()) {
        int x=q.front().x;
        int y=q.front().y;
        q.pop();
        if (x<1||x>m||y>n||y<1) {
            continue;
        }
        if (x==u&&y==v) {
            break;
        }
        for (int j=0;j<4;j++) {
            if (a[x+dx[j]][y+dy[j]]!='#'&&d[x+dx[j]][y+dy[j]]==1e9) {
                d[x+dx[j]][y+dy[j]]=d[x][y]+1;
                q.push({x+dx[j],y+dy[j]});
            }
        }
    }
    if (d[u][v]==1e9) {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<d[u][v]<<"\n";
    while (1) {
        if (d[u][v]==d[u-1][v]+1) {
            s.push('D');
            u--;
            continue;
        }
        if (d[u][v]==d[u][v-1]+1) {
            s.push('R');
            v--;
            continue;
        }
        if (d[u][v]==d[u+1][v]+1) {
            s.push('U');
            u++;
            continue;
        }
        if (d[u][v]==d[u][v+1]+1) {
            s.push('L');
            v++;
            continue;
        }
        if (u==o&&v==e) {
            break;
        }
    }
    while (s.size()) {
        cout<<s.top();
        s.pop();
    }
}
