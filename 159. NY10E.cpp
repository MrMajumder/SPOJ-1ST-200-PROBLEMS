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

ll dp[10][70];
void precalc(int n)
{
    memset(dp, 0, sizeof dp);
    for(int j = 0; j <=n; j++)
    {
        for(int i = 0; i < 10; i++)
        {
            if(i == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            if(j == 0)
            {
                dp[i][j] = i + 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalc(66);
    int t;
    cin>>t;
    int start = t;
    while(t--)
    {
        int test, n;
        cin>>test>>n;
        if(n == 0) cout<<start - t<<" "<<0<<endl;
        else cout<<start - t<<" "<<dp[9][n - 1]<<endl;
    }

    return 0;
}

