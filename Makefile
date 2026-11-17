CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

LAB_BINS = Lab_09_1/Lab_09_1 Lab_09_2_1/Lab_09_2_1 Lab_09_2_2/Lab_09_2_2
TEST_BINS = tests/UnitTest_09_1 tests/UnitTest_09_2_1 tests/UnitTest_09_2_2

.PHONY: all labs tests test clean

all: labs tests

labs: $(LAB_BINS)

tests: $(TEST_BINS)

Lab_09_1/Lab_09_1: Lab_09_1/Lab_09_1.cpp Lab_09_1/var.cpp Lab_09_1/dod.cpp Lab_09_1/sum.cpp Lab_09_1/var.h Lab_09_1/dod.h Lab_09_1/sum.h
	$(CXX) $(CXXFLAGS) Lab_09_1/Lab_09_1.cpp Lab_09_1/var.cpp Lab_09_1/dod.cpp Lab_09_1/sum.cpp -o $@

Lab_09_2_1/Lab_09_2_1: Lab_09_2_1/Lab_09_2_1.cpp Lab_09_2_1/macros.h
	$(CXX) $(CXXFLAGS) Lab_09_2_1/Lab_09_2_1.cpp -o $@

Lab_09_2_2/Lab_09_2_2: Lab_09_2_2/Lab_09_2_2.cpp Lab_09_2_2/triangle_macros.h
	$(CXX) $(CXXFLAGS) Lab_09_2_2/Lab_09_2_2.cpp -o $@

tests/UnitTest_09_1: tests/UnitTest_09_1.cpp Lab_09_1/var.cpp Lab_09_1/dod.cpp Lab_09_1/sum.cpp Lab_09_1/var.h Lab_09_1/dod.h Lab_09_1/sum.h
	$(CXX) $(CXXFLAGS) tests/UnitTest_09_1.cpp Lab_09_1/var.cpp Lab_09_1/dod.cpp Lab_09_1/sum.cpp -o $@

tests/UnitTest_09_2_1: tests/UnitTest_09_2_1.cpp Lab_09_2_1/Lab_09_2_1.cpp Lab_09_2_1/macros.h
	$(CXX) $(CXXFLAGS) tests/UnitTest_09_2_1.cpp -o $@

tests/UnitTest_09_2_2: tests/UnitTest_09_2_2.cpp Lab_09_2_2/Lab_09_2_2.cpp Lab_09_2_2/triangle_macros.h
	$(CXX) $(CXXFLAGS) tests/UnitTest_09_2_2.cpp -o $@

test: tests
	@for t in $(TEST_BINS); do \
		echo "===> Running $$t <==="; \
		$$t || exit 1; \
	done

clean:
	rm -f $(LAB_BINS) $(TEST_BINS)
