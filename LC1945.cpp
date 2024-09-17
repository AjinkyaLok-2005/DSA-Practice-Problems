#include<iostream>
using namespace std;

int getLucky(string s, int k) 
{
        string convertString = "";
        for(int i = 0; i < s.length(); i++)
        {
            convertString+=to_string(s[i]-'a'+1); 
        }
        int sum = 0;
        while(k--)
        {
            sum = 0;
            for(int i = 0; i < convertString.length(); i++)
            {
                sum += (convertString[i]- '0');
            }
            convertString = to_string(sum);
        }
        return sum;
        
    }

int main()
{
    string s = "zbax";
    int k = 2;

    cout << getLucky(s, k);

    return 0;
}