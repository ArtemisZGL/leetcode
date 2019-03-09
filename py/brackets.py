class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        if s.strip() == '':
            return True
        
        stack = []
        for c in s:
            if c == '[' or c == '(' or c == '{':
                stack.append(c)
            if c == ']':
                if len(stack) == 0:
                    return False
                tail = stack.pop()
                if tail != '[':
                    return False
            if c == ')':
                if len(stack) == 0:
                    return False
                tail = stack.pop()
                if tail != '(':
                    return False
            if c == '}':
                if len(stack) == 0:
                    return False
                tail = stack.pop()
                if tail != '{':
                    return False
        return len(stack) == 0

test = Solution()

while True:
    string = raw_input()
    print(test.isValid(string))
