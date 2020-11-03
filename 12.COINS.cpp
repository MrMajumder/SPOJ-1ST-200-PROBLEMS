#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef unsigned long int ult;

map <int, ll> h;

ll getmaxval(ll val)
{
    if(val == 0) return 0;

    ll r = h[val];

    if(r == 0)
    {
        r = max(val, getmaxval(val / 2) + getmaxval(val / 3) + getmaxval(val / 4));
        h[val] = r;
    }
    return r;
}

int main()
{
    ll n;
    vector<ll> val;
    while(cin>>n)
    {
        val.push_back(n);
    }

    int len = val.size();
    for(int i = 0; i < len; i++)
    {
        h.clear();
        cout<<getmaxval(val[i])<<endl;
    }

    return 0;
}

