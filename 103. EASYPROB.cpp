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

void power(int n)
{
    int temp = n;
    if(n <= 3)
    {
        if(n == 3) cout<<"2+2(0)";
        if(n == 2) cout<<"2";
        if(n == 1) cout<<"2(0)";
        return;
    }
    int up = 0;
    while(temp)
    {
        up++;
        temp /= 2;
    }
    int a = pow(2, up - 1);
    cout<<"2(";
    power(up - 1);
    cout<<")";
    if(n - a)
    {
        cout<<"+";
        power(n - a);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {137, 1315, 73, 136, 255, 1384, 16385};
    for(int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<"=";
        power(arr[i]);
        cout<<endl;
    }

    return 0;
}


