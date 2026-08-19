from collections import defaultdict
from typing import List


class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        mp = defaultdict(set)

        for row, seat in reservedSeats:
            mp[row].add(seat)

        result = (n - len(mp)) * 2

        for row, bookedSeats in mp.items():
            def isAvailable(seat):
                return seat not in bookedSeats

            groupA = isAvailable(2) and isAvailable(3) and isAvailable(4) and isAvailable(5)

            groupB = isAvailable(4) and isAvailable(5) and isAvailable(6) and isAvailable(7)

            groupC = isAvailable(6) and isAvailable(7) and isAvailable(8) and isAvailable(9)

            if groupA and groupC:
                result += 2
            elif groupA or groupB or groupC:
                result += 1

        return result

        # mp = defaultdict(int)

        # for row, seat in reservedSeats:
        #     mp[row] |= (1 << seat)

        # result = (n - len(mp)) * 2

        # maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5)
        # maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7)
        # maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9)

        # for row, bookedSeatsMask in mp.items():
        #     groupA = (bookedSeatsMask & maskA) == 0
        #     groupB = (bookedSeatsMask & maskB) == 0
        #     groupC = (bookedSeatsMask & maskC) == 0

        #     if groupA and groupC:
        #         result += 2
        #     elif groupA or groupB or groupC:
        #         result += 1

        # return result


if __name__ == "__main__":
    sol = Solution()

    # Test case 1: expected 4
    n1 = 3
    reservedSeats1 = [[1, 2], [1, 3], [1, 8], [2, 6], [3, 1], [3, 10]]
    print(sol.maxNumberOfFamilies(n1, reservedSeats1))  # 4

    # Test case 2: expected 2
    n2 = 2
    reservedSeats2 = [[2, 1], [1, 8], [2, 6]]
    print(sol.maxNumberOfFamilies(n2, reservedSeats2))  # 2

    # Test case 3: expected 4
    n3 = 4
    reservedSeats3 = [[4, 3], [1, 4], [4, 6], [1, 7]]
    print(sol.maxNumberOfFamilies(n3, reservedSeats3))  # 4