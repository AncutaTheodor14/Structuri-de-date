/*

https://codeforces.com/gym/103999/problem/M

*/
#include<bits/stdc++.h>
#define int long long
#define INF 1000000000000000000
using namespace std;

int v[200005],st[200005],dr[200005],sp[200005];
stack<int>s;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t,l,n,i,val;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>v[i],sp[i]=sp[i-1]+i;
    for(i=1; i<=n; i++)
    {
        while(!s.empty() && v[i]<v[s.top()])
            dr[s.top()]=i-1,s.pop();
        s.push(i);
    }
    while(!s.empty())
        dr[s.top()]=n,s.pop();
    for(i=n; i>=1; i--)
    {
        while(!s.empty() && v[i]<v[s.top()])
            st[s.top()]=i+1,s.pop();
        s.push(i);
    }
    while(!s.empty())
        st[s.top()]=1,s.pop();
    int sum=0;
    for(i=1; i<=n; i++)
    {
        ///(i-st) + (i-st-1) + ... + (i-st-(dr-i))
        val=0;
        if(i-st[i]>0)
        {
            if(i-st[i]-(dr[i]-i)-1<0)
                val=sp[i-st[i]];
            else
                val=sp[i-st[i]]-sp[i-st[i]-(dr[i]-i)-1];
        }
        sum+=val;
    }
    cout<<sum;
    return 0;
}
