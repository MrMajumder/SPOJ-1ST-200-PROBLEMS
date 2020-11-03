#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

typedef long long ll;

void Sieve(int n)
{
    vector<bool> isPrime(n, true);

    isPrime[0] = isPrime[1] = false;
    for(int i = 4; i < n; i += 2)
    {
        isPrime[i] = false;
    }
    int nsqrt = sqrt(n);
    for(int i = 3; i <= nsqrt; i += 2)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j <= n; j += (2 * i))
            {
                isPrime[j] = false;
            }
        }
    }
    int countp = 1;
    cout<<"2\n";
    for(int i = 3; i <= n; i+= 2)
    {
        if(isPrime[i])
        {
            countp++;
            if((countp % 100) == 1) cout<<i<<"\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Sieve(100000000);

    return 0;
}

