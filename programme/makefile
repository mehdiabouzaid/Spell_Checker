SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
RAPPORTDIR=../rapport
DOCDIR=doc
CC = gcc
MKDIR = mkdir -p
AR = ar
CFLAGS=-Wall -pedantic -g -I$(INCLUDEDIR)
LDFLAGS=-lm 
EXEC=asispell

.PHONY : doc
.PHONY : rapport

all :  	$(BINDIR)/$(EXEC)

tests: 	testMot testDictionnaire testCorrecteurOrthographique

testMot : $(SRCDIR)/testMot.o $(LIBDIR)/libAsispell.a
	$(MKDIR) $(TESTDIR)
	$(CC) -o $(TESTDIR)/testMot $^ -lcunit

testDictionnaire : $(SRCDIR)/testDictionnaire.o $(LIBDIR)/libAsispell.a
	$(MKDIR) $(TESTDIR)
	$(CC) -o $(TESTDIR)/testDictionnaire $^ -lcunit

testCorrecteurOrthographique : $(SRCDIR)/TestCorrecteurOrthographique.o $(LIBDIR)/libAsispell.a
	$(MKDIR) $(TESTDIR)
	$(CC) -o $(TESTDIR)/TestCorrecteurOrthographique $^ -lcunit
 
rapport:
	pdflatex $(RAPPORTDIR)/rapport.tex

doxygen:
	$(MKDIR) $(DOCDIR)
	doxygen ./Doxyfile

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(LIBDIR)/libAsispell.a
	$(CC) -o $@ $^ $(LDFLAGS)

$(LIBDIR)/libAsispell.a : $(SRCDIR)/Mot.o $(SRCDIR)/dictionnaire.o $(SRCDIR)/CorrecteurOrthographique.o $(SRCDIR)/ArbreBinaire.o
	$(MKDIR) lib
	$(AR) -r $@ $^

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(LIBDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*
	rm -f $(RAPPORTDIR)/*.dvi
	rm -f $(RAPPORTDIR)/*.aux
	rm -f $(RAPPORTDIR)/*.log
	rm -f $(RAPPORTDIR)/*.out
	rm -f $(RAPPORTDIR)/*.pdf
	rm -f $(RAPPORTDIR)/*.synctex.gz
	rm -f $(RAPPORTDIR)/*.toc
