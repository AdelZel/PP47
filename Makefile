run: game
	./game

game: main.cpp
	g++ \
  main.cpp Game.cpp Button.cpp Score.cpp Entity.cpp Projectile.cpp Spaceship.cpp Player.cpp Laser.cpp Enemy.cpp \
	-o game \
	-lsfml-graphics -lsfml-window -lsfml-system 