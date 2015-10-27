# -*- coding: utf-8 -*-
"""
Created on Tue Oct 27 15:19:39 2015

@author: hehe
"""

def reverseString(strin, s, e):
    '''reverse part of the string
    s-start
    e-end    
    '''
    partofstr = reversed(strin[s:e+1])
    partofstr = ''.join(partofstr)
    return strin[:s]+partofstr+strin[e+1:]

def reverseStringPivot(strin, piv):  
    '''reverse string from a pivot point
    '''
    strin = reverseString(strin, 0, piv)    
    strin = reverseString(strin, piv+1, len(strin)-1)    
    strin = reverseString(strin, 0, len(strin)-1)    
    return strin
    
def reverseWord(sentence):
    '''
    i am a student. ===> student. a am i
    '''
    words = sentence.split(' ')
    revwords = [reverseString(word, 0, len(word)-1) for word in words]    
    revwords = ' '.join(revwords)
    revwords = reverseString(revwords, 0, len(revwords)-1)
    return revwords
        


s = 'i am a student.'
print reverseWord(s)