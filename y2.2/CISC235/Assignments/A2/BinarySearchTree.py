class Node:
    def __init__(self, k, parent=None):
        self.key = k
        self.left = None
        self.right = None
        self.parent = parent

    def to_string(self):
        print(f"({self.key}) -> Left: {self.left}, Right: {self.right}")


class BinarySearchTree:
    """
    Must fulfill the following requirements
    ======================================
    any key in the tree must be:

     i) less than those to the right
    ii) greater than those to the left

    Must have the following functionality
    ======================================
    1) Insert Function
    2) Sum of Heights Function
    3) Weight Balance Factor Function - find the difference between the left & right tree for each node. return max of all
    4) Serialization & deSerialization Function

    5) tests for the above functions

    Implementation
    ======================================
    use nodes to store left and right keys but store actual keys as indices in a Dictionary of nodes.
    this should make the sorting of the nodes easier and reduce un-needed variables.
    """

    def __init__(self, node):
        self.tree = {node.key: node}
        self.root = node
        node.parent = 'ROOT'

    # 1)                                                             NOTE: following the exact algorithm from lesson 5-6
    def insert(self, val, root):
        if val in self.tree.keys():
            return
        # -=-LEFT SIDE-=- #
        if val <= root.key:
            if root.left is not None:
                self.insert(val, self.tree[root.left])
            else:
                root.left = val
                self.tree[val] = Node(val, root.key)

        # -=- RIGHT SIDE -=- #
        if root.key < val:
            if root.right is not None:
                self.insert(val, self.tree[root.right])
            else:
                root.right = val
                self.tree[val] = Node(val, root.key)

    # 2)
    def heights_sum(self) -> int:
        total = 0
        for key in self.tree:
            total = total + self.height(self.tree[key])
        return total

    def height(self, rootnode) -> int:
        if rootnode.left is None and rootnode.right is None:
            return 0
        else:
            try:
                l_h = self.height(self.tree[rootnode.left])
                r_h = self.height(self.tree[rootnode.right])
                if l_h > r_h:
                    return l_h + 1
                else:
                    return r_h + 1

            except KeyError:
                if rootnode.left is None:
                    r_h = self.height(self.tree[rootnode.right])
                    return r_h + 1
                if rootnode.right is None:
                    l_h = self.height(self.tree[rootnode.left])
                    return l_h + 1

    # 3)                                                    NOTE: outputs number of nodes below rootnode+1
    def weight_balance(self):
        w = []
        val = 0
        for key in self.tree:
            n = self.tree[key]
            if n.left is None and n.right is None:
                w.append(0)
            elif n.left is None:
                w.append(self.count_nodes(self.tree[n.right]))
            elif n.right is None:
                w.append(self.count_nodes(self.tree[n.left]))
            else:
                w.append(abs(self.count_nodes(self.tree[n.right]) - self.count_nodes(self.tree[n.left])))
        return max(w)

    def count_nodes(self, rootnode):
        if rootnode.left is None and rootnode.right is None:
            return 1
        else:
            try:
                return 1 + self.count_nodes(self.tree[rootnode.left]) + self.count_nodes(self.tree[rootnode.right])
            except KeyError:
                if rootnode.left is None:
                    return 1 + self.count_nodes(self.tree[rootnode.right])
                if rootnode.right is None:
                    return 1 + self.count_nodes(self.tree[rootnode.left])

    # 4)                            NOTE: this only works with this specific implementation. there was no specification
    #                                     otherwise
    def encode(self):
        code = []
        for key in self.tree.keys():
            code.append(key)
        return code

    def to_string(self):
        for key in self.tree:
            n = self.tree[key]
            print(f"{n.parent}\t>> ({n.key}) -> ({n.left}) || ({n.right})\n")


def decode(code):
    n = Node(code[0])
    decoded = BinarySearchTree(n)
    for key in code[1:]:
        decoded.insert(key, decoded.root)
    return decoded


if __name__ == '__main__':
    x = Node(5)

    bst = BinarySearchTree(x)
    bst.insert(7, bst.root)
    bst.insert(8, bst.root)
    bst.insert(10, bst.root)
    bst.insert(9, bst.root)
    bst.insert(2, bst.root)
    bst.insert(1, bst.root)
    bst.insert(3, bst.root)
    bst.insert(4, bst.root)

    bst.to_string()

    print(f"Height of root: {bst.height(bst.root)}")
    print(f"Sum of Heights: {bst.heights_sum()}")
    print(f"balanced weight factor: {bst.weight_balance()}")
    coded_bst = bst.encode()
    print(f"Encoded Tree: {coded_bst}")
    print("\nDecoded Tree\n========================")
    decoded_bst = decode(coded_bst)
    decoded_bst.to_string()
