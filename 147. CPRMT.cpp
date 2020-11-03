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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    while(cin>>s1)
    {
        cin>>s2;
        vector<int> letter1(26, 0), letter2(26, 0);
        int l1 = s1.size();
        int l2 = s2.size();

        for(int i = 0; i < l1; i++) letter1[s1[i] - 'a']++;
        for(int i = 0; i < l2; i++) letter2[s2[i] - 'a']++;
        vector<char> ans;
        for(int i = 0; i < 26; i++)
        {
            while(letter1[i] > 0 && letter2[i] > 0)
            {
                ans.push_back('a' + i);
                letter1[i] --;
                letter2[i] --;
            }
        }
        string a(ans.begin(), ans.end());
        cout<<a<<endl;
    }

    return 0;
}

