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

int pour(int a, int b, int c)
{
    int step = 1;
    int bucketa = a, bucketb = 0, transfer;
    while(bucketa != c && bucketb != c)
    {
        transfer = min(bucketa, b - bucketb);
        bucketa -= transfer;
        bucketb += transfer;
        step++;
        if(bucketa == c || bucketb == c) break;
        if(bucketa == 0)
        {
            bucketa = a;
            step++;
        }
        if(bucketb == b)
        {
            bucketb = 0;
            step++;
        }
    }
    return step;
}

int gcd(int a, int b)
{
    if(a < b) swap(a, b);
    return b ? gcd(b , a % b) : a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        if((c > a && c > b) || (c % gcd(a, b) != 0)) cout<<-1<<endl;
        //else if(c == a || c == b) cout<<1<<endl;
        else
        {
            cout<<min(pour(a, b, c), pour(b, a, c))<<endl;
        }
    }
    return 0;
}

