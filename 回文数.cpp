/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
class Solution {
public:
    bool isPalindrome(int x) {
        int r = 0;
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
        while (x > r) {
            r = (r * 10) + (x % 10);
            x = x / 10;
        }
        return x == r || x == r / 10;
    }
};

