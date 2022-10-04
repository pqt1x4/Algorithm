/* Author: Phan Quy Thinh - HSGS BDi.ChuVanAn */
//05102022

#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 1009
#define ll long long
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif // ONLINE_JUDGE

typedef pair<string,string> ss;
double n;

void init()
{
    cin>>n;
}

string tos(int x)
{
    ostringstream k;
    k<<x;
    return k.str();
}

string DecToBina(int n)
{
    string ans="";
    for (int i=31;i>=0;i--)
    {
        int k=n>>i;
        if (k&1) ans+="1";
        else ans+="0";
    }
    while (ans[0]=='0') ans.erase(0,1);
    return ans;
}

string GetBitSign(double x)
{
    return (x<0) ? "1" : "0";
}

string GetBitExponent(int x)
{
    string ans=DecToBina(x+127);
    while (ans.size()<8)
        ans="0"+ans;
    return ans;
}

string GetBitMantissa(ss tmp)
{
    while (tmp.se.size()<23) tmp.se+="0";
    return tmp.se;
}

string ToBina(double n)
{
    if (n>=1 || n<=0) return "ERROR";
    string ans="";
    while (n>0)
    {
        if (ans.length()>=32) return "ERROR";
        double base=2*n;
        if (base>=1)
        {
            ans+="1";
            n=base-1;
        }
        else
        {
            ans+="0";
            n=base;
        }
    }
    return ans;
}

int GetT(ss &tmp)
{
    string x=tmp.fi,y=tmp.se;
    char s=x[0];
    x.erase(0,1);
    int num=x.size();
    y=x+y;
    x=s;
    tmp={x,y};
    return num;
}

void solve()
{
    string res=GetBitSign(n) + " ";
    n=abs(n);
    ss num={DecToBina(trunc(n)),ToBina((n-trunc(n)))};
    int temp=GetT(num);
    res+=GetBitExponent(temp) + " " + GetBitMantissa(num);
    cout<<res;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
