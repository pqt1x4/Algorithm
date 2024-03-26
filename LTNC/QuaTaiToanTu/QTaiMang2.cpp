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

struct Array
{
    int n;
    int a[maxn];
};
Array A,B;

istream& operator >> (istream& is,Array& A)
{
    is>>A.n;
    for (int i=1;i<=A.n;i++)
        is>>A.a[i];
    return is;
}

ostream& operator << (ostream& os,Array A)
{
    for (int i=1;i<=A.n;i++)
        os<<A.a[i]<<" ";
    return os;
}

Array operator + (Array A,Array B)
{
    Array C;
    for (int i=1;i<=max(A.n,B.n);i++)
        C.a[i]=A.a[i]+B.a[i];
    C.n=max(A.n,B.n);
    return C;
}

void init()
{
    cin>>A>>B;
}

void solve()
{
    cout<<A+B;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
