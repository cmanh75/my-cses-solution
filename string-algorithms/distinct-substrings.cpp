#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
int last,link[2000009],nx[2000009][27],len[2000009],o=0;
ll ans=0,dp[2000009];
string s;
void add(int c) {
    int p,cur=++o;
    len[cur]=len[last]+1;
    for (p=last;p+1&&!nx[p][c];p=link[p]) {
        nx[p][c]=cur;
    }
    if (p==-1) {
        link[cur]=0;
    }
    else {
        int q=nx[p][c];
        if (len[p]+1==len[q]) {
            link[cur]=q;
        }
        else {
            int clone=++o;
            len[clone]=len[p]+1;
            link[clone]=link[q];
            memcpy(nx[clone],nx[q],sizeof(nx[q]));
            for (;p+1&&nx[p][c]==q;p=link[p]) {
                nx[p][c]=clone;
            }
            link[cur]=link[q]=clone;
        }
    }
    last=cur;
}
void dfs(int i) {
    dp[i]=1;
    for (int j=0;j<26;j++) {
        if (nx[i][j]) {
            int v=nx[i][j];
            if (!dp[v]) {
                dfs(v);
            }
            dp[i]+=dp[v];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>s;
    dp[0]=1;
    last=0;
    link[0]=-1;
    for (char c : s) {
        add(c-'a');
    }
    dfs(0);
    cout<<dp[0]-1;
}
