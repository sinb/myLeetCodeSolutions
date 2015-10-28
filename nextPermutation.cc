#include <iostream>
#include <vector>
using namespace std;
//http://fisherlei.blogspot.jp/2012/12/leetcode-next-permutation.html
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
    template<typename BidiIt>
    bool next_permutation(BidiIt first, BidiIt last)
    {
        const auto rfirst = reverse_iterator<BidiIt>(last);//most right
        const auto rlast = reverse_iterator<BidiIt>(first);//most left
        auto pivot = next(rfirst); // search pivot,
        //which is the first number that violates the increase order(from right to left)
        while (pivot != rlast && *pivot >= *prev(pivot))
        {   //prev(pivot) is the right after the pivot since the pivot is a reversed_iterator
            //when pivot is smaller that it's right one, it breaks the increase trend
            ++pivot;// ++ make pivot go left since it is a reversed_iterator
        }
        if (pivot == rlast)//no pivot found, this sequence is the lagerst sequence of all permutations
            // reverse it so it becomes the first permutation--the smallest
        {
            reverse(rfirst, rlast);
            return false;
        }
        //change point is the first one which larger that pivot point
        auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));
        swap(*change, *pivot);
        reverse(rfirst, pivot);
        return true;

    }

};
