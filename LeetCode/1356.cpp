#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    
    // int countOneBits(int num)  
    // {
    //     int count = 0;

    //     while(num != 0)
    //     {
    //         count += num & 1;
    //         num >>= 1;
    //     }

    //     return count;
    // }

    vector<int> sortByBits(vector<int>& arr) {
        
        auto lambda = [&](int &a, int &b)
        {
        //     int count_a = countOneBits(a); //T.C. => logbase2(num) 
        //     int count_b = countOneBits(b);

            int count_a = __builtin_popcount(a); //T.C. => O(1)
            int count_b = __builtin_popcount(b);

            if(count_a == count_b)
                return a < b; 

            return count_a < count_b;
        };

        sort(arr.begin(), arr.end(), lambda);

        return arr;
    }
};

int main()
{
    vector<int> arr = {0,1,2,3,4,5,6,7,8};

    Solution obj;
    vector<int> result = obj.sortByBits(arr);

    cout << "Sorted array based on the number of 1's in their binary representation: ";
    for(int num : result)
        cout << num << " ";
    cout << endl;

    return 0;
}
