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

int adjmat[21][21];
ll dp[1 << 20];

unsigned numbits(unsigned i)
{
    const unsigned MASK1  = 0x55555555;
    const unsigned MASK2  = 0x33333333;
    const unsigned MASK4  = 0x0f0f0f0f;
    const unsigned MASK8  = 0x00ff00ff;
    const unsigned MASK16 = 0x0000ffff;

    i = (i&MASK1 ) + (i>>1 &MASK1 );
    i = (i&MASK2 ) + (i>>2 &MASK2 );
    i = (i&MASK4 ) + (i>>4 &MASK4 );
    i = (i&MASK8 ) + (i>>8 &MASK8 );
    i = (i&MASK16) + (i>>16&MASK16);

    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin>>adjmat[i][j];
        memset(dp, 0, sizeof dp);
        dp[(1 << n) - 1] = 1;
        for(int i = (1 << n) - 1; i >= 0; i--)
        {
            int idx = numbits(i);
            for(int j = 0; j < n; j++)
            {
                if(adjmat[idx][j] == 0 || (i & (1 << j))) continue;
                dp[i] += dp[(i | (1 << j))];
            }
        }
//        for(int i = 0; i < (1 << n); i++) cout<<dp[i]<<SPACE;
//        cout<<endl;
        cout<<dp[0]<<endl;
    }

    return 0;
}

