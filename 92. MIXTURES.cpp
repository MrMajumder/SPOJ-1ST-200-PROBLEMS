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

int mix[100];
int dp[100][100];

int sum(int a, int b)
{
    int ret = 0;
    for(int i = a; i <= b; i++) ret = (ret + mix[i]) % 100;
    return ret;
}

int calculateMinSmoke(int l, int r)
{
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) return 0;
    int ret = dp[l][r];
    for(int i = l; i < r; i++)
    {
        int temp = calculateMinSmoke(l, i) + calculateMinSmoke(i + 1, r) + (sum(l, i) * sum(i + 1, r));
        if(ret == -1 || ret > temp) ret = temp;

    }
    return (dp[l][r] = ret);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        for(short i = 0; i < n; i++) cin>>mix[i];
        memset(dp, -1, sizeof(dp));
        cout<<calculateMinSmoke(0, n - 1)<<endl;
    }

    return 0;
}

