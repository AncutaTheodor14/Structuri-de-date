/*

https://www.infoarena.ro/problema/bleach

*/
#include<bits/stdc++.h>
using namespace std;

ifstream f("bleach.in");
ofstream g("bleach.out");

long long n,k,heap[1003],n_heap=0,x;

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
    long long i,s,p;
    f>>n>>k;
    for(i=1;i<=k+1;i++)
    {
        f>>x;
        insertt(x);
    }
    s=heap[1];
    p=heap[1];
    for(i=k+2;i<=n;i++)
    {
        if(s>=heap[1])
            s+=heap[1];
        else
        {
            p=p+heap[1]-s;
            s=2*heap[1];
        }
        removee();
        f>>x;
        insertt(x);
    }
    while(n_heap>0)
    {
        if(s>=heap[1])
            s+=heap[1];
        else
        {
             p=p+heap[1]-s;
             s=heap[1]*2;
        }
        removee();
    }
    g<<p;
    return 0;
}
