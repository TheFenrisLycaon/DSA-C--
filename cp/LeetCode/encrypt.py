import itertools
from typing import List


class Encrypter:
    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.mapp = dict(zip(keys, values))
        self.dictionary = dictionary

    def encrypt(self, word1: str) -> str:
        s = ""
        for letter in list(word1):
            s += self.mapp[letter]
        return s

    def decrypt(self, word2: str) -> int:
        inv_map = {}
        for k, v in self.mapp.items():
            inv_map[v] = inv_map.get(v, []) + [k]
        s = []
        for letter in [word2[i : i + 2] for i in range(0, len(word2), 2)]:
            if letter in inv_map:
                s.append(inv_map[letter])
        tot = sum(
            [
                1
                for x in ["".join(k) for k in itertools.product(*s)]
                if x in self.dictionary
            ]
        )
        return tot


obj = Encrypter(
    ["a", "b", "c", "d"],
    ["ei", "zf", "ei", "am"],
    ["abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"],
)
print(obj.encrypt("abcd"))
print(obj.decrypt("eizfeiam"))