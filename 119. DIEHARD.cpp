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

int dp[2000][2000];

int diehard(int step, int health, int armor)
{
    if(health < 1 || armor < 1) return 0;
    if(dp[health][armor] != -1) return dp[health][armor];
    if(step) return diehard(0, health + 3, armor + 2) + 1;
    else dp[health][armor] = max(diehard(1, health - 5, armor - 10), diehard(1, health - 20, armor + 5)) + 1;
    return dp[health][armor];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    memset(dp, -1, sizeof dp);

    while(t--)
    {
        int h, a;
        cin>>h>>a;
        cout<<diehard(0, h + 3, a + 2)<<endl;
    }

    return 0;
}

