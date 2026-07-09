class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x = str(n).replace('0', '')
        num = int(x) if x else 0
        Sum = sum(int(d) for d in str(abs(num)))
        return num * Sum


if __name__ == "__main__":
    sol = Solution()

    n = int(input("Enter n: "))
    print(sol.sumAndMultiply(n))