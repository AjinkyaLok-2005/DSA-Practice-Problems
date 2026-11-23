#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> nums;
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }

    void add(int num) {
        if (num == 0)
        {
            nums = {};
            n = 0;
        }
        else
        {
            if (nums.empty())
            {
                nums.push_back(num);
            }
            else
            {
                nums.push_back(nums[n - 1] * num);
            }

            n++;
        }
    }

    int getProduct(int k) {
        if (k > n)
        {
            return 0;
        }
        else if (k == n)
        {
            return nums[n - 1];
        }

        return nums[n - 1] / nums[n - k - 1];
    }
};

int main() {
    ProductOfNumbers* obj = new ProductOfNumbers();

    obj->add(3);
    obj->add(0);
    obj->add(2);
    obj->add(5);
    obj->add(4);

    cout << obj->getProduct(2) << endl;  // expected 20
    cout << obj->getProduct(3) << endl;  // expected 40
    cout << obj->getProduct(4) << endl;  // expected 0

    obj->add(8);
    cout << obj->getProduct(2) << endl;  // expected 32

    delete obj;
    return 0;
}