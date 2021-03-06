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

    ll t[31], f[31];
    f[0] = 0;
    t[0] = 1;
    for(int i = 1; i <= 30; i++)
    {
        f[i] = t[i - 1] + ((i >= 2) ? f[i - 2] : 0);
        t[i] = ((i >= 2) ? 3 * t[i - 2] : 0) + ((i >= 3) ? 2 * f[i - 3] : 0);
    }

    int n;
    cin>>n;
    while(n != -1)
    {
        cout<<t[n]<<endl;
        cin>>n;
    }

    return 0;
}

