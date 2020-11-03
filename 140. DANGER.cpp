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

    int a, b, c;
    string e;
    cin>>e;
    while(e != "00e0")
    {
        a = e[0] - '0';
        b = e[1] - '0';
        c = e[3] - '0';
        int n = (a * 10 + b) * pow(10, c);
        int ans = (n - pow(2, (int)floor(log2(n))));
        ans = ans << 1 | 1;
        cout<<ans<<endl;
        cin>>e;
    }

    return 0;
}

