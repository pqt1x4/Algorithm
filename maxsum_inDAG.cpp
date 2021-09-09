#include<bits/stdc++.h>
using namespace std;
#define maxn 100009
#define fi first
#define se second
#define pb push_back
#ifndef ONLINE_JUDGE
ifstream fin("task.inp");
ofstream fout("task.out");
#define cin fin
#define cout fout
#endif // ONLINE_JUDGE
typedef pair<int,int> ii;
vector<ii> a[maxn];
int deg[maxn],f[maxn],n,m;
void init()
{
    memset(deg,0,sizeof(deg));
    cin>>n>>m;
    int x,y,w;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y>>w;
        a[x].pb(ii(w,y));
        //deg[y]++;
        f[i]=-1;
    }
}
int dfs(int u)
{
    if (f[u]!=-1) return f[u];
    f[u]=0;
    for (ii i:a[u])
    {
        int uv=i.fi;
        int v=i.se;
        f[u]=max(f[u],dfs(v)+uv);
    }
    return f[u];
}
void solve()
{
    int cur=INT_MIN;
    for (int i=1;i<=n;i++)
    {
        dfs(i);
        cur=max(cur,f[i]);
    }
    cout<<cur;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    solve();
}
