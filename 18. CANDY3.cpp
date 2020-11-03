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
    int testcase;
    cin>>testcase;
    ll stud;
    while(testcase)
    {
        cin>>stud;
        ll hold, sum = 0;
        for(int i = 0; i < stud; i++)
        {
            cin>>hold;
            sum += hold;
            sum %= stud;
        }
        if(!(sum % stud)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        testcase--;
    }

    return 0;
}

