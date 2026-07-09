class Solution:
    def processStr(self, s: str, k: int) -> str:
        n = len(s)

        L = 0

        for ch in s:
            if ch == '*':
                if L > 0:
                    L -= 1
            elif ch == '#':
                L *= 2
            elif ch == '%':
                continue
            else:
                L += 1

        if k >= L:
            return '.'
        
        for i in range(n-1, -1, -1):
            if s[i] == '*':
                L += 1

            elif s[i] =='%':
                k = L - k - 1

            elif s[i] == '#':
                L = L // 2
                if k >= L:
                    k -= L

            else:
                L -= 1

            if k == L:
                return s[i]


        return '.'


if __name__ == "__main__":
    obj = Solution()

    s = input("Enter String: ")
    k = int(input("Enter k: "))

    print(obj.processStr(s, k)) 
