#include <stdio.h>

/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (25.24%)
 * Total Accepted:    653.8K
 * Total Submissions: 2.6M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 * 
 * Example 1:
 * 
 * 
 * Input: 123
 * Output: 321
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -123
 * Output: -321
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 120
 * Output: 21
 * 
 * 
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 0 when the reversed
 * integer overflows.
 * 
 */
int reverse(int x) {
    int max_int = 0x7fffffff;
    int min_int = 0x80000000;
    long long cp = x;
    cp = cp < 0 ? -cp : cp;
    long long res = 0;
    while (cp)
    {
        if (res * 10 > max_int)
        {
            return 0;
        }        
        res = res * 10 + cp % 10;
        cp /= 10;
    }
    if (x < 0)
    {
        res *= -1;
    }
    if (res < min_int)
    {
        return 0;
    }
    
    return res;
}

/* int main(void) */
/* { */
/*     printf("%d\n", reverse(123)); */
/*     return 0; */
/* } */

