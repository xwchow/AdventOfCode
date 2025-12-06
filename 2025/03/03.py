from pathlib import Path

input_file_path = Path(__file__).parent / "input.txt"
test_file_path = Path(__file__).parent / "test.txt"
input = input_file_path.read_text().splitlines()
test = test_file_path.read_text().splitlines()


def solve(input, digits=2):
    total = 0
    for line in input:
        values = [int(x) for x in line if x.isdigit()]
        n = len(values)
        idx = -1
        for i in range(digits):
            rem = digits - i - 1
            value_slice = slice(idx + 1, n - rem)
            val = max(values[value_slice])
            idx += values[value_slice].index(val) + 1
            total += val * 10**rem
    return total


def part1(input):
    total = solve(input)
    print(total)


def part2(input):
    total = solve(input, digits=12)
    print(total)


if __name__ == "__main__":
    part1(test)
    part1(input)
    part2(test)
    part2(input)
