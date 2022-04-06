import numpy as np
import networkx as nx
from random import randint
import matplotlib.pyplot as plt
from scipy.sparse import csr_matrix
from scipy.sparse.csgraph import breadth_first_tree, connected_components, minimum_spanning_tree

class Graph:
    N: int           # Size of Graph
    Amat:  np.matrix # Adjacency Matrix
    Elst:  list      # Edge List
    Wlst:  list      # Weight List
    Tree:  np.matrix # BFS tree of Amat
    Prim:  np.matrix # Prims MST of Amat
    Mini:  np.matrix # MST of Amat
    
    test = np.matrix('0, 15, 0, 7, 10, 0; 15, 0, 9, 11, 0, 9; 0, 9, 0, 0, 12, 7; 7, 11, 0, 0, 8, 14; 10, 0, 12, 8, 0, 8; 0, 9, 7, 14, 8, 0')

    #==| Question 1.1 |==#
    def __init__(self, n: int) -> None:
        #=-= Warning !!!
        if (n < 10):
            return None

        #=-= Init size
        self.N = n
        self.Elst = []
        self.Wlst = []

        connected = False
        while(not connected):
            #=-= Init Adjacency Matrix
            self.Amat = np.zeros((n, n))

            for v in range(1, n):
                #=-= Randomly choose start (a) and range (k) of the sample S
                k,a = randint(1, v), randint(1, v) 
                S = [*range(a, (a+k)%n)]
                #=-= Connect edges in S to those in V
                for s in S:
                    if s == v:
                        pass
                    else:
                        w = randint(10,99)
                        self.Amat[s,v] = w
                        #=-= Add edge to edge list
                        if (s,v) not in self.Elst and (v,s) not in self.Elst:
                            self.Elst.append((s,v))
                            self.Wlst.append(w)
            #=-= Check if graph is connected
            X = connected_components(csr_matrix(self.Amat), directed=False, return_labels=False)
            if X == 2:
                connected = True
            
    #==| Question 1.2 |==#
    def BFS(self) -> int:
        #=-= Prepare data
        X = csr_matrix(self.Amat)
        s = randint(0, self.N-1)

        #=-= Breadth First Search
        t: csr_matrix = breadth_first_tree(X, s, directed=False)
        #==| Question 1.3 |==#
        # In order to modify the BFS() function to perform BFS on
        # *directed* graphs, all one would need to do is
        # change the 'directed' boolean to true

        #=-= Post-processing
        self.Tree = t.toarray()
        return np.sum(t)

    #==| Question 1.4 |==#
    def PMST(self):
        #=-= Init Variables
        n = self.N
        E = self.Elst
        W = self.Wlst

        #=-= Output list
        S = []

        #=-= remaining verticies
        Q = [*range(1, n)]
        #=-= removed verticies
        v = Q.pop(randint(1, n-2))
        T = [v]

        #=-= While there are still verticies to be added to the tree...
        while len(Q) != 0:
            lightest = float('inf')
            #=-= Find the lightest edge which connects any node in Q to any in Q
            for (w,e) in zip(W, E):

                x = e[0]
                y = e[1]

                if w < lightest and x in T and y in Q:
                    lightest = w
            
                    S.append((e, w))
                    T.append(y)
                    Q.remove(y)

                    E.remove(e)

                #=-= Checks for both permutations of coordinates
                elif w < lightest and y in T and x in Q:
                    lightest = w
            
                    S.append((e, w))
                    T.append(x)
                    Q.remove(x)

                    E.remove(e)

        #=-= Post Processing
        X = np.zeros((self.N, self.N))
        for s in S:
            e = s[0]
            w = s[1]

            X[e[0], e[1]] = w

        #=-= Sum of chosen weights
        return np.sum(X)
        
    #==| Bonus ? |==#
    def MST(self):
        X = csr_matrix(self.Amat)

        t: csr_matrix = minimum_spanning_tree(X)

        self.Prim = t.toarray()
        return np.sum(t)

def TEST() -> None:
    k = int(input("How Many Iterations? "))
    nDiff = []
    for n in [20, 40, 60]:
        diff = []
        for _ in range(k):
            G = Graph(n)
            
            bfs = G.BFS()
            prm = G.PMST()

            #smol = prm if prm < bfs else bfs

            diff.append(abs((bfs - prm)) / prm)
        
        nDiff.append(sum(diff)/k)
    print(f"The Results are:\n----------------\n20\t\t\t40\t\t\t60\n{nDiff[0]}\t{nDiff[1]}\t{nDiff[2]}\n----------------")

def help(A):
    Elst = []
    Wlst = []
    X = np.nonzero(A)
    for i in range(len(X[0])):
        Elst.append((X[0][i], X[1][i]))
        Wlst.append(A[X[0][i], X[1][i]])
    return [Elst, Wlst]

def show_graph_with_labels(adjacency_matrix, mylabels):
    rows, cols = np.where(adjacency_matrix == 1)
    edges = zip(rows.tolist(), cols.tolist())
    gr = nx.Graph()
    gr.add_edges_from(edges)
    nx.draw(gr, node_size=500, labels=mylabels, with_labels=True)
    plt.show()


#==| Question 1.5 |==#
if __name__ == "__main__":
    print("-----------\nCISC 235 A4\n-----------")
    
    #=-= Test BFS and PMST

    G = Graph(0)
    a = help(G.test)
    
    G.Amat = G.test
    G.Elst = a[0]
    G.Wlst = a[1]
    G.N = 6

    print(G.Amat)
    print("--- BFS ---")
    print(G.BFS())
    print("--- Prm ---")
    print(G.PMST())
    print("--- Test")

    TEST()
    

