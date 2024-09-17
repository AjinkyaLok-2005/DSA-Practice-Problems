#include<iostream>
#include<vector>
using namespace std;

vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> & arr2, int m)
{    
    vector<int> ans;
    int i = 0, j = 0;
    while(i < n && j < m)
    {
        if(arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {1,2,2,2,3,4};
    int n = arr1.size();
    vector<int> arr2 = {2,2,3,3};
    int m = arr2.size();
    
    vector<int> intersection = findArrayIntersection(arr1, n , arr2, m);
    // findArrayIntersection(arr1, n , arr2, m);

       // Print the intersection
    for (int element : intersection) {
        cout << element << " ";
    }
    cout << endl;


    return 0;
}