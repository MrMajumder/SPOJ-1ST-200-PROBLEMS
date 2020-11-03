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

    string s;
    while(cin>>s)
    {
        bool java, first = true, error = false;
        string ans;
        int ai= 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '_')
            {
                if(first)
                {
                    if(i == 0)
                    {
                        error = true;
                        break;
                    }
                    java = first = false;
                }
                if(java || (i == s.length() - 1) || (s[i + 1] >= 'A' && s[i + 1] <= 'Z') || s[i + 1] == '_')
                {
                    error = true;
                    break;
                }
                else
                {
                    ans.push_back(s[++i] - 'a' + 'A');
                    continue;
                }
            }
            else if(s[i] >= 'A' && s[i] <= 'Z')
            {
                if(first)
                {
                    if(i == 0)
                    {
                        error = true;
                        break;
                    }
                    java = !(first = false);
                }
                if(!java)
                {
                    error = true;
                    break;
                }
                else
                {
                    ans.push_back('_');
                    ans.push_back(s[i] - 'A' + 'a');
                    continue;
                }

            }

            ans.push_back(s[i]);
        }

        if(error) cout<<"Error!"<<endl;
        else cout<<ans<<endl;
    }

    return 0;
}

