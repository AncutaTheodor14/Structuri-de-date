/*

https://www.infoarena.ro/problema/kami

*/

#include<bits/stdc++.h>
#define int long long
#define INF 1000000000000000000
using namespace std;
ifstream f("kami.in");
ofstream g("kami.out");

int n,m,v[100005],r;
int bucket(int i)
{
    return (i-1)/r;
}
struct sum
{
    int s=0,mini=INF;
} w[330];

signed main()
{
    int i,x,j,s,st,dr,type,val,xx,retin,ok,ind;
    f>>n;
    for(i=1; i<=n; i++)
        f>>v[i];
    r=sqrtl(n);
    for(i=1; i<=n; i++)
    {
        x=bucket(i);
        w[x].s+=v[i];
        st=x*r+1;
        dr=x*r+r;
        s=0;
        w[x].mini=0;
        for(j=dr; j>=st; j--)
        {
            w[x].mini=max(w[x].mini,v[j]-s);
            s+=v[j];
        }
    }
    f>>m;
    for(i=1; i<=m; i++)
    {
        f>>type;
        if(type==0)
        {
            f>>x>>val;
            xx=bucket(x);
            w[xx].s-=v[x];
            v[x]=val;
            w[xx].s+=v[x];
            st=xx*r+1;
            dr=xx*r+r;
            s=0;
            w[xx].mini=0;
            for(j=dr; j>=st; j--)
            {
                w[xx].mini=max(w[xx].mini,v[j]-s);
                s+=v[j];
            }
        }
        else
        {
            f>>x;
            xx=bucket(x);
            s=0;
            retin=-1;
            s+=v[x];
            for(j=x-1; j>=1 && bucket(j)==xx; j--)
            {
                if(v[j]>=s)
                {
                    retin=j;
                    break;
                }
                s+=v[j];
            }
            if(retin!=-1)
                g<<j;
            else
            {
                ok=-1;
                for(j=xx-1; j>=0; j--)
                {
                    if(w[j].mini>=s)
                    {
                        ok=j;
                        break;
                    }
                    s+=w[j].s;
                }
                if(ok!=-1)
                {
                    st=ok*r+1;
                    dr=ok*r+r;
                    for(j=dr;j>=st;j--)
                    {
                        if(v[j]>=s)
                        {
                            ind=j;
                            break;
                        }
                        s+=v[j];
                    }
                    g<<ind;
                }
                else

                    g<<0;
            }
            g<<'\n';
        }
    }
    return 0;
}
