#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

int main()
{
    string s;
    cin>>s;

    while(s != "0")
    {
        int len = s.length();

        ll dp[len + 1];

        dp[0] = dp[1] = 1;
        for(int i = 2; i <= len; i++)
        {
            dp[i] = 0;
            if(s[i - 1] != '0') dp[i] = dp[i - 1];
            int x = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(x >= 10 && x <= 26) dp[i] += dp[i - 2];
        }
        cout<<dp[len]<<endl;

        cin>>s;
    }

    return 0;
}

