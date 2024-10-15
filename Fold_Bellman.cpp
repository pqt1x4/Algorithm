#include<bits/stdc++.h>
#define task "task."
using namespace std;

#define maxn 109
#define ll long long 
#define pb push_back
#define fi first
#define se second
#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif

typedef pair<int,int> ii;
struct graph
{
	int n;
	vector<ii> a[maxn];
	ii f[maxn][maxn];
	int pre[maxn];
};
graph g;
int n,m,S;

void init(graph &g)
{
	cin>>n>>S;
	int x,y,z;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			cin>>z;
			x=i;
			y=j;
			if (z==0)
				continue;
			g.a[y].pb({x,z});
		}
}

void prepare(graph &g)
{
	memset(g.f,(0,0),sizeof(g.f));
	for (int i=1;i<=n;i++)
		g.f[0][i]={-1,-1};
	g.f[0][S]={0,0};
	g.pre[S]=-1;
}

void Bellman_Fold(graph &g)
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (j==1)
			{
				g.f[i][j]={0,0};
				continue;
			}
			g.f[i][j]=g.f[i-1][j];
			ii res={INT_MAX,0};
			for (ii x:g.a[j])
				if ((res.fi>(g.f[i-1][x.fi]).fi + x.se) && (g.f[i-1][x.fi].fi!=-1))
					res={g.f[i-1][x.fi].fi + x.se,x.fi};
			if (res.fi==INT_MAX)
				continue;
			g.f[i][j]=res;
			g.pre[j]=res.se;
		}
}

void Print_Bellman_Fold_toV(graph g,int x)
{
	vector<int> ans;
	while (x!=-1)
	{
		ans.pb(x);
		x=g.pre[x];
	}
	reverse(ans.begin(),ans.end());
	for (int i:ans)
		cout<<i<<" ";
}

void Print_Bellman_Fold(graph g)
{
	for (int i=1;i<=n;i++)
	{
		if (i==S)
			continue;
		cout<<g.f[n][i].fi<<":";
		Print_Bellman_Fold_toV(g,i);
		cout<<endl;
	}		
}

void solve(graph g)
{
	prepare(g);
	Bellman_Fold(g);
	Print_Bellman_Fold(g);
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	init(g);
	solve(g);
}
/*
INPUT:
15 28 1
1 2 5
1 5 2
1 8 3
1 12 7
2 5 2
5 8 4
8 12 3
2 3 6
5 6 6
8 9 7
12 13 5
12 3 3
3 6 4
6 9 1
9 13 2
3 4 2
6 10 3
9 10 1
13 10 4
13 14 4
4 10 4
10 14 3
4 7 3
10 15 8
14 15 3
7 15 2
7 11 1
15 11 3

-------
OUTPUT:


*/
