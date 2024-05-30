/*

https://www.infoarena.ro/problema/proc2

*/

#include<bits/stdc++.h>
#define int long long
using namespace std;
ifstream f("proc2.in");
ofstream g("proc2.out");

int n,m;
multiset<pair<int,int>>s1;
multiset<int>s2;

signed main()
{
    int i,j,s,d;
    f>>n>>m;
    for(i=1;i<=n;i++)
        s2.insert(i);
    for(i=1;i<=m;i++)
    {
        f>>s>>d;
        while(!s1.empty() && s1.begin()->first<=s)
            s2.insert(s1.begin()->second),s1.erase(s1.find(*s1.begin()));
        int ans=*s2.begin();
        s2.erase(s2.find(*s2.begin()));
        s1.insert({s+d,ans});
        g<<ans<<'\n';
    }
    return 0;
}
