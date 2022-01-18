CXX       := clang++
CXX_FLAGS := -std=c++17 #-Wall -Wextra 

BIN     := bin
SRC     := src
INCLUDE := include
LIBRARIES   := -stdlib=libc++
EXECUTABLE  := binance


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	@echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) -I$(SRC) $(LIBRARIES) -g $^ -o $@

clean:
	@echo "🧹 Clearing..."
	-rm $(BIN)/*