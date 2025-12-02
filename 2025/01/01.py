from pathlib import Path

input_file_path = Path(__file__).parent / "input.txt"
test_file_path = Path(__file__).parent / "test.txt"
input = input_file_path.read_text().splitlines()
test = test_file_path.read_text().splitlines()


def part1(input):
    num_zeros = 0
    dial_position = 50

    for line in input:
        mul = -1 if line[0] == "L" else 1
        dial_position += int(line[1:]) * mul
        # modular arithmetic
        dial_position = (dial_position + 100) % 100
        if dial_position == 0:
            num_zeros += 1

    print(num_zeros)


def part2(input):
    num_zeros = 0
    dial_position = 50

    for line in input:
        mul = -1 if line[0] == "L" else 1
        new_dial_position = dial_position + int(line[1:]) * mul

        if mul == 1:
            num_zeros += abs(new_dial_position // 100)
            new_dial_position = new_dial_position % 100
            dial_position = new_dial_position
        else:
            # careful that this means floor division, not truncation
            # i.e. -5 // 100 = -1
            num_zeros += abs(new_dial_position // 100)
            new_dial_position = new_dial_position % 100
            if dial_position == 0:
                num_zeros -= 1
            if new_dial_position == 0:
                num_zeros += 1
            dial_position = (new_dial_position + 100) % 100
    print(num_zeros)


if __name__ == "__main__":
    part1(test)
    part1(input)
    part2(test)
    part2(input)
