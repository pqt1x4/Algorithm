// Author: Phan Quy Thinh - HCMC University of Education
// 20072023

#include<bits/stdc++.h>
#define task "task."

using namespace std;

#define maxn 10009
#define ll long long
#define pb push_back
#define endl "\n"
#define fi first
#define se second
#ifndef ONLINE_JUDGE
ifstream f1(task"inp");
ofstream f2(task"out");
#define cin f1
#define cout f2
#endif

class SoPhuc
{
	public:
		float re,im; // re - thực, im - ảo
	public:
		void SetSoPhuc(float _re,float _im)
		{
			re=_re;
			im=_im;
		}

		friend SoPhuc operator + (SoPhuc a,SoPhuc b)
		{
			SoPhuc ANS;
			ANS.SetSoPhuc(a.re+b.re,a.im+b.im);
			return ANS;
		}

		friend SoPhuc operator - (SoPhuc a,SoPhuc b)
		{
			SoPhuc ANS;
			ANS.SetSoPhuc(a.re-b.re,a.im-b.im);
			return ANS;
		}

		friend SoPhuc operator * (SoPhuc a,SoPhuc b)
		{
			SoPhuc ANS;
			ANS.SetSoPhuc(a.re*b.re - a.im*b.im,a.re*b.im + b.re*a.im);
			return ANS;
		}

		friend istream& operator >> (istream& in,SoPhuc& A)
		{
			in>>A.re>>A.im;
			return in;
		}

		friend ostream& operator << (ostream& out,SoPhuc A)
		{
			if (A.re==0 && A.im==0)
			{
				out<<0;
				return out;
			}
			if (A.re!=0) out<<A.re<<" ";
			if (A.im==1) cout<<"i";
				else if (A.im==-1) cout<<"-i";
					else if (A.im!=0) out<<A.im<<"i";
			return out;
		}
};
SoPhuc a,b;

void init()
{
	cin>>a;
	cin>>b;
}

void solve()
{
	cout<<setprecision(2);
	SoPhuc c;
	c=a+b;
	cout<<c;
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	init();
	solve();
}
