class Solution:
    def angleClock(self, hour: int, minute: int) -> float:
        ans = abs(30 * hour - 5.5 * minute)

        if ans > 180:
            ans = 360 - ans

        return ans

if __name__ == "__main__":
    obj = Solution()

    hour = int(input("Enter hour: "))
    minutes = int(input("Enter minutes: "))

    print(obj.angleClock(hour, minutes))