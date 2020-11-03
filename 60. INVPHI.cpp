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

const ll MAX = 1e8;
vector<int> totient(MAX + 1);
vector<int> prime;
vector<int> revtot(MAX + 1);

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
    int t;
    for(int i = 1; i <= n; i++)
    {
        t = totient[i];
        if(revtot[t] == 0) revtot[t] = i;
        else
        {
            if(revtot[t] > i) revtot[t] = i;
        }
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
        cout<<((revtot[num])? revtot[num] : -1)<<endl;
    }

    return 0;
}

