#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        ll n, k, m;
        cin>>n>>k>>m;
        ll ans = 0;
        while((m /= k) >= n) ans++;
        cout<<ans<<endl;
    }

    return 0;
}

