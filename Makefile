CFLAGS = -Wall -g
LDFLAGS = -lgmp

CS_SRC_PATH = app/src/main/cryptosystemes/
CS_BUILD_PATH = app/build/main/cryptosystemes/

rsa.o: $(CS_SRC_PATH)rsa.c
	mkdir -p $(CS_BUILD_PATH)
	gcc -c $(CFLAGS) -o $(CS_BUILD_PATH)$@ $< $(LDFLAGS)
