/*

https://kilonova.ro/contests/230/problems/2410

*/

#include<bits/stdc++.h>
#define int long long
#define INF 1000000000000000000
#define MOD 666013
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;

int q,v[10005],n;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,l,i,x,y,z,e,j,emax,maxi,m,p,op,lasta=-1,lastb=-1,sum=0;
    cin>>q;
    for(l=1; l<=q; l++)
    {
        cin>>op;
        if(op==1 || op==2)
        {
            cin>>p>>x;
            p++;
            n++;
            for(i=n; i>p; i--)
                v[i]=v[i-1];
            if(lasta>=p)
                lasta++;
            if(lastb>=p)
                lastb++;
            v[p]=x;
            if(op==1)
                lasta=p;
            else
            if(op==2)
                lastb=p;
        }
        else
        {
            for(i=min(lasta,lastb);i<=max(lasta,lastb);i++)
                sum=(sum+v[i])%MOD;
        }
    }
    cout<<sum%MOD;
    return 0;
}
