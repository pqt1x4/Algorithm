#include <bits/stdc++.h>
using namespace std;
long long n,a[10001],b[10001],dp[9999][9999],dem=0,d=0;
map<long long,long long> dd;
int nhap()
{
    //freopen("task.inp","r",stdin);
    cin >> n;
    for (long long i=1;i<=n;i++)
    {
        cin >> b[i];
        if (b[i]==0) d++;
        dem++;
        a[dem]=b[i];
    }
    n=0;
    memset(b,0,sizeof(b));
    for (int i=1;i<=dem;i++)
    {
        if (dd[a[i]]==0) b[++n]=a[i];
        dd[a[i]]=1;
    }
    sort(b+1,b+1+n);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    nhap();
    dp[1][1]=abs(a[1]-b[1]);
    for (long long j=2;j<=n;j++) dp[1][j]=min(abs(a[1]-b[j]),dp[1][j-1]);
    for (long long i=2;i<=dem;i++) dp[i][1]=abs(a[i]-b[1])+dp[i-1][1];
    for (long long i=2;i<=dem;i++)
        for (long long j=2;j<=n;j++)
            dp[i][j]=min(dp[i][j-1],dp[i-1][j]+abs(a[i]-b[j]));


    cout << dp[dem][n];
}
