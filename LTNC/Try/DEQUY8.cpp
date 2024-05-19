#include<bits/stdc++.h>
#define task "task."
using namespace std;

#define maxn 109
#define ll long long 
#define pb push_back
#define fi first
#define se second
///*
#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif
//*/

int k,n,a[maxn][maxn];

void init()
{
   cin>>n>>k;
}

void solve()
{
    a[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=i;j++)
        {
            if (j==0 || j==i)
                a[i][j]=1;
            else 
                a[i][j]=a[i-1][j]+a[i-1][j-1];
        }
    cout<<a[n][k];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
