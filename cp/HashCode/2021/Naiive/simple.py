from read_input import Instance, Solution

inst = Instance.from_argv()

intersection_counts = [{} for _ in range(inst.I)]
for p in inst.paths:
    for s in p[:-1]:
        if s not in intersection_counts[inst.streets[s][1]]: intersection_counts[inst.streets[s][1]][s] = 0
        intersection_counts[inst.streets[s][1]][s] += 1

sol = []
epoch_length = 20
assert epoch_length <= inst.D
for i,intsctn in enumerate(intersection_counts):
    tot = sum(intsctn.values())
    durs = []
    for s,n in intsctn.items():
        dur = round(n/tot * epoch_length)
        if dur > 0: durs.append((s,dur))
    if durs: sol.append((i,durs))

s = Solution(sol, inst)
s.write()
