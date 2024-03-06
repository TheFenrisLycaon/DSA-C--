class Task:
    name: str
    type: str
    time = 0
    completed: bool = False

    def __init__(self, name, type, time=0):
        self.name = name
        self.type = type
        self.time = int(time)

    def isCompleted(self) -> bool:
        return self.completed


class Worker:
    name: str
    time = 0
    task: Task = None

    def __init__(self, name):
        self.name = name

    def __str__(self):
        return f"{self.name} {self.task} {self.time}"

    def assign(self, task):
        self.task = task.name
        self.time = task.time

    def isFree(self) -> bool:
        return self.time == 0


def schedule(tasks, n, m):
    workers = [Worker(f"W{i}") for i in range(1, n + 1)]
    for i in range(m):
        worker = workers[i % n]
        task = tasks[i]
        if worker.isFree():
            if task.isCompleted():
                pass
            worker.assign(task)
            task.completed = True
            yield str(worker)
        for w in workers[: i + 1]:
            w.time -= 1 if not w.isFree() else 0


if __name__ == "__main__":
    n = int(input())
    m = int(input())
    try:
        print(
            "\n".join(
                sorted(
                    list(schedule([Task(*input().split()) for _ in range(m)], n, m)),
                    key=lambda x: x[-1],
                )
            )
        )
    except Exception as e:
        print(e)
