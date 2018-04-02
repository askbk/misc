from random import *

counter = {
        'r': 'p', 'p': 's', 's': 'r'
        }

moves = ['r', 's', 'p']

def main():
    global counter, moves
    oppPoints, cPoints, result = 0, 0, 0
    oppMove = ""

    print("p1\tp2\t\tp1\tp2")

    while True:

        cMove = nextMove(oppMove, result)

        oppMove = str(input())

        if counter[cMove] == oppMove:
            oppPoints += 1
            result = -1
        elif counter[oppMove] == cMove:
            cPoints += 1
            result = 1
        else:
            result = 0

        print(cMove, "\t", oppMove, "\t\t", cPoints, "\t", oppPoints)

def nextMove(prevOpp, result):
    if result != 0:

        if result == 1:
            return prevOpp
        else:
            return counter[prevOpp]

    else:
        return moves[randint(0, 2)]

main()

