class Solution(object):
    def levelOrder(self, root):
        if root is None:
            return []
        q = [[root]]
        for level in q:
            record = []
            for node in level:
                if node.left: record.append(node.left)
                if node.right: record.append(node.right)
            if record: q.append(record)
        return [[x.val for x in level] for level in q]
