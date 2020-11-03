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

void factorize(ll n, vector<ll> & factor, vector<ll> & account)
{
    int no = 0;
    while(!(n & 1))
    {
        if(factor.empty() || factor[no] != 2)
        {
            factor.push_back(2);
            account.push_back(1);
        }
        else
        {
            account[no]++;
        }
        n /= 2;
    }
    ll nsqrt = sqrt(n);
    for(ll i = 3; i <= nsqrt; i+= 2)
    {
        while(n % i == 0)
        {
            if(factor.empty() || factor[no] != i)
            {
                if(factor.size() != 0) no++;
                factor.push_back(i);
                account.push_back(1);
            }
            else
            {
                account[no]++;
            }
            n /= i;
        }
    }

    if(n > 1)
    {
        factor.push_back(n);
        account.push_back(1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll num;
    cin>>num;

    while(num)
    {
        vector<ll> factor, account;
        factorize(num, factor, account);

        for(int i = 0; i < factor.size(); i++)
        {
            cout<<factor[i]<<"^"<<account[i]<<" ";
        }
        cout<<endl;

        cin>>num;
    }

    return 0;
}

