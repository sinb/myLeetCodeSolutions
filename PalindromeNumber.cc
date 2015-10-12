class Solution {
public:
//判断数字是不是回文,123321
//想办法每次把第一位和最后一位取出来比较
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int d = 1; // divisor,用来不断做除法
    while (x / d >= 10) d *= 10;//d现在和x一个数量级
    while (x > 0) {
      int q = x / d; // 商,首位
      int r = x % 10;//余数,末位
      // remainder
      if (q != r)
      return false;
      x = x % d / 10;//x%d是第二位到最后一位,再除个10最后一位也没了
      d /= 100;//上一步直接小了两个数据级,所以d也除以100
    };
    return true;
  }
}

