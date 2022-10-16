/* Author: Phan Quy Thinh - HSGS BDi.CVA */
// 16102022
// https://oj.vnoi.info/problem/lem3
#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 20
#define ll long long
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif // ONLINE_JUDGE

int n,a[maxn][maxn],check[maxn][1<<maxn],f[maxn][maxn];

void init()
{
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>a[i][j];
    n++;
}

int TSP(int i,int S)
{
    if (S==((1<<n)-1)) return a[i][0];
    if (check[i][S]!=-1) return check[i][S];
    int res=INT_MAX;
    for (int j=0;j<n;j++)
        if (S&(1<<j)) continue;
        else res=min(res,a[i][j]+TSP(j,S|(1<<j)));
    check[i][S]=res;
    return res;
}

void solve()
{

    memset(check,-1,sizeof(check));
    cout<<TSP(0,1<<0);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
