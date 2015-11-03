class Solution {
public:
//找到第k大的数字
//也可以用来做找到数组中最小的k个数字
//可以直接排序,返回第k个.
//也可以用快速选择,partition的方法.
//先随机打乱数组,对数组中第一个元素(已经是随机排列了的),寻找它的真正位置,假如返回的是j,
//根据j和k的关系,可以进行下一此partition去寻找,直到找到.
//时间O(n)
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k; 
        //我的理解和题目的理解不太一样..题目中说的第1大是指最大,第二大是指次大.
        //我的理解是,第0大指最小,第N-1大是指最大.所以需要转换一下.
        random_shuffle ( nums.begin(), nums.end() );
        int lo = 0, hi = nums.size() - 1;
        while (hi > lo)
        {
            int j = partition(nums, lo, hi);
            if (j < k) lo = j+1;
            else if (j > k) hi = j-1;
            else return nums[k];
        }
        return nums[k];
    }
    int partition(vector<int>& nums, int lo, int hi)
    {
        int i = lo, j = hi+1;
        while (true)
        {
            while (nums[++i] < nums[lo])
            {
                if (i == hi)
                    break;
            }
            while (nums[lo] < nums[--j])
            {
                if (j == lo)
                    break;
            }
            if (i >= j)
                break;
            // swap
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
        }
            int tmp = nums[j];
            nums[j] = nums[lo];
            nums[lo] = tmp;
            return j; // j is in place now
    }
};
