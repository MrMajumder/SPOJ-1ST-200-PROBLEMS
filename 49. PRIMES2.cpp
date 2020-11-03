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

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 1e9;
    int nsqrt = sqrt(n);

    vector<bool> isPrime(n, true);


    isPrime[0] = isPrime[1] = false;
    for(int i = 4; i < n; i+= 2)
    {
        isPrime[i] = false;
    }

    for(int i = 3; i <= nsqrt; i+= 2)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j < n; j+= (2 * i))
            {
                isPrime[j] = false;
            }
        }
    }

    cout<<2<<ENDL;
    int counter = 2;
    for(int i = 5; i < n; i+= 6)
    {
        if(isPrime[i])
        {
            counter++;
            if((counter % 500) == 1) cout<<i<<ENDL;
        }

        if(isPrime[i + 2])
        {
            counter++;
            if((counter % 500) == 1) cout<<i + 2<<ENDL;
        }
    }

    return 0;
}

