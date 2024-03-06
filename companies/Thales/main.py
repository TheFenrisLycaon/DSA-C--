from src.api import API
from src.question import Question
from src.var import file


def main() -> None:
    x = API(file)
    print(x.display)
    print(x.filterSubject("SUB1"))
    print(x.addQuestion("SUB1", {}))
    print(x.genId("SUB1"))
    print(x.removeQuestion("SUB1", "SUB1_2"))
    print(x.upadteQuestion("SUB1", "SUB1_2", "_Question__problemStatement", "Question 1b"))


if __name__ == "__main__":
    main()
