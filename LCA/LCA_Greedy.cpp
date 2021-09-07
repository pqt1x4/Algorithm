/* Authors: Phan Quy Thinh - Chu Van An High School for the Gifted, Binh Dinh */
// 07092021
#include<bits/stdc++.h>
using namespace std;
#define maxn 300005
#define pb push_back
#ifndef ONLINE_JUDGE
ifstream fi("task.inp");
ofstream fo("task.out");
#define cin fi
#define cout fo
#endif // ONLINE_JUDGE
int n,depth[maxn],par[maxn];
vector<int> a[maxn];
void init()
{
    int m;
    cin>>n>>m;
    int x,y;
    for (int i=1;i<n;i++)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
}
void dfs(int u,int p)
{
    depth[u]=depth[p]+1;
    par[u]=p;
    for (auto v:a[u])
        if (v==p) continue;
        else dfs(v,u);
}
int lca(int u,int v)
{
    if (depth[u]<depth[v]) swap(u,v);
    while (depth[u]>depth[v]) u=par[u];
    if (u==v) return u;
    while (u!=v)
    {
        u=par[u];
        v=par[v];
    }
    return u;
}
void solve()
{
    int test;
    int x,y;
    dfs(1,0);
    cin>>test;
    while (test--)
    {
        cin>>x>>y;
        cout<<lca(x,y)<<endl;
    }
    //for (int i=1;i<=n;i++) cout<<depth[i]<<" ";
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    solve();
}
