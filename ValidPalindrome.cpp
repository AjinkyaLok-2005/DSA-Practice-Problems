#include<iostream>
using namespace std;

bool valid(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return 1;
    }
    return 0;
}


char toLowerCase(char ch)
{
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool chechPalindrome(string a)
{
    int s = 0;
    int e = a.length() - 1;

    while(s <= e)
    {
        if(a[s] != a[e])
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
        return 1;
    }
}
int main()
{
    string s = "A man, a plan, a canal: Panama";
    //faltu characters remove
    string temp = "";
    for(int i = 0; i < s.length(); i++)
    {
        if(valid(s[i]))
        {
            temp.push_back(s[i]);
        }
    }

    //lower case me kardo
    for(int i = 0; i < temp.length(); i++)
    {
        temp[i] = toLowerCase(temp[i]); 
    }

    bool ans = chechPalindrome(temp);
    cout << ans;
    
    return 0;
}