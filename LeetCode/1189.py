from collections import Counter

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq = Counter(text)

        return min(
            freq['b'],
            freq['a'],
            freq['l'] // 2,
            freq['o'] // 2,
            freq['n']
        )
    
if __name__ == "__main__":
    text = input("Enter a String: ")
    
    obj = Solution()
    result = obj.maxNumberOfBalloons(text)

    print("Maximum number of balloons: ", result)
    