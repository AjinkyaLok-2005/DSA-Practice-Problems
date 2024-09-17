#include<iostream>
#include<vector>
using namespace std;

int  findDuplicate(vector<int> &arr)
{
    int ans = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    for(int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }

    return ans;
}

int main()
{
    int arr[5] = {4, 2, 1, 3, 1};

    vector<int> vec(arr, arr + 5);

    cout << "Duplicate element in the array is " << findDuplicate(vec) << endl;

    return 0;
}
