#include<bits/stdc++.h>
#define task "task."
using namespace std;

#define maxn 1009
#define ll long long 
#define pb push_back
#define fi first
#define se second
///*
#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif
//*/

typedef pair<int,int> ii;

struct st
{
    int x,y;
};
st a[maxn];
int n;

istream& operator >> (istream& is,st &X)
{
    is>>X.x>>X.y;
    return is;
}

ostream& operator << (ostream& os,st X)
{
    os<<X.x;
    if (X.y<0) 
        os<<"-";
    else os<<"+";
    os<<abs(X.y)<<"*i"<<endl;
    return os;
}

st operator + (st a,st b)
{
    return {a.x+b.x,a.y+b.y};
}

st operator - (st a,st b)
{
    return {a.x-b.x,a.y-b.y};
}

st operator * (st a,st b)
{
    return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}

bool operator < (st a,st b)
{
    ii x={a.x,a.y};
    ii y={b.x,b.y};
    return (x<y);
}

void init()
{
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
}

void solve()
{
    st maxx={0,0},sum={0,0},mul=a[1],minn=a[1];
    for (int i=1;i<=n;i++)
    {
        if (maxx<a[i]) 
            maxx=a[i];
        if (a[i]<minn) 
            minn=a[i];
        sum=sum+a[i];
        if (i!=1) 
            mul=mul*a[i];
    }
    cout<<maxx<<sum<<mul<<maxx-minn;    
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}

