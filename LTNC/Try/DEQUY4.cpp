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

int n,m,Sum=0;

void init()
{
   cin>>n>>m;
}

int Try(int x)
{
    if (x==1)
    {
        Sum=1;
        return 1;
    }
    int tmp=Try(x-1)*m;
    Sum+=tmp;
    return tmp;
}

void solve()
{
    Try(n+1);
    cout<<Sum;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
