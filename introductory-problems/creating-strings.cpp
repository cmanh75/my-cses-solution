#include<bits/stdc++.h>
using namespace std;
string s;
map <string,bool> m;
int d[11];
vector <string> ans;
void cal(int i,string t) {
    if (i==s.size()) {
        if (!m[t]) {
            ans.push_back(t);
            m[t]=1;
        }
        return;
    }
    for (int j=0;j<s.size();j++) {
        if (!d[j]) {
            d[j]=1;
            cal(i+1,t+s[j]);
            d[j]=0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>s;
    sort(s.begin(),s.end());
    cal(0,"");
    cout<<ans.size()<<"\n";
    for (auto j : ans) {
        cout<<j<<"\n";
    }
}
