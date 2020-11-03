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

ll gcd(ll a, ll b)
{
    if(a < b) swap(a, b);
    return b ? gcd(b, a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    int hold;
    int diff[n];
    cin>>diff[0];
    for(int i = 0; i < n - 1; i++)
    {
        cin>>hold;
        diff[i] = hold - diff[i];
        diff[i + 1] = hold;
    }
    int gval = diff[0];
    for(int i = 1; i < n - 1; i++) gval = gcd(gval, diff[i]);
    int ans = 0;
    for(int i = 0; i < n - 1; i++) ans += (diff[i] / gval) - 1;
    cout<<ans<<endl;

    return 0;
}

