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
        int n, k;
        cin>>n>>k;
        int price[k];
        for(int i = 0; i < k; i++) cin>>price[i];
        vector<int> dp(k + 1, INF);
        dp[0] = 0;
        for(int i = 0; i <= k; i++)
        {
            for(int j = 0; j < k; j++)
            {
                if(price[j] == -1) continue;
                if(j + 1 <= i) dp[i] = min(dp[i], dp[i - j - 1] + price[j]);
            }
        }
//        for(int i = 0; i <= k; i++) cout<<dp[i]<<SPACE;
//        cout<<endl;
        if(dp[k] == INF) cout<<-1<<endl;
        else cout<<dp[k]<<endl;
    }

    return 0;
}

