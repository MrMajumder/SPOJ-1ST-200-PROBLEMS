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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n = 1000000;
    int nsqrt = sqrt(n);

    vector<bool> isPrime(n + 1, true);
    vector<int> sum(n + 1, 0);

    isPrime[0] = isPrime[1] = false;
    for(int i = 4; i <= n; i+= 2)
    {
        isPrime[i] =false;
    }
    for(int i = 3; i <= nsqrt; i+= 2)
    {
        if(isPrime[i])
        {
            for(int j = i * i; j <= n; j += (2 * i))
            {
                isPrime[j] = false;
            }
        }
    }

    sum[2] = 1;
    for(int i = 3; i <= n; i++)
    {
        sum[i] = sum[i - 1];
        if(isPrime[i])
        {
            int hipart = i;
            int lopart =0;
            int totallow = 0;
            int ten = 10;
            while(hipart)
            {
                lopart = hipart % ten;
                totallow += lopart;
                hipart -= lopart;
                ten *= 10;
                if(isPrime[totallow] == false || lopart == 0)
                {
                    break;
                }
            }
            if(!hipart) sum[i]++;
        }
    }
    int t, num;
    cin>>t;
    while(t--)
    {
        cin>>num;
        cout<<sum[num]<<"\n";
    }


    return 0;
}

