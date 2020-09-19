DS := $(word 2, $(MAKECMDGOALS))
THIS_FILE := $(lastword $(MAKEFILE_LIST))
$(eval $(DS):;@:)
$(eval $(THIS_FILE):;@:)

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread -std=c++1y

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR = ./googletest/googletest

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

# House-keeping build targets.
TARGETS = ci
all : $(TARGETS)

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
gtest-all.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest-all.cc

gtest_main.o: $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

gtest.a: gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

gtest_main.a: gtest-all.o gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# Unit test part
%_unittest:
	@$(MAKE) -f $(THIS_FILE) unit

unit: struct_$(DS)/unit.cpp gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $(DS)_unittest

test: $(DS)_unittest
	./$(DS)_unittest

compile: struct_$(DS)/main.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $^ -o $(DS)_runfile

run: ./$(DS)_runfile
	@./$^

ci: ./ci.sh
	@bash $^

.PHONY: clean

clean:
	rm -rf *.out *.a *.o *_unittest *_runfile