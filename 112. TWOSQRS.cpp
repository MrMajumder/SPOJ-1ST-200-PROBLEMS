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

vector<ll> sqr;
void precompute()
{
    ll temp;
    ll i = 0;
    while((temp = i * i) <= 1e12)
    {
        sqr.push_back(temp);
        i++;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll i = 0, j = sqrt(n);

        while(i <= j)
        {
            ll x = sqr[i] + sqr[j];
            if(x == n) break;
            else if(x < n) i++;
            else j--;
        }
        if(i <= j) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }

    return 0;
}

