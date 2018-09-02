#include <unistd.h>
#include <iostream>
#include "move.h"

int main(){
    char c;
    while(read(STDIN_FILENO, &c, 1) > 0){
        showLoc(c);
    }
	std::cout << "eof\n" << std::endl;
}
