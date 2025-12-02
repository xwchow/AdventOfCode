from pathlib import Path

input_file_path = Path(__file__).parent / "input.txt"
test_file_path = Path(__file__).parent / "test.txt"
input = input_file_path.read_text().splitlines()
test = test_file_path.read_text().splitlines()

LIMIT = 100_000


def parse_ranges(ranges_str: str) -> list[tuple[int, int]]:
    ranges = []
    for range_str in ranges_str.split(","):
        start, end = map(int, range_str.split("-"))
        ranges.append((start, end))
    return ranges


def num_digits(num):
    return len(str(num))


def within_range(num, ranges):
    for range in ranges:
        if range[0] <= num <= range[1]:
            return True
    return False


def part1(input):
    ranges = parse_ranges(input[0])

    doubles = set()
    sum_doubles = 0
    for i in range(1, LIMIT):
        double = i * 10 ** num_digits(i) + i
        doubles.add(double)
        if within_range(double, ranges):
            sum_doubles += double
    print(sum_doubles)


def part2(input):
    ranges = parse_ranges(input[0])

    multiples = set()
    sum_multiples = 0
    for i in range(1, LIMIT):
        multiple = i
        while multiple < LIMIT**2:
            multiple = multiple * (10 ** num_digits(i)) + i
            if multiple in multiples:
                continue
            multiples.add(multiple)
            if within_range(multiple, ranges):
                sum_multiples += multiple
    print(sum_multiples)


if __name__ == "__main__":
    part1(test)
    part1(input)
    part2(test)
    part2(input)
