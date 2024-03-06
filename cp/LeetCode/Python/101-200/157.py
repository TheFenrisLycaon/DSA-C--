class Solution(object):
    def read(self, buf, n):
        pos, eof = 0, False
        while not eof and pos < n:
            buffer = [''] * 4
            sz = read4(buffer)
            if sz < 4:
                eof = True
            for i in range(sz):
                buf[pos + i] = buffer[i]
            pos += min(n - pos, sz)
        return pos