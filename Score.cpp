//
//  Score.cpp
//

#include "Score.h"
#include <stdexcept>

namespace cs31 {

// setup a default score - all WRONG ANSWERs
Score::Score() {
    for (int i = 0; i < REQUIREDLENGTH; i++)
        array[i] = WRONG;
}

// comparing the played move to the answer move
// build the ANSWER array of this Score
Score::Score (Move move, Move answer) : Score() {
    std::string s1 = move.to_string();
    std::string s2 = answer.to_string();
    
    // check for RIGHTs
    for (int i = 0; i < REQUIREDLENGTH; i++)
        if (s1.at(i) == s2.at(i))
            array[i] = RIGHT;
    
    int userRed = 0, userBlue = 0, userGreen = 0, userYellow = 0, userPurple = 0, userOrange = 0;
    
    for (int i = 0; i < REQUIREDLENGTH; i++)
        switch (s1.at(i)) {
            case 'R':
                userRed++;
                break;
                
            case 'B':
                userBlue++;
                break;
                
            case 'G':
                userGreen++;
                break;
                
            case 'Y':
                userYellow++;
                break;
                
            case 'P':
                userPurple++;
                break;
                
            case 'O':
                userOrange++;
                break;
                
            default:
                break;
        }
    
    if (userRed + userBlue + userGreen + userYellow + userPurple + userOrange != 4)
        throw std::logic_error ("your move doesn't have 4 colors");
   
    int red = 0, blue = 0, green = 0, yellow = 0, purple = 0, orange = 0;
    
    for (int i = 0; i < REQUIREDLENGTH; i++)
        switch (s2.at(i)) {
            case 'R':
                red++;
                break;
                
            case 'B':
                blue++;
                break;
                
            case 'G':
                green++;
                break;
                
            case 'Y':
                yellow++;
                break;
                
            case 'P':
                purple++;
                break;
                
            case 'O':
                orange++;
                break;
                
            default:
                break;
        }
    
    for (int i = 0; i < REQUIREDLENGTH; i++)
        if (array[i] == RIGHT)
            switch (s1.at(i)) {
                case 'R':
                    userRed--;
                    red--;
                    break;
                    
                case 'B':
                    userBlue--;
                    blue--;
                    break;
                    
                case 'G':
                    userGreen--;
                    green--;
                    break;
                    
                case 'Y':
                    userYellow--;
                    yellow--;
                    break;
                    
                case 'P':
                    userPurple--;
                    purple--;
                    break;
                    
                case 'O':
                    userOrange--;
                    orange--;
                    break;
                    
                default:
                    break;
            }
    
    for (int i = 0; i < REQUIREDLENGTH; i++)
        if (array[i] == WRONG) {
            switch (s1.at(i)) {
                case 'R':
                    if (userRed > 0 && red > 0) {
                        array[i] = MAYBE;
                        userRed--;
                        red--;
                    }
                    else
                        array[i] = WRONG;
                    break;
                    
                case 'B':
                    if (userBlue > 0 && blue > 0) {
                        array[i] = MAYBE;
                        userBlue--;
                        blue--;
                    }
                    else
                        array[i] = WRONG;
                    break;
                    
                case 'G':
                    if (userGreen > 0 && green > 0) {
                        array[i] = MAYBE;
                        userGreen--;
                        green--;
                    }
                    else
                        array[i] = WRONG;
                    break;
                    
                case 'Y':
                    if (userYellow > 0 && yellow > 0) {
                        array[i] = MAYBE;
                        userYellow--;
                        yellow--;
                    }
                    else
                        array[i] = WRONG;
                    break;
                    
                case 'P':
                    if (userPurple > 0 && purple > 0) {
                        array[i] = MAYBE;
                        userPurple--;
                        purple--;
                    }
                    else
                        array[i] = WRONG;
                    break;
                    
                case 'O':
                    if (userOrange > 0 && orange > 0) {
                        array[i] = MAYBE;
                        userOrange--;
                        orange--;
                    }
                    else
                        array[i] = WRONG;
                    break;
                    
                default:
                    break;
            }
        }
}

ANSWER Score::getAnswer (int i) {
    if (i >= 0 && i < REQUIREDLENGTH)
        return array[i];
    else
        throw std::logic_error ("invalid i value");
}

// stringify this Score
std::string Score::to_string() const {
    std::string s = "";
    int mCount = 0, rCount = 0;
    for (int i = 0; i < REQUIREDLENGTH; i++) {
        switch (array[i]) {
            case WRONG:
                s += "_";
                break;
            case RIGHT:
                rCount++;
                s += "R";
                break;
            case MAYBE:
                mCount++;
                s += "M";
                break;
        }
    }
    return s;
}

// is the ANSWER array all RIGHT ANSWERs?
bool Score::isExactMatch() const {
    int rCount = 0, i = 0;
    for (i = 0; i < REQUIREDLENGTH; i++)
        if (array[i] == RIGHT)
            rCount++;
    
    bool b = (rCount == REQUIREDLENGTH);
    return b;
}

}
