class Solution(object):
    def zigzagLevelOrder(self, root):
        if root is None:
            return []
        q = [[root]]
        for level in q:
            record = []
            for node in level:
                if node.left:
                    record.append(node.left)
                if node.right:
                    record.append(node.right)
            if record:
                q.append(record)
        res = []
        for index, level in enumerate(q):
            temp = [x.val for x in level]
            if index % 2 == 0:
                res.append(temp)
            else:
                res.append(temp[::-1])
        return res
