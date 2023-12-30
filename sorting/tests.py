import unittest
from collections import Counter
from itertools import combinations
from random import seed, shuffle
from typing import List

from solution import selection_sort, bubble_sort, insertion_sort, hybrid_merge_sort, SpecialBlackjack, Card

seed(331)


class Project4Tests(unittest.TestCase):

    def test_selection_sort_basic(self):
        # test with basic list of integers - default comparator
        data = [7, 4, 1, 0, 8, 9, 3, 2, 12]
        expected = sorted(data)
        selection_sort(data)
        self.assertEqual(expected, data)

        # test with basic list of strings - default comparator
        data = ["dog", "banana", "orange", "tree", "clutter", "candy", "silence"]
        expected = sorted(data)
        selection_sort(data)
        self.assertEqual(expected, data)

        # test with already sorted data - default comparator
        data = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        expected = sorted(data)
        selection_sort(data)
        self.assertEqual(expected, data)

        # test empty
        data = []
        selection_sort(data)
        self.assertEqual([], data)

        # check that function does not return anything
        data = [5, 6, 3, 2]
        self.assertIsNone(selection_sort(data))

    def test_selection_sort_comparator(self):
        # sort powers of ten by number of digits, in reverse
        data = [10 ** i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: -1 * len(str(x)))
        selection_sort(data, comparator=lambda x, y: len(str(x)) > len(str(y)))
        self.assertEqual(expected, data)

        # sort strings by length
        data = ['a' * i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(x))
        selection_sort(data, comparator=lambda x, y: len(x) < len(y))
        self.assertEqual(expected, data)

    def test_selection_sort_descending(self):
        # sort powers of ten by number of digits, in reverse
        data = [10 ** i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(str(x)), reverse=True)
        selection_sort(data, comparator=lambda x, y: len(str(x)) < len(str(y)), descending=True)
        self.assertEqual(expected, data)

        # sort strings by length
        data = ['a' * i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(x), reverse=True)
        selection_sort(data, comparator=lambda x, y: len(x) < len(y), descending=True)
        self.assertEqual(expected, data)

    def test_selection_sort_comprehensive(self):
        # *********************************************************
        # ***WORTH NO POINTS, FOR PERSONAL TESTING PURPOSES ONLY***
        # *********************************************************

        # sort a lot of integers
        data = list(range(1500))
        shuffle(data)
        expected = sorted(data)
        selection_sort(data)
        self.assertEqual(expected, data)

        # sort a lot of integers with alternative comparator
        # this comparator (defined as a named lambda) compares values as follows:
        #   x < y
        #   if and only if
        #   sum(digits(x)) < sum(digits(y))
        # ex: 12 < 15 since 1 + 2 = 3 < 6 = 1 + 5
        def comp(x, y): return sum([int(digit) for digit in str(x)]) < sum([int(digit) for digit in str(y)])
        data = list(range(1500))
        expected = sorted(data, key=lambda x: sum([int(digit) for digit in str(x)]))
        selection_sort(data, comparator=comp)
        # there are multiple possible orderings, thus we must compare via sums of digits
        for index, item in enumerate(expected):
            expected_sum = sum([int(digit) for digit in str(item)])
            actual_sum = sum([int(digit) for digit in str(data[index])])
            self.assertEqual(expected_sum, actual_sum)

    def test_bubble_sort_basic(self):
        # test with basic list of integers - default comparator
        data = [7, 4, 1, 0, 8, 9, 3, 2, 12]
        expected = sorted(data)
        bubble_sort(data)
        self.assertEqual(expected, data)

        # test with basic list of strings - default comparator
        data = ["dog", "banana", "orange", "tree", "clutter", "candy", "silence"]
        expected = sorted(data)
        bubble_sort(data)
        self.assertEqual(expected, data)

        # test with already sorted data - default comparator
        data = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        expected = sorted(data)
        bubble_sort(data)
        self.assertEqual(expected, data)

        # test empty
        data = []
        bubble_sort(data)
        self.assertEqual([], data)

        # check that function does not return anything
        data = [5, 6, 3, 2]
        self.assertIsNone(bubble_sort(data))

    def test_bubble_sort_comparator(self):
        # sort powers of ten by number of digits, in reverse
        data = [10 ** i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: -1 * len(str(x)))
        bubble_sort(data, comparator=lambda x, y: len(str(x)) > len(str(y)))
        self.assertEqual(expected, data)

        # sort strings by length
        data = ['a' * i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(x))
        bubble_sort(data, comparator=lambda x, y: len(x) < len(y))
        self.assertEqual(expected, data)

    def test_bubble_sort_descending(self):
        # sort powers of ten by number of digits, in reverse
        data = [10 ** i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(str(x)), reverse=True)
        bubble_sort(data, comparator=lambda x, y: len(str(x)) < len(str(y)), descending=True)
        self.assertEqual(expected, data)

        # sort strings by length
        data = ['a' * i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(x), reverse=True)
        bubble_sort(data, comparator=lambda x, y: len(x) < len(y), descending=True)
        self.assertEqual(expected, data)

    def test_bubble_sort_comprehensive(self):
        # *********************************************************
        # ***WORTH NO POINTS, FOR PERSONAL TESTING PURPOSES ONLY***
        # *********************************************************

        # sort a lot of integers
        # Smaller than the other comprehensive tests; bubble sort is slow!
        data = list(range(500))
        shuffle(data)
        expected = sorted(data)
        bubble_sort(data)
        self.assertEqual(expected, data)

        # sort a lot of integers with alternative comparator
        # this comparator (defined as a named lambda) compares values as follows:
        #   x < y
        #   if and only if
        #   sum(digits(x)) < sum(digits(y))
        # ex: 12 < 15 since 1 + 2 = 3 < 6 = 1 + 5
        def comp(x, y): return sum([int(digit) for digit in str(x)]) < sum([int(digit) for digit in str(y)])
        data = list(range(500))
        expected = sorted(data, key=lambda x: sum([int(digit) for digit in str(x)]))
        bubble_sort(data, comparator=comp)
        # there are multiple possible orderings, thus we must compare via sums of digits
        for index, item in enumerate(expected):
            expected_sum = sum([int(digit) for digit in str(item)])
            actual_sum = sum([int(digit) for digit in str(data[index])])
            self.assertEqual(expected_sum, actual_sum)

    def test_insertion_sort_basic(self):
        # test with basic list of integers - default comparator
        data = [7, 4, 1, 0, 8, 9, 3, 2, 12]
        expected = sorted(data)
        insertion_sort(data)
        self.assertEqual(expected, data)

        # test with basic list of strings - default comparator
        data = ["dog", "banana", "orange", "tree", "clutter", "candy", "silence"]
        expected = sorted(data)
        insertion_sort(data)
        self.assertEqual(expected, data)

        # test with already sorted data - default comparator
        data = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        expected = sorted(data)
        insertion_sort(data)
        self.assertEqual(expected, data)

        # test empty
        data = []
        insertion_sort(data)
        self.assertEqual([], data)

        # check that function does not return anything
        data = [5, 6, 3, 2]
        self.assertIsNone(insertion_sort(data))

    def test_insertion_sort_comparator(self):
        # sort powers of ten by number of digits, in reverse
        data = [10 ** i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: -1 * len(str(x)))
        insertion_sort(data, comparator=lambda x, y: len(str(x)) > len(str(y)))
        self.assertEqual(expected, data)

        # sort strings by length
        data = ['a' * i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(x))
        insertion_sort(data, comparator=lambda x, y: len(x) < len(y))
        self.assertEqual(expected, data)

    def test_insertion_sort_descending(self):
        # sort powers of ten by number of digits, in reverse
        data = [10 ** i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(str(x)), reverse=True)
        insertion_sort(data, comparator=lambda x, y: len(str(x)) < len(str(y)), descending=True)
        self.assertEqual(expected, data)

        # sort strings by length
        data = ['a' * i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(x), reverse=True)
        insertion_sort(data, comparator=lambda x, y: len(x) < len(y), descending=True)
        self.assertEqual(expected, data)

    def test_insertion_sort_comprehensive(self):
        # *********************************************************
        # ***WORTH NO POINTS, FOR PERSONAL TESTING PURPOSES ONLY***
        # *********************************************************

        # sort a lot of integers
        data = list(range(1500))
        shuffle(data)
        expected = sorted(data)
        insertion_sort(data)
        self.assertEqual(expected, data)

        # sort a lot of integers with alternative comparator
        # this comparator (defined as a named lambda) compares values as follows:
        #   x < y
        #   if and only if
        #   sum(digits(x)) < sum(digits(y))
        # ex: 12 < 15 since 1 + 2 = 3 < 6 = 1 + 5
        def comp(x, y): return sum([int(digit) for digit in str(x)]) < sum([int(digit) for digit in str(y)])
        data = list(range(1500))
        expected = sorted(data, key=lambda x: sum([int(digit) for digit in str(x)]))
        insertion_sort(data, comparator=comp)
        # there are multiple possible orderings, thus we must compare via sums of digits
        for index, item in enumerate(expected):
            expected_sum = sum([int(digit) for digit in str(item)])
            actual_sum = sum([int(digit) for digit in str(data[index])])
            self.assertEqual(expected_sum, actual_sum)

    def test_hybrid_merge_sort_basic(self):
        # test with basic list of integers - default comparator and threshold
        data = [7, 4, 1, 0, 8, 9, 3, 2, 12]
        expected = sorted(data)
        hybrid_merge_sort(data)
        self.assertEqual(expected, data)

        # test with basic set of strings - default comparator and threshold
        data = ["dog", "banana", "orange", "tree", "clutter", "candy", "silence"]
        expected = sorted(data)
        hybrid_merge_sort(data)
        self.assertEqual(expected, data)

        # test with already sorted data - default comparator and threshold
        data = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        expected = sorted(data)
        hybrid_merge_sort(data)
        self.assertEqual(expected, data)

        # test empty - default comparator and threshold
        data = []
        hybrid_merge_sort(data)
        self.assertEqual([], data)

        # check that function does not return anything
        data = [5, 6, 3, 2]
        self.assertIsNone(hybrid_merge_sort(data, threshold=0))

    def test_hybrid_merge_sort_threshold(self):

        # first, all the tests from basic should work with higher thresholds

        # test with basic list of integers - default comparator
        data = [7, 4, 1, 0, 8, 9, 3, 2, 12]
        expected = sorted(data)
        hybrid_merge_sort(data, threshold=2)
        self.assertEqual(expected, data)

        # test with basic set of strings - default comparator
        data = ["dog", "banana", "orange", "tree", "clutter", "candy", "silence"]
        expected = sorted(data)
        hybrid_merge_sort(data, threshold=2)
        self.assertEqual(expected, data)

        # test with already sorted data - default comparator
        data = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        expected = sorted(data)
        hybrid_merge_sort(data, threshold=2)
        self.assertEqual(expected, data)

        # now, for a longer test - a bunch of thresholds
        data = list(range(25))
        expected = sorted(data)
        for t in range(11):
            shuffle(data)
            hybrid_merge_sort(data, threshold=t)
            self.assertEqual(expected, data)

    def test_hybrid_merge_sort_comparator(self):
        # sort powers of ten by number of digits, in reverse
        data = [10 ** i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: -1 * len(str(x)))
        hybrid_merge_sort(data, comparator=lambda x, y: len(str(x)) > len(str(y)))
        self.assertEqual(expected, data)

        # sort strings by length
        data = ['a' * i for i in range(15)]
        shuffle(data)
        expected = sorted(data, key=lambda x: len(x))
        hybrid_merge_sort(data, comparator=lambda x, y: len(x) < len(y))
        self.assertEqual(expected, data)

    def test_hybrid_merge_sort_descending(self):
        # test with basic list of integers - default comparator, threshold of zero
        data = [7, 4, 1, 0, 8, 9, 3, 2, 12]
        expected = sorted(data, reverse=True)
        hybrid_merge_sort(data, threshold=0, descending=True)
        self.assertEqual(expected, data)

        # test with basic list of strings - default comparator, threshold
        data = ["dog", "banana", "orange", "tree", "clutter", "candy", "silence"]
        expected = sorted(data, reverse=True)
        hybrid_merge_sort(data, threshold=0, descending=True)
        self.assertEqual(expected, data)

        # test with already sorted data - default comparator, threshold
        data = [1, 2, 3, 4, 5, 6, 7, 8, 9]
        expected = sorted(data, reverse=True)
        hybrid_merge_sort(data, threshold=0, descending=True)
        self.assertEqual(expected, data)

        # test empty
        data = []
        hybrid_merge_sort(data, threshold=0, descending=True)
        self.assertEqual([], data)

        # check that function does not return anything
        data = [5, 6, 3, 2]
        self.assertIsNone(hybrid_merge_sort(data, threshold=0, descending=True))

        # now let's test with multiple thresholds
        data = list(range(50))
        expected = sorted(data, reverse=True)
        for t in range(20):
            shuffle(data)
            hybrid_merge_sort(data, threshold=t, descending=True)
            self.assertEqual(expected, data)

    def test_hybrid_merge_sort_comprehensive(self):
        # *********************************************************
        # ***WORTH NO POINTS, FOR PERSONAL TESTING PURPOSES ONLY***
        # *********************************************************

        # sort a lot of integers, with a lot of thresholds
        data = list(range(500))
        for t in range(100):
            shuffle(data)
            expected = sorted(data)
            hybrid_merge_sort(data, threshold=t)
            self.assertEqual(expected, data)

        # sort a lot of integers with alternative comparator, threshold of 8
        # this comparator (defined as a named lambda) compares values as follows:
        #   x < y
        #   if and only if
        #   sum(digits(x)) < sum(digits(y))
        # ex: 12 < 15 since 1 + 2 = 3 < 6 = 1 + 5
        def comp(x, y): return sum([int(digit) for digit in str(x)]) < sum([int(digit) for digit in str(y)])
        data = list(range(1500))
        expected = sorted(data, key=lambda x: sum([int(digit) for digit in str(x)]))
        hybrid_merge_sort(data, threshold=8, comparator=comp)
        # there are multiple possible orderings, thus we must compare via sums of digits
        for index, item in enumerate(expected):
            expected_sum = sum([int(digit) for digit in str(item)])
            actual_sum = sum([int(digit) for digit in str(data[index])])
            self.assertEqual(expected_sum, actual_sum)

        # sort a lot of integers with alternative comparator, thresholds in [1,...,49]
        # this comparator (defined as a named lambda) compares values as follows:
        #   x < y
        #   if and only if
        #   sum(digits(x)) < sum(digits(y))
        # ex: 12 < 15 since 1 + 2 = 3 < 6 = 1 + 5
        def comp(x, y): return sum([int(digit) for digit in str(x)]) < sum([int(digit) for digit in str(y)])
        data = list(range(1000))
        expected = sorted(data, key=lambda x: sum([int(digit) for digit in str(x)]))
        for t in range(50):
            shuffle(data)
            hybrid_merge_sort(data, threshold=t, comparator=comp)
            for index, item in enumerate(expected):
                expected_sum = sum([int(digit) for digit in str(item)])
                actual_sum = sum([int(digit) for digit in str(data[index])])
                self.assertEqual(expected_sum, actual_sum)

    # def test_hybrid_merge_sort_speed(self):
    #     # *********************************************************
    #     # ***WORTH NO POINTS, FOR PERSONAL TESTING PURPOSES ONLY***
    #     # *********************************************************
    #     # the point of this sort is to be fast, right?
    #     # this (probably) won't finish if you're not careful with time complexity
    #     # but it isn't a guarantee
    #     data = list(range(300000))
    #     expected = data[:]
    #     shuffle(data)
    #     hybrid_merge_sort(data)
    #     self.assertEqual(expected, data)

    def test_hybrid_merge_actually_hybrid(self):
        # *********************************************************
        # ***WORTH NO POINTS, FOR PERSONAL TESTING PURPOSES ONLY***
        # *********************************************************
        # this test is to make sure that the hybrid merge sort is actually
        # hybrid, i.e calls insertion sort when appropriate

        from collections.abc import MutableSequence
        from collections import defaultdict
        calling_functions = defaultdict(set)

        class MyList(MutableSequence):
            # This class was taken from
            # https://stackoverflow.com/questions/6560354/how-would-i-create-a-custom-list-class-in-python
            def __init__(self, data=None):
                super(MyList, self).__init__()
                self._list = list(data)

            def __delitem__(self, ii):
                """Delete an item"""
                del self._list[ii]

            def __setitem__(self, ii, val):
                self._list[ii] = val

            def insert(self, ii, val):
                self._list.insert(ii, val)

            def __len__(self):
                """List length"""
                return len(self._list)

            def __getitem__(self, ii):
                import inspect
                calling_functions[inspect.stack()[1].function].add(len(self))
                if isinstance(ii, slice):
                    return self.__class__(self._list[ii])
                else:
                    return self._list[ii]

        data = MyList(range(50))
        hybrid_merge_sort(data, threshold=2)
        self.assertIn('insertion_sort', calling_functions)
        self.assertIn('hybrid_merge_sort', calling_functions)
        self.assertTrue(all(length <= 2 for length in calling_functions['insertion_sort']))
        self.assertAlmostEqual(len(calling_functions['hybrid_merge_sort']), 10, delta=2)

    def test_special_blackjack(self):
        possible_totals = list(range(4, 23))

        def get_possible_totals_to_count(cards: List[Card]):
            def card_value(card: Card):
                if card.rank.isnumeric():
                    return int(card.rank)
                return 11 if card.rank == 'Ace' else 10
            nums = [card_value(card) for card in cards]
            totals = {num: 0 for num in possible_totals}
            for total in possible_totals:
                freqs = Counter(nums)
                for num1, num2 in combinations(nums, 2):
                    if freqs[num1] > 0 and freqs[num2] > 0 and num1 + num2 == total:
                        totals[total] += 1
                        freqs[num1] -= 1
                        freqs[num2] -= 1
            return totals

        def generate_actual(blackjack: SpecialBlackjack):
            return {num: blackjack.num_ways_to_get_sum(num) for num in possible_totals}

        # Test 1: Empty list, ensure returns all zeros
        cards = []
        blackjack = SpecialBlackjack(cards)

        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 1

        # Test 2: One card (2 of hearts), ensure returns all zeros
        cards = [Card('Hearts', '2')]
        blackjack = SpecialBlackjack(cards)

        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 2

        # Test 3: Two cards (2 of hearts, 3 of hearts), everything except 5 should be 0
        cards = [Card('Hearts', '2'), Card('Hearts', '3')]
        blackjack = SpecialBlackjack(cards)
        self.assertEqual(1, blackjack.num_ways_to_get_sum(5))  # 3
        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 3

        # Test 4: Two cards (Ace of spaces, 2 of hearts), everything except 13 should be 0
        # Remember that ace is always treated as 11
        cards = [Card('Spades', 'Ace'), Card('Hearts', '2')]
        blackjack = SpecialBlackjack(cards)
        self.assertEqual(1, blackjack.num_ways_to_get_sum(13))  # 4
        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 4

        # Test 5: Three cards (2 of hearts, 3 of hearts, 4 of hearts), 5, 6, 7 should be 1
        cards = [Card('Hearts', '2'), Card('Hearts', '3'), Card('Hearts', '4')]
        blackjack = SpecialBlackjack(cards)
        self.assertEqual(1, blackjack.num_ways_to_get_sum(5))  # 5
        self.assertEqual(1, blackjack.num_ways_to_get_sum(6))  # 5
        self.assertEqual(1, blackjack.num_ways_to_get_sum(7))  # 5
        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 5

        # Test 6: Four cards but with duplicates
        # (2 of hearts, 4 of hearts, 2 of spades, 4 of spades), 4 should be 1, 6 should be 2, 8 should be 1
        cards = [Card('Hearts', '2'), Card('Hearts', '4'),
                 Card('Spades', '2'), Card('Spades', '4')]
        blackjack = SpecialBlackjack(cards)
        self.assertEqual(1, blackjack.num_ways_to_get_sum(4))  # 6
        self.assertEqual(2, blackjack.num_ways_to_get_sum(6))  # 6
        self.assertEqual(1, blackjack.num_ways_to_get_sum(8))  # 6
        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 6

        # Test 7: Four cards with duplicates, face cards are also included (Ace of hearts, Queen of hearts, King of hearts, Ace of spades)
        # Recall that face cards are worth 10
        # 21 should be 2, 22 should be 1, 20 should be 1
        cards = [Card('Hearts', 'Ace'), Card('Hearts', 'Queen'),
                 Card('Hearts', 'King'), Card('Spades', 'Ace')]
        blackjack = SpecialBlackjack(cards)
        self.assertEqual(2, blackjack.num_ways_to_get_sum(21))  # 7
        self.assertEqual(1, blackjack.num_ways_to_get_sum(22))  # 7
        self.assertEqual(1, blackjack.num_ways_to_get_sum(20))  # 7
        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 7

        # Test 8: 10 cards
        cards = [Card('Hearts', 'Ace'), Card('Hearts', 'Queen'),
                 Card('Hearts', 'King'), Card('Clubs', 'Ace'),
                 Card('Spades', '2'), Card('Spades', '3'),
                 Card('Spades', '4'), Card('Spades', '5'),
                 Card('Spades', '6'), Card('Diamonds', '7')]
        blackjack = SpecialBlackjack(cards)

        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 8

        # Test 9: 20 cards
        cards = [Card('Hearts', 'Ace'), Card('Hearts', 'Queen'),
                 Card('Hearts', 'King'), Card('Clubs', 'Ace'),
                 Card('Spades', '2'), Card('Spades', '3'),
                 Card('Spades', '4'), Card('Spades', '5'),
                 Card('Spades', '6'), Card('Diamonds', '7'),
                 Card('Hearts', 'Ace'), Card('Hearts', 'Queen'),
                 Card('Hearts', 'King'), Card('Clubs', 'Ace'),
                 Card('Spades', '2'), Card('Spades', '3'),
                 Card('Spades', '4'), Card('Spades', '5'),
                 Card('Spades', '6'), Card('Diamonds', '7')]
        blackjack = SpecialBlackjack(cards)
        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 9

        # Test 10: Full deck
        cards = [Card('Hearts', 'Ace'), Card('Hearts', '2'),
                 Card('Hearts', '3'), Card('Hearts', '4'),
                 Card('Hearts', '5'), Card('Hearts', '6'),
                 Card('Hearts', '7'), Card('Hearts', '8'),
                 Card('Hearts', '9'), Card('Hearts', '10'),
                 Card('Hearts', 'Jack'), Card('Hearts', 'Queen'),
                 Card('Hearts', 'King'), Card('Clubs', 'Ace'),
                 Card('Clubs', '2'), Card('Clubs', '3'),
                 Card('Clubs', '4'), Card('Clubs', '5'),
                 Card('Clubs', '6'), Card('Clubs', '7'),
                 Card('Clubs', '8'), Card('Clubs', '9'),
                 Card('Clubs', '10'), Card('Clubs', 'Jack'),
                 Card('Clubs', 'Queen'), Card('Clubs', 'King'),
                 Card('Spades', 'Ace'), Card('Spades', '2'),
                 Card('Spades', '3'), Card('Spades', '4'),
                 Card('Spades', '5'), Card('Spades', '6'),
                 Card('Spades', '7'), Card('Spades', '8'),
                 Card('Spades', '9'), Card('Spades', '10'),
                 Card('Spades', 'Jack'), Card('Spades', 'Queen'),
                 Card('Spades', 'King'), Card('Diamonds', 'Ace'),
                 Card('Diamonds', '2'), Card('Diamonds', '3'),
                 Card('Diamonds', '4'), Card('Diamonds', '5'),
                 Card('Diamonds', '6'), Card('Diamonds', '7'),
                 Card('Diamonds', '8'), Card('Diamonds', '9'),
                 Card('Diamonds', '10'), Card('Diamonds', 'Jack'),
                 Card('Diamonds', 'Queen'), Card('Diamonds', 'King')]
        blackjack = SpecialBlackjack(cards)

        expected = get_possible_totals_to_count(cards)
        actual = generate_actual(blackjack)
        self.assertEqual(expected, actual)  # 10


if __name__ == '__main__':
    unittest.main()
