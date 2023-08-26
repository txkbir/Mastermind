//
//  Board.h
//

#ifndef BOARD_H
#define BOARD_H

#include "Move.h"
#include "Score.h"
#include "Settings.h"
#include <string>

namespace cs31 {
// The Board object is repetitively displayed as the
// Mastermind game progresses
// It holds an array of Moves and Scores fed to it with calls to
// endRound that get printed later with a call to display
class Board {
public:
    Board();
    // save this Move and Score which will get printed later
    void endRound (Move m, Score s);
        
    int getCurrentRound() const;
        
    Move getMoveForRound (int round) const;
        
    Score getScoreForRound (int round) const;
        
    // print this Board
    std::string display() const;
private:
    // the current round of play so far
    int mRoundCount;
    
    // set of scores provided to this Board so far
    Score scores[TOTALROUNDSALLOWED];
    
    // set of moves provided to this Board so far
    Move moves[TOTALROUNDSALLOWED];
};

}

#endif
