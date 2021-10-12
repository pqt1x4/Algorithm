/* Authors: Phan Quy Thinh - Chu Van An High School for the Gifted, Binh Dinh */
// 13092021
// https://lqdoj.edu.vn/problem/dc2021dog
#include<bits/stdc++.h>
#define task "task"

using namespace std;

#define maxn 300009
#define fi first
#define se second
#define pb push_back
#define ll long long
#ifndef ONLINE_JUDGE
ifstream f1(task".inp");
ofstream f2(task".out");
#define cin f1
#define cout f2
#endif // ONLINE_JUDGE

typedef pair<ll,ll> ii;
vector<ii> a[maxn];
ll n,fin[maxn],fout[maxn];

void init()
{
    cin>>n;
    ll u,v,w;
    for (ll i=1;i<n;i++)
    {
        cin>>u>>v>>w;
        a[u].pb({v,w});
        a[v].pb({u,w});
    }
}

void dfsin(ll u,ll par)
{
    fin[u]=0;
    for (ii v:a[u])
        if (v.fi!=par)
        {
            dfsin(v.fi,u);
            fin[u]=max(fin[u],fin[v.fi]+v.se);
        }
}

void dfsout(ll u,ll par)
{
    ll f=0,s=0;
    for (ii v:a[u])
        if (v.fi!=par)
        {
            if (fin[v.fi]+v.se>f)
            {
                s=f;
                f=fin[v.fi]+v.se;
            }
            else s=max(s,fin[v.fi]+v.se);
        }
    for (ii i:a[u])
    if (i.fi!=par)
    {
        ll v=i.fi,w=i.se;
        fout[v]=max(fout[u],fin[v]+w==f ? s : f)+w;
        dfsout(v,u);
    }
}

void solve()
{
    dfsin(1,-1);
    dfsout(1,-1);
    for (ll i=1;i<=n;i++)
        cout<<max(fin[i],fout[i])<<" ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    init();
    solve();
}
