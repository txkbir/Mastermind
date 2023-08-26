//
//  Board.cpp
//

#include "Board.h"
#include <stdexcept>
#include <string>
#include <iostream>

namespace cs31 {
    Board::Board() : mRoundCount(0) {}
    
    // save this Move and Score into the set of Moves and Scores
    // being managed by this Board
    void Board::endRound (Move m, Score s) {
        if (mRoundCount < TOTALROUNDSALLOWED) {
            moves[mRoundCount] = m;
            scores[mRoundCount] = s;
            // increment to the next round
            mRoundCount++;
        } else {
            // throw an error rather than walk off the edge of the array
            throw std::logic_error ("invalid roundcount value");
        }
    }
    
    // print this Board
    // the Mastermind object repetitively calls
    // this operation as the game play proceeds
    std::string Board::display() const {
        
        std::string s = "\t\t  CS31 Mastermind Game\nR-red B-blue G-green Y-yellow, P-purple O-orange\n";
        if (mRoundCount > 0) {
            int i = 0;
            while (i < mRoundCount) {
                s += std::to_string (i + 1);
                s += " : ";
                s += moves[i].to_string();
                s += " - ";
                s += scores[i].to_string();
                s += "\n";
                i++;
            }
        }
        return s;
    }
    
    int Board::getCurrentRound() const { return mRoundCount; }


    Move Board::getMoveForRound (int round) const {
        if (round < mRoundCount && mRoundCount > 0)
            return moves[round];
        else
            throw std::logic_error ("invalid round");
    }


    Score Board::getScoreForRound (int round) const {
        if (round < mRoundCount && mRoundCount > 0)
            return scores[round];
        else
            throw std::logic_error ("invalid score");
    }

}
