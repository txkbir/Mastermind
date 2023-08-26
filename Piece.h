//
//  Piece.h
//

#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "Enums.h"

namespace cs31 {

// This class is completely finished
class Piece {
public:
    Piece();                   // by default, a Piece will be invalid
    Piece (COLOR color);       // build a Piece based on the COLOR parameter
    Piece (char c);            // build a Piece based on the character parameter
    Piece (std::string s);     // build a Piece based on the first letter of the string parameter

    COLOR getColor() const;                 // cannot modify any private member variables
    std::string getColorAsString() const;   // converts a COLOR into its string representation

private:
    COLOR mColor;
    void pickColor (char c);
};

}

#endif
