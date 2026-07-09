class Solution:
    def findWaveScore(self, num: int) -> int:
        s = str(num)

        l = len(s)
        if l < 3:
            return 0

        score = 0

        for i in range(1, l - 1):
            # Peak
            if s[i] > s[i - 1] and s[i] > s[i + 1]:
                score += 1

            # Valley
            if s[i] < s[i - 1] and s[i] < s[i + 1]:
                score += 1

        return score

    def totalWaviness(self, num1: int, num2: int) -> int:
        score = 0

        for num in range(num1, num2 + 1):
            score += self.findWaveScore(num)

        return score


if __name__ == "__main__":
    num1 = int(input())
    num2 = int(input())

    sol = Solution()
    print(sol.totalWaviness(num1, num2))