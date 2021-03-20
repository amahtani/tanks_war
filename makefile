
CXX = g++
RM = rm

CFLAGS = `sdl2-config --cflags --libs -Wall`
LIBS = -lSDL2_image -lSDL2_ttf -lSDL2_mixer

TARGET = main

OBJS = Shooter.o main.o Game.o Tank.o Wall.o Bullet.o Loop.o Missile.o Bonus_missiles.o Collision.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(CFLAGS) $(LIBS) -Wall
	
%.o: %.cpp
	$(CXX) -c $(CFLAGS) -Wall -Wextra -Wchkp $<

clean: 
	$(RM) -f *.o $(TARGET)