/* Authors: Phan Quy Thinh - Chu Van An High School for the Gifted, Binh Dinh */
// 07092021
#include<bits/stdc++.h>
#define task "diameter"
using namespace std;
#define maxn 300009
#define pb push_back
ifstream fi(task".inp");
ofstream fo(task".out");
#define cin fi
#define cout fo
vector<int> a[maxn];
int n,fin[maxn],fout[maxn];
void init()
{
    cin>>n;
    int x,y;
    for (int i=1;i<n;i++)
    {
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
}
void dfsin(int u,int par)
{
    fin[u]=0;
    for (int v:a[u])
        if (v!=par)
        {
            dfsin(v,u);
            fin[u]=max(fin[u],fin[v]+1);
        }
}
void dfsout(int u,int par)
{
    int first=-1,second=-1;
    for (int v:a[u])
        if (v!=par)
        {
            if (fin[v]>=first)
            {
                second=first;
                first=fin[v];
            }
            else second=max(second,fin[v]);
        }
    for (int v:a[u])
        if (v!=par)
        {
            fout[v]=max(1,fout[u]+1);
            fout[v]=max(fout[v],fin[v]==first ? second + 2 : first + 2);
            dfsout(v,u);
        }
}
void solve()
{
    memset(fin,0,sizeof(fin));
    memset(fout,0,sizeof(fout));
    dfsin(1,-1);
    dfsout(1,-1);
    int ans=0;
    for (int i=1;i<=n;i++) ans=max({ans,fin[i],fout[i]});
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int test;
    cin>>test;
    init();
    solve();
}
