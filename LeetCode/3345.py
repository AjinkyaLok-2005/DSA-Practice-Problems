class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        while True:
            product = 1
            num = n

            while num > 0:
                product *= num % 10
                num //= 10

            if product % t == 0:
                return n

            n += 1


if __name__ == "__main__":
    # Take input from the user
    n = int(input("Enter n: "))
    t = int(input("Enter t: "))

    # Create an object of Solution
    obj = Solution()

    # Call the function and print the result
    ans = obj.smallestNumber(n, t)
    print("Smallest Number:", ans)