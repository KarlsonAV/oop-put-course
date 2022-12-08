from elf import Elf
from pair import Pair


if __name__ == "__main__":
    count_overlaps = 0
    with open("input.txt", mode='r') as file:
        lines = file.readlines()
        for line in lines:
            line1 = line
            line = line.strip().split(',')
            range1, range2 = line[0].split('-'), line[1].split('-')

            elf1 = Elf(range1)
            elf2 = Elf(range2)
            pair = Pair(elf1.section_range(), elf2.section_range())
            count_overlaps += pair.overlapped_completely()
    
    # Result: 415
    print(f"Total amount of overlaps - {count_overlaps}")

