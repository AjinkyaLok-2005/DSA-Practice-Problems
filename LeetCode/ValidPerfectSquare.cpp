#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {

        bool ans = false;

        for(long long int i = 1; i*i <= num; i++)
        {
            if(i*i == num)
                ans = true;
        }

        return ans;
    }
};

int main()
{
    int num;
    cin >> num;

    Solution obj;
    cout << obj.isPerfectSquare(num);

    return 0;
}
