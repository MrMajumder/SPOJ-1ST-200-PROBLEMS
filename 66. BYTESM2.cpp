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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int r, c;
        cin>>r>>c;
        int dp[r + 1][c + 2];
        int val[r][c];
        int ans = -1;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cin>>val[i][j];
            }
        }

        for(int i = 0; i <= r; i++)
        {
            for(int j = 0; j <= c + 1; j++)
            {
                if(i == 0 || j == 0 || j == (c + 1)) dp[i][j] = 0;
                else
                {
                    dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])) + val[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}


