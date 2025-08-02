#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < arr.size(); j++)
        {
            sum += arr[j];
            if(pq.size() < k)
            {
                pq.push(sum);
            }
            else
            {
                if(pq.top() < sum)
                {
                    pq.pop();
                    pq.push(sum);
                }
            }
        }
    }

    return pq.top();
}

int main()
{
    vector<int> arr = {5, 4, -8, 6};

    int k = 10;

    int ans = getKthLargest(arr, k);

    cout << "The Kth Largest Sum Subarray from the given array is: " << ans << endl;

    return 0;
}