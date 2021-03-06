#include <iostream>
#include <string>
#include "player.h"

using namespace std;

Player :: Player(string pname){
    name = pname;
    // Initialize array -1 checks if no card
    for (int i = 0; i < 3; i++){
        hand[i] = Card(-1, suit :: diamonds);
        hasPlayed[i] = false;
    }
    score = 0;
}

string Player :: getName() const {
    return name;
}

void Player :: drawCard(Deck &dk){
    Card temp;
    // Enum through array
    for (int i = 0; i < 3; i++){
       // Checks if valid card in list
        if(hand[i].getPointValue() == -1){
            hand[i] = dk.dealCard();
            hasPlayed[i] = false;
            // Only deal one card
            break;
        }
    }
//    for (int i = 0; i < 3; i++){
//        for(int j = i + 1; j < 3; j++){
//            if(hand[i] > hand[j]){
//                temp = hand[i];
//                hand[i] = hand[j];
//                hand[j] = temp;
//            }
//        }
//    }
}

void Player :: addScore(Card acard){
    score += acard.getPointValue();
}

int Player :: getScore() const{
    return score;
}

bool Player :: emptyHand() const{
   // Checks if valid card in list
    if(hand[0].getPointValue() == -1 &&
       hand[1].getPointValue() == -1 &&
       hand[2].getPointValue() == -1){
        return true;
    }
    else{
        return false;
    }
}

Card Player :: playCard(){
    int pos = 0;
    Card highHand = hand[0];
    // Stores highest card
    Card temp;
    // Enum through brute force and order cards lowest to highest
//    for (int i = 0; i < 3; i++){
//        for(int j = i + 1; j < 3; j++){
//            if(hand[i] > hand[j]){
////                hasPlayed[0] = false;
////                hasPlayed[1] = false;
////                hasPlayed[2] = false;
//                temp = hand[i];
//                hand[i] = hand[j];
//                hand[j] = temp;
//                temp = hand[j];
////                hasPlayed[j] = true;
//
////                hand[j] = Card(-1, suit :: diamonds);
//            }
//        }
//    }
    
    for(int i = 1; i < 3; i++){
        if(hand[i] > highHand){
            highHand = hand[i];
            pos = i;
        }
    }
//    cout << "Highest Card POSITION: " << pos << endl;
    // Only the 3rd card in array will be played
    hasPlayed[pos] = true;
    // Holds highest card
    temp = hand[pos];
    // Sets the highest card to a non-valid
    hand[pos] = Card(-1, suit :: diamonds);
    return temp;
}

ostream& operator << (ostream& os, const Player& player){
    for (int i = 0; i < 3; i++){
        if(player.hasPlayed[i]){
            os << "_____  ";
        }
        else{
            os << player.hand[i] << "  ";
        }
    }
    return os;
}
