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
char x;
istream& operator >> (istream& is,ps& A)
{
    is>>A.x>>A.y;
    return is;
}

ostream& operator << (ostream& os,ps A)
{
    os<<A.x<<"/"<<A.y<<endl;
    return os;
}

int ucln(ps A)
{
    while (A.y!=0)
    {
        A.x%=A.y;
        swap(A.x,A.y);
    }
    return A.x;
}

ps rutgon(ps A)
{
    int base=(A.x/abs(A.x))*(A.y/abs(A.y));
    A={abs(A.x),abs(A.y)};
    int cur=ucln(A);
    if (base!=1)
        return {-A.x/cur,A.y/cur};
    return {A.x/cur,A.y/cur};
}

ps operator + (ps A,ps B)
{
    int curF=A.x*B.y+A.y*B.x;
    int curS=A.y*B.y;
    return rutgon({curF,curS});
}

void init()
{
    cin>>x;
}

template<class T>
void calc()
{
    T x;
    vector<T> a;
    while (cin>>x)
        a.pb(x);
    for (int i=1;i<a.size();i++)
        a[0]=a[0]+a[i];
    cout<<a[0];
}

void solve()
{
      if (x=='a')
          calc<int>();
      else calc<ps>();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
