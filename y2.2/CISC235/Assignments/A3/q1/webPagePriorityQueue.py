#!/usr/bin/env python3

import heapq 
import webPageIndex as wpi

#=-= Create node class for Queue =-=#
class node:
    def __init__(self, doc_name: str, doc_priority: int) -> None:
        self.name = self.name.append(doc_name)
        self.place = doc_priority

    def getName(self) -> str:
        return self.name

    def getPlace(self) -> int:
        return self.place

    def __toString__(self) -> None:
        print(f"name:\t{self.name}\nplace:\t{self.place}")

class webPagePriorityQueue:

    # Question 1.2 (1)
    def __init__(self, pages: list, query: str) -> None:
        data = {}
        for page_indx in pages:
            place_sum = 0
            for q in query:
                place_sum = (place_sum + page_indx.getCount(q))
                
            data[place_sum] = page_indx

        #=-= Initialize Queue Fields =-=#
        self.data = data 
        # Question 1.2 (2)
        self.query = query

    # Queston 1.2 (3)
    def peak(self) -> list:
        return heapq.nlargest(1, self.data)

    def peakn(self, n: int) -> list:
        return heapq.nlargest(n, self.data)

    # Question 1.2 (4)
    def poll(self):
        peak = heapq.nlargest(1, self.data)
        return self.data.pop(peak[0])

    def polln(self, n: int):
        for _ in range(n):
            self.poll()

    # Question 1.2 (5)
    def reheap(self, query: list):
        data = {}
        for i in self.data:
            place_sum = 0
            for q in query:
                place_sum = place_sum + self.data[i].getCount(q)
                
            data[place_sum] = self.data[i]
        self.data = data


if __name__ == "__main__":
    doc1 = '../a3_files/data/doc1-arraylist.txt'
    doc2 = '../a3_files/data/doc2-graph.txt'
    doc3 = '../a3_files/data/doc3-binarysearchtree.txt'
    doc4 = '../a3_files/data/doc4-stack.txt'

    docs = [doc1, doc2, doc3, doc4]
    query = 'binary tree'
    docs_indx = []

    for doc in docs:
        indx = wpi.webPageIndex(doc)
        docs_indx.append(indx)

    priqueue = webPagePriorityQueue(docs_indx, query)
    print(f'\nFiles in Priority Queue with the query: \'{priqueue.query}\'')
    for i in priqueue.data:
        print(f"{i}:\t{priqueue.data[i].getName()}")

    print('\nHighest Priority File in Queue')
    BIGpri = priqueue.peak()
    print(priqueue.data[BIGpri[0]].getName())

    print('\nnow, this is the priority queue after a poll')
    priqueue.poll()
    for i in priqueue.data:
        print(f"{i}:\t{priqueue.data[i].getName()}")

    new_query = 'the'
    print(f"\nfinally, the heap is reheaped with: {new_query}")
    priqueue.reheap([new_query])
    for i in priqueue.data:
        print(f"{i}:\t{priqueue.data[i].getName()}")









