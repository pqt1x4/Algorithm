#include<bits/stdc++.h>
#define task "task."
using namespace std;

#define maxn 109
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

stack<char> a;
string s;

void init()
{
    cin>>s;
}

bool check(char x,char y)
{
    if (x=='(' && y==')')
        return true;
    if (x=='[' && y==']')
        return true;
    if (x=='{' && y=='}')
        return true;
    return false;
}

void solve()
{
    for (int i=0;i<s.length();i++)
        if (s[i]=='(' || s[i]=='[' || s[i]=='{')
            a.push(s[i]);
        else
        {
            if (a.empty()==true)
            {
                cout<<"no";
                return;
            }
            if (check(a.top(),s[i])==false)
            {
                cout<<"no";
                return;
            }
            else a.pop();
        }
    if (a.empty()==true)
        cout<<"yes";
    else cout<<"no";
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    init();
    solve();
}
