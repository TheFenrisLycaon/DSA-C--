import sys


class Instance:
    def __init__(self, file):
        self.file_name = file
        with open(file) as f:
            self.D, self.I, self.S, self.V, self.F = map(
                int, next(f).strip().split())
            self.streets = {}
            for _ in range(self.S):
                B, E, name, L = next(f).strip().split()
                self.streets[name] = (int(B), int(E), int(L))
            self.paths = []
            for _ in range(self.V):
                p = list(next(f).strip().split())[1:]
                self.paths.append(p)

    @staticmethod
    def from_argv():
        return Instance(sys.argv[1])

    def score_upperbound(self):
        return self.V * (self.F + self.D)


class Solution:
    def __init__(self, solution, instance):
        assert isinstance(instance, Instance)
        self.instance = instance
        # typecheck the solution
        # solution = list(
        #   (intersection_id, list((street, time),....),
        #   (inte...)
        #   )
        allowed_streets = set(instance.streets.keys())
        assert type(solution) == list
        found_intersections = set()
        for intersection in solution:
            assert type(intersection) == tuple
            assert len(intersection) == 2
            iid, streets = intersection
            assert type(iid) == int
            assert iid not in found_intersections
            found_intersections.add(iid)
            assert 0 <= iid < instance.I
            assert type(streets) == list
            found_streets = set()
            for street in streets:
                assert len(street) == 2
                sn, time = street
                assert sn in allowed_streets
                assert type(sn) == str
                assert sn not in found_streets
                assert type(time) == int
                assert 1 <= time <= instance.D
                found_streets.add(sn)
        self.solution = solution

    @staticmethod
    def from_file(file, instance):
        with open(file) as f:
            solution = None  # parse solution from file
        return Solution(solution, instance)

    @staticmethod
    def from_argv(instance=None):
        n_argv = 1
        if instance is None:
            instance = Instance.from_argv()
            n_argv += 1
        return Solution.from_file(sys.argv[n_argv], instance)

    def score(self):
        # calculate score
        score = 0
        return score

    def write(self):
        import os
        score = self.score()
        print(
            f"New score is {score} which is {score/self.instance.score_upperbound()*100}% of upperbound.")
        file_name = f"{self.instance.file_name.split('/')[-1][0]}_{score}.out"
        file_path = os.path.join("output", file_name)
        with open(file_path, "w") as f:
            f.write(f"{len(self.solution)}\n")
            for iid, streets in self.solution:
                f.write(f"{iid}\n")
                f.write(f"{len(streets)}\n")
                for sn, time in streets:
                    f.write(f"{sn} {time}\n")
            # write this to file
