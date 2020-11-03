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

ull binomialCoeff(int n, int k)
{
    ull res = 1;
    k = min(k, n - k);
    for(int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;
        cout<<(ull) binomialCoeff(n - 1, k - 1)<<endl;
    }

    return 0;
}


