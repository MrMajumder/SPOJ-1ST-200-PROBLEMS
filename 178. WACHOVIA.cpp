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
        int tweight, bag;
        cin>>tweight>>bag;
        int weight[bag];
        int val[bag];
        for(int i = 0; i < bag; i++) cin>>weight[i]>>val[i];
        int dp[tweight + 1][bag + 1];
        for(int i = 0; i <= tweight; i++)
        {
            for(int j = 0; j <= bag; j++)
            {
                if(i == 0 || j == 0) dp[i][j] = 0;
                else
                {
                    if(i - weight[j - 1] >= 0) dp[i][j] = max(dp[i][j - 1], dp[i - weight[j - 1]][j - 1] + val[j - 1]);
                    else dp[i][j] = dp[i][j - 1];
                }
            }
        }
        cout<<"Hey stupid robber, you can get "<<dp[tweight][bag]<<"."<<endl;
    }

    return 0;
}

