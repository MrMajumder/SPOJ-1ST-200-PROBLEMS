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

string bigadd(string num1, string num2)
{
    string ans = "";
    int len1 = num1.size();
    int len2 = num2.size();
    bool yes = (len1 >= len2)? true: false;

    if(!yes)
    {
        swap(num1, num2);
        swap(len1, len2);
    }

    int carry = 0;

    int diff = len1 - len2;
    for(int i = len2 - 1; i >= 0; i--)
    {
        int x = (num1[i + diff] - '0') + (num2[i] - '0') + carry;
        ans+= (x % 10) + '0';
        carry = x / 10;
    }
    for(int i = diff - 1; i >= 0; i--)
    {
        int x = (num1[i] - '0') + carry;
        ans+= (x % 10) + '0';
        carry = x / 10;
    }

    while(carry)
    {
        ans+= (carry % 10) + '0';
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string bigmultiply(string val, int x)
{
    string ans = "";
    int len = val.size();
    ll carry = 0;

    for(int i = len - 1; i >= 0; i--)
    {
        ll product = (x * (val[i] - '0')) + carry;
        ans += (product % 10) + '0';
        carry = floor(product / 10);
    }

    while(carry)
    {
        ans += (carry % 10) + '0';
        carry /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string bigdivide(string num, int divisor)
{
    string ans = "";
    int idx = 0;
    int temp = num[idx] - '0';
    while(temp < divisor) temp = (temp * 10) + num[++idx] - '0';

    while(num.size() > idx)
    {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor)* 10 + num[++idx] -'0';
    }

    return ans;
}


int bigmod(string s, int n)
{
    int res = 0;
    int len = s.length();

    for(int i = 0; i < len; i++)
    {
        res = ((res * 10) + s[i] - '0') % n;
    }
    return res;
}

string bigbigmultiply(string val1, string val2)
{
    string ans;
    if(val1 == "0" || val2 == "0") return "0";
    int len = val2.size();
    for(int i = 1; i < len; i++)
    {
        string temp = bigmultiply(val1, int(val2[i] - '0'));
        ans = bigmultiply(ans, 10);
        ans = bigadd(ans, temp);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        string s1, s2;
        cin>>s1>>s2;

        //cout<<s1<<s2<<endl;;
        string s = bigbigmultiply(s1, s2);
        cout<<s<<endl;
    }

    return 0;
}

