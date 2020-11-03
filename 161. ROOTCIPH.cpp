#include<bits/stdc++.h>
using namespace std;

//defined my own datatypes
typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ull a, b, c;
        scanf("%lld%lld%lld", &a, &b, &c);
        cout<<(a * a) - (2 * b)<<endl;
    }

    return 0;
}

