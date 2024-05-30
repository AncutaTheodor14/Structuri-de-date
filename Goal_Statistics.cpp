/*

https://kilonova.ro/problems/960

*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int v[1000005],aib_sum[1000005],aib_count[1000005],n=1e6,put,fv[1000005];

void update(int poz, int nr, int val)
{
    int i;
    for(i=poz;i<=n;i+=i&-i)
    {
        aib_sum[i]+=val;
        aib_count[i]+=nr;
    }
}

int caut_binar(int poz)
{
    int p=put;
    int i=0;
    while(p>0)
    {
        if(aib_count[i+p]<poz)
        {
            poz-=aib_count[i+p];
            i+=p;
        }
        p/=2;
        while(i+p>n && p>0)
            p/=2;
    }
    return i+1;
}

int query(int poz)
{
    int i,sum=0;
    for(i=poz;i>=1;i-=i&-i)
        sum+=aib_sum[i];
    return sum;
}

int query1(int poz)
{
    int i,sum=0;
    for(i=poz;i>=1;i-=i&-i)
        sum+=aib_count[i];
    return sum;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    put=1;
    while(put<=n)
        put*=2;
    put/=2;
    int i,q,x,y;
    cin>>q;
    for(i=1;i<=q;i++)
    {
        cin>>x>>y;
        if(x==1)
            fv[y]++,update(y,1,y);
        else
        {
            int ans= caut_binar(y-1);
            int ans1= caut_binar(y);
            int val= query1(ans);
            int ras= y-val;
            cout<<query(ans)+ras*ans1<<'\n';
        }
    }
    return 0;
}
