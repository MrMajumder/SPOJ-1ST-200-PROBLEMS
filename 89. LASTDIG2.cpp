#include<bits/stdc++.h>
using namespace std;
int ans[][4] = {0, 0, 0, 0, 1, 1, 1, 1, 6, 2, 4, 8, 1, 3, 9, 7, 6, 4, 6, 4, 5, 5, 5, 5, 6, 6, 6, 6, 1, 7, 9, 3, 6, 8, 4, 2, 1, 9, 1, 9};
int bigmod(string s, int n)
{
    int res = 0, len = s.length();
    for(int i = 0; i < len; i++) res = ((res * 10) + s[i] - '0') % n;
    return res;
}
int main()
{
    int t; string a, b; cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(b == "0" && a != "0")
        {
            cout<<1<<endl;
            continue;
        }
        int alen = a.size(), anum = (int) (a[alen - 1] - '0'), bnum = bigmod(b, 4);
        cout<<ans[anum][bnum]<<endl;
    }
    return 0;
}
