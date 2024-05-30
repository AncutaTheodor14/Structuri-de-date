/*

https://www.infoarena.ro/problema/stramosi

*/

#include<bits/stdc++.h>
using namespace std;

ifstream f("stramosi.in");
ofstream g("stramosi.out");

int n,m,v[23][250005];

int main()
{
    int i,x,y,j,p,q,bit;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>v[0][i];
    }
    for(i=1;i<=20;i++)
    {
        for(j=1;j<=n;j++)
        {
            v[i][j]=v[i-1][v[i-1][j]];
        }
    }
    for(i=1;i<=m;i++)
    {
        f>>q>>p;
        for(bit=19;bit>=0;bit--)
        {
            if(p>=(1<<bit))
            {
                p-=(1<<bit);
                q=v[bit][q];
            }
        }
        g<<q<<'\n';
    }
    return 0;
}

//v[i][j]=al 2 la puterea i tata al lui j
//v[5][j]=al 2 la puterea 5 tata al lui j
