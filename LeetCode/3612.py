class Solution:
    def processStr(self, s: str) -> str:
        result = ""

        for ch in s:
            if 'a' <= ch <= 'z':
                result += ch
            elif ch == '#':
                result += result
            elif ch == '%':
                result = result[::-1]
            else:
                if result:
                    result = result[:-1]

        return result
    

if __name__ == "__main__":
    sol = Solution()

    s = input().strip()
    print(sol.processStr(s))