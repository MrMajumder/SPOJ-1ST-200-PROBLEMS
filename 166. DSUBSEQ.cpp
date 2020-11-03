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
        string s;
        cin>>s;
        int n = s.length();
        ll dp[n + 1];
        vector<int> last(26, -1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            dp[i] = (2 * dp[i - 1]) % MOD;
            if(last[s[i - 1] - 'A'] != -1) dp[i] = (dp[i] - dp[last[s[i - 1] - 'A']] + MOD) % MOD;
            last[s[i - 1] - 'A'] = i - 1;
        }
        cout<<(dp[n] % MOD)<<endl;
    }

    return 0;
}

