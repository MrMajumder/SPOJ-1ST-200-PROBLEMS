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

int dp[1001][22][80];
int oxi[1001];
int nitro[1001];
int weight[1001];

int calc(int n, int ox, int ni)
{
    if(dp[n][ox][ni] != -1) return dp[n][ox][ni];
    if(ox == 0 && ni == 0) dp[n][ox][ni] = 0;
    else if (n == 0) dp[n][ox][ni] = INF;
    else dp[n][ox][ni] = min(calc(n - 1, ox,ni), calc(n - 1, max(ox - oxi[n - 1], 0), max(ni - nitro[n - 1], 0)) + weight[n - 1]);
    return dp[n][ox][ni];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n, oxygen, nitrogen;
        cin>>oxygen>>nitrogen>>n;

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= oxygen; j++)
                for(int k = 0; k <= nitrogen; k++)
                    dp[i][j][k] = -1;
        for(int i = 0; i < n; i++) cin>>oxi[i]>>nitro[i]>>weight[i];
        cout<<calc(n, oxygen, nitrogen)<<endl;
    }

    return 0;
}

