# -*- coding: utf-8 -*-
"""
Created on Tue Jun 30 23:13:57 2015
这个题偷个懒用python吧,不会c++的哈系表
findBrother return brother string of a given string in a list 
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

def findBrother(a, listofwords):                      
    def getDic(word):
        dic = {}
        for char in word:
            if dic.get(char, 0) == 0:
                dic[char] = 0            
                dic[char] += 1
            else:
                dic[char] += 1
        return dic      
    dic1 = getDic(a)
    for word in listofwords:
        dic2 = getDic(word)
        if dic2 == dic1 and word != a:
            return word
        else:
            pass
    return None        
            
if __name__ == '__main__'    :
    result = stringContain('qqabcde', 'xab')
    print result
    a = 'abcx'
    listofwords = ['abcd', 'cbax']
    a_brother = findBrother(a, listofwords)
    print a_brother
