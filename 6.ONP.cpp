#include<bits/stdc++.h>
using namespace std;

#define max2(a, b) (((a) > (b)) ? (a) : (b))
#define min2(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

const int INF = 0x3f3f3f3f;

typedef long long ll;

bool isOperator(char c)
{
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') return true;
    return false;
}

int priority(char c)
{
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c == '+' || c == '-') return 1;
}

void PrintPostOrder(string arr)
{
    stack<char> st;

    for(int i = 0; i < arr.length(); i++)
    {
        char c = arr[i];
        if(c == '(')
        {
            st.push(c);
        }
        else if(isOperator(c))
        {
            while(priority(c) <= priority(st.top()) && st.top() != '(')
            {
                // !st.empty() && priority(c) <= priority(st.top()) && st.top() != '('
                cout<<st.top();
                st.pop();
            }
            st.push(c);
        }
        else if(c == ')')
        {
            while(st.top() != '(')
            {
                cout<<st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            cout<<c;
        }
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    string str;

    for(int i = 0; i < n; i++)
    {
        cin>>str;
        PrintPostOrder(str);
        cin.clear();
    }

    return 0;
}

