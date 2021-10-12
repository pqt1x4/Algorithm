#include<bits/stdc++.h>
using namespace std;
const int mmax = 1e9;
vector<int> a[100005];
queue<int> q;
int n,m, stackkt, ans,cnt=0;
stack <int> st;
int low[100005], num[100005],dd[100005],temp=0;
void nhap()
{
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
    }
}
void visit(int u)
{
    low[u]=num[u]=++cnt;
    st.push(u);
    for (int v:a[u])
        if (num[v])
            low[u] = min(low[u],num[v]);
        else
        {
            visit(v);
            low[u] = min(low[u],low[v]);
        }

    if (num[u]==low[u])
    {
        ans++;
        int v;
        do
        {
            v=st.top();
            st.pop();
            num[v]=low[v]=INT_MAX;
        }
        while (v!=u);
    }
}
void xuat()
{
    for (int i=1;i<=n;i++)
        if (!num[i]) visit(i);
    cout<<ans;
}
int main()
{
    nhap();
    xuat();
    return 0;
}
