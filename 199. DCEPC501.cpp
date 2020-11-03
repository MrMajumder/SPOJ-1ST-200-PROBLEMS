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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int price[n + 10] = {0};
        for(int i = 0; i < n; i++) cin>>price[i];
        ll dp[n + 10] = {0};
        for(int i = n; i >= 0; i--) dp[i] = max(price[i] + dp[i + 2], max(price[i] + price[i + 1] + dp[i + 4], price[i] + price[i + 1] + price[i + 2] + dp[i + 6]));
        cout<<dp[0]<<endl;
    }

    return 0;
}

