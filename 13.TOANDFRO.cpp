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
    int n;
    cin>>n;

    while(n)
    {
        string s;
        cin>>s;

        int len = s.length();
        int row = len / n;
        int col = n;
        char arr[row][col];
        bool flag = true;
        int holder = 0;
        for(int i = 0; i < row; i++)
        {
            if(flag)
            {
                for(int j = 0; j < col; j++)
                {
                    arr[i][j] = s[holder];
                    holder++;
                }
                flag = false;
            }
            else
            {
                for(int j = col - 1; j >= 0; j--)
                {
                    arr[i][j] = s[holder];
                    holder++;
                }
                flag = true;
            }
        }

        for(int j = 0; j < col; j++)
        {
            for(int i = 0; i < row; i++)
            {
                cout<<arr[i][j];
            }
        }
        cout<<endl;
        cin>>n;
    }

    return 0;
}

