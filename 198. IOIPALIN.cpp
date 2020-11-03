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

    int n;
    string s1;
    cin>>n>>s1;

    //string s1 = s.substr(0, n / 2);
    string s2 = s1;
    reverse(s1.begin(), s1.end());

    int len = s1.length();
    int dp[len + 1][len + 1];
    for(int i = 0; i <= len; i++)
    {
        for(int j = 0; j <= len; j++)
        {
            if(!i || !j) dp[i][j] = 0;
            else
            {
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout<< (len - dp[len][len])<<endl;

    return 0;
}

