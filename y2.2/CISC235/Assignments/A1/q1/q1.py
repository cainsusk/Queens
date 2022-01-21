import timeit as ti
import q1_fx as q1

# 1 Binary Search or Linear Search? 50 points #

def algorithm_a(ls, target):
    for val in ls:  # iterate through list s
        if val == target:  # if one of the elements of s is x, it will return true
            return True
    return False  # if x is not found in s then it will return false


def algorithm_b(ls, target):  # ls must be sorted !!
    if q1.binary_search(ls, target):
        return True
    return False


def sort_b(ls):  # sort list for algorithm_b
    lc = ls.copy()  # copy list because merge_sort affects the input and has no output
    q1.merge_sort(lc)
    return lc


def test(ls, k_target, func):  # test an algorithm func with list ls and targets k_target
    count = 0
    for i in range(len(k_target) - 1):  # iterate through all targets
        x = k_target[i]
        e = func(ls, x)
        if e:
            count += 1
    return count


def init_test(n=1000, k=10):  # initializes data for the test() function
    data = [q1.std_rand() for i in range(n)]  # initialize list of ints

    if k == 1:
        target = q1.std_rand()  # get random int for target

    else:
        target = []
        for i in range(k):
            if i < int(k / 2):  # ensures that half of the targets are not in the list
                target.append(q1.rand.randint(-1000, -1))  # because std_rand uses a range which is greater than 0
            else:
                target.append(data[q1.rand.randint(0, len(data) - 1)])
    return data, target


def experiment(k, time1, time2, func1, func2, k_step=1):
    rndm = True
    while time1 < time2:  # iterate until time 2 is faster than time1
        for i in range(k_step):
            if rndm:  # Add targets to the list without having to recreate the data
                k_x.append(q1.std_rand())
            if not rndm:
                k_x.append(s_a[q1.rand.randint(0, len(s_a) - 1)])
            rndm = not rndm
        k += k_step

        time1 = ti.Timer(lambda: test(s_a, k_x, func1)).timeit(number=1)  # time func1
        time2 = ti.Timer(lambda: test(s_b, k_x, func2)).timeit(number=1) + time_sort  # time func2 with sort time added

    print(f"\n\ntime_a at result_k:\t{time1:.10f}\ntime_b at result_k:\t{time2:.10f}\n")  # print final times
    return k


if __name__ == "__main__":
    k_start = 10  # number of targets to search initially
    n = 10000  # size of list to be searched

    s_a, k_x = init_test(n, k_start)
    s_b = sort_b(s_a)

    time_sort = ti.Timer(lambda: sort_b(s_a)).timeit(number=1)  # time sort algorithm, is added to time for algorithm_b
    time_a = ti.Timer(lambda: test(s_a, k_x, algorithm_a)).timeit(number=1)  # time search algorithms
    time_b = ti.Timer(lambda: test(s_b, k_x, algorithm_b)).timeit(number=1) + time_sort

    print(f"\n\ntime a:\n{time_a:.10f}\n\ntime b:\n{time_b:.10f}")  # print initial times
    result_k = experiment(k_start, time_a, time_b, algorithm_a, algorithm_b)  # run experiment
    print(f"size of list(n):\n{n}\ncritical point(result_k):\n{result_k}")  # print final result of experiment
