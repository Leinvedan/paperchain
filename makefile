CC = g++
CHAIN_SRC = src/chain.cpp
TEST_SRC = test/tstChain.cpp
INCLUDE_PATH = include
CHAIN_HEADER = $(INCLUDE_PATH)/chain.h
CHAIN_OBJ = bin/chain.o
TEST_OBJ = bin/chaintst.o
FINAL = bin/chaintest


all: $(FINAL)
	@echo "Done"


$(FINAL): $(CHAIN_OBJ) $(TEST_OBJ)
	@echo "Linking objects"
	$(CC) -o $(FINAL) $(CHAIN_OBJ) $(TEST_OBJ)


$(CHAIN_OBJ): $(CHAIN_SRC)
	@echo "Compiling the test file"
	$(CC) -o $(CHAIN_OBJ) -c $(CHAIN_SRC) -I $(INCLUDE_PATH)

$(TEST_OBJ): $(TEST_SRC) $(CHAIN_HEADER)
	@echo "Compiling chain"
	$(CC) -o $(TEST_OBJ) -c $(TEST_SRC) -I $(INCLUDE_PATH)  

clear:
	@echo "Removing .o files"
	rm bin/*.o

