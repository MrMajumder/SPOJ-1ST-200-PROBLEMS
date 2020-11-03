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
const int MAX = 1000001;

ll totient[MAX + 1];
ll sum[MAX + 1];

void ETF(int n)
{
    for(int i = 1; i <= n; i++) totient[i] = i;
    for(int i = 2; i <= n; i++)
    {
        if(totient[i] == i)
        {
            for(int j = i; j <= n; j+= i)
            {
                totient[j] = totient[j] / i * (i - 1);
            }
        }
    }
}

void findSum(int n)
{
    for(int i = 1; i < n; i++)
    {
        for(int j = 2; i * j <= n; j++)
        {
            sum[i * j] +=  i * totient[j];
        }
    }

    for(int i = 2; i <= n; i++) sum[i] += sum[i - 1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ETF(MAX);
    findSum(MAX);

    int num;
    cin>>num;

    while(num)
    {
        cout<<sum[num]<<endl;
        cin>>num;
    }

    return 0;
}

