cc = gcc -Wall
FILES = obj/main.o #liste des fichiers sources avec .o
ifeq ($(OS), Windows_NT)
	OPT = -lm -lmingw32 -lSDL2main -lSDL2 #-lSDL2_ttf -lSDL2_image
else
	OPT = `pkg-config --libs --cflags sdl2`
endif

all: Qwirkle #commande pour compiler et lancer le jeu
	./Qwirkle

Qwirkle: $(FILES) #commande pour compiler le jeu
	$(cc) $^ -o $@ $(OPT)

obj/%o: src/%c #commande de création des .o avec les .c
	$(cc) -c $^ -o $@ $(OPT) 


clean: #commande pour retirer tous les fichiers objects
	rm obj/*.o
