#include <iostream>
#include "move.h"

void showLoc(char dir){
    switch(dir){
        case UP:
        {
            std::cout << "^^^" << std::endl;
			break;
        }
        case DOWN:
        {
            std::cout << "vvv" << std::endl;
			break;
        }
        case LEFT:
        {
            std::cout << "<<<" << std::endl;
			break;
        }
        case RIGHT:
        {
            std::cout << ">>>" << std::endl;
			break;
        }
        default: break;
    }
}
