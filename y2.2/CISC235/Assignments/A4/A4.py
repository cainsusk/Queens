from random import randint

class Graph:
    V = []
    E = []
    W = []

    # dont really understand what is happening here,
    # havent tested it yet...
    def randGraph(self, n: int) -> None:
        V = range(1,n)
        for v in V:
            k, a = randint(1, v-1), randint(1, v-1)
            
            S = range(a, (a+k)%v)

            for s in S:
                w = randint(10,100)

                self.E.append((v, s))
                self.W[s] = w








if __name__ == "__main__":
    print('hello there sir')

