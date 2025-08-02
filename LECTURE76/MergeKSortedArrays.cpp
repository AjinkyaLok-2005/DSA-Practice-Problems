#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void merge(vector<int> & nums1, int m, vector<int> & nums2, int n)
{
    vector<int> ans;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < m; i++)
    {
        ans.push_back(nums1[i]);
    }

    for(int j = 0; j < n; j++)
    {
        ans.push_back(nums2[j]);
    }

    for(int i = 0; i < ans.size(); i++)
    {
        pq.push(ans[i]);
    }

    for(int i = 0; i < ans.size(); i++)
    {
        nums1.erase(nums1.begin());
        nums1.push_back(pq.top());
        pq.pop();
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    
    vector<int> nums2 = {2, 5, 6};
    int n = 3;

    
    cout << "The array after merging the give arrays is: " <<endl;
    merge(nums1, m, nums2, n);
    
    for(int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << " ";
    }
    cout << endl;
    return 0;
}
