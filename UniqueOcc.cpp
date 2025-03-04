#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


bool uniqueOccurrences(vector<int>& arr) {
    vector<int> ans;
    int size = arr.size();
    sort(arr.begin(), arr.end());
    int i=0;
    while(i<size){
        int count =1;
        for(int j = i+1; j<size; j++){
            if(arr[i] == arr[j]){
                count++;
            }
            else{
                break;
            }
        }
        ans.push_back(count);
        i=i+count;
    }
    size = ans.size();
    sort(ans.begin(), ans.end());
    for(int i=0; i<size-1;i++){
        if(ans[i]==ans[i+1]){
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr;
    arr = {-3,0,1,-3,1,1,1,-3,10,0};

    uniqueOccurrences(arr);
    return 0;
}