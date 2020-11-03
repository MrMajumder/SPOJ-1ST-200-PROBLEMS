#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

void multiply(vector<int> &val, int x)
{
    ll carry = 0;

    for(int i = 0; i < val.size(); i++)
    {
        ll product = (x * val[i]) + carry;
        val[i] = product % 10;
        carry = floor(product / 10);
    }

    while(carry)
    {
        val.push_back(carry % 10);
        carry /= 10;
    }
}

void fact(int x)
{
    if(x == 0 || x == 1)
    {
        cout<<1<<endl;
        return;
    }

    vector<int> val;
    val.push_back(1);

    for(int i = 2; i <= x; i++)
    {
        multiply(val, i);
    }

    for(int i = val.size() - 1; i >= 0; i--)
    {
        cout<<val[i];
    }
    cout<<endl;
}


int main()
{
    int n, x;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>x;
        fact(x);
    }

    return 0;
}

