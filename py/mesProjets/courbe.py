"""this is a program to draw a function in the terminal"""

from math import *

# yScreen
# ^
# |   x
# |  x
# | x
#--x---------->xScreen
# x
#x|
# |

def draw(Board, xRes, yRes):
    """it print the board where the function will be"""
    
    for y in range(len(Board[0])):
        #we print line by line so y is the first var
        for x in range(len(Board)):
            #here we print each value for a line
            print(Board[x][-1-y], end='')
            #-1-y to place the origin at bottom left and not top left

        print()

def f(x):
    y = 50*(1-exp(-x/20))
    return int(y)

def makeBoard(horizontal, vertical):
    """it create a list of list i.e. the 'screen' """

    board = list() #the screen is a x lists each of y values i.e. a list of lists
    for i in range(horizontal):
        temp = [] #temporary list for y values
        for j in range(vertical):
            temp.append(" ") #here is like a pixel

        board.append(temp) #we add a list of the y values
    return board

def placeOrigin(Board, x, y):
    """place the origin according to screen base"""
    for i in range(len(Board)):
        Board[i][y] = "-"
    for j in range(len(Board[0])):
        Board[x][j] = "|"

def applyF(Board, F):
    """apply the function on the board"""
    for t in range(len(Board)):
        Board[t][F(t)] = "X"

#------------------------------

board = makeBoard(120,60)

placeOrigin(board, 0, 0)
#you can't change the origin for now

applyF(board, f)

draw(board, 0, 0)
