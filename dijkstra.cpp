#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 15
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

typedef pair<ll,ll> ii;
vector<ii> a[maxn];
vector<ll> nodes;
ll n,k,d[maxn],f[maxn],X[maxn],ans=INT_MAX;

void init()
{
    cin>>n>>k;
    ll x;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=n;j++)
        {
            cin>>x;
            a[i].pb({x,j});
        }
}

void dijkstra(ll Begin)
{
    for (ll i=1;i<=n;i++) d[i]=INT_MAX;
    d[Begin]=0;
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push({0,Begin});
    while (!q.empty())
    {
        ll du=q.top().fi;
        ll u=q.top().se;
        q.pop();
        if (d[u]!=du) continue;
        for (ii i:a[u])
        {
            ll uv=i.fi;
            ll v=i.se;
            if (d[v]>du+uv)
            {
                d[v]=du+uv;
                q.push({d[v],v});
            }
        }
    }
    for (ll i=1;i<=n;i++)
        f[i]=min(f[i],d[i]);
}

void out()
{
    for (int i=1;i<=n;i++) f[i]=INT_MAX;
    int cnt=0;
    for (ll i=1;i<=n;i++)
        if (X[i]==0)
        {
            cnt++;
            dijkstra(i);
        }
    ll cur=0;
    for (ll i=1;i<=n;i++)
        cur=max(cur,f[i]);
    if (cur<ans && cnt==k)
    {
        ans=cur;
        nodes.clear();
        for (ll i=1;i<=n;i++)
            if (X[i]==0) nodes.pb(i);
    }
}

void bt(ll i)
{
    for (ll j=0;j<=1;j++)
    {
        X[i]=j;
        if (i!=n)
            bt(i+1);
        else out();
    }
}

void solve()
{
    bt(1);
    cout<<ans<<"\n";
    for (ll i:nodes) cout<<i<<" ";
    //for (int i=1;i<=n;i++) cout<<f[i]<<" ";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
