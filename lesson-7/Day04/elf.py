class Elf:
    def __init__(self, section_range: list):
        self.__section_range = list(map(lambda x: int(x), section_range))

    def section_range(self) -> list:
        return self.__section_range