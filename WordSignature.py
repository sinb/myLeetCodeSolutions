"""
生成单词签名，可用来找变体词
AAABBC -> A3B2C
"""

# -*- coding: utf-8 -*-
def solution(input):
    s = sorted(input)
    old_key = s[0]
    count = 0
    result = []
    for c in s:
        if c != old_key:
            result.append(old_key + str(count))
            count = 0
            old_key = c
        count += 1
    result.append(old_key + str(count))
    print "".join(result)
    return "".join(result)

solution("effective")
