#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string ans = "";

        for(int i = 0; i < words.size(); i++)
        {
            int sum = 0;

            for(char ch : words[i])
            {
                int index = ch - 'a';
                sum = sum + weights[index];
            }

            int result = sum % 26;
            int t = 26 - result - 1;
            char ch = 'a' + t;
            ans.push_back(ch);
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter the number of words: ";
    cin >> n;

    vector<string> words(n);
    vector<int> weights(26);

    cout << "Enter the words: " << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    cout << "Enter the weights for each character (a to z): " << endl;
    for(int i = 0; i < 26; i++)
    {
        cin >> weights[i];
    }

    Solution obj;
    string result = obj.mapWordWeights(words, weights);

    cout << "Mapped String: " << result << endl;

    return 0;
}