CXXFLAGS=-std=c++0x -lSDLmain -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
EXEC_NAME = Tetris
OBJ_FILES = obj/sound.o obj/game.o obj/main.o obj/factory.o obj/player.o obj/screen.o obj/AbstractShape.o obj/shape0.o obj/shape1.o obj/shape2.o obj/shape3.o obj/shape4.o obj/shape5.o obj/shape6.o obj/shape7.o obj/shape8.o obj/shape9.o obj/shape10.o obj/shape11.o obj/shape12.o obj/shape13.o obj/shape14.o obj/shape15.o obj/shape16.o obj/shape17.o obj/shape18.o obj/menu.o obj/score.o

all: $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	g++ -o $(EXEC_NAME) $(OBJ_FILES) $(CXXFLAGS)

obj/%.o: cpp/%.cpp
	g++ -o $@ -c $< $(CXXFLAGS)

obj/main.o: main.cpp
	g++ -o $@ -c $< $(CXXFLAGS)

clean:
	rm -rf obj/*.o tetris