"""little game of finding gold in the ocean"""

from random import randrange
from math import *
from os import system

class Screen():
    """Management of screen"""

    def __init__(self, horizontal, vertical, pixel):
        """create a screen of size = horizontal*vertical, each tile = pixel"""
        self.pixel = pixel
        self.x = horizontal
        self.y = vertical
        self.Board = list()

        for i in range(self.x):
            temp = []
            for j in range(self.y):
                temp.append(self.pixel)
            self.Board.append(temp)

    def set(self, posX, posY, char):
        """change a given position character"""
        self.Board[posX][posY] = char

    def getTreasure(self):
        """get all position of treasures"""
        posAll = list()
        for x in range(self.x):
            for y in range(self.y):
                if self.Board[x][y] == "X":
                    posAll.append([x,y])
        return posAll

    def getProbe(self):
        """get all position of treasures"""
        posAll = list()
        for x in range(self.x):
            for y in range(self.y):
                if self.Board[x][y] == "¤":
                    posAll.append([x,y])
        return posAll


    def draw(self):
        """draw the ocean"""

        print(" ",end='')
        for i in range(self.x):
            if i%10 == 0:
                print(i//10, end='')
            else:
                print(' ', end='')
        print()

        print("/", end='')
        #print the second guideline :
        for i in range(int(self.x/10)):
            for j in range(10):
                print(j, end='')
        for k in range(self.x - int(self.x/10)*10):
            print(k, end='')

        print()
        for y in range(self.y):
            print(y, end='')
            for x in range(self.x):
                print(self.Board[x][y], end='')
            print()


def getShortestRange(treasureList, probe):
    distance = 1000 #big value for getting the first following condition
    for i in range(len(treasureList)):
        vector = [treasureList[i][0]-probe[0], treasureList[i][1]-probe[1]]
        if sqrt(vector[0]**2 + vector[1]**2) < distance :
            distance = sqrt(vector[0]**2 + vector[1]**2)
    return int(distance)

#------------------------------

xmax = 31
ymax = 5

board = Screen(xmax,ymax, "~")
trueBoard = Screen(xmax,ymax, "~")
hiddenBoard = Screen(xmax,ymax, "~")

for i in range(3):
    """random treasure generation"""
    randomPos = [randrange(xmax), randrange(ymax)]
    hiddenBoard.set(randomPos[0], randomPos[1], "X")

while len(hiddenBoard.getTreasure()) > 0:
    system("clear")
    try:
        print("Radar board :")
        board.draw()

        print("Already taken positions : ")
        trueBoard.draw()
        end = False

        while True:
            try:
                userRaw = input("Probe position > ")
                user = userRaw.split()
                user[0] = int(user[0])
                user[1] = int(user[1])
                break
            except KeyboardInterrupt :
                print("\nend of program")
                end = True
                break
            except ValueError :
                print("please give a valid position")
            except IndexError :
                print("please give x<space>y coordinates")
        if end == True:
            break

        board.set(user[0],user[1], "¤")

        probeRange = getShortestRange(hiddenBoard.getTreasure(), board.getProbe()[0])

        if probeRange == 0:
            board.set(user[0], user[1], "T")
            trueBoard.set(user[0], user[1], "¤")
            hiddenBoard.set(user[0], user[1], "¤")
        else :
            trueBoard.set(user[0], user[1], "¤")
            board.set(user[0], user[1], probeRange)
    except IndexError :
        print("This position is not on the board !")
