'''
 * https://leetcode.com/problems/palindrome-number/
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 1230 - >false
 * 123->false
 * 12321 -> true
 * 6146384638462834 - > false (INT_MAX) overflow
 * -123 - >false
 * -12321 ->false
 * 0~9 ->true
 * 10->false
 * 11->true
 * 12->false
 * 121->true
 */

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer",
you know that the reversed integer might overflow. How would you handle such case?


'''


class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        rev = 0
        remain = x
        while remain > 0:
            rev = rev * 10 + remain % 10
            remain = int(remain / 10)
        return rev == x

if __name__ == '__main__':
    obj = Solution()
    #print(obj.isPalindrome(123) == False)
    #print(obj.isPalindrome(-1221) == False)
    print(obj.isPalindrome(1) == True)