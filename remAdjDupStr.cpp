#include<iostream>
using namespace std;

string removeDuplicates(string s)
{
    // int i = 0;
    // while(i < s.length())
    // {
    //     // if s[i] == s[i+1] and i+1 != '\0' then
    //     if(s[i] == s[i+1] && i+1 != '\0')
    //     {
    //         s.erase(i, 2);
    //         i = 0;
    //     }
    //     else
    //     {
    //         i++;
    //     }
        
    // }
    // return s;
    int i = 0;
    string temp = "";
    while(i < s.length())
    {
        //if temp is empty or s[i] is not equal to temp.back() then....
        if(temp.empty() || s[i] != temp.back())
        {
            temp.push_back(s[i]);        
        }
        else
        {
            temp.pop_back();
        }
        i++;
        
    }
    return temp;
}

int main()
{
    string str = "azxxzy";

    cout << removeDuplicates(str) << endl;

    return 0;
}