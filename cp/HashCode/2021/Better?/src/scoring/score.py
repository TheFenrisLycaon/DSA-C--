from ..data.output import Output


class Score():
    def __init__(self, output):
        self.score = hash(self) % 100
