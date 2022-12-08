class Pair:
    def __init__(self, range1: list, range2: list):
        self.__range1 = range1
        self.__range2 = range2

    def overlapped_completely(self) -> int:
        if self.__range1[0] >= self.__range2[0] and self.__range1[1] <= self.__range2[1]:
            return 1
        elif self.__range2[0] >= self.__range1[0] and self.__range2[1] <= self.__range1[1]:
            return 1
        else:
            return 0