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
        deg[y]++;
    }
}
void solve()
{
    memset(f,0,sizeof(f));
    queue<int> q;
    for (int i=1;i<=n;i++)
        if (deg[i]==0) q.push(i);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for (ii i:a[u])
        {
            f[i.se]=max(f[i.se],f[u]+i.fi);
            deg[i.se]--;
            if (deg[i.se]==0)
                q.push(i.se);
        }
    }
    int cur=INT_MIN;
    for (int i=1;i<=n;i++) cur=max(cur,f[i]);
    cout<<cur;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    solve();
}
