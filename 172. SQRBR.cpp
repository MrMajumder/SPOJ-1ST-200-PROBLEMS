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

int dp[41][41];
bool fixedpos[41];



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
        memset(fixedpos, false, sizeof fixedpos);
        for(int i = 0; i < k; i++)
        {
            int x;
            cin>>x;
            fixedpos[x] = true;
        }
        memset(dp, 0, sizeof dp);
        dp[1][1] = 1;
        for(int i = 2; i <= 2 * n; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(fixedpos[i])
                {
                    if(j == 0) dp[i][j] = 0;
                    else dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    if(j == 0) dp[i][j] = dp[i - 1][1];
                    else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
                }
            }
        }
        cout<<dp[2 * n][0]<<endl;
    }

    return 0;
}

