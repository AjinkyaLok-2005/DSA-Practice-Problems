#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
void solve(string digits, string output, int index, vector<string> & ans, string mapping[])
{
    //base case
    if(index >= digits.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0'; 
    //THIS IS B/C digits[index] WILL GIVE A char TO CONVERT IT INTO INT
    string value = mapping[number];

    for(int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digits, output, index+1, ans, mapping);
        output.pop_back();
    }
}

public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        string output;
        if(digits.length() == 0)
        {
            return ans;
        }
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, index, ans, mapping);
        return ans;  
    }
};


int main() {
    Solution solution;
    string digits;

    cout << "Enter digits: ";
    cin >> digits;

    vector<string> combinations = solution.letterCombinations(digits);

    cout << "Letter combinations are:" << endl;
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
