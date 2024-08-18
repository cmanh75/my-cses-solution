#include<bits/stdc++.h>
using namespace std;
char a[9][9];
int ans;
void trans(int i,int j) {
    for (int k=i;k<=8;k++) {
        a[k][j]='*';
    }
    int x=i,y=j;
    while (i>=1&&j>=1) {
        a[i][j]='*';
        i--;
        j--;
    }
    i=x,j=y;
    while (i>=1&&j<=8) {
        a[i][j]='*';
        i--;
        j++;
    }
    i=x,j=y;
    while (i<=8&&j>=1) {
        a[i][j]='*';
        i++;
        j--;
    }
    i=x,j=y;
    while (i<=8&&j<=8) {
        a[i][j]='*';
        i++;
        j++;
    }
}
void tim(int i) {
    if (i>8) {
        ans++;
        return;
    }
//    cout<<i<<"\n";
    char b[9][9];
    for (int k=1;k<=8;k++) {
        for (int j=1;j<=8;j++) {
            b[k][j]=a[k][j];
        }
    }
    for (int j=1;j<=8;j++) {
        if (a[i][j]=='.') {
            trans(i,j);
            tim(i+1);
            for (int k=1;k<=8;k++) {
                for (int h=1;h<=8;h++) {
                    a[k][h]=b[k][h];
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    for (int i=1;i<=8;i++) {
        for (int j=1;j<=8;j++) {
            cin>>a[i][j];
        }
    }
    tim(1);
    cout<<ans;
}
