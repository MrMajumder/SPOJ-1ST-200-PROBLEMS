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
vector<int> totient(MAX);
vector<int> perm(MAX);

void ETF(int n)
{
    for(int i = 1; i < n; i++) totient[i] = i;

    for(int i = 2; i < n; i++)
    {
        if(totient[i] == i)
        {
            for(int j = i; j < n; j += i) totient[j] -= (totient[j] / i);
        }
    }
}

bool permutation(int a, int b)
{
    vector<int> c(10, 0);
    while(a)
    {
        c[a % 10]++;
        a /= 10;
    }

    while(b)
    {
        c[b % 10]--;
        b /= 10;
    }

    for(int i = 0; i < 10; i++)
    {
        if(c[i]) return false;
    }
    return true;
}

void precalc(int n)
{
    perm[21] = 21;
    pair<ll, ll> temp = {21, totient[21]};

    for(int i = 22; i < n; i++)
    {
        if(permutation(i, totient[i]))
        {
            if(i * temp.second <= temp.first * totient[i])
            {
                temp = {i, totient[i]};
            }
        }
        perm[i] = temp.first;
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
        num--;
        if(num < 21) cout<<"No solution."<<ENDL;
        else cout<<perm[num]<<ENDL;
    }

    return 0;
}
