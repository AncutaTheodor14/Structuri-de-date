/*

https://infoarena.ro/problema/plantatie

*/

#include<bits/stdc++.h>
using namespace std;

ifstream f("plantatie.in");
ofstream g("plantatie.out");

int a[503][503],rmq[10][503][503],e[503],p[503],n,m;
///rmq 2D

void constructie()
{
    int x=2,k=1,i,j;
    while(x<=n)
    {
        for(i=1; i<=n-x+1; i++)
        {
            for(j=1; j<=n-x+1; j++)
            {
                rmq[k][i][j]=max({rmq[k-1][i][j],rmq[k-1][i+x/2][j],rmq[k-1][i][j+x/2],rmq[k-1][i+x/2][j+x/2]});
            }
        }
        x*=2;
        k++;
    }
}

int main()
{
    int i,j,i1,j1,nr,val,cv;
    f>>n>>m;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            f>>a[i][j];
            rmq[0][i][j]=a[i][j];
        }
    }
    int x=1,k=0;
    for(i=1; i<=n; i++)
    {
        if(2*x==i)
        {
            x*=2;
            k++;
        }
        e[i]=k;
        p[k]=x;
    }
    constructie();
    for(i=1;i<=m;i++)
    {
        f>>i1>>j1>>nr;
        val=e[nr];
        cv=p[val];
        g<<max({rmq[val][i1][j1],rmq[val][i1][j1+nr-1-cv+1],rmq[val][i1+nr-1-cv+1][j1],rmq[val][i1+nr-1-cv+1][j1+nr-1-cv+1]})<<'\n';
    }
    return 0;
}
