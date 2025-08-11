// Your task is to return the number of elements common to ‘ARR1’ and ‘ARR2’ and the number of elements in the union of ‘ARR1’ and ‘ARR2’.

#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

pair <int, int> findSimilarity(vector<int> arr1, vector<int> arr2) 
{
	// Write Your Code here.        
	unordered_set<int> s1(arr1.begin(), arr1.end());
	unordered_set<int> s2(arr2.begin(), arr2.end());

	int comm = 0;
	for(int x : s1)
	{
		if (s2.count(x)) comm++;
	}

	int uni = s1.size() + s2.size() - comm;

	return {comm, uni};
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 4, 6, 8};

    pair<int, int> ans = findSimilarity(arr1, arr2);

    cout << "Common Elements: " << ans.first << endl;
    cout << "Union Elements: " << ans.second << endl;

    return 0;
}