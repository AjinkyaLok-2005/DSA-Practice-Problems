#include<iostream>
#include<vector>

using namespace std;

bool lemonadeChange(vector<int>& bills) 
    {
        // bool ans = true;
        vector<int> a(3, 0);
        for(int i = 0; i < bills.size(); i++)
        {
            if(bills[i] == 5)
            {
                ++a[0];
            }
            else if(bills[i] == 10)
            {
                if(a[0]>0)
                {
                    --a[0], ++a[1];
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(a[1]>0 && a[0]>0)
                {
                    --a[1], --a[0], ++a[2];
                }
                else if(a[0] >= 3)
                {
                    a[0] -= 3; ++a[2]; 
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }

int main()
{
    vector<int> bills = {5, 5, 10, 10, 20};
    bool ans = lemonadeChange(bills);
    cout << ans;
    return 0;
}