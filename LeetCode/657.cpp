#include<iostream>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;

        for(char & ch : moves)
        {
            if(ch == 'U')
                y++;
            if(ch == 'D')
                y--;
            if(ch == 'R')
                x++;
            if(ch == 'L')
                x--;
        }   

        return x == 0 && y == 0;
        
    }
};

int main()
{
    Solution obj;
    
    string moves;
    cout << "Enter moves: ";
    cin >> moves;

    if(obj.judgeCircle(moves))
        cout << "Robot returned to origin" << endl;
    else
        cout << "Robot did not return to origin" << endl;

    return 0;
}