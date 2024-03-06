class Solution(object):
    def isSameTree(self, p, q):
        if(p is None and q is None):
            return True
        if(p==None or q==None):
            return False
        if(p.val!=q.val):
            return False
        else:
            return self.isSameTree( p.right, q.right) and self.isSameTree( p.left, q.left)
