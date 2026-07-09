from typing import List

class Solution:
    def numOfstrings(self, patterns: List[str], word: str) -> int:
        count = 0

        for pattern in patterns:
            if pattern in word:
                count += 1

        return count
    
if __name__ == "__main__":
    patterns = input("Enter patterns separated by spaces: ").split()
    word = input("Enter the word: ")

    sol = Solution()
    result = sol.numOfStrings(patterns, word)

    print("Number of patterns found: ", result)