#include<bits/stdc++.h>
#define task "task."
using namespace std;

#define maxn 109
#define ll long long 
#define pb push_back
#define fi first
#define se second
/*
#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif
*/

int n,k,a[maxn];
vector<string> ans;

void init()
{
   cin>>k>>n;
}

void Try(int j)
{
    for (int i=1;i<=k;i++)
    {
        a[j]=i;
        if (j==n)
        {
            string tmp="";
            for (int i=1;i<=n;i++)
                tmp+=(char)(a[i]+48);
            ans.pb(tmp);
        }
        else Try(j+1);
    }
}

void solve()
{
   Try(1);
   cout<<ans.size()<<endl;
   for (string i:ans)
       cout<<i<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
