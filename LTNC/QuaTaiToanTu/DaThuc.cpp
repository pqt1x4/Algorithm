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

struct BacNhat
{
    int x,y;
};
BacNhat A,B;
int n;

istream& operator >> (istream& is,BacNhat& A)
{
    is>>A.x>>A.y;
    return is;
}

ostream& operator << (ostream& os,BacNhat A)
{
    os<<A.x<<"x+"<<A.y;
    return os;
}

BacNhat operator + (BacNhat A,BacNhat B)
{
    return {A.x+B.x,A.y+B.y};
}

bool operator == (BacNhat A,BacNhat B)
{
    return (A.x+A.y==B.x+B.y);
}

int calc(BacNhat A,int temp)
{
    return A.x*temp+A.y;
}

void init()
{
    cin>>A>>B>>n;
}

void solve()
{
    cout<<A<<endl;
    cout<<B<<endl;
    cout<<A<<"+"<<B<<"="<<A+B<<endl;
    cout<<calc(A,n)<<endl;
    cout<<calc(B,n)<<endl;
    if (A==B)
        cout<<"TRUE";
    else cout<<"FALSE";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
