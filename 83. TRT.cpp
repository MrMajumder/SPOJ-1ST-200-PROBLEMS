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

int dp[2001][2001];
int val[2001];
int n;

int compute(int l, int r)
{
    if(l > r)
        return 0;
    if(dp[l][r] != 0) return dp[l][r];
    int year = n - (r - l);
    return dp[l][r] = max(compute(l + 1, r) + (val[l] * year),
                          compute(l, r - 1) + (val[r] * year));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;

    for(int i = 0; i < n; i++) cin>>val[i];
    int ans = compute(0, n - 1);
    cout<<ans<<endl;

    return 0;
}

