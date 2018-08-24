from random import *

movesFreq = dict()   #contains the frequency of all combinations 4 moves. I.e., what move is played the most frequently after any 3 moves

humanMoves = str()  #previous 4 moves

counter = { #the counter of the predicted move
            'r': 'p', 'p': 's', 's': 'r'
        }

moves = ['r', 'p', 's']

def main():
    global movesFreq, humanMoves, counter, moves
    rounds = 10000
    hPoints, cPoints = 0, 0

    print("p1\tp2\tp1\tp2")

    for i in range(0, rounds):
        hMove = str(input())

        cMove = nextMove()

        #print(cMove)
        
        if counter[cMove] == hMove:
            hPoints += 1
        elif counter[hMove] == cMove:
            cPoints += 1
        
        outUpdate(hMove, cMove, hPoints, cPoints)   #print standings
        
        if len(humanMoves) > 3:
            updatePredictions();
            humanMoves = humanMoves[1:] + hMove
        else:
            humanMoves += hMove

def outUpdate(hMove, cMove, hPoints, cPoints):
    print(hMove, "\t", cMove, "\t", hPoints, "\t", cPoints)

def updatePredictions():
    if humanMoves in movesFreq:
        movesFreq[humanMoves] += 1
    else:
        movesFreq[humanMoves] = 1

def nextMove():
    if len(humanMoves) < 4:
        return moves[randint(0, 2)]
    else:
        maxFreq = 0 #the most frequently used 4 consecutive moves
        maxMoves = ""

        for a in moves:
            temp = humanMoves[:3] + a

            if temp in movesFreq:

                if movesFreq[temp] > maxFreq:
                    maxMoves = temp + ""
                    maxFreq = movesFreq[temp]
        
        if maxMoves not in movesFreq or maxMoves == "":
            return moves[randint(0, 2)]
        else:
            return counter[maxMoves[3]]

main()
