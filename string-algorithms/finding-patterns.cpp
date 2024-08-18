#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
int link[2000009],len[2000009],nx[2000009][27],last,q,o=0;
string s,t;
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
        if (len[q]==len[p]+1) {
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
            link[q]=link[cur]=clone;
        }
    }
    last=cur;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>s;
    link[0]=-1;
    last=0;
    for (char c : s) {
        add(c-'a');
    }
    cin>>q;
    while (q--) {
        cin>>t;
        int p=0,ok=0;
        for (int i=0;i<(int)t.size();i++) {
            if (nx[p][t[i]-'a']) {
                p=nx[p][t[i]-'a'];
            }
            else {
                cout<<"NO"<<"\n";
                ok=1;
                break;
            }
        }
        if (!ok) {
            cout<<"YES"<<"\n";
        }
    }
}
