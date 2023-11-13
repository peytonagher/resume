# Project 3: Sorting Algorithms

**Due Thursday, February 16 @ 9:00 PM ET**

*This is not a team project, do not copy someone else's work.*

*Make sure to read the entire project description, especially the grading policies.*

## Background Information

![](img/sorting_comparison.png)

A **sorting algorithm** is an algorithm that puts elements in
a [certain order](https://en.wikipedia.org/wiki/Total_order). Such algorithms are often used to organize an array or
list in numerical or lexicographical order. However, their use is not limited in scope to such simple orderings, a fact
that will be demonstrated in this project.

Throughout the 20th century, as the domain of problems to which computers were applied grew, so to did the size of data
sets that required sorting. This resulted in the rapid development of sorting algorithms. Simple *O(n^2)* algorithms,
such as selection and bubble sort, were supplemented by faster *O(n log(n))* algorithms, such as quick or merge sort.
Still, these *O(n^2)* algorithms have their place to this day because they are often faster for sorting small sets of
data. Optimized modern sorting methods use hybrid techniques, which leverage the recursive nature of quicksort or merge
sort by using these algorithms for large sets of data, but which use an algorithm such as insertion sort for the
smaller fragments of data that the input ends up being separated into.

This project will expose you to insertion sort, selection sort, bubble sort, merge sort, and quicksort. Additionally, it
will include a hybrid sort using merge and insertion sorts. Python's built in `list.sort` is actually based on
a ([somewhat more advanced](https://hg.python.org/cpython/file/tip/Objects/listsort.txt)) merge/insertion hybrid sort.

In addition to the overviews of each sort presented below, we encourage you to refer to the relevant sections in Zybooks. 

### Bubble Sort

![](img/bubble_sort.png)

Bubble sort is one of the simplest sorting algorithms, and it works by repeatedly traversing a list and swapping
adjacent elements whenever it finds two that are out of order. This traversal is then repeated until a complete
traversal is completed without having to do any swaps, which indicates that the list has been sorted.

Like selection and insertion sorts, it has *O(n^2)* worst/average case
time complexity, and can operate in-place for *O(1)* auxiliary space complexity. Bubble sort, however, tends to be the
slowest of the sorting algorithms mentioned here in practice.

### Insertion Sort

![](img/insertion_sort.png)

Insertion sort works by keeping track of sorted and unsorted portions of the list, and building up the sorted portion on
the lefthand side of the list. To start, the first element is considered sorted (a single-element list is always
sorted), and the remainder of the list is the unsorted portion. Next, the first element of the unsorted portion is
compared to each element of the sorted portion in reverse order until its proper place in the sorted portion is found.
Finally, the element from the unsorted portion is *inserted* into the list at the proper spot, which for arrays requires
a series of swaps. Each of these insertion steps increases the size of the sorted section by one, allowing the algorithm
to proceed with a new "first element of the unsorted section" until the entire list has been sorted.

Insertion sort has  *O(n^2)* worst/average case *O(n)* for the best case, and the same space complexity as bubble sort, but ittends to be a bit faster in practice. Insertion sort is especially well suited to sorting small lists.

### Selection Sort

![](img/selection_sort.png)

Selection sort works quite similarly to insertion sort, keeping a sorted and unsorted portion of the list, and building up the sorted portion one element at a time. The difference with selection sort is that instead of taking the first
element of the unsorted portion and inserting it at the proper spot, selection sort *selects* the smallest element of the unsorted portion on each pass, and puts it at the end of the sorted portion. This time, the entire list starts out
as the unsorted portion instead of the first element being sorted–the starting element of the sorted portion has to befound from the list like every other element since elements don't move after being put in the sorted portion.

To highlight the difference: insertion sort picks a spot for the next element by searching through the sorted portion,
selection sort picks an element for the next spot by searching through the unsorted portion.

Selection sort has identical time/space complexity for the worst case just like  bubble and insertion sorts, and like insertion sort is faster than
bubble sort. Still, insertion sort is usually preferred for small-data sorting.

### Merge Sort

![](img/merge_sort.png)

Merge sort is a more efficient algorithm than the three mentioned above. It works on the principle of [Divide and Conquer](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm), repeatedly breaking down a list
into several sublists until each sublist consists of a single element, then repeatedly merging pairs of these sublists
in a manner that results in a sorted list.

Unlike bubble, insertion, and selection sorts, merge sort is worst case *O(n log(n))*, so it scales much better to large
lists. While there are ways to write an in-place merge sort, the typical space complexity is [*O(n)*](https://stackoverflow.com/a/28641693).

### Quicksort

Quicksort is an advanced sorting algorithm which works differently from the others we've seen so far. Like merge sort,
it is recursive, but for each step a "pivot" element from the list is selected, and elements to the left and right of the pivot are swapped as needed so that the list is partitioned into elements less than the pivot and elements greater
than or equal to the pivot. Quicksort is then applied recursively to these partitions until the list is fully sorted.

Like merge sort, quicksort is average case *O(n log(n))*, but its worst case performance is *O(n^2)*. 
The performance of quicksort depends heavily on the method used for pivot selection, with the 
[median-of-three pivot selection algorithm](https://stackoverflow.com/a/7560859)
helping to avoid pitfalls common in more naive (e.g., random, first, last) selection techniques. 

In practice, quicksort is still popular because it performs well on array-backed lists by exploiting optimizations for [locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference). 
Merge sort may outperform it for very large data sets, and is usually preferred for linked lists. Both of these algorithms are significant improvements on the average case *O(n^2)* algorithms mentioned above.

### Hybrid Sorting

While merge sort has a better runtime complexity than insertion sort, it has some overhead from not being an in-place
sort, and insertion sort tends to be faster for sorting small amounts of data. This means that it is more efficient to
combine the two algorithms into a hybrid sorting routine, where the recursive list partitions that merge sort creates
are sorted by insertion sort instead of merge sort once they get small enough.

## Project Details


### **"There's a term for people who don't read the project details: unemployed" -Dr. Owen **

### Overview

In this project, you will be implementing: the bubble, insertion, selection, and merge sort algorithms. We will provide the completed code for the quicksort algorithm for your reference. While you don't have any assignment relating to the quicksort code on this project, we recommend looking through it to familiarize yourself with that algorithm. Multiple questions regarding quick sort 
will appear on your exam, so it is in your best interest to take some time to understand it. The merge sort that you implement will be a hybrid merge sort which defers to insertion sort for handling small lists.

All the sorting algorithms should accept a custom `comparator` argument which substitutes for `<` when comparing
items to put in the list. If calling `comparator(a, b)` returns `True`, you should read that result as "`a` should come before `b` in a sorted list."

There is also an argument `descending` which defaults to `False`. If
the `descending` argument is `True`, you should sort the list in descending order. Since you can sort the list in
descending order by flipping the order of the inputs of the comparator and leaving the other logic the same, it might be
helpful for you to write a *helper function*, perhaps called `do_comparison`, which takes elements `a` and `b`, the `comparator`, and `descending` as arguments, and tells you whether or not to put `a` before `b` in the sorted list. This helper function should only be a few lines!
Implementing this function is **highly recommended** as it greatly simplifies the logic in your sorting functions.

It is important to note that ***the comparator means strictly `<` and not `<=`***, so for descending you should
consider `comparator(b, a)` instead of `not comparator(a, b)`, since the second one would give you `a >= b` instead of 
`a > b`. If you did it the second way, your bubble sort might never stop swapping!

You can call the argument `comparator` the same as any other function, and the underlying function that gets called will
be whatever function was passed in for this argument. This takes advantage of the fact that Python has what are
called [first-class functions](https://en.wikipedia.org/wiki/First-class_function), meaning functions can be stored and
passed around the same way as any other type of value. The type of `comparator` is explained by this diagram:

![](img/comparator_diagram.png)

Also note that some arguments will be specified after the pseudo-argument `*,`. 
The arguments following the asterisk `*` are ["keyword-only" arguments](https://www.python.org/dev/peps/pep-3102/).
Keyword-only arguments are designed to prevent accidental miscalls that can occur with positional parameters.

```python
# Note the "argument" *, which some of the other arugments come after
def some_func(a, b, *, c, d):
    pass

# Ok
some_func(1, 2, c=3, d=4)

# will raise TypeError: some_func() takes 2 positional arguments but 4 were given
some_func(1, 2, 3, 4)
```

### Tips, Tricks, and Notes

- There are different ways to implement merge sort, but make sure you are aiming for a solution that will fit the time
  complexity! If your recursive calls are some form of `hybrid_merge_sort(data[1:])`, this will not be *O(n log(n))*, as this does not divide the input list in half.
- A recursive implementation of merge sort will be the easiest to write. As you split the arrays, you should switch to
  insertion sort as soon as the split arrays get smaller than threshold. This means each of the recursive calls should
  be using the same threshold, such that the threshold is considered at each recursive call.
- Make sure to pass `comparator` and `descending` properly for all recursive calls as well.
- Using a helper function to do your comparisons that takes `descending` into account will make your code much easier
  to write. Look at the `do_comparison` stub that's provided in the starter code.
- Try these web applications to visualize sorting algorithms:
  - <https://visualgo.net/bn/sorting>
  - <https://opendsa-server.cs.vt.edu/embed/mergesortAV> (good merge sort visualization)
  - <https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html>

### Assignment Specs

You will be given one file to edit, `solution.py`. You must complete and implement the following functions. Take note of
the specified return values and input parameters. 

***DO NOT USE BUILTIN SORT FUNCTIONS LIKE sort() or sorted() FOR THIS PROJECT IN ANY FUNCTION! DOING SO WILL FORFEIT ALL POINTS FOR THE FUNCTION.***

***Do not change the function signatures, including default values.***

***If you implement a function that passes the tests but does not use the specified sorting algorithm for that function*,
*you will not get **any** points for that function.***

Make sure to consult the lectures, Zybooks, and other resources available if
you are not sure how a given sorting algorithm works. To earn manual points, you must also meet the required time and
space complexity. Using the right algorithm will help!

**solution.py:**
- **selection_sort(data: List[T], \*, comparator: Callable[[T,T], bool], descending: bool = False)**
  - Given a list of values, sort that list in-place using the selection sort algorithm and the provided comparator,
    and perform the sort in descending order if `descending` is `True`.
  - **param data**: List of items to be sorted
  - **param comparator**: A function which takes two arguments of type `T` and returns `True` when the first argument
    should be treated as less than the second argument.
  - **param descending**: Perform the sort in descending order when this is `True`. Defaults to `False`.
  - Time Complexity: *O(n^2)*
  - Aux.Space Complexity: *O(1)*

- **bubble_sort(data: List[T], \*, comparator: Callable[[T,T], bool], descending: bool = False)**
  - Given a list of values, sort that list in-place using the bubble sort algorithm and the provided comparator,
    and perform the sort in descending order if `descending` is `True`.
  - **param data**: List of items to be sorted
  - **param comparator**: A function which takes two arguments of type `T` and returns `True` when the first argument
    should be treated as less than the second argument.
  - **param descending**: Perform the sort in descending order when this is `True`. Defaults to `False`.
  - Time Complexity: *O(n^2)*
  - Aux.Space Complexity: *O(1)*
  
- **insertion_sort(data: List[T], \*, comparator: Callable[[T,T], bool], descending: bool = False)**
  - Given a list of values, sort that list in-place using the insertion sort algorithm and the provided comparator,
    and perform the sort in descending order if `descending` is `True`.
  - **param data**: List of items to be sorted
  - **param comparator**: A function which takes two arguments of type `T` and returns `True` when the first argument
    should be treated as less than the second argument.
  - **param descending**: Perform the sort in descending order when this is `True`. Defaults to `False`.
  - Time Complexity: *O(n^2)*
  - Aux.Space Complexity: *O(1)*

- **hybrid_merge_sort(data: List[T], \*, threshold: int = 12, comparator: Callable[[T,T], bool], descending: bool = False)**
  - Given a list of values, sort that list using a hybrid sort with the merge sort and insertion sort
    algorithms and the provided comparator, and perform the sort in descending order if `descending` is `True`.
    The function should use `insertion_sort` to sort lists once their size is less than or equal to `threshold`, and
    otherwise perform a merge sort.
  - **IMPORTANT**: Every semester there are students that don't actually implement a hybrid sort. These students generally make one of these mistakes:
    1. Check the threshold only once in hybrid_sort, and not for _every_ recursive call of merge_sort (if implemented separately).
    2. Call insertion_sort in each recursive call of merge sort, regardless of threshold
    3. Call merge_sort regardless of threshold
    4. Forget to pass threshold to each call of merge_sort
  - **param data**: List of items to be sorted
  - **param threshold**: Maximum size at which insertion sort will be used instead of merge sort. **Students frequently make mistakes with this, so be careful!**
  - **param comparator**: A function which takes two arguments of type `T` and returns `True` when the first argument
    should be treated as less than the second argument.
  - **param descending**: Perform the sort in descending order when this is `True`. Defaults to `False`.
  - Time Complexity: *O(n log(n))*
  - Aux. Space Complexity: *O(n)*

## Application: Blackjack (with a twist)! 

![](https://media.tenor.com/RFRPkimHjfcAAAAC/zach-galifianakis-very-bad-trip-meme.gif)

Congratulations! You've just been hired by a large, very well-to-do casino in Las Vegas to perform analysis 
on a brand new, proprietary version of Blackjack that they want to introduce in their tables. You might be wondering: Why are they
creating a new version of Blackjack? Well, while Blackjack tables often bring in many customers due to its simple rules,
recently a Blackjack genius by the name of *Zuck Galiphianeas* nearly cleaned out the entire casino! To prevent this from happening again,
the casino has decided to replace the Blackjack tables with their own version, and you will perform analysis on the possible starting hands you can have
in this game.

If you aren't familiar with the rules of Blackjack, or even want some strategies on how to win more, see [here](https://en.wikipedia.org/wiki/Blackjack#Rules_of_play_at_casinos).

This new version of Blackjack, frankly, is an aberration. Aces are always worth 11, the deck of cards
is random (and doesn't even have to be a full deck). On the bright side, you are still summing the values of your cards. You just want to focus on your task here and move on.

### Your Task

Your task is simple. You care only about the initial pair of cards a player is dealt. You need to complete the following class:

**NOTE THAT THE USE OF BUILTIN SORT FUNCTIONS IS PROHIBITED (yours above are fine, though)**
- **class SpecialBlackjack:**
  - **\_\_init\_\_(self, cards: list[Card]) -> None:**
    - Processes the list of cards so that the other function in this class can reach the required complexities.
    - **DO NOT ADD MORE DATA MEMBERS! (i.e. *self.data_member*)**
    - In Python, this method is called when the class is constructed.
    - **param cards**: List of Card objects (see below) that make up the current deck of cards.
    - Time Complexity: *O(n log(n)) (hint)*
    - Space Complexity: *O(n)*
  - **num_ways_to_get_sum(self, target: int) -> int:**
    - Finds the number of ways a pair of cards sum to *target*.
    - **IMPORTANT:** Once a pair of cards has been used to sum to *target*, those cards should no longer be considered for remaining sums (see examples).
    - Cards will need to be converted into number values at some point. This should be simple.
    - For testing, this function will be run 18 times, with *target* being every integer from 4 to 22, inclusive (i.e. the possible sums of a pair of card values). The testing result will be a dictionary where the keys are integers 4 through 22 and the values are the respective results for each key returned by this function.
    For example, if there are two ways to sum to 4, the value at key 4 in the dictionary will be 2.
    - **param target**: Integer representing the target sum of the card values.
    - **returns**: Integer representing the number of ways you can sum up a pair of card values to the target, with the restriction that each card can only be used once in a sum to the target.
    - Time Complexity: *O(n)*
    - Space Complexity: *O(1)*

**DO NOT MODIFY THIS CLASS**
- **class Card:**
  - **value(self):**
    - Returns the integer value of a Card object for use in your class above.
    - Face cards are worth 10 while aces are always worth 11.

### Examples

#### Example 1
```angular2html
cards = [Card('Hearts', '2')]
# Expected result:
{4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0, 10: 0, 
11: 0, 12: 0, 13: 0, 14: 0, 15: 0, 16: 0, 17: 0, 18: 0, 
19: 0, 20: 0, 21: 0, 22: 0}
```
##### Explanation:
When there is just one or zero cards, there are no ways that a pair of cards could sum to any number between 2 and 22, since there is no pair of cards possible.

#### Example 2
```angular2html
cards = [Card('Hearts', '2'), Card('Hearts', '3'), Card('Hearts', '4')]
# Expected result:
{4: 0, 5: 1, 6: 1, 7: 1, 8: 0, 9: 0, 10: 0, 
11: 0, 12: 0, 13: 0, 14: 0, 15: 0, 16: 0, 17: 0, 18: 0, 
19: 0, 20: 0, 21: 0, 22: 0}
```
##### Explanation:
There is exactly one way to add up to 5, 6, and 7 with a pair of cards each. They are
2 + 3, 2 + 4, and 3 + 4, respectively.

#### Example 3
```angular2html
cards = [Card('Hearts', 'Ace'), Card('Hearts', 'Queen'),
         Card('Hearts', 'King'), Card('Spades', 'Ace')]
# Expected result:
{4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0, 10: 0, 
11: 0, 12: 0, 13: 0, 14: 0, 15: 0, 16: 0, 17: 0, 18: 0, 
19: 0, 20: 1, 21: 2, 22: 1}
```
##### Explanation:
Kings and Queens are both worth 10 while Aces are always worth 11 (two aces are actually worth 22 here).
There is one way for a pair to sum to 20: it is adding the King and Queen. There is also one way for a pair to sum to 22: adding the two Aces.
However, there are only two ways for a pair to sum to 21 since once we take a set of cards that sum to 21,
like the Ace of Hearts and the Queen of Hearts, those cards can no longer be used. So, the only remaining way to sum to 21 is 
with the Ace of Spades and the King of Hearts. We cannot include the Ace of Hearts and the King of Hearts, even though their sum is 21.

## **Submission**


#### **Deliverables**
In every project you will be given a file named as "**solution.py**". Your will work on this file to write your Python code.
We recommend that you **download your "solution.py" and "tests.py" to your local drive**, and work on your project using PyCharm so you can easily debug your code.

Below are the simple steps to work on any project locally in your personal computer in this class:

**APPROACH 1: USING D2L TO DOWNLOAD PROJECT'S STARTER PACKAGE:**
1. Make sure you installed PyCharm
2. You can download the starter package from D2L under Projects content. Watch the short tutorial video on how to download the starter package from D2L and open it up in PyCharm.
3. Work on your project as long as you want then upload your solution.py , (watch the short tutorial video on D2L for uploading your solution.py), and upload your solution.py to Codio.
4. Click **Submit** and **Mark Complete** on Guide when you are done!
![](img/Submit.png)

**APPROACH 2: USING CODIO TO DOWNLOAD solution.py and tests.py**
1. On your own computer make sure to create a local folder in your local drive, name it something like **ProjectXX**, replace xx with the actual project number. 
2. **Download** solution.py from Codio by simply right mouse clicking on the file tree, see image below
![](img/Codio_FileTree.png)
3. **Download** tests.py from Codio by simply right mouse clicking on the file tree as shown above.
4. Work locally using PyCharm as long as you need. 
5. When finished with your solution.py file, upload your file to Codio by right mouse clicking on the Project Directory on file tree.You should rename or remove the solution.py file that is currently existing in Codio before you upload your completed version. 
6. Go To Guide and click Submit button
![](img/Codio_Upload.png)


**It does not matter which approach you choose to work on your project, just be sure to upload your solution, “solution.py”, to Codio by and click on the Submit button and Mark your work complete by its deadline.**

Working locally is recommended so you can learn debugging. You can complete your entire solution.py using Codio editor, debugging may not as intuitive as PyCharm IDE. For this reason we recommend that you work locally as long as you need, then upload your code to Codio.

### Grading

The following 100-point rubric will be used to determine your grade on Project 3:

- Policies
  - ***Making all of these policies bold or italic would get too visually fatiguing but read them all because they're
    important!***
  - Using a different sorting algorithm than the one specified for some function will result in the loss of all
    automated and manual points for that function.
  - Not making the merge sort hybrid will result in the loss of half of all automated and manual points for that
    function.
  - You will not receive any points on this project if you use Python's built-in sorting functions or sorting functions
    imported from any library.
  - You will not receive any points on the project if you use any list-reversing function such as `reversed`,
    `list.reverse`, or a homemade alternative to these. You must sort the lists in ascending or descending order
    directly.

- Tests (70)
- **NOTE**: The comprehensive tests are there to test the robustness of your sorting algorithms. They are worth **zero points each** due to the difficulties Helproom TAs face in debugging them, but we have decided to include them in the test suite for you to better gauge the effectiveness of your solutions.
- Sorts: __/50
    - Selection: __/11
      - test_selecton_sort_basic: __/3
      - test_selection_sort_comparator: __/4
      - test_selection_sort_descending: __/4
      - test_selection_sort_comprehensive: __/0
    - Bubble: __/11
      - test_bubble_sort_basic: __/3
      - test_bubble_sort_comparator: __/4
      - test_bubble_sort_descending: __/4
      - test_bubble_sort_comprehensive: __/0
    - Insertion: __/11
      - test_insertion_sort_basic: __/3
      - test_insertion_sort_comparator: __/4
      - test_insertion_sort_descending: __/4
      - test_insertion_sort_comprehensive: __/0
    - Hybrid Merge: __/17
      - test_hybrid_merge_sort_basic: __/4
      - test_hybrid_merge_sort_threshold: __/5
      - test_hybrid_merge_sort_comparator: __/4
      - test_hybrid_merge_sort_descending: __/4
      - test_hybrid_merge_sort_comprehensive: __/0
  - Application: __/20
    - test_special_blackjack: __/20
* **Manual (30 points)**
  * Time and Space complexity points are **divided equally** for each function. If you fail to meet time **or** space complexity in a given function, you receive half of the manual points for that function.
  * Loss of 1 point per missing docstring (max 5 point loss)
  * Loss of 2 points per changed function signature (max 20 point loss)
  * **Loss of complexity and loss of testcase points for the required functions in this project. You may not use any additional data structures such as dictionaries, and sets!”**
  * M1 - selection sort: \_\_/3
  * M2 - bubble sort: \_\_/3
  * M3 - insertion sort: \_\_/4
  * M4 - hybrid sort: \_\_/8
  * M5 - application \_\_init\_\_: \_\_/2
  * M6 - application num_ways_to_get_sum: \_\_/8
  * M7 - test\_feedback and citation: \_\_/2


- We probably don't have to tell you this if you made it this far but make sure to read the specs including all grading 
  requirements!

*This project was created by Joseph Pallipadan and Adam Kasumovic*



* **Important reminder**
Note students can not use Chegg or similar sites, see syllabus for details, **use of outside resources for the application problem is strictly forbidden**, use of outside resources is limited to max of 2 functions in a project.


    * **DOCSTRING** is not provided for this project. Please use Project 1 as a template for your DOCSTRING . 
    To learn more on what is a DOCSTRING visit the following website: [What is Docstring?](https://peps.python.org/pep-0257/)
      * One point per function that misses DOCSTRING.
      * Up to 5 points of deductions

<input type="checkbox"> <b>STEP 1 :Rename the old solution file by clicking Rename button below. This button renames your file to **solution_old.py** </b>
{Rename}(mv solution.py solution_old.py)
<input type="checkbox"> <b>STEP 2 : Refresh your file tree by clicking on the refresh button under project name or refresh your browser. </b>

<input type="checkbox"> <b>STEP 3 : Upload your **solution.py** from your computer to Codio File Tree on the left. Refresh your file tree or browser to see if it actually updated the solution.py </b>


<input type="checkbox"> <b>STEP 4:Submit your code, by clicking the Submit button, you can submit as many times as you like, no limit on submission. 


Submit button is tied to tests.py in our secure folder, and it always gets the updated version of the tests.py. In case of any tests.py update, students will always get the latest version to test their code through the submit button. 
{SUBMIT!|assessment}(test-3379255259)
Please note that there will be manual grading after you submit your work. Clicking Submit only runs the Auto-grader for the test cases. Manual Grading is 30 points in this project. (28 pts for Run Time and Space complexity, +2 points for filling out the feedback and the citation text box)


<input type="checkbox"> <b>STEP 5: Please make sure to **scroll all the way down on Guide Editor page**, Guide is the specs document, it is the document you are reading right now, scroll all the way down, and **click at the Mark as Completed button**, see below for the image of the button so you know what it looks like. Please scroll down and actually push the button. If you do not mark complete yourself, Codio will mark it at the end of the last penalty day, which will give 0 to your project. </b>
![](img/markcomplete.png)

{Check It!|assessment}(grade-book-3266829715)
{Submit Answer!|assessment}(free-text-3024451938)









