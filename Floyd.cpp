#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ifstream fi("FLOYD.INP");
//ofstream fo("FLOYD.OUT");
//#define cin fi
//#define cout fo
ll n,m,ts,a[101][101],f[101][101],p[101][101],trace[101];
void nhap()
{
    cin>>n>>m>>ts;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
            a[i][j]=INT_MAX;
    for (ll i=1;i<=m;i++)
    {
        ll u,v,t;
        cin>>u>>v>>t;
        a[u][v]=a[v][u]=t;
    }
}
void start()
{
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
        {
            f[i][j]=a[i][j];
            p[i][j]=j;
        }
}
void floyd()
{
    start();
    for (ll k=1;k<=n;k++)
        for (ll i=1;i<=n;i++)
            for (ll j=1;j<=n;j++)
                if (f[i][j]>f[i][k]+f[k][j] && i!=j)
                {
                    f[i][j]=f[i][k]+f[k][j];
                    p[i][j]=p[i][k];
                    //f[j][i]=f[i][j];
                }
}
void out(ll x,ll y)
{
    if (x==y)
    {
        cout<<1<<" "<<x<<endl;
        return;
    }
    ll temp=0;
    while (x!=y)
    {
        temp++;
        trace[temp]=x;
        x=p[x][y];
    }
    cout<<temp+1<<" ";
    for (int i=1;i<=temp;i++)
        cout<<trace[i]<<" ";
    cout<<y<<endl;
}
void xuat()
{
    floyd();
    for (ll i=1;i<=ts;i++)
    {
        ll x1,x2,x3;
        cin>>x1>>x2>>x3;
        if (x1==0)
        {
            if (f[x2][x3]==INT_MAX) cout<<0<<endl;
            else cout<<f[x2][x3]<<endl;
        }
        else out(x2,x3);
    }
}
int main()
{
    nhap();
    xuat();
}
