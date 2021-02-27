CXX 	:= 	g++
CXXFLAGS := -std=gnu++17 -Wall
OBJ_DIR := 	obj
OBJECTS := 	$(OBJ_DIR)/main.o \
			$(OBJ_DIR)/SingleLinkedList.o \
			$(OBJ_DIR)/SortedSingleLinkedList.o \
			$(OBJ_DIR)/DoubleLinkedList.o
TARGET 	:= 	DataStruct

all: build $(TARGET)

build:
	@mkdir -p $(OBJ_DIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

.PHONY: all build debug clean

debug: CXXFLAGS += -DDEBUG -g
debug: all

clean:
	-@rm -f *.o $(OBJECTS) sd DataStruct
	-@rmdir $(OBJ_DIR)
