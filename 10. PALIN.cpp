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
    while(t--)
    {
        string s;
        cin>>s;
        int len = s.length();
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
            if(s[before -i] == s[after + i])
            {
                temp++;
            }
            if(s[before -i] < s[after + i])
            {
                isLeftGreater = false;
                break;
            }
        }
        if(temp == mid) isLeftGreater = false;

        temp = 0;
        if(!isLeftGreater)
        {
            if(len % 2)
            {
                before++;
            }
            temp = before;
            int carry = 0
            while((s[temp] = (s[temp] - '0' + carry) + '0')== '9')
            {
                s[temp] == '0';
                carry = 1;
            }
        }

        if(len % 2)
        {
            if(s[mid] > s[mid + 2])
            {
                for(int i = 0; i < mid + 2; i++)
                {
                    cout<<s[i];
                }
                reverse(s, s + mid + 1);
                for(int i = 0; i < mid + 1; i++)
                {
                    cout<<s[i];
                }
                cout<<endl;
                continue;
            }
            else
            {

            }
        }
    }

    return 0;
}
