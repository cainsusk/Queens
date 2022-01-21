import q3_fx as circlequeue


# 3 implement a circular queue 35 points #


def init_test() -> circlequeue.CircleQueue:
    queue = circlequeue.CircleQueue(5)  # tests if the init function is working:make a queue and print/dequeue it
    print(queue.to_string())
    print(queue.dequeue())
    return queue


def enqueue_dequeue_test(queue):
    for i in range(5):  # tests the enqueue and dequeue methods and their special cases (full or empty)
        print(queue.enqueue(i))
        print(queue.to_string())
    for i in range(5):
        print(queue.dequeue())
        print(queue.to_string())
    print(queue.dequeue())


if __name__ == '__main__':
    c_q = init_test()
    enqueue_dequeue_test(c_q)

