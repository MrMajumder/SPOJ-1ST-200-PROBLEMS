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

ll ans[1000000 + 1];
ll totient[1000000 + 1];


void ETF(int n)
{
    for(int i = 1; i <= n; i++) totient[i] = i;
    for(int i = 2; i <= n; i++)
    {
        if(totient[i] == i)
        {
            for(int j = i; j <= n; j += i)
            {
                totient[j] /= i;
                totient[j] *= (i - 1);
            }
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j+= i)
        {
            ans[j] += (i * totient[i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ETF(1000000);
    ll t, num;
    cin>>t;
    while(t--)
    {
        cin>>num;
        ll out = ans[num] + 1;
        out *= num;
        out /= 2;
        cout<<out<<ENDL;
    }

    return 0;
}

