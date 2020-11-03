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
const int MOD = 1000000007; //9digits
const double EPS = 1e-8;
const long double EULER = 2.71828182845904523536;   //20digits
const long double PI = 3.14159265358979323846;      //20digits
//float = 7digits, double = 15digits, long double = 21 digits precision

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

class Order{
public:
    int start, duration, price;
    //Order(int s, int d, int p) { start = s, duration = s, price = p;}
    bool operator < (const Order& a)
    {
        return (start + duration) < (a.start + a.duration);
    }
} orders[10002];

int binsearch(int val, int start, int fin)
{
    if(start == fin) return start;
    int mid = ceil((start + fin) / 2.0);
    //cout<<start<<" "<<mid<<" "<<fin<<endl;
    Order & temp = orders[mid];
    if(temp.start + temp.duration <= val) return binsearch(val, mid, fin);
    else return binsearch(val, start, mid - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        orders[0].start = orders[0].duration = orders[0].price = 0;
        for(int i = 1; i <= n; i++) cin>>orders[i].start>>orders[i].duration>>orders[i].price;

        sort(orders, orders + n + 1);
        vector<ll> dp(n + 1, 0);
        dp[1] = orders[1].price;

        for(int i = 2; i <= n; i++)
        {
            int idx = binsearch(orders[i].start, 0, i - 1);
            //cout<<"ekhane mara khelo"<<endl;
            if(idx) dp[i] = max(dp[i - 1], dp[idx] + orders[i].price);
            else dp[i] = max(dp[i - 1], (ll)orders[i].price);
        }
        cout<<dp[n]<<endl;
    }

    return 0;
}

