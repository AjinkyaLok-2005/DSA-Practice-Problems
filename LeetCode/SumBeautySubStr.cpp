#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;

        for(int i = 0; i < n; i++)
        {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;

                int maxi = INT_MIN;
                int mini = INT_MAX;

                for(int k = 0; k < 26; k++)
                {
                    if(freq[k] > 0)
                    {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                } 

                totalBeauty += (maxi - mini);
            }
        }

        return totalBeauty;
    }
};

int main()
{
    Solution s;
    string str = "aabcb";
    int ans = s.beautySum(str);
    cout << ans << endl;

    return 0;
}