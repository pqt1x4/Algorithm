/* Author: Phan Quy Thinh - HSGS CVA.BDi */
// https://oj.vnoi.info/problem/cvabdi_tcts
// 22082022
#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 1000009
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
vector<ii> p;
ll n,m;
vector<ll> prime;

void init()
{
    cin>>n>>m;
}

void IsPrime()
{
    bool dd[maxn/2+109];
    for (ll i=2;i<=sqrt(maxn)/2;i++)
        if (dd[i]==0)
        for (ll j=i+i;j<=maxn/2;j+=i)
            dd[j]=1;
    for (ll i=2;i<=maxn/2;i++)
        if (dd[i]==0)
            prime.pb(i);
}

vector<ii> prepare(ll k)
{
    vector<ii> ans;
    for (ll i=2;k!=1;i++)
        if (k%i==0)
        {
            ll tmp=0;
            while (k%i==0)
            {
                k/=i;
                tmp++;
            }
            ans.pb({i,tmp});
        }
    return ans;
}

ll findmaxn(ll n,ll p)
{
    ll r=p,res=0;
    while (r-n<=0)
    {
        res+=(n/r);
        r*=p;
    }
    return res;
}

ll Get(ll n,ll k)
{
    ll ans=INT_MAX;
    vector<ii> tmp;
    tmp=prepare(k);
    for (auto i:tmp)
        ans=min(ans,findmaxn(n,i.fi)/i.se);
    return ans;
}

void solve()
{
    IsPrime();
    p=prepare(m);
    ll ans=INT_MAX;
    for (ii x:p)
    {
        ll k=Get(n,x.fi);
        k/=x.se;
        ans=min(ans,k);
    }
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
