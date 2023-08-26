//
//  Piece.cpp
//

#include "Piece.h"

namespace cs31 {

Piece::Piece() : mColor(NOTVALID) {}    // if no arguments, it is NOT VALID

Piece::Piece (COLOR color) : mColor(color) {};  // build a Piece based on COLOR param

Piece::Piece (char c) { pickColor (c); }        // build a Piece based on char param

Piece::Piece (std::string s) {    // build a Piece based on first letter of str param
    if (s.length() > 0)
        pickColor (s.at(0));      // s.at(0) is a CHAR -- valid param for pickColor
}

void Piece::pickColor (char c) {  // if param passed into Piece is not already a COLOR
    switch (c) {
        case 'B':
        case 'b':
            mColor = BLUE;
            break;
        case 'G':
        case 'g':
            mColor = GREEN;
            break;
        case 'O':
        case 'o':
            mColor = ORANGE;
            break;
        case 'P':
        case 'p':
            mColor = PURPLE;
            break;
        case 'R':
        case 'r':
            mColor = RED;
            break;
        case 'Y':
        case 'y':
            mColor = YELLOW;
            break;

        default:
            mColor = NOTVALID;
            break;
    }
}

COLOR Piece::getColor() const { return mColor; }

std::string Piece::getColorAsString() const {
    std::string s;
    switch (mColor) {
        case BLUE:
            s = "B";
            break;
        case GREEN:
            s = "G";
            break;
        case ORANGE:
            s = "O";
            break;
        case PURPLE:
            s = "P";
            break;
        case RED:
            s = "R";
            break;
        case YELLOW:
            s = "Y";
            break;

        default:
            s = " ";
            break;
    }
    return s;
}

}
