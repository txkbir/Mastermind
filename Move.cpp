//
//  Move.cpp
//

#include "Move.h"
#include "Random.h"
#include <stdexcept>

namespace cs31 {

// by default, a move is four NOTVALIDs
Move::Move() {
    Piece p;        // invalid piece b/c default constructor sets COLORs to NOTVALID
    array[0] = p;
    array[1] = p;
    array[2] = p;
    array[3] = p;
}

Piece Move::getPiece (int i) {
    if (i >= 0 && i < REQUIREDLENGTH)
        return array[i];
    else    // if index is out of range
        throw std::logic_error ("invalid i value");
}

void Move::setPiece (int i, char c) {
    if (i >= 0 && i < REQUIREDLENGTH) {
        Piece p(c);
        array[i] = p;
    }
    else    // if index is out of range
        throw std::logic_error ("invalid i value");
}

void Move::setPiece (int i, Piece p) {
    if (i >= 0 && i < REQUIREDLENGTH)
        array[i] = p;
    else    // if index is out of range
        throw std::logic_error ("invalid i value");
}

void Move::setPiece (int i, std::string s) {
    if (i >= 0 && i < REQUIREDLENGTH)
        setPiece (i, s.at(0));
    else    // if index is out of range
        throw std::logic_error ("invalid i value");
}

void Move::setPieces (std::string s) {
    if (s.size() == REQUIREDLENGTH)
        for (int i = 0; i < REQUIREDLENGTH; i++)
            setPiece(i, s.at(i));
    else
        throw std::logic_error ("supplied word is not 4 characters");
}

// stringify this Move
std::string Move::to_string() const {
    std::string s;
    for (int i = 0; i < REQUIREDLENGTH; i++)
        s += array[i].getColorAsString();

    return s;
}

bool Move::isValid() const {
    bool result(true);
    for (int i = 0; i < REQUIREDLENGTH; i++) 
        if (array[i].getColor() == NOTVALID)
            result = false;

    return result;
}

void Move::random() {
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        Random r(VALIDCOLORCOUNT - 1);
        r.random();
        COLOR c = static_cast< COLOR > (r.getValue());
        Piece p(c);
        array[i] = p;
    }
}

}
