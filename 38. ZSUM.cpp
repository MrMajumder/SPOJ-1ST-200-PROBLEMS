#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;
ll mod = 10000007;

ll modexponen(ll b, ll p, ll m)
{
    ll ans = 1;
    while(p)
    {
        if(p & 1) ans = (ans * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }

    return ans;
}

int main()
{
    ll n, k;
    cin>>n>>k;

    while(n || k)
    {
        ll sum = 0;
        sum = (2 * modexponen(n - 1, k, mod)) + (2 * modexponen(n - 1, n - 1, mod)) + modexponen(n, k, mod) + modexponen(n, n, mod);
        sum %= mod;
        cout<<sum<<endl;
        cin>>n>>k;
    }

    return 0;
}

