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

const int MAX = 1e4;
vector<int> totient(MAX + 1);
vector<ll> sum(MAX + 1);

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

void precalc(int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            sum[max(i, j)] += (totient[i] *  totient[j]);
        }
    }

    for(int i = 1; i <= n; i++)
    {
        sum[i] += sum[i - 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ETF(MAX);
    precalc(MAX);

    int t, num;
    cin>>t;

    while(t--)
    {
        cin>>num;
        cout<<sum[num]<<ENDL;
    }

    return 0;
}

