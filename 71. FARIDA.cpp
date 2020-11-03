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

const int MAX = 10000 + 5;
ll arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin>>t;

    ll prevtake, prevnotake, nowtake, nownotake;
    int c = 1;
    while(t--)
    {
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        prevtake = prevnotake = nowtake = nownotake = 0;

        for(int i = 0; i < n; i++)
        {
            nowtake = prevnotake + arr[i];
            nownotake = max(prevtake, prevnotake);

            prevnotake = nownotake;
            prevtake = nowtake;
        }

        cout<<"Case "<<c++<<": "<<(ll) max(nowtake, nownotake)<<endl;
    }

    return 0;
}

