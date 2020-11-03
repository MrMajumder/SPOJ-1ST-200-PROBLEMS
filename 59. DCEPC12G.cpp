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

const int MAX = 1e7;
vector<int> totient(MAX + 1);

vector<int> primecount(MAX + 1);
vector<ll> ans(MAX + 1);

ll modexponen(ll b, ll p, ll m)
{
    ll ans = 1;
    while(p)
    {
        if(p & 1) ans = (ans * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }
    return ans % m;
}

void ETF(int n)
{
    for(int i = 1; i <= n; i++) totient[i] = i;
    for(int i = 2; i <= n; i++)
    {
        if(totient[i] == i)
        {
            for(int j = i; j <= n; j += i) totient[j] -= (totient[j] / i);
        }
    }
}

void sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    int nsqrt = sqrt(n);

    for(int i = 4; i <= n; i+= 2) isPrime[i] = false;
    for(int i = 3; i <= nsqrt; i+= 2)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j <= n; j += (2 * i)) isPrime[j] = false;
        }
    }
    for(int i = 2; i <= n; i++) primecount[i] = primecount[i - 1] + ((isPrime[i])? 1 : 0);
}

void precalc(int n)
{
    for(int i = 1; i <= n; i++)
    {
        if(primecount[i] - totient[i] <= 1) ans[i] = totient[i];
        else ans[i] = modexponen(totient[i], primecount[i] - totient[i], MOD);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ETF(MAX);
    sieve(MAX);
    precalc(MAX);

    int t, num;
    cin>>t;

    while(t--)
    {
        cin>>num;
        cout<<ans[num]<<ENDL;
    }

    return 0;
}

