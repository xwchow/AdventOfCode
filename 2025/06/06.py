from functools import reduce
from pathlib import Path

input_file_path = Path(__file__).parent / "input.txt"
test_file_path = Path(__file__).parent / "test.txt"
input = input_file_path.read_text().splitlines()
test = test_file_path.read_text().splitlines()


def part1(input):
    numbers = [[int(x) for x in line.split()] for line in input[:-1]]
    numbers = list(zip(*numbers))  # transposing numbers
    operations = [c for c in input[-1].split()]

    total = 0
    for i, op in enumerate(operations):
        if op == "*":
            total += reduce(lambda x, y: x * y, numbers[i])
        else:
            total += reduce(lambda x, y: x + y, numbers[i])
    print(total)


def part2(input):
    chars = input[:-1]

    # skip the first operation since we only know the width after finding the next operation
    last_idx = 0
    operations = input[-1]
    operations += " 0"  # terminal char to force an operation

    n = len(chars)
    total = 0
    for i, c in enumerate(operations):
        if i == 0:
            continue

        if c == " ":
            continue

        current_operation = operations[last_idx]

        numbers = []
        for j in range(last_idx, i - 1):
            number_str = ""
            for k in range(n):
                number_str += chars[k][j] if chars[k][j] != " " else ""
            if number_str != "":
                numbers.append(int(number_str))

        if current_operation == "+":
            total += reduce(lambda x, y: x + y, numbers)
        else:
            total += reduce(lambda x, y: x * y, numbers)
        last_idx = i
    print(total)


if __name__ == "__main__":
    part1(test)
    part1(input)
    part2(test)
    part2(input)
