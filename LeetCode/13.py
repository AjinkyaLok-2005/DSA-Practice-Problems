class Solution:
    def romanToInt(self, s: str) -> int:
        roman = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        ans = 0

        for i in range(len(s)):
            # If the current value is less than the next value,
            # subtract it instead of adding it.
            if i < len(s) - 1 and roman[s[i]] < roman[s[i + 1]]:
                ans -= roman[s[i]]
            else:
                ans += roman[s[i]]

        return ans


if __name__ == "__main__":
    s = input("Enter a Roman numeral: ").strip()

    solution = Solution()
    result = solution.romanToInt(s)

    print("Integer value:", result)