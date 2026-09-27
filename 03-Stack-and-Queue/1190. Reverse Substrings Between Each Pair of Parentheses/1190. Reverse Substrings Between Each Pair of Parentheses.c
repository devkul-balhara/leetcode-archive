class Solution:
    def reverseParentheses(self, s: str) -> str:
        right_for_left = dict()
        left_for_right = dict()
        stack = []
        for right,c in enumerate(s):
            if c == '(':
                stack.append(right)
            elif c == ')':
                left = stack.pop()
                right_for_left[left] = right
                left_for_right[right] = left
        i = 0
        direction = 1
        res = []
        while i < len(s):
            if s[i] != '(' and s[i] != ')':
                res.append(s[i])
            else:
                if s[i] == '(':
                    i = right_for_left[i]
                else:
                    i = left_for_right[i]
                direction = -direction
            i += direction
        return ''.join(res)