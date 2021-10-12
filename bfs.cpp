#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 109
#define endl "\n"
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
typedef pair<ll,ii> iii;
ii Begin,End;
ll a[maxn][maxn],f[maxn][maxn],n,m;
ll dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
bool visit[maxn][maxn];

void init()
{
    cin>>n>>m;
    for (ll i=1;i<=n;i++)
        for (ll j=1;j<=m;j++)
            cin>>a[i][j];
    cin>>Begin.fi>>Begin.se>>End.fi>>End.se;
}

void bfs(ll I,ll J)
{
    priority_queue<iii,vector<iii>,greater<iii>> q;
    memset(visit,true,sizeof(visit));
    q.push({0,{I,J}});
    f[I][J]=0;
    visit[I][J]=false;
    while (!q.empty())
    {
        ll u=q.top().se.fi;
        ll v=q.top().se.se;
        q.pop();
        for (ll k=0;k<4;k++)
        {
            ll i=u+dx[k],j=v+dy[k];
            if (i>=1 && i<=n && j>=1 && j<=m && visit[i][j]==true)
            {
                visit[i][j]=false;
                f[i][j]=f[u][v]+abs(a[i][j]-a[u][v])*2+1;
                q.push({f[i][j],{i,j}});
            }
        }
    }
}

void solve()
{
    memset(f,0,sizeof(f));
    bfs(Begin.fi,Begin.se);
    cout<<f[End.fi][End.se];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
