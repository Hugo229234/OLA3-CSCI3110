#include "card.h"
#include <iostream>
#include <string>

using namespace std;
Card :: Card(int f, suit s){
    cardFace = f;
    cardSuit = s;
    if(f == 0){
        pointValue = 15;
    }
    else if(f >= 10){
        pointValue = 10;
    }
    else if(f == -1){
        pointValue = -1;
    }
    else{
        pointValue = f + 1;
    }
}

int Card :: getPointValue() const{
    return pointValue;
}

int Card :: getFaceValue() const{
    return cardFace;
}

suit Card :: getSuit() const{
    return cardSuit;
}

bool Card :: operator > (const Card& cd) const{
    if( (pointValue > cd.getPointValue()) ||
        (pointValue == cd.getPointValue() && cardFace > cd.getFaceValue()) ||
        ((pointValue == cd.getPointValue() && cardFace == cd.getFaceValue()) && cardSuit > cd.getSuit())){
        return true;
    }
    return false;
}

bool Card :: operator < (const Card& cd) const{
    if( (pointValue < cd.getPointValue()) ||
        (pointValue == cd.getPointValue() && cardFace < cd.getFaceValue()) ||
        ((pointValue == cd.getPointValue() && cardFace == cd.getFaceValue()) && cardSuit < cd.getSuit())){
        return true;
    }
    return false;
}

bool Card :: operator == (const Card& cd) const{
    if(pointValue == cd.getPointValue() && cardFace == cd.getFaceValue() && cardSuit == cd.getSuit()){
        return true;
    }
    return false;
}

ostream& operator << (ostream& os, const Card& cd){
    string faceValue, suitValue;
    for (int i = 0; i < 3; i++){
        switch(cd.getFaceValue()){
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
                faceValue = to_string(cd.getPointValue());
        }
        switch (cd.getSuit()) {
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
    }
    os << faceValue << suitValue << "[" << cd.getPointValue() << "]";
    return os;
}
