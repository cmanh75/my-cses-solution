#include<bits/stdc++.h>
using namespace std;
struct ii {
    int x,y;
};
vector <ii> ans;
void Tower(int n , int a, int b, int c ){
    if(n==1){
        ans.push_back({a,c});
        return;
    }
    Tower(n-1,a,c,b);
    Tower(1,a,b,c);
    Tower(n-1,b,a,c);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a=1, b=2, c=3;
    int n;
    cin>>n;
    Tower(n,a,b,c);
    cout<<ans.size()<<"\n";
    for (auto j : ans) {
        cout<<j.x<<" "<<j.y<<"\n";
    }
}
