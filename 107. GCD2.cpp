#include<bits/stdc++.h>
using namespace std;
int bigmod(string s, int n)
{
    int res = 0, len = s.length();
    for(int i = 0; i < len; i++)
    {
        res = ((res * 10) + s[i] - '0') % n;
    }
    return res;
}
int gcd(int a, int b)
{
    if(b > a) swap(a, b);
    return (b) ? gcd(b, a % b) : a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int a;
        string b;
        cin>>a>>b;
        if(a == 0) cout<<b<<endl;
        else cout<<gcd(a, bigmod(b, a))<<endl;
    }

    return 0;
}
