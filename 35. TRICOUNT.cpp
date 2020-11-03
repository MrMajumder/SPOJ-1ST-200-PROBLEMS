#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans;
        if(n & 1) ans = (n * (n + 2) * ((2 * n) + 1) - 1) / 8;
        else ans = ((n * (n + 2) * ((2 * n) + 1)) / 8);
        cout<<ans<<endl;
    }

    return 0;
}

