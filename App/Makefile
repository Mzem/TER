CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lgmp

EXEC = PRIMALITE

# Repertoires
SDIR  = src
HDIR = head
ODIR  = bin

CRYP_SDIR = $(SDIR)/fonctionnalites/cryptosystemes
TPRIM_SDIR = $(SDIR)/fonctionnalites/tests_primalite
MESP_SDIR = $(SDIR)/mesures_performance

CRYP_HDIR = $(HDIR)/fonctionnalites/cryptosystemes
TPRIM_HDIR = $(HDIR)/fonctionnalites/tests_primalite
MESP_HDIR = $(HDIR)/mesures_performance


all: $(EXEC)
	
run: $(EXEC)
	./$(EXEC)


$(EXEC): $(ODIR)/PRIMALITE_main.o $(ODIR)/RPNG.o $(ODIR)/RSA.o $(ODIR)/testOptimal.o $(ODIR)/testNaif.o $(ODIR)/testWilson.o $(ODIR)/testFermat.o $(ODIR)/testMillerRabin.o $(ODIR)/testSolovay.o $(ODIR)/mesureTemps.o
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)


$(ODIR)/PRIMALITE_main.o: $(CRYP_HDIR)/RPNG.h $(CRYP_HDIR)/RSA.h $(TPRIM_HDIR)/testOptimal.h $(TPRIM_HDIR)/testNaif.h $(TPRIM_HDIR)/testWilson.h $(TPRIM_HDIR)/testFermat.h $(TPRIM_HDIR)/testMillerRabin.h $(TPRIM_HDIR)/testSolovay.h $(MESP_HDIR)/mesureTemps.h
$(ODIR)/RPNG.o: $(TPRIM_HDIR)/testOptimal.h
$(ODIR)/RSA.o: $(CRYP_HDIR)/RPNG.h
$(ODIR)/mesureTemps.o: $(CRYP_HDIR)/RPNG.h $(TPRIM_HDIR)/testNaif.h $(TPRIM_HDIR)/testWilson.h $(TPRIM_HDIR)/testFermat.h $(TPRIM_HDIR)/testMillerRabin.h $(TPRIM_HDIR)/testSolovay.h


$(ODIR)/%.o: $(SDIR)/%.c
	mkdir -p $(ODIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)

$(ODIR)/%.o: $(CRYP_SDIR)/%.c
	mkdir -p $(ODIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)

$(ODIR)/%.o: $(TPRIM_SDIR)/%.c
	mkdir -p $(ODIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)

$(ODIR)/%.o: $(MESP_SDIR)/%.c
	mkdir -p $(ODIR)
	$(CC) -c $< -o $@ $(CFLAGS) $(LDFLAGS)


.PHONY: clean mrproper

clean:
	rm -rf *.o
	rm -rf $(ODIR)

mrproper: clean
	rm -rf $(EXEC)
