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

struct Diem
{
    int x,y;
};

istream& operator >> (istream& is,Diem& A)
{
    is>>A.x>>A.y;
    return is;
}

ostream& operator << (ostream& os,Diem A)
{
    os<<"("<<A.x<<","<<A.y<<")";
    return os;
}

double dist(Diem A,Diem B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}

bool check(Diem A,Diem B)
{
    return (A.x==B.x && A.y==B.y);
}

struct Tamgiac
{
    Diem a,b,c; 
    //public:
    friend istream& operator >> (istream& is,Tamgiac& X);
    friend ostream& operator << (istream& os,Tamgiac X);
};
Tamgiac A,B;

istream& operator >> (istream& is,Tamgiac& X)
{
    is>>X.a>>X.b>>X.c;
    return is;
}

ostream& operator << (ostream& os,Tamgiac X)
{
    os<<X.a<<X.b<<X.c;
    return os;
}

double Chuvi(Tamgiac A)
{
    double x=dist(A.a,A.b);
    double y=dist(A.a,A.c);
    double z=dist(A.c,A.b);
    return (double)(x+y+z);
}

bool operator < (Tamgiac A,Tamgiac B)
{
    return (Chuvi(A)<Chuvi(B));
}

typedef pair<int,int> ii;

vector<ii> prepare(Tamgiac A)
{
    vector<ii> tmp;
    tmp.pb({A.a.x,A.a.y});
    tmp.pb({A.b.x,A.b.y});
    tmp.pb({A.c.x,A.c.y});
    sort(tmp.begin(),tmp.end());
    return tmp;
}

bool checkvt(ii x,ii y)
{
    return (x.fi==y.fi && x.se==y.se);
}

bool operator == (Tamgiac A,Tamgiac B)
{
    vector<ii> temp1,temp2;
    temp1=prepare(A);
    temp2=prepare(B);
    for (int i=0;i<3;i++)
        if (checkvt(temp1[i],temp2[i])==false)
            return false;
    return true;
}

void init()
{
    cin>>A>>B;
}

void solve()
{
    cout<<A<<endl;
    cout<<B<<endl;
    if (A<B)
        cout<<"TRUE";
    else cout<<"FALSE";
    cout<<endl;
    if(A==B)
        cout<<"TRUE";
    else cout<<"FALSE";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
