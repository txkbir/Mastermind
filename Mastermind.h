//
//  Mastermind.h
//

#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "Settings.h"
#include "Board.h"
#include "Score.h"
#include "Move.h"
#include "Enums.h"
#include <string>

namespace cs31 {
// The Mastermind object plays the game
// It holds a Board, a winning Move, the current Score and a round count
// CS 31 students have TODO methods to complete documented below
class Mastermind {
public:
    Mastermind();                   // by default, selects a random move as the answer
    
    Mastermind (Move m);            // specify the winning word as a Move
    
    Mastermind (std::string s);     // specify the winning word as a string
   
    // stringify this Mastermind object which occurs repetitively
    // as the game proceeds
    std::string display (std::string msg = "") const;
    
    Move play (std::string turn);   // convert the entered string into a Move object
    
    Score endRound (Move m);
    
    // construct a GAMEOUTCOME based on the state of this Mastermind game
    GAMEOUTCOME determineGameOutcome() const;
    
    // stringify the current GAMEOUTCOME value
    std::string gameOutcomeAsString() const;

    bool gameIsOver() const;        // is the game over?

    Board getBoard() const;         // trivial getter
    
    std::string answer() const;     // what is the winning word?
private:
    int mRound;                     // the game's current round of play
    Board mBoard;                   // this game's Board
    Move mWinningMove;              // this game's winning Move
    Score mCurrentScore;            // this game's current Score
};

}


#endif

