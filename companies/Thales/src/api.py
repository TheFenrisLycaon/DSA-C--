import json
from typing import Any


class API:
    def __init__(self, file: str) -> None:
        self.file = file

    def genId(self, subCode: str) -> str:
        with open(self.file, "r") as f:
            x = json.load(f)
        lastID = list(x[subCode].keys())[-1]
        lastID_num = int(lastID.split("_")[-1])
        return subCode + "_" + str(lastID_num + 1)

    def addQuestion(self, subCode: str, qstnDict: dict) -> bool:
        with open(self.file, "r") as f:
            x = json.load(f)
        try:
            x[subCode][self.genId(subCode)] = qstnDict
            with open(self.file, "w") as f:
                json.dump(x, f, indent=4)
            return True
        except Exception as e:
            print(e)
            return False

    def upadteQuestion(
        self, subCode: str, id: str, component: str, newValue: Any
    ) -> bool:
        with open(self.file, "r") as f:
            x = json.load(f)
        try:
            x[subCode][id][component] = newValue
            with open(self.file, "w") as f:
                json.dump(x, f, indent=4)
            return True
        except Exception as e:
            print(e)
            return False

    def removeQuestion(self, subCode: str, id: str) -> bool:
        with open(self.file, "r") as f:
            x = json.load(f)
        try:
            x[subCode].pop(id)
            with open(self.file, "w") as f:
                json.dump(x, f, indent=4)
            return True
        except Exception as e:
            print(e)
            return False

    def filterSubject(self, subCode: str) -> str:
        with open(self.file, "r") as f:
            x = json.load(f)
        return [value for key, value in x.items() if key == subCode]

    @property
    def display(self):
        with open(self.file, "r") as f:
            x = json.load(f)
        return [value for key, value in x.items()]
