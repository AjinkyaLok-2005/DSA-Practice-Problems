class Solution:
    def largestAltitude(self, gain: list[int]): 
        altitude = [0]

        temp = 0

        for g in gain:
            temp += g
            altitude.append(temp)

        return max(altitude)
    
obj = Solution()

gain = [-5, 1, 5, 0, -7]

print(obj.largestAltitude(gain))