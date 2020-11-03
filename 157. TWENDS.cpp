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

int arr[1001];
int dp[1001][1001];

int maxdiff(int s, int e)
{
    if(s >= e) return 0;
    if(dp[s][e] != -1) return dp[s][e];
    int h1, h2;
    if(arr[s + 1] >= arr[e]) h1 = arr[s] - arr[s + 1] + maxdiff(s + 2, e);
    else h1 = arr[s] - arr[e] + maxdiff(s + 1, e - 1);

    if(arr[s] >= arr[e - 1]) h2 = arr[e] - arr[s] + maxdiff(s + 1, e - 1);
    else h2 = arr[e] - arr[e - 1] + maxdiff(s, e - 2);

    return dp[s][e] = max(h1, h2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int start = 1;
    while(n != 0)
    {
        for(int i = 0; i < n; i++) cin>>arr[i];
        memset(dp, -1, sizeof dp);
        cout<<"In game "<<(start++)<<", the greedy strategy might lose by as many as "<<maxdiff(0, n - 1)<<" points."<<endl;
        cin>>n;
    }

    return 0;
}

