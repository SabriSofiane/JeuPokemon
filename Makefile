all: clean pokemon

pokemon: objets/start_game.o objets/audio.o objets/collisions.o objets/event.o objets/initialisation.o objets/map.o objets/motor.o objets/player.o objets/string_matrice.o objets/text.o objets/textures.o objets/window_render.o objets/menu.o objets/controller.o objets/combat.o objets/main.o
	gcc -o bin/pokemon objets/start_game.o objets/audio.o objets/collisions.o objets/event.o objets/initialisation.o objets/map.o objets/motor.o objets/player.o objets/string_matrice.o objets/text.o objets/textures.o objets/window_render.o objets/menu.o objets/controller.o objets/combat.o  objets/main.o -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/audio.o: src/audio.c
	gcc -o objets/audio.o -c src/audio.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/collisions.o: src/collisions.c
	gcc -o objets/collisions.o -c src/collisions.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/event.o: src/event.c
	gcc -o objets/event.o -c src/event.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/initialisation.o: src/initialisation.c
		gcc -o objets/initialisation.o -c src/initialisation.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/map.o: src/map.c
		gcc -o  objets/map.o -c src/map.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/motor.o: src/motor.c
	gcc -o  objets/motor.o -c src/motor.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/player.o: src/player.c
	gcc -o  objets/player.o -c src/player.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/string_matrice.o: src/string_matrice.c
	gcc -o  objets/string_matrice.o -c src/string_matrice.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/text.o: src/text.c
	gcc -o  objets/text.o -c src/text.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/textures.o: src/textures.c
	gcc -o  objets/textures.o -c src/textures.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/window_render.o: src/window_render.c
	gcc -o  objets/window_render.o -c src/window_render.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/menu.o: src/menu.c
	gcc -o  objets/menu.o -c src/menu.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/controller.o: src/controller.c
	gcc -o objets/controller.o -c src/controller.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/combat.o: src/combat.c
	gcc -o objets/combat.o -c src/combat.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/liste.o: src/liste.c
	gcc -o objets/liste.o -c src/liste.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/start_game.o: src/start_game.c
	gcc -o objets/start_game.o -c src/start_game.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

objets/main.o: src/main.c $(wildcard include/*.h) ./include/SDL2/SDL.h ./include/SDL2/SDL_image.h ./include/SDL2/SDL_mixer.h ./include/SDL2/SDL_ttf.h
	gcc -o  objets/main.o -c src/main.c -I include/SDL2 -L lib/ -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf

clean:
	powershell "Remove-Item objets/*.o"
