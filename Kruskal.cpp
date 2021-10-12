#include<bits/stdc++.h>
using namespace std;
#define maxn 1000009
#define pb push_back
#define end "\n"
struct tmp
{
    int u,v,w;
};
tmp a[maxn];
typedef pair<int,int> ii;
vector<ii> res;
int n,m,par[maxn],r[maxn];
void init()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>a[i].u>>a[i].v>>a[i].w;
    for (int i=1;i<=n;i++) par[i]=i;
}
int FIND(int x)
{
    return (x!=par[x])?(par[x]=FIND(par[x])):(x);
}
int UNION(int x,int y)
{
    x=FIND(x);
    y=FIND(y);
    if (x==y) return 0;
    (r[x]<r[y])?(par[y]=x):(par[x]=y);
    /*
    r[x]+=(r[x]<=r[y]) ? 1:0;
    r[y]+=(r[x]>r[y]) ? s[x]:0;
    */
    r[x]+=(r[x]==r[y])? 1:0;
    return 1;
}
void solve()
{
    sort(a+1,a+m+1,[](tmp x1,tmp x2){return x1.w<x2.w;});
    memset(r,0,sizeof(r));
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int cur=UNION(a[i].u,a[i].v);
        ans+=(cur!=0)?(a[i].w):(0);
        if (cur!=0) res.pb({a[i].u,a[i].v});
    }
    cout<<ans<<endl;
    //for (auto i:res) cout<<i.first<<" "<<i.second<<endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
