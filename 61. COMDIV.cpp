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

vector<int> prime;

void sieve(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    prime.push_back(2);
    for(int i = 4; i <= n; i+= 2) isPrime[i] = false;
    for(int i = 3; i <= n; i+= 2)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
            for(int j = i * i; j <= n; j+= (2 * i)) isPrime[j] = false;
        }
    }
//    for(int i = 0; i < prime.size(); i++) cout<<prime[i]<<SPACE;
//    cout<<endl;
}

int gcd(int a, int b)
{
    if(a < b) swap(a, b);
    return b? gcd(b, a % b) : a;
}

int findCommonDivisor(int a, int b)
{
    int g = gcd(a, b);
    int ans = 1;
    for(int i = 0; (prime[i] * prime[i]) <= g; i++)
    {
        if(g % prime[i] == 0)
        {
            int c = 1;
            g /= prime[i];
            while(g % prime[i] == 0)
            {
                g /= prime[i];
                c++;
            }
            ans *= (c + 1);
        }
    }
    if(g > 1)
    {
        ans *= 2;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve(1010);
    int t, a, b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<findCommonDivisor(a, b)<<ENDL;
    }
//    for(int i = 1; i <= 1000000; i++)
//    {
//        for(int j = i; j <= 1000000; j++)
//        {
//            cout<<i<<SPACE<<j<<SPACE<<findCommonDivisor(i, j)<<ENDL;
//        }
//    }

    return 0;
}

