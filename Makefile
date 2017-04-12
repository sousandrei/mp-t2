RMDIR = rm -rf
RM = rm

DIRECTIVES = -std=c++11 -Wall -Wextra -c
LIBS = -lm -pthread -lgtest -lgtest_main

EXEC_NAME = t2

EXEC = build/$(EXEC_NAME)
EXEC_TEST = build/$(EXEC_NAME)_test

CC = clang++-3.8
# CC = g++

DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d

BUILD_PATH = build
TMP_PATH = tmp
SRC_PATH = src/cpp
BIN_PATH = $(TMP_PATH)/cpp
DEP_PATH = $(TMP_PATH)/hpp

CPP_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES = $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEP_FILES = $(wildcard $(DEP_PATH)/*.d)

.PHONY: clean test test_build test_run

all: $(EXEC)
$(EXEC): src/main.cpp $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)

tmp/main.o: src/main.cpp 
$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp 
	@mkdir -p $(DEP_PATH) $(BIN_PATH) $(BUILD_PATH)
	$(CC) $(DEP_FLAGS) -c -o $@ $< $(DIRECTIVES)

test: test_build test_run

test_build: $(EXEC_TEST)
$(EXEC_TEST): src/test/main.cpp $(OBJ_FILES)
	$(CC) -o $@ $^ $(LIBS)
	
test_run:
	./build/$(EXEC_NAME)_test

debug: DIRECTIVES += -ggdb
debug: all

release: DIRECTIVES += -Ofast -mtune=native
release: all

print-% : ; @echo $* = $($*)

clean:
	$(RMDIR) $(TMP_PATH) $(BUILD_PATH)
	$(RM) -f $(EXEC)

$(DEP_PATH)/%.d: ;
.PRECIOUS: $(DEP_PATH)/%.d

-include $(DEP_FILES)
