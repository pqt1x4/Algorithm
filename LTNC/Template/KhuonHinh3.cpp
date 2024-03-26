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

struct PS
{
    int x,y;
};

istream& operator >> (istream& is,PS& X)
{
    is>>X.x>>X.y;
    return is;
}

ostream& operator << (ostream& os,PS X)
{
    os<<X.x<<"/"<<X.y;
    return os;
}

bool operator < (PS A,PS B)
{
    return (A.x*B.y<A.y*B.x);
}

template<class T>
void change(vector<T>& X)
{
    sort(X.begin(),X.end(),[](T x1,T x2){return x1<x2;});
}

template<class T>
void calc(vector<T> x)
{
    change(x);
    if (x.empty())
        cout<<"khong co"<<endl;
    else cout<<x[0]<<endl;
}

vector<int> A;
vector<double> B;
vector<PS> C;

template<class T>
void prepare(char x)
{
    if (x=='a')
    {
        int y;
        cin>>y;
        A.pb(y);
    }
    else 
    if (x=='b')
    {
        double y;
        cin>>y;
        B.pb(y);
    }
    else
    {
        PS y;
        cin>>y;
        C.pb(y);
    }
}

void init()
{
    char x;
    while (cin>>x)
    if (x=='a') prepare<int>(x);
    else if (x=='b') prepare<double>(x);
    else prepare<PS>(x);
    change<int>(A);
    change<double>(B);
    change<PS>(C);
}

void solve()
{
    calc(A);
    calc(B);
    calc(C);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
