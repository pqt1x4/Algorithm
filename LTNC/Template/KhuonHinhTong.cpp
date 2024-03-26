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

struct ps
{
    int x,y;
};

istream& operator >> (istream& is,ps& A)
{
    is>>A.x>>A.y;
    return is;
}

ostream& operator << (ostream& os,ps A)
{
    os<<A.x<<"/"<<A.y;
    return os;
}

bool operator < (ps A,ps B)
{
    return (A.x*B.y<A.y*B.x);
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
    int temp=ucln(A);
    A.x/=temp;
    A.y/=temp;
    return A;
}

ps operator + (ps A,ps B)
{
    int tu=A.x*B.y+A.y*B.x;
    int mau=A.y*B.y;
    return rutgon({tu,mau});
}

vector<int> A;
vector<ps> B;

template<class T>
void prepare(char x)
{
    if (x=='a')
    {
        int tmp;
        cin>>tmp;
        A.pb(tmp);
    }
    else
    {
        ps tmp;
        cin>>tmp;
        B.pb(tmp);
    }
}

template<class T>
void calc(vector<T> a)
{
    if (a.empty())
    {
        cout<<"khong co"<<endl;
        return;
    }
    for (int i=1;i<a.size();i++)
        a[0]=a[0]+a[i];
    cout<<a[0]<<endl;
}

void init()
{
   char x;
   while (cin>>x)
   {
       if (x=='a') prepare<int>(x);
       else prepare<ps>(x);
   }
}

void solve()
{
    calc<int>(A);
    calc<ps>(B);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
