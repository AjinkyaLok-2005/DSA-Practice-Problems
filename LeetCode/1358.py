class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)

        result = 0

        mp = [0] * 3

        i = 0
        j = 0

        while j < n:
            ch = s[j]
            mp[ord(ch) - ord('a')] += 1

            while mp[0] > 0 and mp[1] > 0 and mp[2] > 0:
                result += (n-j)

                mp[ord(s[i]) - ord('a')] -= 1
                i += 1

            j += 1

        return result
    
if __name__ == "__main__":
    s = input("Enter the string: ")

    obj = Solution()
    ans = obj.numberOfSubStrings(s)

    print("Number of substrings: ", ans)