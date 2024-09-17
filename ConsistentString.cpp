#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        unordered_set<char> s;
        for(auto x: allowed)
        {
            s.insert(x);
        }   

        int count = 0;

        for(auto word: words)
        {
            bool status = true;
            for(int i = 0; i < word.size(); i++)
            {
                if(s.find(word[i]) == s.end())
                {
                    status = false;
                    break;
                }
            }
            if(status)
            {
                count++;
            }
        }
        return count;
    }

int main()
{
    string allowed = "ab";
    vector<string> words = {"ad","bd","aaab","baa","badab"};

    int answer = countConsistentStrings(allowed, words);
    cout << answer;

    return 0;
}
