class Solution:
    def isHappy(self, n: int) -> bool:
        count=0
        while(True):
            rep=str(n)
            n=0
            for i in rep:
                n+=int(i)**2
            if(n==1):
                return True
                break
            elif count == 20:
                return False
                break
            count+=1
