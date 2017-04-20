LIBS = -lm -pthread
GTEST = -lgtest -lgtest_main
GCOV = -fprofile-arcs -ftest-coverage
DIRECTIVES = -std=c++11 -Wall -Wextra -c

EXEC_NAME = t2
MAIN = src/main.cpp

EXEC = build/$(EXEC_NAME)

# CC = clang++-3.8
CC = g++

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d

COV_PATH = cov
TMP_PATH = tmp
BUILD_PATH = build
SRC_PATH = src/cpp
BIN_PATH = $(TMP_PATH)/cpp
DEP_PATH = $(TMP_PATH)/hpp

CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEP_FILES = $(wildcard $(DEP_PATH)/*.d)

.PHONY: clean test test_build test_run run run_run release debug

all: clean $(EXEC)
$(EXEC): $(OBJ_FILES)
	$(CC) -o $@ $^ tmp/main.o $(LIBS)

$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp 
	@mkdir -p $(DEP_PATH) $(BIN_PATH) $(BUILD_PATH) $(COV_PATH)
	$(CC) -o tmp/main.o $(MAIN) $(DIRECTIVES)
	$(CC) $(DEP_FLAGS) -c -o $@ $< $(DIRECTIVES)

run: clean all run_run

run_run:
	./build/t2

cov: clean cov_build cov_run

cov_run:
	./build/t2
	gcov main -o tmp/ -r
	gcov tmp/cpp/* -o tmp/cpp -r
	mv *.gcov cov/
	
cov_build: DIRECTIVES += $(GCOV)
cov_build: GTEST += $(GCOV)
cov_build: clean test_build

test: clean test_build test_run

test_build: MAIN = src/test/main.cpp
test_build: LIBS += $(GTEST)
test_build: all
	
test_run:
	./$(EXEC)

debug: DIRECTIVES += -ggdb
debug: clean all

release: DIRECTIVES += -Ofast -mtune=native
release: clean all

clean:
	rm -rf $(TMP_PATH) $(BUILD_PATH) $(COV_PATH)
	rm -rf -f $(EXEC)

$(DEP_PATH)/%.d: ;
.PRECIOUS: $(DEP_PATH)/%.d

-include $(DEP_FILES)