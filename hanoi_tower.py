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


def hanoi_tower2(n_disk, src, mid, dest):
    if n_disk == 1:
        print "from {} to {}".format(src, dest)
        return
    hanoi_tower2(n_disk-1, src, dest, mid)
    print "from {} to {}".format(src, dest)
    hanoi_tower2(n_disk - 1, mid, src, dest)


class HanoiProblem:
    def __init__(self, n_disk, src, mid, dest):
        self.n_disk = n_disk
        self.src = src
        self.mid = mid
        self.dest = dest


def hanoi_stack(n):
    stack = [HanoiProblem(n, 1, 2, 3)]
    while stack:
        current_problem = stack.pop()
        if current_problem.n_disk == 1:
            print "from {} to {}".format(current_problem.src, current_problem.dest)
        else:  # 后解决的先入栈，注意顺序，和递归是反的
            stack.append(HanoiProblem(current_problem.n_disk-1, current_problem.mid,
                                      current_problem.src, current_problem.dest))

            stack.append(HanoiProblem(1, current_problem.src, current_problem.mid, current_problem.dest))

            stack.append(HanoiProblem(current_problem.n_disk - 1, current_problem.src,
                                      current_problem.dest, current_problem.mid))


if __name__ == "__main__":
    # hanoi_tower2(3, 1, 2, 3)
    hanoi_stack(3)
