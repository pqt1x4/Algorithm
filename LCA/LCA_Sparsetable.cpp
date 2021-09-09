#include<bits/stdc++.h>
using namespace std;
#define maxn 10009
ifstream fin("task.inp");
ofstream fout("task.out");
#define cin fin
#define cout fout
int n,q,depth[maxn],T[maxn][25];
vector<int> V[maxn];
void init()
{
    cin>>n;
    int u,v;
    for (int i=1;i<n;i++)
    {
        cin>>u>>v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
}
void dfs(int u,int p)
{
    depth[u]=depth[p]+1;
    T[u][0]=p;
    for (int i=1;i<17;i++)
        T[u][i]=T[T[u][i-1]][i-1];
    for (auto v:V[u])
        if (v==p) continue;
        else dfs(v,u);
}
int LCA(int u,int v)
{
    if (depth[u]<depth[v]) swap(u,v);
    for (int i=16;i>=0;i--)
    if (depth[T[u][i]]>=depth[v]) u=T[u][i];
    if (u==v) return u;
    for (int i=16;i>=0;i--)
        if (T[u][i]!=T[v][i])
        {
            u=T[u][i];
            v=T[v][i];
        }
    return T[u][0];
}
void solve()
{
    dfs(1,0);
    //for (int i=1;i<=n;i++) cout<<depth[i]<<" ";
    //cout<<LCA(5,7);
}
int main()
{
    init();
    solve();
}
