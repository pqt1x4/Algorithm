#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 10009
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

vector<ll> step,tour;
ll n,m,k,f[maxn][3];

void init()
{
    step.clear();
    tour.clear();
    cin>>n>>m>>k;
    for (ll i=1;i<=n;i++)
        cin>>f[i][0]>>f[i][1];
    char x;
    for (ll i=1;i<=m;i++)
    {
        cin>>x;
        step.pb((x=='L') ? 0 : 1);
    }
}

ll FIND(ll t,ll val)
{
    ll pos=1,cur=0;
    tour.pb(pos);
    while (cur<val)
    {
        cur++;
        for (ll i:step)
        {
            pos=f[pos][i];
            tour.pb(pos);
        }
        if (pos==1 && t==0)
            break;
    }
    if (t==1) cout<<pos;
    return cur;
}

void solve()
{
    k%=FIND(0,100101);
    //FIND(1,k);
    cout<<tour[k*m*1LL];
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
