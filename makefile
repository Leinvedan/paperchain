CC = g++
#CHAIN_SRC = src/chain.cpp
TEST_SRC = test/tstChain.cpp
INCLUDE_PATH = include
CHAIN_HEADER = $(INCLUDE_PATH)/chain.h
#CHAIN_OBJ = bin/chain.o
TEST_OBJ = bin/chaintst.o
FINAL = bin/chaintest


all: $(FINAL)
	@echo "Done"


$(FINAL): $(TEST_OBJ)
	@echo "Linking"
	$(CC) -o $(FINAL) $(TEST_OBJ)


$(TEST_OBJ): $(TEST_SRC) $(CHAIN_HEADER)
	@echo "Compiling test file"
	$(CC) -o $(TEST_OBJ) -c $(TEST_SRC) -I $(INCLUDE_PATH)  

clear:
	@echo "Removing .o files"
	rm bin/*.o

