CFLAGS = -Wall -g
LDFLAGS = -lgmp

CS_SRC_PATH = src/main/cryptosystemes/
CS_BUILD_PATH = build/main/cryptosystemes/

TP_SRC_PATH = src/main/tests_primalite/
TP_BUILD_PATH = build/main/tests_primalite/

GP_SRC_PATH = src/main/generateur_premier/
GP_BUILD_PATH = build/main/generateur_premier/

EX_SRC_PATH = src/main/exemples/
EX_BUILD_PATH = build/main/exemples/

PP_SRC_PATH = src/main/prog_principal/
PP_BUILD_PATH = build/main/prog_principal/

#Ensemble des .o
OBJ = $(TP_BUILD_PATH)fermat.o $(TP_BUILD_PATH)miller_rabin.o $(TP_BUILD_PATH)tests_primalite.o\
	$(CS_BUILD_PATH)rsa.o\
	$(EX_BUILD_PATH)exemples.o\
	$(GP_BUILD_PATH)rpng.o\
	$(PP_BUILD_PATH)main.o

#Compilation et lancement du main
all: $(PP_BUILD_PATH)exe
	$(PP_BUILD_PATH)exe

run:
	$(PP_BUILD_PATH)exe
	
#Tests de primalité
$(TP_BUILD_PATH)fermat.o: $(TP_SRC_PATH)fermat.c $(TP_SRC_PATH)fermat.h
	mkdir -p $(TP_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

$(TP_BUILD_PATH)miller_rabin.o: $(TP_SRC_PATH)miller_rabin.c $(TP_SRC_PATH)miller_rabin.h
	mkdir -p $(TP_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

$(TP_BUILD_PATH)tests_primalite.o: $(TP_SRC_PATH)tests_primalite.c $(TP_SRC_PATH)tests_primalite.h
	mkdir -p $(TP_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

#Cryptosystemes
$(CS_BUILD_PATH)rsa.o: $(CS_SRC_PATH)rsa.c $(CS_SRC_PATH)rsa.h
	mkdir -p $(CS_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)
	
#Generateur aléatoire de nombres premiers
$(GP_BUILD_PATH)rpng.o: $(GP_SRC_PATH)rpng.c $(GP_SRC_PATH)rpng.h
	mkdir -p $(GP_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

#Exemples : fonctions de tests
$(EX_BUILD_PATH)exemples.o: $(EX_SRC_PATH)exemples.c $(EX_SRC_PATH)exemples.h
	mkdir -p $(EX_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

#Programme principal
$(PP_BUILD_PATH)main.o: $(PP_SRC_PATH)main.c $(PP_SRC_PATH)def.h
	mkdir -p $(PP_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

$(PP_BUILD_PATH)exe: $(OBJ)
	mkdir -p $(PP_BUILD_PATH)
	gcc -o $@ $^ $(LDFLAGS)
	
#Nettoyage
.PHONY: clean

clean:
	rm -rf build/
