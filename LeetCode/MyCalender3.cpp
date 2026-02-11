#include<iostream>
#include<map>
using namespace std;

class MyCalendarThree {
public:
    map<int, int>events;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        events[startTime] += 1;
        events[endTime] -= 1;

        int count = 0;
        int maxInt = 0;

        for(auto &it : events)
        {
            count += it.second;
            maxInt = max(maxInt, count); 
        }

        return maxInt;
    }
};


int main() {
    MyCalendarThree obj;
    cout << obj.book(10, 20) << endl; 
    cout << obj.book(50, 60) << endl; 
    cout << obj.book(10, 40) << endl; 
    cout << obj.book(5, 15) << endl;  
    cout << obj.book(5, 10) << endl;  
    cout << obj.book(25, 55) << endl; 

    return 0;
}