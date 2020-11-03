#include<bits/stdc++.h>
using namespace std;

//defined my macro functions
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

//defined my macro strings
#define ENDL "\n"
#define SPACE " "
#define CHECK "check"

//defined my constants
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;
const double EPS = 1e-8;
const double PI = 3.14159265358979323846;

typedef long long ll;
typedef unsigned long long ull;

ull mulmod(ull a, ull b, ull m)
{
    ull ans = 0;
    a %= m;

    while(b)
    {
        if(b & 1) ans = (ans + a) % m;
        a = (a << 1)% m;
        b >>= 1;
    }

    return ans % m;
}

ull modexponen(ull base, ull power, ull m)
{
    ull ans = 1;
    power %= m;

    while(power)
    {
        if(power & 1) ans = mulmod(ans, base, m);
        base = mulmod(base, base, m);
        power >>= 1;
    }

    return ans % m;
}

bool checkComposite(ull a, ull d, ull n, ull s)
{
    ull x = modexponen(a, d, n);

    if(x == 1 || x == (n - 1)) return false;

    for(int i = 1; i < s; i++)
    {
        x = mulmod(x, x, n);
        if(x == 1) return true;
        if(x == (n - 1)) return false;
    }
    return true;
}

bool MilerRabinTest(ull n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(n & 1 == 0) return false;

    ull d = n - 1;
    ull twopower = 0;

    while((d & 1) == 0)
    {
        d >>= 1;
        twopower++;
    }
    int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    int len = sizeof(prime) / sizeof(prime[0]);

    for(int i = 0; i < len; i++)
    {
        ull a = prime[i];
        if(a == n) return true;
        if(checkComposite(a, d, n, twopower))
        {
            return false;
        }
    }
    return true;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    ull num;
    cin>>t;
    while(t--)
    {
        cin>>num;
        if(MilerRabinTest(num)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}

