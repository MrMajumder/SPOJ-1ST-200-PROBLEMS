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

int totient(int n)
{
    int ans = n;
    if(n % 2 == 0)
    {
        while(n % 2 == 0)
        {
            n /= 2;
        }
        ans -= (ans / 2);
    }

    for(int i = 3; i * i <= n; i+= 2)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                n/= i;
            }
            ans -= (ans / i);
        }
    }

    if(n > 1) ans -= (ans / n);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<totient(n)<<ENDL;
    }

    return 0;
}

