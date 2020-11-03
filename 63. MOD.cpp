///Still to big of a jump for me, do later, when we become more pro
///Jan 26, 2020
///Jan 26, 2020

#include<bits/stdc++.h>
using namespace std;

//defined my macro functions
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

//defined my macro strings
#define ENDL "\n"
#define SPACE " "

//defined my constants
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 3.14159265358979323846;

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

//ll solve(ll a, ll b, ll m)
//{
//    ll n = sqrt(m) + 1;
//    ll an = 1;
//    for(ll i = 0; i < n; i++)
//    {
//        an = (an * a) % m;
//    }
//    unordered_map<ll, ll> store;
//    for(ll p = 1, cur = an; p <= n; p++)
//    {
//        if(!store.count(cur))
//            store[cur] = p;
//        cur = (cur * an) % m;
//    }
//
//    for(ll q = 0, cur = b; q <= n; q++)
//    {
//        if(store.count(cur))
//            return (store[cur] * n - q);
//        cur = (cur * a) % m;
//    }
//    return -1;
//}

ll gcd(ll a, ll b)
{
    if(a < b) swap(a, b);
    return b? (gcd(b, a % b)) : a;
}

ll solve(ll a, ll b, ll m) {
    a %= m; b %= m;
    if(b == 1) return 0;
    if(gcd(a, m) != 1) return INF;
    ll ans = INF;
    int n = (int) sqrt (m + .0) + 1;

    ll an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<ll, ll> vals;
    for (ll p = 1, cur = an; p <= n; ++p) {
        if (!vals.count(cur))
            vals[cur] = p;
        cur = (cur * 1ll * an) % m;
    }

    for (ll q = 0, cur = b; q <= n; ++q) {
        if (vals.count(cur)) {
            ll temp = vals[cur] * n - q;
            if(temp < ans)
                ans = temp;
        }
        cur = (cur * 1ll * a) % m;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll x, z, k;
    cin>>x>>z>>k;

    while(x || z || k)
    {
        ll y = solve(x, k, z);
        if(y == INF) cout<<"No Solution"<<endl;
        else cout<<y<<endl;
        cin>>x>>z>>k;
    }

    return 0;
}

