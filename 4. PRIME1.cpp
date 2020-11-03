#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

void fillPrime(vector<ll> &prime, int range)
{
    bool isPrime[range];
    ll spf[range];
    memset(isPrime, true, range);

    isPrime[0] = isPrime[1] = false;
    spf[0] = spf[1] = 0;

    for(int i = 2; i < range; i++)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
            spf[i] = i;
        }

        for(int j = 0; j < prime.size() && (i * prime[j]) < range && prime[j] <= spf[i]; j++)
        {
            isPrime[i * prime[j]] = false;
            spf[i * prime[j]] = prime[j];
        }
    }
}

void printPrime(ll low, ll high, ll range, vector<ll> prime)
{
    ll temphigh = low + range;
    ll templow = low;
    while(templow < high)
    {
        if(temphigh > high)
            temphigh = high;
        if(templow <= 1) templow = 2;
        ll upto = floor(sqrt(temphigh)) + 1;
        bool isPrime[(temphigh - templow) + 1];
        memset(isPrime, true, (temphigh - templow) + 1);

        for(int i = 0; i < prime.size() && prime[i] <= upto; i++)
        {
            ll start = floor(templow / prime[i]) * prime[i];
            if(start < templow) start += prime[i];
            if(start == prime[i]) start += prime[i];

            for(; start < temphigh; start += prime[i])
            {
                isPrime[start - templow] = false;
            }
        }

        for(int i = templow; i < temphigh; i++)
        {
            if(isPrime[i - templow]) cout<<i<<endl;
        }
        templow = low;
        templow += range;
        low += range;
        temphigh += range;
    }
}

int main()
{
    int n;
    cin>>n;
    ll lo[n], hi[n];
    ll maxi;

    for(int i = 0; i < n; i++)
    {
        cin>>lo[i]>>hi[i];
        if(i == 0) maxi = hi[i];
        else {
            if(hi[i] > maxi)
                maxi = hi[i];
        }
    }
    ll range = floor(sqrt(maxi)) + 1;
    vector<ll> prime;
    fillPrime(prime, range);

    for(int i = 0; i < n; i++)
    {
        printPrime(lo[i], hi[i] + 1, range, prime);
        cout<<endl;
    }


    return 0;
}

