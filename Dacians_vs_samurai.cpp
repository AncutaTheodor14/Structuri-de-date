/*

https://codeforces.com/gym/103999/problem/I

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

struct elem{
    int a,b;
}v[100005];

multiset<int>s,s1;

int cmp(elem &x, elem &y){
    if(x.a==y.a)
        return x.b<y.b;
    return x.a<y.a;
}

signed main()
{
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i].a>>v[i].b;
    for(i=1;i<=n;i++)
        if(v[i].a>v[i].b)
            swap(v[i].a,v[i].b);
    sort(v+1,v+n+1, cmp);
    int maxi=-1e9-1, mini=1e9+1;
    int ans=v[n].a-v[1].a;
    for(i=1;i<=n;i++)
    {
        maxi=max(maxi,v[i].b);
        mini=min(mini,v[i].b);
        if(i+1<=n)
        {
            int d=v[i+1].a, e=v[n].a;
            if(max(maxi,e)-min(mini,d)<ans)
                ans=max(maxi,e)-min(mini,d);
        }
    }
    cout<<min(ans,maxi-mini);
    return 0;
}
