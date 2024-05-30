/*

https://codeforces.com/gym/103999/problem/H

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

int fv[31],v[200005],n;

signed main()
{
    int i,j,k,a,b,ans=-1,maxi=-1;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    for(i=2;i<=n-2;i++)//al doilea indice
    {
        int maxia=-1, maxib=-1;
        for(j=i+1;j<=n;j++)
        {
            if(v[j]>maxia)
                maxia=v[j];
        }
        for(j=i+1;j<=n;j++)
        {
            if(v[j]>maxib && maxia!=v[j])
                maxib=v[j];
        }
        ans=-1;
        for(j=1;j<i;j++)
        {
            if(v[i]^v[j]>ans)
                ans=v[i]^v[j];
        }
        int cv=maxia+maxib;
        maxi=max(maxi,ans*(maxia+maxib));
    }
    cout<<maxi;
    return 0;
}
