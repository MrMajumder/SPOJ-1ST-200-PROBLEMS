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
    string s, dummy;
    getline(cin, dummy);
    while(t--)
    {
        getline(cin, dummy);
        getline(cin, s);
        int n1 = 0, n2 = 0, n3 = 0;
        bool prob1, prob2, prob3;
        prob1 = prob2 = prob3 = false;
        int c = 0;

        while(s[c] != '+')
        {
            if(s[c] == ' ')
            {
                c++;
                continue;
            }
            else if(s[c] >= '0' && s[c]<= '9')
            {
                n1 = (n1 * 10) + s[c] - '0';
            }
            else
            {
                c += 6;
                prob1 = true;
            }
            c++;
        }
        c++;
        while(s[c] != '=')
        {
            if(s[c] == ' ')
            {
                c++;
                continue;
            }
            else if(s[c] >= '0' && s[c]<= '9')
            {
                n2 = (n2 * 10) + s[c] - '0';
            }
            else
            {
                c += 6;
                prob2 = true;
            }
            c++;
        }
        c++;
        while(s[c] != '\0')
        {
            if(s[c] == ' ')
            {
                c++;
                continue;
            }
            else if(s[c] >= '0' && s[c] <= '9')
            {
                n3 = (n3 * 10) + s[c] - '0';
            }
            else
            {
                c += 6;
                prob3 = true;
            }
            c++;
        }

        if(prob1) n1 = n3 - n2;
        if(prob2) n2 = n3 - n1;
        if(prob3) n3 = n1 + n2;

        cout<<n1<<" + "<<n2<<" = "<<n3<<endl;

    }


    return 0;
}

