from collections import defaultdict
from typing import List

class Solution:
    def generate(self, word):
        arr = [0] * 26

        for ch in word:
            arr[ord(ch) - ord('a')] += 1

        new_word = ""

        for i in range(26):
            freq = arr[i]

            if freq > 0:
                new_word += chr(ord('a') + i) * freq

        return new_word

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mp = defaultdict(list)

        for word in strs:
            new_word = self.generate(word)
            mp[new_word].append(word)

        result = []

        for group in mp.values():
            result.append(group)

        return result