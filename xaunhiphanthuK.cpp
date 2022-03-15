/* Author: Phan Quy Thinh - HSGS BDi.CVA */
// 15032022
// https://oj.vnoi.info/problem/cvabdi_bdd
#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 9999999
#define ll long long
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
ifstream fi(task"inp");
ofstream fo(task"out");
#define cin fi
#define cout fo
#endif // ONLINE_JUDGE

ll n,m=0,f[maxn],sum=0;

void init()
{
    cin>>n;
}

void prepare()
{
    f[0]=1;
    ll i=0;
    while (sum<=n)
    {
        i++;
        ll x=f[i-1];
        f[i]=x*2*1LL;
        sum+=f[i];
    }
    m=i;
}

void solve()
{
    prepare();
    n-=(sum-f[m]);
    string s="";
    for (ll i=0;i<m;i++) s+="1";
    //cout<<s;
    for (ll i=1;i<=m;i++)
        if (n-f[m-i]>0)
        {
            s[i-1]='2';
            n-=f[m-i];
        }
    cout<<s;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
