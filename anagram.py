class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        s_map = {}
        t_map = {}
        for i in range(len(s)):
            if s_map.get(s[i], 0) == 0:
                s_map[s[i]] = 1
            else:
                s_map[s[i]] += 1               
            if t_map.get(t[i], 0) == 0:
                t_map[t[i]] = 1
            else:
                t_map[t[i]] += 1                
        return t_map == s_map

