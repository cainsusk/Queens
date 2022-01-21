import random as rand
import math as mat


def binary_search(ls, target):
    lft = 0  # initialize bounds used for searching
    size = len(ls)
    rgt = size - 1

    while lft != rgt:  # iterates until l(e)ft and r(i)g(h)t are at the same place
        m = mat.ceil((lft + rgt) / 2)

        if ls[m] > target:
            rgt = m - 1
        else:
            lft = m
    if ls[lft] == target:  # checks if lft equals target
        return True
    return False


def merge_sort(ls):
    if len(ls) > 1:

        mid = len(ls) // 2  # middle of list
        lft = ls[:mid]  # left half of list
        rgt = ls[mid:]  # right half of list

        merge_sort(lft)  # sort left half
        merge_sort(rgt)  # sort right half

        i = j = k = 0

        while i < len(lft) and j < len(rgt):  # Copy ls to temp arrays lft[] and rgt[]
            if lft[i] < rgt[j]:
                ls[k] = lft[i]
                i += 1
            else:
                ls[k] = rgt[j]
                j += 1
            k += 1

        while i < len(lft):  # Check if there are any remaining elements
            ls[k] = lft[i]
            i += 1
            k += 1

        while j < len(rgt):
            ls[k] = rgt[j]
            j += 1
            k += 1


def std_rand():  # easily callable random int generator
    return rand.randint(0, 1000)


def init_data(n=10) -> list[:]:  # initializes a list of random ints for size n
    data = [std_rand() for i in range(n)]
    return data


def init_target():  # creates a random target
    return std_rand()


def isworking(func):  # checks if an algorithm is working
    r = False
    while not r:  # iterates until a target is in the list
        s = init_data(10)
        x = init_target()
        r = func(s, x)
        print(f"\n\nsorted:\n{s}\n\ntarget:\n{x}\n\nfound:\n{r}")
