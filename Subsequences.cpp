#include<iostream>
#include<vector>
using namespace std;

void solve(string str, string output, int index, vector<string> & ans)
{
    //base case
    if(index >= str.length())
    {
        if(output.length() > 0) //This for loop is for excluding the empty string
        {
            ans.push_back(output);
        }
        return;
    }

    //exclude
    solve(str, output, index+1, ans);

    //include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;
    solve(str, output, index, ans);
    return ans;
}

int main()
{
    string str = "abc"; // Input string

    // Get all subsequences
    vector<string> result = subsequences(str);

    // Print the subsequences
    cout << "Subsequences are:" << endl;
    for (int i = 0; i < result.size(); i++)
    {
        cout << "\"" << result[i] << "\"" << endl;
    }

    return 0;
}

