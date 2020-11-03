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

ll dp[15][100];

ll func(int n, int k)
{
    if(n == 0) return 0;
    if(k == 0) return 1;
    if(dp[n][k] != -1) return dp[n][k];
    ll val = 0;
    for(int i = 0; i < n && (k - i) >= 0; i++) val += func(n - 1, k - i);
    return dp[n][k] = val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        memset(dp, -1, sizeof dp);
        cout<<func(n, k)<<endl;
    }

    return 0;
}

