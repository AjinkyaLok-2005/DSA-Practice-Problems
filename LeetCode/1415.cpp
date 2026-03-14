#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    void solve(int n, string& curr, int & count, int & k, string & result)
    {
        if(curr.length() == n)
        {
            // result.push_back(curr);
            count++;
            if(count == k)
                result = curr;

            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++)
        {
            if(!curr.empty() && curr.back() == ch)
                continue;
            
            curr.push_back(ch);

            solve(n, curr, count, k, result);

            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";

        // vector<string> result;
        string result = "";

        int count = 0;

        solve(n, curr, count, k, result);

        // if(result.size() < k)
        //     return "";

        // return result[k-1];
        return result;
    }
};

int main()
{
    int n, k;
    cout << "Enter n and k: ";
    cin >> n >> k;

    Solution obj;
    string ans = obj.getHappyString(n, k);

    if(ans == "")
        cout << "No such happy string exists" << endl;
    else
        cout << "Happy String: " << ans << endl;

    return 0;
}