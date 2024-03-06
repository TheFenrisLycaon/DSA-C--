class LRUCache(object):
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = {}
        self.queue = []

    def updateQueue(self, key):
        self.queue.remove(key)
        self.queue.insert(0, key)

    def get(self, key):
        if key in self.cache:
            self.updateQueue(key)
            return self.cache[key]
        else:
            return -1

    def put(self, key, value):
        if key in self.cache:
            self.queue.remove(key)
        elif len(self.queue) == self.capacity:
            del self.cache[self.queue.pop(-1)]
        self.cache[key] = value
        self.queue.insert(0, key)
