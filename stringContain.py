# -*- coding: utf-8 -*-
"""
Created on Tue Jun 30 23:13:57 2015
这个题头偷个懒用python吧,不会c++的哈系表
@author: hehe
"""

def stringContain(a, b):
    dic = {}
    for char in a:
        if dic.get(char, 0) == 0:
            dic[char] = 1
        else:
            pass
    for char in b:
        if dic.get(char,0) == 0:
            return False
    return True            
    
if __name__ == '__main__'    :
    result = stringContain('qqabcde', 'xab')
    print result
