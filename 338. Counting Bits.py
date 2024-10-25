class Solution:
    def countBits(self, n: int) -> List[int]:
        result = [0] * (n + 1)
        for i in range(n + 1):
            count = 0
            num = i

            while num>0:
                if num & 1:
                    count +=1
                num>>=1

            result[i]=count
        return result
        