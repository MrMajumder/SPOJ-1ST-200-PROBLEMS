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

ll gcd(ll a, ll b)
{
    if(a < b) swap(a, b);
    return (b) ? gcd(b, a % b): a;
}

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
        int dp = 0;
        bool isfrac = false;
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == '.')
            {
                isfrac = true;
                break;
            }
            else dp++;
        }
        ll num = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '.') continue;
            num = (num * 10) + (ll)(s[i] - '0');
        }
        int denom = 1;
        if(isfrac) while(dp--) denom *= 10;
        cout<<(denom / gcd(num, denom))<<endl;
    }

    return 0;
}

