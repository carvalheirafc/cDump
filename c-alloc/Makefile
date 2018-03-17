BINDIR = bin
SRCDIR = src
INCLUDEDIR = include
APPDIR = application
OBJDIR = build
TESTDIR = test

CC = gcc

CFLAGS = -I $(INCLUDEDIR)

LDFLAGS =

BIN = ${BINDIR}/lab07

APP = ${APPDIR}/main.c

SRC = $(wildcard $(SRCDIR)/*.c)
INC = $(wildcard $(INCLUDEDIR)/*.h)
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRC))
APPOBJ = $(patsubst $(APPDIR)/%.c,$(OBJDIR)/%.o,$(APP))
##INCOBJ = $(patsubst $(INCLUDEDIR)/%.h, $(OBJDIR)/%.o,$(INC))

_TESTS = $(wildcard $(TESTDIR)/*.c)
TESTS = $(patsubst %.c,%,$(_TESTS))

$(BIN): $(OBJS) $(APPOBJ) $(INCOBJ)
	$(CC) -o $(BIN) $(APPOBJ) $(OBJS) $(INCOBJ) $(CFLAGS) $(LDFLAGS)

$(APPOBJ): $(APP)
	$(CC) -c -o $@ $< $(CFLAGS)

${OBJDIR}/%.o: $(SRCDIR)/%.c $(INCLUDEDIR)/%.h
	$(CC) -c -o $@ $< $(CFLAGS)

test: $(TESTS) 
	$(info ************  Testes concluídos com sucesso! ************)

$(TESTDIR)/t_%: $(TESTDIR)/t_%.c $(OBJS) $(INCOBJ)
	$(CC) -o $@ $< $(OBJS) $(CFLAGS) $(LDFLAGS)
	$@

clean:
	rm -f $(BIN) $(OBJS) $(APPOBJ) 
	rm -f $(TESTS)
