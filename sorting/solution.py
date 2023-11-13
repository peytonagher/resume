import random
import time
from typing import TypeVar, List, Callable, Dict
from dataclasses import dataclass

T = TypeVar("T")  # represents generic type


# do_comparison is an optional helper function but HIGHLY recommended!!!
def do_comparison(first: T, second: T, comparator: Callable[[T, T], bool],
                  descending: bool) -> bool:
    """
    Parameters:
    - first (T): The first element to be compared.
    - second (T): The second element to be compared.
    - comparator (Callable[[T, T], bool]): A callable that takes two arguments
        and returns a bool indicating whether the first argument should be
        ordered before the second.
    - descending (bool): A flag indicating whether the elements should be
        sorted in descending order. If True, the comparator will be called
        with the arguments reversed.

    Returns:
        bool: True if the elements should be swapped, False otherwise. The return
        value depends on the comparator function and the descending flag. If
        descending is False, the function returns comparator(first, second).
        If descending is True, the function returns comparator(second, first).
    """
    if descending:
        return comparator(second, first)
    else:
        return comparator(first, second)



def selection_sort(data: List[T], *, comparator: Callable[[T, T], bool]
                   = lambda x, y: x < y, descending: bool = False) -> None:
    """
    Parameters:
    - data (List[T]): The list of data to be sorted.
    - comparator (Callable[[T, T], bool], optional): A callable that takes two
        arguments and returns a bool indicating whether the first argument should
        be ordered before the second. Defaults to lambda x, y: x < y, which sorts
        the data in ascending order.
    - descending (bool, optional): A flag indicating whether the data should be
        sorted in descending order. If True, the comparator will be called with
        not descending to switch the sort order. Defaults to False.

    Returns:
        None, sorts the data in-place.
    """
    for i in range(len(data)):
        low_i = i

        for j in range(i + 1, len(data)):

            if do_comparison(data[j], data[low_i], comparator, descending):
                low_i = j

        if low_i != i:
            data[i], data[low_i] = data[low_i], data[i]



def bubble_sort(data: List[T], *, comparator: Callable[[T, T], bool]
                = lambda x, y: x < y, descending: bool = False) -> None:
    """
    Parameters:
    - data (List[T]): The list of data to be sorted.
    - comparator (Callable[[T, T], bool], optional): A callable that takes two
        arguments and returns a bool indicating whether the first argument
        should be ordered before the second. Defaults to lambda x, y: x < y,
        which sorts the data in ascending order.
    - descending (bool, optional): A flag indicating whether the data should be
        sorted in descending order. If True, the comparator will be called with
        data[j + 1] and data[j] reversed to switch the sort order.
        Defaults to False.

    Returns:
        None, sorts the data in-place.
    """
    n = len(data)
    for i in range(0, n - 1):
        for j in range(0, n - i - 1):
            if descending:
                if comparator(data[j], data[j + 1]):
                    data[j], data[j + 1] = data[j + 1], data[j]
            else:
                if do_comparison(data[j + 1], data[j], comparator, descending):
                    data[j], data[j + 1] = data[j + 1], data[j]



def insertion_sort(data: List[T], *, comparator: Callable[[T, T], bool]
                   = lambda x, y: x < y, descending: bool = False) -> None:
    """
    Parameters:
    - data (List[T]): The list of data to be sorted.
    - comparator (Callable[[T, T], bool], optional): A callable that takes two
        arguments and returns a bool indicating whether the first argument
        should be ordered before the second. Defaults to lambda x, y: x < y,
        which sorts the data in ascending order.
    - descending (bool, optional): A flag indicating whether the data should be
        sorted in descending order. If True, the comparator will be called with
        data[j] and key reversed to switch the sort order.
        Defaults to False.

    Returns:
        None, sorts the data in-place.
    """
    for i in range(1, len(data)):
        key = data[i]
        j = i - 1
        while j >= 0 and comparator(data[j], key) == descending:
            data[j + 1] = data[j]
            j -= 1
        data[j + 1] = key



def hybrid_merge_sort(data: List[T], *, threshold: int = 12,
                      comparator: Callable[[T, T], bool] = lambda x, y: x < y,
                      descending: bool = False) -> None:
    """
    Parameters:
    - data (List[T]): The list of data to be sorted.
    - threshold (int, optional): The threshold at which the algorithm switches
        from merge sort to insertion sort. If the number of elements being
        sorted is less than or equal to this threshold, insertion sort is used
        instead of merge sort. Defaults to 12.
    - comparator (Callable[[T, T], bool], optional): A callable that takes two
        arguments and returns a bool indicating whether the first argument should
        be ordered before the second. Defaults to lambda x, y: x < y, which sorts
        the data in ascending order.
    - descending (bool, optional): A flag indicating whether the data should be
        sorted in descending order. If True, the comparator will be called with
        left[i] and right[j] reversed to switch the sort order.
        Defaults to False.

    Returns:
        None, sorts the data in-place.
    """
    def merge_sort(data_ms: List[T], start: int, end: int):
        if end - start <= threshold:
            insertion_sort(data_ms, comparator=comparator, descending=descending)
        else:
            size = 1
            while size < end - start:
                left = start
                while left < end:
                    mid = left + size
                    right = min(mid + size, end)
                    merge(data_ms, left, mid, right)
                    left = right
                size *= 2

    def merge(data_m: List[T], start: int, mid: int, end: int):
        left = data_m[start:mid]
        right = data_m[mid:end]
        if descending:
            left.reverse()
            right.reverse()
        i = j = 0
        for k in range(start, end):
            if j == len(right) or (i < len(left)
                                   and do_comparison(left[i], right[j],
                                                     comparator, descending)):
                data_m[k] = left[i]
                i += 1
            else:
                data_m[k] = right[j]
                j += 1

    merge_sort(data, 0, len(data))



### DO NOT MODIFY ###
@dataclass
class Card:
    suit: str
    rank: str

    def value(self):
        if self.rank.isnumeric():
            return int(self.rank)
        else:
            return 10 if self.rank != "Ace" else 11


### MODIFY BELOW ###
class SpecialBlackjack:
    def __init__(self, cards: List[Card]) -> None:
        """
        Initializes a SpecialBlackjack game with the given cards.

        Parameters:
        - cards (List[Card]): A list of cards for the game.
        """
        card_list = []
        for card in cards:
            card_list.append(card.value())
        hybrid_merge_sort(card_list)
        self.cards = card_list
        # No extra data members are allowed (but you might want to do work here)

    def num_ways_to_get_sum(self, target: int) -> int:
        """
        Returns the number of ways to get the target sum using two cards from
        a list of cards sorted in ascending order.

        Parameters:
        - target (int): The target sum to be achieved using two cards.

        Returns:
            int: The number of ways to get the target sum using two cards
            from the list of cards.
        """
        num_ways = 0
        left = 0
        right = len(self.cards) - 1
        while left < right:
            sum_of_cards = self.cards[left] + self.cards[right]
            if sum_of_cards == target:
                num_ways += 1
                left += 1
                right -= 1
            elif sum_of_cards < target:
                left += 1
            else:
                right -= 1
        return num_ways
