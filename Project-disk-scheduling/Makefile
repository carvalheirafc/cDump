##More updated
##By Carlos Carvalheira


BINDIR = bin
SRCDIR = src
INCLUDEDIR = include
APPDIR = application
OBJDIR = build
TESTDIR = test

CC = g++

CFLAGS = -g -O0  -Wall -ansi -pedantic -std=c++11 -I $(INCLUDEDIR)

LDFLAGS =

BIN = ${BINDIR}/diskSimullator

APP = ${APPDIR}/main.cpp

SRC = $(wildcard $(SRCDIR)/*.cpp)
INC = $(wildcard $(INCLUDEDIR)/*.h)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
APPOBJ = $(patsubst $(APPDIR)/%.cpp,$(OBJDIR)/%.o,$(APP))

_TESTS = $(wildcard $(TESTDIR)/*.cpp)
TESTS = $(patsubst %.cpp,%,$(_TESTS))

.PHONY: clean init all

$(BIN): $(OBJS) $(APPOBJ) $(INCOBJ)
	$(CC) -o $(BIN) $(APPOBJ) $(OBJS) $(INCOBJ) $(CFLAGS) $(LDFLAGS)

$(APPOBJ): $(APP)
	$(CC) -c -o $@ $< $(CFLAGS)

${OBJDIR}/%.o: $(SRCDIR)/%.cpp $(INCLUDEDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TESTS)
	$(info ************  Testes concluídos com sucesso! ************)

$(TESTDIR)/t_%: $(TESTDIR)/t_%.cpp $(OBJS) $(INCOBJ)
	$(CC) -o $@ $< $(OBJS) $(CFLAGS) $(LDFLAGS)
	$@

init:
	mkdir ./$(BINDIR) ./$(OBJDIR)
clean:
	rm -f $(BIN) $(OBJS) $(APPOBJ) $(INCOBJ)
	rm -f $(TESTS)
