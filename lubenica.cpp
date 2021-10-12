/* Author: Phan Quy Thinh - CVA High School for the Gifted, Binh Dinh */
// 26092021
// https://oj.vnoi.info/problem/lubenica
#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 100009
#define endl "\n"
#define ll long long
#define pb push_back
#define LOG 20
#define fi first
#define se second
#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif // ONLINE_JUDGE

typedef pair<ll,ll> ii;
typedef pair<ll,pair<ll,ll>> iii;

vector<ii> a[maxn];
iii T[maxn][LOG];
ll n,depth[maxn];

void init()
{
    cin>>n;
    ll x,y,z;
    for (ll i=1;i<n;i++)
    {
        cin>>x>>y>>z;
        a[x].pb({y,z});
        a[y].pb({x,z});
    }
}

void prepare()
{
    for (ll i=0;i<LOG;i++)
        for (ll u=0;u<=n;u++)
        T[u][i]={0,{0,LLONG_MAX}};
}

void dfs(ll u,ll p)
{
    depth[u]=depth[p]+1;
    T[u][0].fi=p;
    for (ll i=1;i<LOG;i++)
        {
            T[u][i].fi=T[T[u][i-1].fi][i-1].fi;
            T[u][i].se.fi=max(T[u][i-1].se.fi,T[T[u][i-1].fi][i-1].se.fi);
            T[u][i].se.se=min(T[u][i-1].se.se,T[T[u][i-1].fi][i-1].se.se);
        }
    for (ii v:a[u])
        if (v.fi!=p)
        {
            T[v.fi][0].se.fi=T[v.fi][0].se.se=v.se;
            dfs(v.fi,u);
        }
}

ii LCA(ll u,ll v)
{
    ii res={0,LLONG_MAX};
    if (depth[u]<depth[v]) swap(u,v);
    for (ll i=LOG-1;i>=0;i--)
        if (depth[T[u][i].fi]>=depth[v])
        {
            res={max(res.fi,T[u][i].se.fi),min(res.se,T[u][i].se.se)};
            u=T[u][i].fi;
        }
    if (u==v) return res;
    for (ll i=LOG-1;i>=0;i--)
        if (T[u][i].fi!=T[v][i].fi)
        {
            res={max({res.fi,T[u][i].se.fi,T[v][i].se.fi}),min({res.se,T[u][i].se.se,T[v][i].se.se})};
            u=T[u][i].fi;
            v=T[v][i].fi;
        }
    return {max({res.fi,T[u][0].se.fi,T[v][0].se.fi}),min({res.se,T[u][0].se.se,T[v][0].se.se})};
}

void solve()
{
    prepare();
    dfs(1,0);
    ll query,u,v;
    cin>>query;
    for (ll i=1;i<=query;i++)
    {
        cin>>u>>v;
        ii tmp=LCA(u,v);
        cout<<tmp.se<<" "<<tmp.fi<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
