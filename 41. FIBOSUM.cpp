#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

typedef long long ll;

void matmultiply(int ax, int ay, int by, ll a[][3], ll b[][3])
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

    for(int i = 0; i < ax; i++)
    {
        for(int j = 0; j < ay; j++)
        {
            a[i][j] = (temp[i][j] % MOD);
        }
    }
}

void matpower(int ax, int ay, ll a[][3], ll power)
{
    ll res[3][3];

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
        if(power & 1) matmultiply(3, 3, 3, res, a);
        matmultiply(3, 3, 3, a, a);
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

ll fibsum(int x)
{
    if(x <= 0) return 0L;
    ll mat[][3] = {1, 1, 0};
    ll matmul[][3] = {1, 0, 0, 1, 1, 1, 1, 1, 0};

    matpower(3, 3, matmul, x - 1);
    matmultiply(1, 3, 3, mat, matmul);

    ll ans = mat[0][0];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin>>t;
    int a, b;
    while(t--)
    {
        cin>>a>>b;
        ll sum = ((fibsum(b) - fibsum(a - 1)) + MOD) % MOD;
        cout<<sum<<endl;
    }

    return 0;
}

