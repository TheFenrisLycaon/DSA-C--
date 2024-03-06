class Solution(object):
    def cloneGraph(self, node):
        if node is None:
            return None
        label_map = {}
        queue = [node]
        graphCopy = UndirectedGraphNode(node.label)
        label_map[node.label] = graphCopy
        while len(queue) > 0:
            curr = queue.pop(0)
            for ne in curr.neighbors:
                if ne.label in label_map:
                    label_map[curr.label].neighbors.append(label_map[ne.label])
                else:
                    neighborCopy = UndirectedGraphNode(ne.label)
                    label_map[curr.label].neighbors.append(neighborCopy)
                    label_map[ne.label] = neighborCopy
                    queue.append(ne)
        return graphCopy
