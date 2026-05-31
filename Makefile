CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

SFML_DIR := ./libs/SFML
INCLUDES := -I$(SFML_DIR)/include
LDFLAGS  := -L$(SFML_DIR)/lib -Wl,-rpath,$(SFML_DIR)/lib
LDLIBS   := -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

SRC      := src/main.cpp
TARGET   := timber

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
