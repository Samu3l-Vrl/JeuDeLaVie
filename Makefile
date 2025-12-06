CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

# Bibliothèques SFML nécessaires
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Tous tes fichiers source
SRC = \
    src/alivecell.cpp \
    src/deadcell.cpp \
    src/grid.cpp \
    src/print.cpp \
    src/file.cpp \
    src/jeudelavie.cpp \
	src/rules.cpp

OBJ = $(SRC:.cpp=.o)
TARGET = jeu

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(SFML_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
