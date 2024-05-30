/*

https://www.pbinfo.ro/probleme/3860/consecutive1

*/

#include<bits/stdc++.h>
#define INF 100000000000
using namespace std;

long long n,v[100002],t,x,y,maxi[350],mini[350],sum[350],r;
vector<int>a;

int bucket(int i)
{
    return (i-1)/r;
}

int main()
{
    long long i,ba,bb,j;
    long long suma;
    cin>>n;
    r=sqrt(n);
    for(i=1;i<=350;i++)
        mini[i]=INF;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
        maxi[bucket(i)]=max(maxi[bucket(i)],v[i]);
        mini[bucket(i)]=min(mini[bucket(i)],v[i]);
        sum[bucket(i)]+=v[i];
    }
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>x>>y;
        suma=0;
        long long maxim=INT_MIN,minim=INT_MAX;
        ba=bucket(x);
        bb=bucket(y);
        if(bb-ba<=1)
        {
            for(j=x;j<=y;j++)
            {
                if(v[j]>maxim)
                    maxim=v[j];
                if(v[j]<minim)
                    minim=v[j];
                suma+=v[j];
            }
        }
        else
        {
            for(j=ba+1;j<bb;j++)
            {
                maxim=max(maxim,maxi[j]);
                minim=min(minim,mini[j]);
                suma+=sum[j];
            }
            for(j=x; bucket(j)==ba; j++)
            {
                if(v[j]>maxim)
                    maxim=v[j];
                if(v[j]<minim)
                    minim=v[j];
                suma+=v[j];
            }
            for(j=y; bucket(j)==bb; j--)
            {
                if(v[j]>maxim)
                    maxim=v[j];
                if(v[j]<minim)
                    minim=v[j];
                suma+=v[j];
            }
        }
        if((maxim*(maxim+1)/2)-(minim*(minim-1)/2)==suma)
        {
            a.push_back(1);
        }
        else
        {
            a.push_back(0);
        }
    }
    for(int it=0;it<a.size();it++)
            cout<<a[it];
    return 0;
}

