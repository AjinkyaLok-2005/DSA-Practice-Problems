#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    queue<char> q;
    string ans = "";

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];

        // Increment frequency of character
        count[ch]++;

        // Push character into queue
        q.push(ch);

        // Check the first non-repeating character
        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop(); // Remove repeating characters
            }
            else
            {
                ans.push_back(q.front()); // Found first non-repeating character
                break;
            }
        }

        // If queue is empty, no non-repeating character exists
        if (q.empty())
        {
            ans.push_back('#');
        }
    }
    return ans;
}

int main()
{
    string A = "aabc";
    cout << "First non-repeating characters: " << FirstNonRepeating(A) << endl;

    return 0;
}
