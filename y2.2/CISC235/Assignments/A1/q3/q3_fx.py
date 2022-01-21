

class CircleQueue:
    def __init__(self, max_size):
        self.data = [None] * max_size
        self.max = max_size
        self.size = 0
        self.h = 0  # head of queue
        self.t = 0  # tail of queue

    def enqueue(self, elem):
        if self.size == self.max:  # special case: full
            return "queue is full!"
        self.data[self.t] = elem  # set TAIL to elem
        self.size += 1  # increment size
        self.t = (self.t+1) % self.max  # increment TAIL without going outside the queue
        return True

    def dequeue(self):
        if self.size == 0:  # special case: empty
            return "queue is empty!"
        head = self.data[self.h]  # fetch value from HEAD
        self.data[self.h] = None  # replace value with None
        self.size -= 1  # decrement size
        self.h = (self.h+1) % self.max  # increment HEAD without going outside the queue
        return head

    def to_string(self):
        string = ""
        for i in range(self.max):  # iterates through each elem in the queue and prints the appropriate substring
            if i == self.h and i == self.t:  # handles elems that are HEAD and TAIL
                if self.data[i] is None:  # checks if elem is None or has value
                    add = "HEAD->[]->TAIL "
                else:
                    add = f"HEAD->[{self.data[i]}]->TAIL "
                string += add

            if i == self.h and i != self.t:  # handles if an elem is just HEAD
                if self.data[i] is None:  # checks if elem is None or has value
                    add = f"HEAD->[] "
                else:
                    add = f"HEAD->[{self.data[i]}] "
                string += add

            if i == self.t and i != self.h:  # handles if an elem is just TAIL
                if self.data[i] is None:  # checks if elem is None or has value
                    add = f"[]->TAIL "
                else:
                    add = f"[{self.data[i]}]->TAIL "
                string += add

            if i != self.h and i != self.t and self.data[i] is not None:  # handles if elem is just a value in the queue
                add = f"[{self.data[i]}] "
                string += add

            if i != self.h and i != self.t and self.data[i] is None:  # handles if elem is just None in the queue
                add = "[] "
                string += add
        return string
