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
ll unitval[11];
void precalc(int n)
{
    unitval[0] = 0;
    unitval[1] = 45;
    for(int i = 2; i <= n; i++) unitval[i] = (unitval[i - 1] * 10) + (45 * floor(pow(10, i - 1) + 0.5));
}

ll digitsumUntil(int n)
{
    if(n < 10) return (n + 1) * n / 2;
    ll d = log10(n);
    ll p = floor(pow(10, d) + 0.5);
    ll msd = n / p;
    return (msd * unitval[d]) + (((msd * (msd - 1)) / 2) * p) + (msd * (1 + (n % p))) + digitsumUntil(n % p);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precalc(10);
    int a, b;
    cin>>a>>b;
    while(a != -1)
    {
        ll ans = digitsumUntil(b) - digitsumUntil(a - 1);
        cout<<ans<<endl;
        cin>>a>>b;
    }

    return 0;
}

