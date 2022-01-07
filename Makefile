CPP=g++
CPPFLAGS=`wx-config --cxxflags --libs` -std=c++11
SRC=src
OBJ=obj

SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(SRC)/*.h)
BIN=kantor

all: $(BIN)

$(BIN): $(OBJS) $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp $(OBJ)
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

clean:
	$(RM) -r $(OBJ)
	$(RM) $(BIN)