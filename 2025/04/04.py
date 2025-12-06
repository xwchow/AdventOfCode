from pathlib import Path

input_file_path = Path(__file__).parent / "input.txt"
test_file_path = Path(__file__).parent / "test.txt"
input = input_file_path.read_text().splitlines()
test = test_file_path.read_text().splitlines()

di = [-1, -1, -1, 0, 0, 1, 1, 1]
dj = [-1, 0, 1, -1, 1, -1, 0, 1]


def part1(input):
    grid = [[c for c in line] for line in input]
    n = len(grid)
    m = len(grid[0])

    total = 0
    for i in range(n):
        for j in range(m):
            num_rolls = 0
            if grid[i][j] != "@":
                continue
            for k in range(8):
                i2 = i + di[k]
                j2 = j + dj[k]
                if i2 < 0 or i2 >= n or j2 < 0 or j2 >= m:
                    continue
                num_rolls += 1 if grid[i2][j2] == "@" else 0
            total += 1 if num_rolls < 4 else 0
    print(total)


def part2(input):
    grid = [[c for c in line] for line in input]
    n = len(grid)
    m = len(grid[0])

    prev_total = -1
    total = 0
    while total != prev_total:
        prev_total = total
        for i in range(n):
            for j in range(m):
                num_rolls = 0
                if grid[i][j] != "@":
                    continue
                for k in range(8):
                    i2 = i + di[k]
                    j2 = j + dj[k]
                    if i2 < 0 or i2 >= n or j2 < 0 or j2 >= m:
                        continue
                    num_rolls += 1 if grid[i2][j2] == "@" else 0
                if num_rolls < 4:
                    total += 1
                    grid[i][j] = "x"
    print(total)


if __name__ == "__main__":
    part1(test)
    part1(input)
    part2(test)
    part2(input)
