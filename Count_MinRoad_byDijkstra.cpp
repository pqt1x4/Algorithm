#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr first
#define se second
typedef pair<ll,ll> ii;
vector<ii> a[50005];
ii d[50005];
ll n,m,S=-1,f[5005][5005],ans=0,l[500005],tmp=0;
bool visit[50005];
void nhap()
{
    cin>>n>>m;
    for (ll i=1;i<=m;i++)
    {
        ll k,u,v,l;
        cin>>k>>u>>v>>l;
        a[u].push_back(ii(l,v));
        f[u][v]=l;
        if (k==2)
        {
            a[v].push_back(ii(l,u));
            f[v][u]=l;
        }
    }
}
// QHĐ + DIJKSTRA
void dijkstra(ll x,ll y)
{
    priority_queue<ii,vector<ii>,greater<ii>> q;
    q.push(ii(0,x));
    for (ll i=1;i<=n;i++) d[i].fr=INT_MAX;
    d[x].fr=0;
    d[x].se=1;
    while (!q.empty())
    {
        ll du=q.top().fr;
        ll u=q.top().se;
        q.pop();
        if (du!=d[u].fr) continue;
        for (ll i=0;i<a[u].size();i++)
        {
            ll v=a[u][i].se;
            ll uv=a[u][i].fr;
            if (d[v].fr==du+uv) d[v].se+=d[u].se;
            else if (d[v].fr>du+uv)
            {
                d[v].fr=du+uv;
                d[v].se=d[u].se;
                q.push(ii(d[v].fr,v));
            }
        }
    }
    cout<<d[y].fr<<" "<<d[y].se;
}
// TRÂU
/*
void out(ll tmp)
{
    ll temp=0;
    for (ll i=1;i<tmp;i++)
        temp+=f[l[i-1]][l[i]];
    if (temp==S) ans++;
}
void bt(ll tmp)
{
    if (l[tmp-1]==n) out(tmp);
    else
    {
        for (ll i=1;i<=n;i++)
            if (f[l[tmp-1]][i]!=0 && visit[i]==true)
            {
                l[tmp]=i;
                visit[i]=false;
                bt(tmp+1);
                l[tmp]=0;
                visit[i]=true;
            }
    }
}
void start()
{
    S=dijkstra(1,n);
    memset(visit,true,sizeof(visit));
    visit[1]=false;
    l[0]=1;
}
*/
void xuat()
{
    dijkstra(1,n);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    nhap();
    xuat();
}
/*
6 9
1 1 2 1
1 2 3 1
1 3 6 1
1 2 6 2
1 1 5 1
1 5 6 3
1 1 4 1
2 4 5 2
2 6 4 2
*/
