# -*- coding: utf-8 -*-
"""
Created on Thu Oct  8 13:38:52 2015

@author: hehe
"""
# 思路:首先找因数,只找一半,比如64找到8*8就停下,后面的16*4前面已经出现了.
# 对于找到的一组因数,加入result list,对于这组因数的第二个再进行因数分解,比如2*16,
class Solution:
    # @param {integer} n
    # @return {integer[][]}
    def getFactors(self, n):
        result = []
        factors = []
        self.getResult(n, result, factors)
        return result, factors

    def getResult(self, n, result, factors):
        i = 2 if not factors else factors[-1]
        while i <= n / i:
            if n % i == 0:
                factors.append(i);
                factors.append(n / i);
                result.append(list(factors));
                factors.pop();
                self.getResult(n / i, result, factors);
                factors.pop()
            i += 1
    #all factors            
    def allFactor(self, n):
        i = 1
        result = []
        while i <= n / i:
            if n % i == 0:
                result.append(i)                
                result.append(n/i)
            i+=1           
        return sorted(result)
if __name__ == '__main__'     :
    s = Solution()
    factors = s.allFactor(30)