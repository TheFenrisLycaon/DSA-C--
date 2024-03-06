from queue import PriorityQueue


def path_finder(area):
    arr = []
    for val in area.split("\n"):
        arr.append(list(map(int, val)))
    pq = PriorityQueue()
    memory = dict()
    r, c = len(arr), len(arr[0])
    start, finish = (0, 0), (r - 1, c - 1)
    neighbors = [(-1, 0), (1, 0), (0, 1), (0, -1)]
    pq.put((0, start))
    while not pq.empty():
        cur_cost, cur_pos = pq.get()
        if cur_pos in memory and memory[cur_pos] <= cur_cost:
            continue
        memory[cur_pos] = cur_cost
        if cur_pos == finish:
            break
        for nei in neighbors:
            tmp_pos = (nei[0] + cur_pos[0], nei[1] + cur_pos[1])
            if 0 <= tmp_pos[0] < r and 0 <= tmp_pos[1] < c:
                tmp_cost = abs(
                    arr[tmp_pos[0]][tmp_pos[1]] - arr[cur_pos[0]][cur_pos[1]]
                )
                if tmp_pos in memory and memory[tmp_pos] <= tmp_cost + cur_cost:
                    continue
                pq.put((tmp_cost + cur_cost, tmp_pos))

    return memory[finish]
