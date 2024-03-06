class Solution(object):
    def __init__(self):
        self.buff = [''] * 4
        self.offset = 0
        self.bufsize = 0

    def read(self, buf, n):
        pos, eof = 0, False
        while not eof and pos < n:
            if self.bufsize == 0:
                self.bufsize = read4(self.buff)
                eof = self.bufsize < 4
            byte = min(n - pos, self.bufsize)
            for i in range(byte):
                buf[pos + i] = self.buff[self.offset + i]
            self.offset = (self.offset + byte) % 4
            self.bufsize -= byte
            pos += byte
        return pos
