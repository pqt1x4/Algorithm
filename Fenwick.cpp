/* Author: Phan Quy Thinh - CVA High School for the Gifted, Binh Dinh */
// 29092021
// https://oj.vnoi.info/problem/cvabdi_cumdancu
#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 1000009
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
ll n,K,BIT[maxn],ans[maxn*4],f[maxn];
ii val[maxn];
struct tmp
{
    ll l,r,k,vt;
};
tmp a[maxn*4];

void init()
{
    cin>>n;
    ll x;
    f[0]=0;
    for (ll i=1;i<=n;i++)
    {
        cin>>x;
        f[i]=f[i-1]+x;
    }
    cin>>K;
}

void prepare()
{
    for(ll i=1;i<=n;i++)
        val[i]={f[i]-K*i,i};
    for(ll i=1;i<=n;i++)
        a[i]={i,n,f[i-1]-K*i+K,i};
    sort(val+1,val+n+1,greater<ii>());
    sort(a+1,a+n+1,[](tmp x1,tmp x2){return x1.k>x2.k;});
}

void update(ll pos)
{
    for(ll i=pos;i<=n;i+=i&-i)
        BIT[i]++;
}

ll GetAns(ll pos)
{
    ll ans=0;
    for(ll i=pos;i>=1;i-=i&-i)
        ans+=BIT[i];
    return ans;
}

void solve()
{
    prepare();
    ll pos=1;
    for(ll i=1;i<=n;i++)
    {
        while(val[pos].fi>=a[i].k && pos<=n)
        {
            update(val[pos].se);
            pos++;
        }
        ans[a[i].vt]=GetAns(a[i].r)-GetAns(a[i].l-1);
    }
    ll result=0;
    for(ll i=1;i<=n;i++)
       result+=ans[i];
    cout<<result;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
