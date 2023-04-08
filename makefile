CXX = g++
WARNINGS = -Wall -Wextra -Wwrite-strings -Wno-unused-results
CFLAGS = -march=native -O2 -ftree-vectorize -fno-sematic-interposition -fno-plt -pipe -s -flto -D_FORTIFY_SOURCE=1
DEBUGFLAGS = -Og -g
INCLUDES =
LINKS = -lX11

SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
OBJDIR = obj
BINDIR = bin


.PHONY = clean install uninstall debug build run

debug: $(BINDIR) bin/debug

build: $(BINDIR) bin/swm
	
clean:
	rm -r obj/* bin/*

install: build
	cp -f bin/swm /bin/swm
	chmod 755 /bin/swm

uninstall:
	rm -f /bin/swm

run: debug
	xinit ./bin/debug -- :1 vt2


$(BINDIR):
	mkdir bin

$(OBJDIR):
	mkdir obj

bin/swm: $(SRC)
	$(CXX) $(CFLAGS) $(INCLUDES) $(LINKS) $^ -o $@

bin/debug: $(OBJ)
	$(CXX) $(DEBUGFLAGS) $(LINKS) $^ -o $@

obj/%.o: src/%.cpp
	$(CXX) $(DEBUGFLAGS) $(INCLUDES) $^ -o $@
