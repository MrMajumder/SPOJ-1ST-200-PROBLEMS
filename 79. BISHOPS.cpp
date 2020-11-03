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

string bigsubtract(string num1, string num2)
{
    string ans = "";
    int len1 = num1.size();
    int len2 = num2.size();
    bool yes = (len1 >= len2)? true: false;
    if(len1 == len2)
    {
        int a = len1;
        while(a >= 0)
        {
            if(num1[a] > num2[a])
            {
                yes = true;
                break;
            }
            else if(num1[a] < num2[a])
            {
                yes = false;
                break;
            }
            a--;
        }
    }

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
        if(x < 0)
        {
            x += 10;
            carry = 1;
        }
        else carry = 0;
        ans += x + '0';
    }
    reverse(ans.begin(), ans.end());
    string arr;
    int i = 0;
    while(ans[i] == '0') i++;
    if(i == ans.size()) i--;
    for(; i < ans.size(); i++)
    {
        arr += ans[i];
    }
    return arr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string num;
    while(1)
    {
        getline(cin, num);
        if(num == "") return 0;
        if(num == "1")
        {
            cout<<num<<endl;
            continue;
        }
        num = bigmultiply(num, 2);
        num = bigsubtract(num, "2");
        cout<<num<<endl;
    }


    return 0;
}

