#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;


string bigsubtract(string num1, string num2)
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
        int x = (num1[i + diff] - '0') - (num2[i] - '0') - carry;
        if(x < 0)
        {
            x += 10;
            carry = 1;
        }
        else carry = 0;
        ans += x + '0';
    }
    for(int i = diff - 1; i >= 0; i--)
    {
        int x = (num1[i] - '0') - carry;
        if(i > 0 || x > 0)
        {
            ans += x + '0';
        }
        carry = 0;
    }
    reverse(ans.begin(), ans.end());
    string arr;
    int i = 0;
    while(ans[i] == '0') i++;
    for(; i < ans.size(); i++)
    {
        arr += ans[i];
    }
    return arr;
}

string bigdivide(string num, int divisor)
{
    string ans = "";
    int idx = 0;
    int temp = num[idx] - '0';
    while(temp < divisor) temp = (temp * 10) + num[++idx] - '0';

    while(num.size() > idx)
    {
        ans+= (temp / divisor) + '0';
        temp = (temp % divisor)* 10 + num[++idx] -'0';
    }

    return ans;
}

string removeinitialzeroes ( string &s)
{
    int len = s.length() - 1;
    int what = 0;

    for(int i = 0; i < len; i++)
    {
        if(s[i] == '0') what++;
        else break;
    }
    s.erase(0, what);
    return s;
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

int main()
{
    ll t;
    cin>>t;
    int arr[] = {942, 192, 442, 692};
    while(t--)
    {
        string s;
        cin>>s;
        cout<<bigdivide(bigsubtract(s, "1"), 4);
        cout<<arr[bigmod(s, 4)]<<endl;
    }
    return 0;
}

