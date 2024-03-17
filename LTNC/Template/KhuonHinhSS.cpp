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

template<class T>
void ss()
{
    T a,b;
    if (x=='c')
    {
        ps tmp;
        double A,B;
        cin>>tmp.x>>tmp.y;
        A=(double)(tmp.x)/(tmp.y);
        cin>>tmp.x>>tmp.y;
        B=(double)(tmp.x)/(tmp.y);
        a=A;
        b=B;
    }
    else cin>>a>>b;
    if (a==b)
        cout<<"true";
    else cout<<"false";
}

int main()
{
    cin>>x;
    if (x=='a') ss<int>();
    else if (x=='b' || x=='c') ss<double>();
}

/*
void solve()
{
      
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
*/
