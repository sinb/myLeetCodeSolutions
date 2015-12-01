# -*- coding: utf-8 -*-
"""
Created on Sat Nov 28 15:28:54 2015
find top K number in a huge array
从一个数组中找最大的k个,或者最小的k个
如果直接排序取前k个,就是o(nlogn)
如果使用,每次选出k个,就是说先找出第0大(最小),第二大,第三大...第k-1大的方法,就是o(k logn)
使用最小堆最快,是o(n logk)
对于找出最大的k个问题,做法是维护一个k大小的最小堆,对每个新来的数字,如果它比堆顶(堆顶始终是最小的)还小,那就跳过,否则加入堆.
堆会自己调整.
@author: hehe
"""

import heapq
import random
bigArray = range(10000)
def topK(arr, k):
    heap = []
    for num in arr:
        if len(heap) < k or num > heap[0]:
            if len(heap) == k:
                heapq.heappop(heap)
            heapq.heappush(heap, num)
    return heap
      
top10 = topK(bigArray, 10)

#或者直接用heapq的函数
#heapq.nlargest( bigArray, k )
