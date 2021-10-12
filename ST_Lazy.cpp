#include<bits/stdc++.h>
using namespace std;
#define maxn 50009
#define ll long long
struct Node
{
    ll lazy,val;
};
Node a[4*maxn];
ll n,m,value[maxn];
void down(ll root)
{
    ll temp=a[root].lazy;
    a[root*2].val+=temp;
    a[root*2].lazy+=temp;
    a[root*2+1].val+=temp;
    a[root*2+1].lazy+=temp;
    a[root].lazy=0;
}
void update(ll root,ll l,ll r,ll u,ll v,ll k)
{
    if (l>v || r<u) return;
    if (l>=u && r<=v)
    {
        a[root].lazy+=k;
        a[root].val+=k;
        return;
    }
    ll mid=(l+r)/2;
    down(root);
    update(root*2,l,mid,u,v,k);
    update(root*2+1,mid+1,r,u,v,k);
    a[root].val=max(a[root*2].val,a[root*2+1].val);
}
ll ans(ll root,ll l,ll r,ll u,ll v)
{
    if (l>v || r<u) return INT_MIN;
    if (l>=u && r<=v) return a[root].val;
    ll mid=(l+r)/2;
    down(root);
    return max(ans(root*2,l,mid,u,v),ans(root*2+1,mid+1,r,u,v));
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll x,u,v,k;
    for (ll i=1;i<=m;i++)
    {
        cin>>x>>u>>v;
        if (x==1) cout<<ans(1,1,n,u,v)<<endl;
        else
        {
            cin>>k;
            update(1,1,n,u,v,k);
        }
    }
}
