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

struct Box
{
    int h, w, d;
};

bool customcomp(Box a, Box b)
{
    return (a.d * a.w) > (b.d * b.w);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    while(n)
    {
        Box cube[3 * n];
        int a, b, c;
        int bcount = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>a>>b>>c;
            cube[bcount].h = a;
            cube[bcount].w = max(b, c);
            cube[bcount].d = min(b, c);
            bcount++;
            cube[bcount].h = b;
            cube[bcount].w = max(a, c);
            cube[bcount].d = min(a, c);
            bcount++;
            cube[bcount].h = c;
            cube[bcount].w = max(b, a);
            cube[bcount].d = min(b, a);
            bcount++;
        }
        n = 3 * n;
        sort(cube, cube + n, customcomp);
        int dp[n];
        for(int i = 0; i < n; i++) dp[i] = cube[i].h;
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(cube[j].d > cube[i].d && cube[j].w > cube[i].w && dp[j] + cube[i].h > dp[i]) dp[i] = dp[j] + cube[i].h;
            }
        }
        int ans = -1;
        for(int i = 0; i < n; i++) ans = max(ans, dp[i]);
        cout<<ans<<endl;
        cin>>n;
    }

    return 0;
}

