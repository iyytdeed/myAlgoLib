CC=g++
CC_FLAGS=-Wall -Werror -g

r:game.o move.o
	$(CC) $(CC_FLAGS) -o r $^

# $^指所有前置条件, $<指的是第一个前置条件
game.o:game.cpp move.h
	g++ -c -g $<
move.o:move.cpp move.h
	g++ -c -g $<

# .PHONY表示clean为指令，可以make clean
.PHONY:clean
clean:
	rm *.o
