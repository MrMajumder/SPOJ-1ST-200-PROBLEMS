#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;
ll mod = 1000000007;

ll modexponen(ll b, ll p, ll m)
{
    ll res = 1;
    while(p)
    {
        if(p & 1) res = (res * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }

    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll out = 1;
        ll res;
        if(n <= 1) goto fin;

        res = n % 3;
        if(res == 1) n -= 4;
        if(res == 2) n -= 2;

        out = n / 3;
        out = modexponen(3, out, 1000000007);
        if(res == 1) out = (out * 4) % 1000000007;
        if(res == 2) out = (out * 2) % 1000000007;

        fin:
        cout<<out<<endl;
    }

    return 0;
}

