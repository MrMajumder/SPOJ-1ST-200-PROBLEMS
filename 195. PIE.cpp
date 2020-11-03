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

vector<long double> vol;
int n, f;

bool calc(long double val)
{
    int total = 0;
    for(int i = 0; i < n; i++) total += int(vol[i] / val);
    return (total >= f) ? true : false;
}

long double compute()
{
    long double start = 0, fin = vol[n - 1], mid;
    while(fin - start > 1e-6)
    {
        mid = (start + fin) / 2.0;
        if(calc(mid)) start = mid;
        else fin = mid;
    }
    return mid;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {

        cin>>n>>f;
        f++;
        int rad[n];
        for(int i = 0; i < n; i++) cin>>rad[i];
        sort(rad, rad + n);
        vol = vector<long double>(n);
        for(int i = 0; i < n; i++)
        {
            vol[i] = PI * rad[i] * rad[i];
        }
        long double ans = compute();
        cout<<setprecision(4)<<fixed<<ans<<endl;
    }

    return 0;
}

