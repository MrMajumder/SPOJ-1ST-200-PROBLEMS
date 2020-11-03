#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;
const int MOD = 1000000007;

void matmultiply(int ax, int ay, int by, ll a[][2], ll b[][2])
{
    ll temp[ax][by];
    for(int i = 0; i < ax; i++)
    {
        for(int j = 0; j < by; j++)
        {
            temp[i][j] = 0;
            for(int k = 0; k < ay; k++)
            {
                temp[i][j] += (((a[i][k] % MOD) * (b[k][j] % MOD))% MOD);
                temp[i][j] %= MOD;
            }
        }
    }

    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            a[i][j] = (temp[i][j] % MOD);
        }
    }
}

void matpower(int ax, int ay, ll a[][2], ll power)
{
    ll res[2][2];

    for(int i = 0; i < ax; i++)
    {
        for(int j = 0; j < ay; j++)
        {
            if(i == j) res[i][j] = 1;
            else res[i][j] = 0;
        }
    }

    while(power)
    {
        if(power & 1) matmultiply(2, 2, 2, res, a);
        matmultiply(2, 2, 2, a, a);
        power >>= 1;
    }

    for(int i = 0; i < ax; i++)
    {
        for(int j = 0; j < ay; j++)
        {
            a[i][j] = (res[i][j] % MOD);
        }
    }
}

ll getFib(ll n)
{
    ll mat[][2] = {{1, 0}};
    ll mulpart[][2] = {{1, 1}, {1, 0}};

    matpower(2, 2, mulpart, n - 1);
    matmultiply(1, 2, 2, mat, mulpart);

    ll val = mat[0][0];
    return val;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    ll n;
    ll ans;

    while(t--)
    {
        cin>>n;

        if(n == 0) ans = 0;
        else if(n == 1) ans = 2;
        else ans = getFib(n + 3);

        cout<<ans<<endl;
    }

    return 0;
}

