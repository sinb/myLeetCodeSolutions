# -*- coding: utf-8 -*-
"""
Created on Wed Oct  7 16:48:23 2015

@author: hehe
"""

class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        result = {}
        for word in strs:
            hash_key = ''.join(sorted(word))
            if hash_key in result:
                result[hash_key] += [word]
            else:
                result[hash_key] = [word]
                
        return [tuple(sorted(lst)) for lst in result.values() ]
