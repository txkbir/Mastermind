//
//  Move.h
//

#ifndef MOVE_H
#define MOVE_H
#include "Settings.h"
#include "Piece.h"

#include <string>

namespace cs31 {

// Move holds an array of Piece of the required length
// CS 31 students have TODO methods to complete documented below
class Move {
public:
    Move();     // by default, a move will be invalid
    
    void setPieces (std::string s);
    
    // various different ways to establish one Piece of this Move
    void setPiece (int i, char c);
    void setPiece (int i, std::string s);
    void setPiece (int i, Piece p);
    
    Piece getPiece (int i);
    
    std::string to_string() const;      // called whenever a Board is displayed
    
    bool isValid() const;
    void random();
    
private:
    Piece array[REQUIREDLENGTH];        // the ordered set of Pieces that makeup this Move
};

}

#endif
