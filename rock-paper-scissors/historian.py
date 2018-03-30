from random import *
from collections import deque

movesFreq = dict()   #contains the frequency of all combinations 4 moves. I.e., what move is played the most frequently after any 3 moves

humanMoves = str()  #previous 4 moves

counter = { #the counter of the predicted move
            'r': 'p', 'p': 's', 's': 'r'
        }

moves = ['r', 'p', 's']

def main():
    global movesFreq, humanMoves, counter, moves
    hPoints, cPoints = 0, 0

    while True:
        hMove = str(input("ur input ;): "))

        cMove = nextMove()
        
        if counter[cMove] == hMove:
            hPoints += 1
        elif counter[hMove] == cMove:
            cPoints += 1
        
        outUpdate(hMove, cMove, hPoints, cPoints)   #print standings
        
        updatePredictions();

        humanMoves = humanMoves[:3] + hMove

def outUpdate(hMove, cMove, hPoints, cPoints):
    print("you played ", hMove, ", computer played ", cMove, ". human: ", hPoints, " computer: ", cPoints, "\n")

def updatePredictions():
    if humanMoves in movesFreq:
        movesFreq[humanMoves] += 1
    else:
        movesFreq[humanMoves] = 1
    

def nextMove():
    if len(humanMoves) < 4:
        return moves[randint(0, 2)]
    else:
        maxFreq = humanMoves[:3] #the most frequently used 4 consecutive moves

        for a in moves:
            temp = maxFreq + a

            if temp in movesFreq:

                if movesFreq[temp] > movesFreq[maxFreq]:
                    maxFreq = temp + ""

        return maxFreq[3]

main()
