from random import *

counter = {
        'r': 'p', 'p': 's', 's': 'r'
        }

moves = ['r', 's', 'p']

def main():
    global counter, moves

    oppPoints, cPoints = 0, 0

    print("p1\tp2\t\tp1\tp2")

    while True:

        oppMove = ""

        if oppMove != "":
            cMove = counter[oppMove]
        else:
            cMove = moves[randint(0, 2)]

        oppMove = str(input())

        if counter[cMove] == oppMove:
            oppPoints += 1
        elif counter[oppMove] == cMove:
            cPoints += 1

        print(cMove, "\t", oppMove, "\t\t", cPoints, "\t", oppPoints)

main()

