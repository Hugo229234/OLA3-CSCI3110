#include <algorithm>
#include "deck.h"
using namespace std;
Deck :: Deck(){
    topCard = 51;
    for(int i = 0; i <= 12; i++){
        theDeck[i] = Card(i, suit :: clubs);
        theDeck[i+13] = Card(i, suit :: hearts);
        theDeck[i+26] = Card(i, suit :: spades);
        theDeck[i+39] = Card(i, suit :: diamonds);
    }
}

void Deck :: Shuffle(){
    random_shuffle(begin(theDeck), end(theDeck));
}

Card Deck :: dealCard(){
    topCard--;
    return theDeck[topCard+1];
}

bool Deck :: isEmpty(){
    if(topCard == -1){
        return true;
    }
    return false;
}

ostream& operator << (ostream& os, const Deck& deck){
    string faceValue, suitValue;
    int count = 0;

    for (int i = 51; i >= 0; i--){
        switch(deck.theDeck[i].getFaceValue()){
            case 12:
                faceValue = 'K';
                break;
            case 11:
                faceValue = 'Q';
                break;
            case 10:
                faceValue = 'J';
                break;
            case 0:
                faceValue = 'A';
                break;
            default:
                faceValue = to_string(deck.theDeck[i].getPointValue());
        }
        switch (deck.theDeck[i].getSuit()) {
            case suit :: diamonds:
                suitValue = 'D';
                break;
            case suit :: clubs:
                suitValue = 'C';
                break;
            case suit :: hearts:
                suitValue = 'H';
                break;
            case suit :: spades:
                suitValue = 'S';
                break;
        }
        if(count == 13){
            count = 0;
            os << endl;
        }
        os << faceValue << suitValue << "[" << deck.theDeck[i].getPointValue() << "]" << " ";
        count ++;
    }
    return os;
}
