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

vector<ll> prime;

void sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    prime.push_back(2);
    for(ll i = 4; i <= n; i+= 2) isPrime[i] = false;
    for(ll i = 3; i <= n; i+= 2)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
            for(ll j = i * i; j <= n; j+= (2 * i)) isPrime[j] = false;
        }
    }
}

ll binexponen(ll b, ll p)
{
    ll ans = 1;
    while(p)
    {
        if(p & 1)  ans = (ans * b);
        b = (b * b);
        p >>= 1;
    }
    return ans;
}

ll factorSum(ll a)
{
    ll ans = 1;
    for(int i = 0; (prime[i] * prime[i]) <= a; i++)
    {
        if(a % prime[i] == 0)
        {
            ll p = prime[i];
            int c = 1;
            a /= p;
            while(a % p == 0)
            {
                a /= p;
                c++;
            }
            ans *= ((binexponen(p, c + 1) - 1)/ (p - 1));
        }
    }
    if(a > 1)
    {
        ans *= (a + 1);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(100001000);

    int t;
    ll num;
    cin>>t;
    while(t--)
    {
        cin>>num;
        cout<<factorSum(num) - num<<ENDL;
    }

    return 0;
}

