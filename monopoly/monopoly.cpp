#include <cmath>
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <iomanip>

using namespace std;

int random(int max){
    return rand() % max;
}

int diceRoll(){
    return random(6) + random(6) + 2;
}

int chanceRoll(){
    return random(16);
}

int chestRoll(){
    return random(10);
}

int main(){
    srand(time(NULL));
    
    // number of rolls to simulate, numbers of rounds around board, number of visits per space, number of turns in jail now, current position);
    long long N, visits[40], moves = 0;
    int jailturns = 0, pos = 0;
    double frequency[40];  //  percentage of time spent on each space
    bool injail = false;
    string board[40] = {"start", "meditarrenean avenue", "community chest", "baltic avenue", "income tax", "reading railroad", "oriental avenue", "chance", "vermont avenue", "connecticut avenue", "in jail/visiting", "st. charles place", "electric company", "states avenue", "virginia avenue", "pennsylvania railroad", "st. james place", "community chest", "tennessee avenue", "new york avenue", "free parking", "kentucky avenue", "chance", "indiana avenue", "illinois avenue", "b&o railroad", "atlantic avenue", "ventnor avenue", "water works", "marvin gardens", "go to jail", "pacific avenue", "north carolina avenue", "community chest", "pennsylvania avenue", "short line", "chance", "park place", "luxury tax", "boardwalk"}; //name of each space
    int communityChest[16] = {0, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int chance[16] = {0, 5, 11, 24, 39, 10, -3, -2, -2, -3, -1, -1, -1, -1, -1, -1};
    int utilities[2] = {12, 28};
    int railroads[4] = {5, 15, 25, 35};
    memset(visits, 0, sizeof visits);
    cout << "number of rolls to simulate:\n";
    cin >> N;
    
    int tempRoll;

    while(N--){
        tempRoll = diceRoll();
        //cout << tempRoll << "\n";
        pos += tempRoll;
        ++moves;
        pos %= 40;
        ++visits[pos];
        if(board[pos] == "chance"){
            tempRoll = chanceRoll();
            if(tempRoll < 7){
                pos = tempRoll;
                ++visits[pos];
                ++moves;
            }else if(tempRoll == 7){
                pos -= 3;
                ++visits[pos];
                ++moves;
                if(board[pos] == "community chest"){
                    tempRoll = chestRoll();
                    if(communityChest[tempRoll] != -1){
                        pos = tempRoll;
                        ++visits[pos];
                        ++moves;
                    }
                }
            }else if(tempRoll < 10){
                for(int j = 0; j < 4; ++j){
                    if(pos < railroads[j]){
                        pos = railroads[j];
                        continue;
                    }
                }
                ++visits[pos];
                ++moves;
            }else if(tempRoll == 10){
                if(pos < utilities[0]) pos = utilities[0];
                else pos = utilities[1];
                ++visits[pos];
                ++moves;
            }
        }else if(board[pos] == "community chest"){
            tempRoll = chestRoll();
            if(communityChest[tempRoll] != -1){
                pos = tempRoll;
                ++visits[pos];
                ++moves;
            }
        }else if(board[pos] == "go to jail"){
            pos = 10;
            ++visits[pos];
            ++moves;
        }
    }

    for(int i = 0; i < 40; ++i){
        frequency[i] = double(visits[i]) / double(moves);
    }

    using std::cout;
    using std::setw;
    cout << left << setw(21) << "space" << setw(10) << "visits" << setw(12) << "frequency\n";
    for(int i = 0; i < 40; ++i){
        cout << left << setw(21) << board[i] << setw(10) << visits[i] << setw(12) << frequency[i] << "\n";
    }
    cout << "moves: " << moves << "\n";
}
