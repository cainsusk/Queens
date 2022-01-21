

class Stack:  # stack class
    def __init__(self):
        self.data = []

    def is_empty(self):  # returns true if stack is empty, false otherwise
        if not self.data:
            return True
        return False

    def push(self, elem):  # add an element to the top of the stack
        self.data.append(elem)

    def pop(self):  # removed the top element from the stack
        if self.is_empty():
            return "stack is empty!"
        return self.data.pop()

    def top(self):
        if self.is_empty():
            return "stack is empty!"
        return self.data[-1]

    def size(self):
        return len(self.data)

    def purge(self):  # remove all elems from the stack
        self.data.clear()

    def to_string(self):
        return f"{self.data}"
