class Node:
    # 1) implement Node (see AVT for height)
    def __init__(self, k, v, parent=None):
        self.key = k
        self.value = v
        self.left = None
        self.right = None

    def to_string(self):
        print(f"[{self.key}]={self.value} -> Left: {self.left}, Right: {self.right}")


class AVLTree():
    def __init__(self):
        self.node = None
        self.height = -1
        self.balance = 0

    # 2) implement put
    def put(self, key, val):  # insert val at key in avt
        tree = self.node

        newnode = Node(key, val)

        if tree is None:  # base case for induction
            self.node = newnode
            self.node.left = AVLTree()
            self.node.right = AVLTree()

        elif key < tree.key:
            self.node.left.put(key, val)

        elif key > tree.key:
            self.node.right.put(key, val)

        self.rebalance()

    def rebalance(self):  # rebalance AVT using algorithm
        self.update_heights(False)
        self.update_balances(False)
        while self.balance < -1 or self.balance > 1:
            if self.balance > 1:
                if self.node.left.balance < 0:
                    self.node.left.l_rotate()
                    self.update_heights()
                    self.update_balances()
                self.r_rotate()
                self.update_heights()
                self.update_balances()

            if self.balance < -1:
                if self.node.right.balance > 0:
                    self.node.right.r_rotate()
                    self.update_heights()
                    self.update_balances()
                self.l_rotate()
                self.update_heights()
                self.update_balances()

    def r_rotate(self):  # rebalance helper functions
        # Rotate left pivoting on self
        A = self.node
        B = self.node.left.node
        T = B.right.node

        self.node = B
        B.right.node = A
        A.left.node = T

    def l_rotate(self):
        # Rotate left pivoting on self
        A = self.node
        B = self.node.right.node
        T = B.left.node

        self.node = B
        B.left.node = A
        A.right.node = T

    def update_heights(self, recurse=True):
        if not self.node is None:
            if recurse:
                if self.node.left is not None:
                    self.node.left.update_heights()
                if self.node.right is not None:
                    self.node.right.update_heights()

            self.height = max(self.node.left.height,
                              self.node.right.height) + 1
        else:
            self.height = -1

    def update_balances(self, recurse=True):
        if not self.node is None:
            if recurse:
                if self.node.left is not None:
                    self.node.left.update_balances()
                if self.node.right is not None:
                    self.node.right.update_balances()

            self.balance = self.node.left.height - self.node.right.height
        else:
            self.balance = 0

    def height(self):  # evaluate height of avt
        if self.node:
            return self.node.height
        else:
            return 0

    def is_leaf(self):
        return self.height == 0

    # 3) implement get
    def get(self, target_key):
        tree = self.node

        if tree.key == target_key:
            print(f"@{tree.key}: {tree.value}")

        elif target_key < tree.key:
            self.node.left.get(target_key)

        elif target_key > tree.key:
            self.node.right.get(target_key)


if __name__ == '__main__':
    # 4) testing code
    avl = AVLTree()
    avl.put(15, 'bob')
    avl.put(20, 'anna')
    avl.put(24, 'tom')
    avl.put(10, 'david')
    avl.put(13, 'david')
    avl.put(7, 'ben')
    avl.put(30, 'karen')
    avl.put(36, 'erin')
    avl.put(25, 'david')
    avl.get(20)
    avl.get(13)
    avl.get(25)
    avl.get(7)
