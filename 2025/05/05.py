from pathlib import Path

input_file_path = Path(__file__).parent / "input.txt"
test_file_path = Path(__file__).parent / "test.txt"
input = input_file_path.read_text().splitlines()
test = test_file_path.read_text().splitlines()


def parse_input(input) -> tuple[list[tuple[int, int]], list[int]]:
    ranges = []
    ingredients = []
    mode = 0
    for line in input:
        if line == "":
            mode = 1
            continue
        if mode == 0:
            r = line.split("-")
            ranges.append((int(r[0]), int(r[1])))
        else:
            ingredients.append(int(line))
    return (ranges, ingredients)


def part1(input):
    ranges, ingredients = parse_input(input)
    total = 0
    for ingredient in ingredients:
        for range in ranges:
            if ingredient >= range[0] and ingredient <= range[1]:
                total += 1
                break
    print(total)


def part2(input):
    ranges, _ = parse_input(input)
    ranges.sort(key=lambda x: (x[0], x[1]))
    total = 0
    interval_end = -1
    for range in ranges:
        if range[1] < interval_end:
            continue
        total += range[1] - max(range[0], interval_end) + 1
        interval_end = max(interval_end, range[1]) + 1
    print(total)


if __name__ == "__main__":
    part1(test)
    part1(input)
    part2(test)
    part2(input)
