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

string word, text;
int wlen, tlen;

void createAux(int aux[])
{
    int i = 1, m = 0;
    while(i < wlen)
    {
        if(word[m] == word[i])
        {
            aux[i++] = ++m;
        }
        else if(word[m] != word[i] && m != 0) m = aux[m - 1];
        else
        {
            aux[i++] = 0;
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while(cin>>wlen)
    {
        cin>>word;
        cin>>text;
        tlen = text.size();

        int aux[wlen] = {0};
        createAux(aux);


        int i, j;
        i = j = 0;

        while(j < tlen)
        {
            if(word[i] != text[j])
            {
                if(i == 0) j++;
                else i = aux[i - 1];
            }
            else
            {
                i++, j++;
                if(i == wlen)
                {
                    cout<<j - i<<endl;
                    i = aux[i - 1];
                }
            }
        }
        cout<<endl;
    }


    return 0;
}

