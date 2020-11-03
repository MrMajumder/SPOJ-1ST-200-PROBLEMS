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
        string s;
        cin>>s;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++)
        {
            int zcount, ocount;
            zcount = ocount = 0;
            if(s[i] == '0') zcount++;
            else ocount++;
            for(int j = i - 1; j >= 0; j--)
            {
                int x = dp[j];
                if(zcount < ocount) x += i - j;
                dp[i] = max(dp[i], x);
                if(s[j] == '0') zcount++;
                else ocount++;
            }
            if(zcount < ocount) dp[i] = i + 1;
        }
//        for(int i = 0; i < n; i++) cout<<dp[i]<<SPACE;
//        cout<<endl;
        cout<<dp[n - 1]<<endl;
    }

    return 0;
}

