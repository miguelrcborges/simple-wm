CXX = g++
WARNINGS = -Wall -Wextra -Wwrite-strings -Wno-unused-results
CFLAGS = -march=native -O2 -ftree-vectorize -fno-semantic-interposition -fno-plt -pipe -s -flto -D_FORTIFY_SOURCE=1
DEBUGFLAGS = -Og -g -D_DEBUG
INCLUDES =
LINKS = -lX11 -lXinerama

HEADERS = $(wildcard src/*.h) $(wildcard src/**/*.h)
SRC = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
OBJ = $(patsubst src/%.cpp, obj/%.o, $(SRC))
OBJDIR = obj obj/actions obj/utils
BINDIR = bin


.PHONY = clean install uninstall debug build run format

debug: $(OBJDIR) $(BINDIR) bin/debug

build: $(BINDIR) bin/swm
	
clean:
	rm -r obj bin

install: build swm.desktop
	install -Dm755 bin/swm /bin/swm
	install -D swm.desktop /usr/share/xsessions/swm.desktop

uninstall:
	rm -f /bin/swm /usr/share/xsessions/swm.desktop

run: debug
	xinit ./bin/debug -- :1 vt2

format:
	clang-format -i -style=file:src/.clang-format src/*.cpp src/**/*.cpp


$(BINDIR):
	mkdir $@

$(OBJDIR):
	mkdir $@

bin/swm: $(SRC)
	$(CXX) $(CFLAGS) $(INCLUDES) $(LINKS) $^ -o $@

bin/debug: $(OBJ)
	$(CXX) $(DEBUGFLAGS) $(LINKS) $^ -o $@

obj/%.o: src/%.cpp $(HEADERS)
	$(CXX) -c $(DEBUGFLAGS) $(INCLUDES) $< -o $@
