CFLAGS = -Wall -g
LDFLAGS = -lgmp

CS_SRC_PATH = src/main/cryptosystemes/
CS_BUILD_PATH = build/main/cryptosystemes/

TP_SRC_PATH = src/main/tests_primalite/
TP_BUILD_PATH = build/main/tests_primalite/

EX_SRC_PATH = src/main/exemples/
EX_BUILD_PATH = build/main/exemples/

#Ensemble des .o
OBJ = $(TP_BUILD_PATH)fermat.o $(TP_BUILD_PATH)miller_rabin.o $(CS_BUILD_PATH)rsa.o  $(EX_BUILD_PATH)exemples.o $(EX_BUILD_PATH)main.o

#Compilation et lancement du main
all: $(EX_BUILD_PATH)exemples
	$(EX_BUILD_PATH)exemples

run:
	$(EX_BUILD_PATH)exemples
	
#Tests de primalité
$(TP_BUILD_PATH)fermat.o: $(TP_SRC_PATH)fermat.c
	mkdir -p $(TP_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

$(TP_BUILD_PATH)miller_rabin.o: $(TP_SRC_PATH)miller_rabin.c
	mkdir -p $(TP_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

tests_primalite: $(TP_BUILD_PATH)fermat.o $(TP_BUILD_PATH)miller_rabin.o

#Cryptosystemes
$(CS_BUILD_PATH)rsa.o: $(CS_SRC_PATH)rsa.c
	mkdir -p $(CS_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

cryptosystemes: $(CS_BUILD_PATH)rsa.o

#Exemples
$(EX_BUILD_PATH)exemples.o: $(EX_SRC_PATH)exemples.c cryptosystemes tests_primalite
	mkdir -p $(EX_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

$(EX_BUILD_PATH)main.o: $(EX_SRC_PATH)main.c $(EX_SRC_PATH)exemples.h
	mkdir -p $(EX_BUILD_PATH)
	gcc -c $(CFLAGS) -o $@ $< $(LDFLAGS)

$(EX_BUILD_PATH)exemples: $(OBJ)
	mkdir -p $(EX_BUILD_PATH)
	gcc -o $@ $^ $(LDFLAGS)
	
#Nettoyage
.PHONY: clean

clean:
	rm -rf build/
