class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        temp =''
        for i in s:
            if (i == '#') and (temp!= ''):
                temp=temp[:-1]
            elif i!= '#':
                temp+=i
        s = temp
        temp = ''
        for i in t:
            if (i == '#') and (temp!= ''):
                temp=temp[:-1]
            elif i!= '#':
                temp+=i
        return s==temp
