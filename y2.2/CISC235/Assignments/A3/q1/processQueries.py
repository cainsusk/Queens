#!/usr/bin/env python3

import webPageIndex as wpi
import webPagePriorityQueue as wppq
from os import listdir
from os.path import isfile, join

def readFiles(path: str):
    onlyfiles = [path+f for f in listdir(path) if isfile(join(path, f))]
    docs = []
    print('these are the files in \'docs\'')
    for doc in onlyfiles:
        docs.append(wpi.webPageIndex(doc))
        print(doc)
    return docs

def main(docs: list, query_file: str):
    for q in open(query_file, 'r'):
        queue = wppq.webPagePriorityQueue(docs, q)
        print(f"search for {q} in docs")
        print(queue.poll().getName())
        print('----DONE----')

if __name__ == "__main__":
    pages = readFiles('../a3_files/data/')
    main(pages, '../a3_files/queries.txt')
