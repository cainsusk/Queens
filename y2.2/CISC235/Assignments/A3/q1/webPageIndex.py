#!/usr/bin/env python3

class webPageIndex:
    # Question 1.1 (1)
    def __init__(self, file: str) -> None:
        
        #=-= Read Input =-=#
        txt_file = open(file, 'r')
        text = txt_file.read()

        #=-= clean up Input =-=#
        text = text.lower()
        words = text.split()
        words = [word.strip('.,!;()[]') for word in words]
        words = [word.replace("'s", '') for word in words]

        #=-= initialize fields =-=#
        self.words = words
        self.name = file

    # Question 1.1 (2)
    def getCount(self, target: str) -> int:

        #=-= Clean String =-=#
        target = target.lower()

        #=-= Count Occurences =-=#
        count = 0
        for word in self.words:
            if word == target:
                count = count + 1 
                
        return count

    def getName(self) -> str:
        return self.name

    def __toString__(self) -> None:
        print(f"wpi@ {self.name}")

# Question 1.1 (3)
if __name__ == '__main__':

    #=-== Change File Based on Data Location ==-=#
    filename = '../a3_files/data/doc1-arraylist.txt'
    #=-==-==-==-==-==-==-==-+-==-==-==-==-==-==-=#

    target = 'an'
    wpi = webPageIndex(filename)
    print(f"there are {wpi.getCount(target)} occurences of '{target}' in {filename}")
