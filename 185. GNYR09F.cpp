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
const int MOD = 1000000007; //9digits
const double EPS = 1e-8;
const long double EULER = 2.71828182845904523536;   //20digits
const long double PI = 3.14159265358979323846;      //20digits
//float = 7digits, double = 15digits, long double = 21 digits precision

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

ll dp[110][110][2];

void precalc()
{
    dp[1][0][0] = dp[1][0][1] = 1;
    for(int i = 2; i < 102; i++)
    {
        for(int j = 0; j < i; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j][0];
            if(j > 0) dp[i][j][1] += dp[i - 1][j - 1][1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalc();
    int t;
    cin>>t;
    while(t--)
    {
        int pos, n, k;
        cin>>pos>>n>>k;
        if(k < n) cout<<pos<<" "<<dp[n][k][0] + dp[n][k][1]<<endl;
        else cout<<pos<<" "<<0<<endl;
    }

    return 0;
}

