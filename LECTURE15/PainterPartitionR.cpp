#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> arr, int n, int k, int mid)
{
    int painterCount = 1;
    int time = 0;

    for(int i = 0; i < n; i++)
    {
        if(time + arr[i] <= mid)
        {
            time += arr[i];
        }
        else
        {
            painterCount++;
            if(painterCount > k || arr[i] > mid)
            {
                return false;
            }
            time = arr[i];
        }
    }
    return true;
}

int painterPartition(vector<int> arr, int s, int e, int n, int k, int ans)
{
    //base case
    if(s > e)
    {
        return ans;
    }

    int mid = s + (e-s)/2;

    //Recursive Call
    if(isPossible(arr, n, k, mid))
    {
        ans = mid;
        return painterPartition(arr, s, mid-1, n, k, ans);
    }
    else
    {
        return painterPartition(arr, mid+1, e, n, k, ans);
    }
}

int ans(vector<int> arr, int n, int k)
{
    int s = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int ans = -1;

    int result = painterPartition(arr, s, e, n, k, ans);

    return result;

}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();
    int k = 2;

    int result = ans(arr, n, k);

    cout << "The area of the minimum time to complete this work of painting is " << result << endl;

    return 0;
}