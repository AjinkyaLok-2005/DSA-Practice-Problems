class Solution {
public:
    int getNext(int n)
    {
        int sum = 0;
        while(n != 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n) {

        // Approach - 1 
        // bool isTrue = true;

        // unordered_set<int> st;

        // while(n != 1)
        // {
        //     int sumPdtSq = 0;
        //     while(n != 0)
        //     {
        //         int digit = n % 10;
        //         int pdt = digit * digit;
        //         sumPdtSq += pdt;
        //         n = n / 10;
        //     }

        //     if(st.find(sumPdtSq) != st.end())
        //     {
        //         isTrue = false;
        //         break;
        //     }
        //     else
        //     {
        //         st.insert(sumPdtSq);
        //     }

        //     n = sumPdtSq;
        // }

        // return isTrue;



        // Approach - 2

        int slow = n;
        int fast = getNext(n); 

        while(fast != 1 && slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }

        return fast == 1;
    }
};