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
        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin>> arr[i];
        }

        stack <int> s;

        int focus = 1;

        for(int i = 0; i < n; i++)
        {
            if(focus == arr[i])
            {
                focus++;
            }
            else if(!s.empty() && focus == s.top())
            {
                s.pop();
                focus++;
                i--;
            }
            else
            {
                s.push(arr[i]);
            }
        }
        while(!s.empty() && s.top() == focus)
        {
            s.pop();
            focus++;
        }
        if(focus == n + 1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;

        cin>>n;
    }

    return 0;
}

