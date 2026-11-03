from typing import List

class Solution:
    def fairCandySwap(self, aliceSizes: List[int], bobSizes: List[int]) -> List[int]:
        sumA = sum(aliceSizes)
        sumB = sum(bobSizes)

        diff = (sumB - sumA) // 2
        bobSet = set(bobSizes)

        for a in aliceSizes:
            if a + diff in bobSet:
                return [a, a + diff]