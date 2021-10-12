/* Author: Phan Quy Thinh - CVA High School for the Gifted, Binh Dinh */
// 05102021
// https://oj.vnoi.info/problem/cvabdi_ant
#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 50009
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

struct tmp
{
    ll w,pos,d;
};
tmp a[maxn],T[maxn];
vector<ll> To0,ToL,AntPos;

ll n,L,Sum=0,flag=0;

void init()
{
    cin>>n>>L;
    ll x,y,z;
    for (ll i=1;i<=n;i++)
    {
        cin>>x>>y>>z;
        a[i]={x,y,z};
        Sum+=x;
        AntPos.pb(y);
    }
    sort(a+1,a+n+1,[](tmp x1,tmp x2){return x1.pos<x2.pos;});
}

void prepare()
{
    for (ll i=1;i<=n;i++)
    {
        T[i]=a[i];
        T[i].pos=(a[i].d==1) ? L-a[i].pos : a[i].pos;
        (a[i].d==1) ? ToL.pb(a[i].pos) : To0.pb(a[i].pos);
    }
}

ll GetWeight(ll t,ll &l,ll &r)
{
    return (t==1) ? a[r--].w : a[l++].w;
}

ll GetPos(ll l,ll r,ll Pos,ll AddTime)
{
    ll mid,cur=n;
    while (l<=r)
    {
        if (a[(mid=(l+r)/2)].pos<Pos+2*AddTime) l=mid+1;
        else
        {
            cur=mid;
            r=mid-1;
        }
    }
    return cur;
}

int GetFlag()
{
    sort(a+1,a+n+1,[](tmp x1,tmp x2){return ((x1.d>x2.d) || (x1.d==x2.d && x1.pos<x2.pos));});
    for (int i=1;i<=n;i++)
        if (a[i].d==-1) return i;
}

void solve()
{
    ll Time=0,l=1,r=n,SumWeight=0,ans=0,meet=0;
    prepare();
    sort(T+1,T+n+1,[](tmp x1,tmp x2){return x1.pos<x2.pos;});
    for (ll i=1;i<=n;i++)
    if (a[i].pos!=a[i+1].pos)
    {
        ans+=(T[i].d==1) ? GetToL(a[i].pos+Time,T[i].pos-Time,Time) : GetTo0(a[i].pos-Time,T[i].pos-Time,Time);
        Time=T[i].pos;
        SumWeight+=GetWeight(T[i].d,l,r);
        if (SumWeight*2>=Sum) break;
    }
    ll flag=GetFlag();
    for (ll i=1;i<flag;i++)
        meet+=GetPos(flag,n,a[i].pos,Time)-GetPos(flag,n,a[i].pos,0)+1;
    cout<<meet;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
