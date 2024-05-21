#!/bin/bash

source setup.sh

# Function to test push_swap with given arguments
# ... (same as in your provided script) ...

# Test all permutations of 3 arguments
TEST_CASE=1
for a in {1..3}; do
	for b in {1..3}; do
		for c in {1..3}; do
			if [ $a -ne $b ] && [ $a -ne $c ] && [ $b -ne $c ]; then
				test_push_swap "$a $b $c" 3 $TEST_CASE "size_3"
				((TEST_CASE++))
			fi
		done
	done
done
