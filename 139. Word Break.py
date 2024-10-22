class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False] * (n + 1)
        dp[0] = True

        for i in range(1, n+1):
            for j in range(i):
                word = s[j:i]
                if dp[j] and word in wordDict:
                    dp[i] = True  
                    break
        result = dp[n]
        return result


        