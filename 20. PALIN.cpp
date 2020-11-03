#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int len = s.length();
        int removetill = 0;
        for(int i = 0; i < len - 1; i++)
        {
            if(s[i] == '0') removetill++;
            else break;
        }
        s.erase(0, removetill);
        len = s.length();
        int mid = len / 2;
        int before = mid - 1, after = mid;

        if(len % 2)
        {
            after++;
        }

        bool isLeftGreater = true;
        int temp = 0;

        for(int i = 0; i < mid; i++)
        {
            if(s[before - i] > s[after + i])
            {
                isLeftGreater = true;
                break;
            }
            else if(s[before - i] == s[after + i])
            {
                temp++;
            }
            else
            {
                isLeftGreater = false;
                break;
            }
        }

        if(temp == mid) isLeftGreater = false;

        temp = 0;
        bool sp = 0;
        if(!isLeftGreater)
        {
            temp = before;
            if(len % 2)
            {
                temp++;
            }

            int carry = 0;
            while((s[temp])== '9' && (temp >= 0))
            {
                s[temp] = '0';
                carry = 1;
                temp--;
            }

            if(temp >= 0 && carry)
            {
                s[temp] = (s[temp] - '0') + 1 + '0';
            }
            else if(temp < 0 && carry)
            {
                s.insert(0, "1");
                sp = true;
            }

            if(!carry)
            {
                if(len%2)
                {
                    s[mid] = (s[mid] - '0') + 1 + '0';
                }
                else
                {
                    s[mid - 1] = (s[mid - 1] - '0') + 1 + '0';
                }
            }
        }

        for(int i = 0; i <= (mid - 1 + sp); i++)
        {
            cout<<s[i];
        }
        if(len % 2)
        {
            if(len == 1 && sp)
            {
                cout<<1;
            }
            else
            {
                cout<<s[mid + sp];
            }
        }
        for(int i = before; i >= 0; i--)
        {
            cout<<s[i];
        }
        cout<<endl;
    }

    return 0;
}
