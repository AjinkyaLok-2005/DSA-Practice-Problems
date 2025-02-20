#include<iostream>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n)
{
    int deficit = 0;
    int balance = 0;
    int start  = 0;

    for(int i = 0; i < n; i++)
    {
        balance += p[i].petrol - p[i].distance;
        if(balance < 0)
        {
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }

    if(deficit + balance >= 0)
    {
        return start;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int n;
    cout << "Enter the number of petrol pumps: ";
    cin >> n;

    petrolPump p[n];

    cout << "Enter petrol and distance for each petrol pump " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Petrol Pump " << i + 1 << ": ";
        cin >> p[i].petrol >> p[i].distance;
    }

    int result = tour(p, n);
    if(result != -1)
    {
        cout << "Start the tour from petrol pump index: " << result << endl;
    }
    else
    {
        cout << "No feasible starting point found for the tour. " << endl;
    }
    
    return 0;
}