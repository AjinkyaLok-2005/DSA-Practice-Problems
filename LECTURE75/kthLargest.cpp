#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthLargest(vector<int> & nums, int k)
{
    int l = nums.size();

    priority_queue<int> pq;

    for(int i = 0; i < l; i++)
    {
        pq.push(nums[i]);
    }
    while(k > 1 && !pq.empty())
    {
        pq.pop();
        k--;
    }
    return pq.top();
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};

    int k = 2;
    int ans = kthLargest(arr, k);

    cout << k << "th largest element in the given array is " << ans << endl;

    return 0;
}