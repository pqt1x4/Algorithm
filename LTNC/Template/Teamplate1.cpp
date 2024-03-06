#include<bits/stdc++.h>
#define task "task."
using namespace std;

#define maxn 1009
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

struct ps
{
    int x,y;
};

template <class T> T max(T a,T b,T c)
{
    vector<T> temp;
    temp.pb(a);
    temp.pb(b);
    temp.pb(c);
    sort(temp.begin(),temp.end());
    return temp[2];
}

char n;

void init()
{
    cin>>n;
}

void TypeA()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<max<int>(a,b,c);

}

void TypeB()
{
    float a,b,c;
    cin>>a>>b>>c;
    cout<<max<float>(a,b,c);
}

void TypeC()
{
    ps a,b,c;
    cin>>a.x>>a.y;
    cin>>b.x>>b.y;
    cin>>c.x>>c.y;
    float x,y,z;
    x=(float)(a.x)/(a.y);
    y=(float)(b.x)/(b.y);
    z=(float)(c.x)/(c.y);
    float temp=max<float>(x,y,z);
    if (temp==x) 
        cout<<a.x<<"/"<<a.y;
    else if (temp==y)
        cout<<b.x<<"/"<<b.y;
    else cout<<c.x<<"/"<<c.y;
}

void solve()
{
    if (n=='a')
        TypeA();
    else if (n=='b')
        TypeB();
    else TypeC();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
