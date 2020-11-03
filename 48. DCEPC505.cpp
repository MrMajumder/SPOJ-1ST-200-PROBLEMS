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

    int n = 1.1e7;
    int need = 2e6;
    int nsqrt = sqrt(n);

    vector<int> prime(n + 1, 0);


    for(int i = 2; i <= nsqrt; i++)
    {
        if(!prime[i])
        {
            for(int j = i * i; j <= n; j += i)
            {
                prime[j] = i;
            }
        }
    }

    vector<int> mul;
    int counter = 0;
    for(int i = 2; i <= n && counter <= need; i++)
    {
        if(prime[i] && (prime[i] != i / prime[i]) && !prime[prime[i]] && !prime[i / prime[i]])
        {
            mul.push_back(i);
            counter++;
        }
    }

    int t, num;
    cin>>t;
    while(t--)
    {
        cin>>num;
        cout<<mul[num - 1]<<ENDL;
    }

    return 0;
}

