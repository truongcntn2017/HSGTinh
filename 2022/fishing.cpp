#include<bits/stdc++.h>
using namespace std;
int n,h;
int t[1111111],f[1111111],d[1111111];
int save[22][222222];

int fishing(int vt,int tg)
{
    int a=f[vt];
    int b=f[vt]-(tg-1)*d[vt];
    return (a+b)*tg/2;
}

int dp(int vt,int tg)
{
    if (tg==0) return 0;
    if (tg<0) return -1e9;
    if (vt>=n+1) return 0;
    if (save[vt][tg]) return save[vt][tg];
    int ret=0;
    for (int i=0;i<=tg;i++)
    {
        if (f[vt]-(i-1)*d[vt]>=0) 
        {
            ret=max(ret,dp(vt+1,tg-t[vt]-i)+fishing(vt,i));
        }
        else
        {
            break;
        }
    }
    return save[vt][tg]=ret;
}
int main()
{
    cin >> n >> h;
    h = h*12;
    for (int i=1;i<=n-1;i++) 
    {
        cin >> t[i];
        t[i]/=5;
    }
    for (int i=1;i<=n;i++) 
    {
        cin >> f[i];
    }
    for (int i=1;i<=n;i++) 
    {
        cin >> d[i];
    }
    cout << dp(1,h);

    return 0;
}