/*

https://www.infoarena.ro/problema/timbre

*/

#include<bits/stdc++.h>
using namespace std;

ifstream f("timbre.in");
ofstream g("timbre.out");

int n,m,k,heap[10003],n_heap;

struct structura
{
    int sup,cost;
} v[10003];

int cmp(const structura &a, const structura &b)
{
    return a.sup<b.sup;
}

void insertt(int x)
{
    n_heap++;
    heap[n_heap]=x;
    int current=n_heap;
    while(current>1 && heap[current]<heap[current/2])
    {
        swap(heap[current],heap[current/2]);
        current/=2;
    }
}

void removee()
{
    heap[1]=heap[n_heap];
    heap[n_heap]=0;
    n_heap--;
    int current=2,p=1;
    while(current<=n_heap)
    {
        if(current+1<=n_heap && heap[current+1]<heap[current])
            current++;
        if(heap[current]<heap[p])
            swap(heap[current],heap[p]);
        p=current;
        current=p*2;
    }
}

int main()
{
    int i,sum=0;
    f>>n>>m>>k;
    for(i=1; i<=m; i++)
    {
        f>>v[i].sup>>v[i].cost;
    }
    sort(v+1,v+m+1,cmp);
    for(i=m;i>=1;i--)
    {
        if(v[i].sup>=n)
            insertt(v[i].cost);
        else
        {
            sum+=heap[1];
            removee();
            i++;
            n-=k;
        }
    }
    while(n_heap!=0&&n>0)
    {
        sum+=heap[1];
        removee();
        n-=k;
    }
    g<<sum;
    return 0;
}
