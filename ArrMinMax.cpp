#include<iostream>
#include<climits>
using namespace std;


int getMax(int num[], int n)
{
    int MAX = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        MAX = max(MAX, num[i]);  //this is inbuilt function for max
        // if(num[i] > max)
        // {
        //     max = num[i];
        // }
    }

    // return max;
    return MAX;
}

int getMin(int num[], int n)
{
    int MINI = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        MINI = min(MINI,num[i]); //this is inbuilt function for min
        // if(num[i] < min)
        // {
        //     min = num[i];
        // }
    }

    // return min;
    return MINI;
}


int main() {

    int size;
    cin >> size;

    int num[100];

    for(int i = 0; i < size; i++)
    {
        cin >> num[i];
    }


    cout << "Maximum value is " << getMax(num, size) << endl;
    cout << "Minimum value is " << getMin(num, size) << endl;
    return 0;
}

