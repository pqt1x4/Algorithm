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

struct mang
{
    int n;
    int a[maxn];
    int& operator[](mang A)
    {
      return a[i];
    }
};
mang A,B;

istream& operator >> (istream& is,mang& A)
{
    is>>A.n;
    for (int i=1;i<=A.n;i++)
        is>>A.a[i];
    return is;
}

ostream& operator << (ostream& os,mang A)
{
    for (int i=1;i<=A.n;i++)
        cout<<A.a[i]<<" ";
    return os;
}

mang operator + (mang A,mang B)
{
    int endd=max(A.n,B.n);
    for (int i=1;i<=endd;i++)
        A.a[i]+=B.a[i];
    return A;
}

bool operator == (mang A,mang B)
{
    int endd=max(A.n,B.n);
    for (int i=1;i<=endd;i++)
        if (A.a[i]!=B.a[i])
            return false;
    return true;
}

bool operator != (mang A,mang B)
{
    int endd=max(A.n,B.n);
    for (int i=1;i<=endd;i++)
        if (A.a[i]==B.a[i])
            return false;
    return true;
}

void init()
{
   cin>>A>>B;
}

void solve()
{
      if (A==B)
          cout<<"yes";
      else cout<<"no";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
