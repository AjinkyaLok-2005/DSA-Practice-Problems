class Solution:
    def pivotArray(self, nums, pivot):
        n = len(nums)

        result = [0] * n

        i = 0
        j = n-1

        i_ = 0
        j_ = n-1

        while i < n and j >= 0:
            if nums[i] < pivot:
                result[i_] = nums[i]
                i_ += 1

            if nums[j] > pivot:
                result[j_] = nums[j]
                j_ -= 1

            i += 1
            j -= 1

        while i_ <= j_:
            result[i_] = pivot
            i_ += 1 

        return result
    
if __name__ == "__main__":
    nums = list(map(int, input("Enter the array elements: ").split()))

    pivot = int(input("Enter Pivot: "))

    sol = Solution()
    result = sol.pivotArray(nums, pivot)

    print("Result: ", result)