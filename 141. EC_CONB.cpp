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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n, ans;
        cin>>n;
        if(n % 2) ans = n;
        else
        {
            ans = 0;
            while(n)
            {
                ans <<= 1;
                if(n % 2) ans += 1;
                n >>= 1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}

