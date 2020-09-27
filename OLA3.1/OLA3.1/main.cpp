#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;
int main(){
    string player1, player2;
    int x, roundNum = 1;
    ifstream myIn;
    Card p1CardPlayed, p2CardPlayed;
    myIn.open("cardgame.txt");
    //Read in player names and seed
    myIn >> player1 >> player2 >> x;
    
    // Random Seed
    srand(x);
    
    // Initialize players
    Player p1(player1), p2(player2);
    

    // Initialize Deck
    Deck theDeck;
    cout << theDeck << endl << endl;
    theDeck.Shuffle();
    cout << theDeck << endl << endl;
    if(p1.emptyHand()){
        cout<<"No Bands" << endl <<endl;
    }
    // Initialize hand
    for(int i = 0; i < 3; i++){
        p1.drawCard(theDeck);
        p2.drawCard(theDeck);
    }

    
    // Begin
    while(!p1.emptyHand()){
        cout << roundNum << ")  " << p1.getName() << "  " << p1 << "(" <<
        p1.getScore() << ") - " << p2.getName() << "  " << p2 << "(" << p2.getScore() << ")" << endl;
        
        p1CardPlayed = p1.playCard();
        p2CardPlayed = p2.playCard();
        
        
        // Check winner
        if(p1CardPlayed > p2CardPlayed){
            cout << roundNum << ")  " << p1.getName() << "* "<< p1 << "(" <<
            p1.getScore() << ") - " << p2.getName() << "  " << p2 << "(" << p2.getScore() << ")" << endl << endl;
            // Winner holds cards
            p1.addScore(p1CardPlayed);
            p1.addScore(p2CardPlayed);
        }
        else if (p1CardPlayed < p2CardPlayed){
            cout << roundNum << ")  " << p1.getName() << " "<< p1 << "(" <<
            p1.getScore() << ") - " << p2.getName() << "* " << p2 << "(" << p2.getScore() << ")" << endl << endl;
            // Winner holds cards
            p2.addScore(p1CardPlayed);
            p2.addScore(p2CardPlayed);
        }
        if(!theDeck.isEmpty()){
            p1.drawCard(theDeck);
            p2.drawCard(theDeck);
        }
        roundNum ++;
    }
    
    // Output Winner
    if(p1.getScore() > p2.getScore()){
        cout << "Winner " << player1 << " " << p1.getScore() << endl;
    }
    else if(p1.getScore() < p2.getScore()){
        cout << "Winner " << player2 << " " << p1.getScore() << endl;
    }
    else{
        cout << "Tie " << " " << p1.getScore() << endl;
    }

    return 0;
}
