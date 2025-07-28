#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthSmallest(vector<int> & arr, int k)
{
    int l = arr.size();

    priority_queue<int> pq;

    for(int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for(int j = k; j < l; j++)
    {
        if(arr[j] < pq.top())
        {
            pq.pop();
            pq.push(arr[j]);
        }
    }

    int ans = pq.top();

    return ans;
}

int main()
{

    vector<int> arr = {7, 10, 4, 3, 20, 15};
    // vector<int> arr = {2, 3, 1, 20, 15};

    int k = 3;
    int ans = kthSmallest(arr, k);

    cout << k << "th Smallest element in the given array is " << ans << endl;

    return 0;
}