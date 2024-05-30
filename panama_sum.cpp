/*

https://kilonova.ro/problems/304

*/

#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,q,v[100005];

struct form{
    int bestsum, pref, suf, sum;
}aint1[4*100000 +5], aint2[4*100005 +5];

form join(form a, form b)
{
    form c;
    c={max({a.bestsum,b.bestsum, a.suf + b.pref}), max(a.pref, a.sum + b.pref), max(b.suf, b.sum + a.suf), a.sum+b.sum};
    return c;
}

void update1(int nod, int st, int dr, int poz, int val)
{
    if(st==dr)
    {
        if(val>0)
            aint1[nod]={val,val,val,val};
        else
            aint1[nod]={0,val,val,val};
    }
    else
    {
        int mij=(st+dr)/2;
        if(poz<=mij)
            update1(2*nod,st,mij,poz,val);
        else
            update1(2*nod+1,mij+1,dr,poz,val);
        aint1[nod]=join(aint1[2*nod],aint1[2*nod+1]);
    }
}

void update2(int nod, int st, int dr, int poz, int val)
{
    if(st==dr)
    {
        if(val>0)
            aint2[nod]={val,val,val,val};
        else
            aint2[nod]={0,val,val,val};
    }
    else
    {
        int mij=(st+dr)/2;
        if(poz<=mij)
            update2(2*nod,st,mij,poz,val);
        else
            update2(2*nod+1,mij+1,dr,poz,val);
        aint2[nod]=join(aint2[2*nod],aint2[2*nod+1]);
    }
}

form query1(int nod, int st, int dr, int l, int r)
{
    if(st==l && dr==r)
        return aint1[nod];
    int mij=(st+dr)/2;
    if(r<=mij)
        return query1(2*nod,st,mij,l,r);
    else
        if(l>=mij+1)
            return query1(2*nod+1,mij+1,dr,l,r);
    else
    {
        return join(query1(2*nod,st,mij,l,mij), query1(2*nod+1,mij+1,dr,mij+1,r));
    }
}

form query2(int nod, int st, int dr, int l, int r)
{
    if(st==l && dr==r)
        return aint2[nod];
    int mij=(st+dr)/2;
    if(r<=mij)
        return query2(2*nod,st,mij,l,r);
    else
    if(l>=mij+1)
        return query2(2*nod+1,mij+1,dr,l,r);
    else
    {
        return join(query2(2*nod,st,mij,l,mij), query2(2*nod+1,mij+1,dr,mij+1,r));
    }
}

signed main()
{
    int i,t,x,y;
    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        if(i%2==0)
        {
            update1(1,1,n,i,v[i]);
            update2(1,1,n,i,-v[i]);
        }
        else
        {
            update1(1, 1, n, i, -v[i]);
            update2(1, 1, n, i, v[i]);
        }
    }
    for(i=1;i<=q;i++)
    {
        cin>>t>>x>>y;
        if(t==1)
        {
            if(x%2==0)
            {
                update1(1,1,n,x,y);
                update2(1,1,n,x,-y);
            }
            else
            {
                update1(1, 1, n, x, -y);
                update2(1, 1, n, x, y);
            }
        }
        else
        {
            cout<<max(query1(1,1,n,x,y).bestsum, query2(1,1,n,x,y).bestsum)<<'\n';
        }
    }
    return 0;
}
