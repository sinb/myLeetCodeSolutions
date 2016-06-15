# -*- coding: utf-8 -*-
"""
1 -> source peg
2 -> helper peg
3 -> destination peg
分三步，参考这个图
http://www.mathcs.emory.edu/~cheung/Courses/170/Syllabus/13/hanoi.html
"""
def hanoi_tower(n_disk, from_peg, to_peg):
    if n_disk == 1:
        print "from {} to {}".format(from_peg, to_peg)
        return 
    help_peg = 6 - from_peg - to_peg
    hanoi_tower(n_disk-1, from_peg, help_peg)
    print "from {} to {}".format(from_peg, to_peg)
    hanoi_tower(n_disk - 1, help_peg, to_peg)

hanoi_tower(3, 1, 3)
