#!/bin/bash

source setup.sh

# Function to test push_swap with given arguments
# ... (same as in your provided script) ...

# Test all permutations of 5 arguments
TEST_CASE=1
for a in {1..5}; do
	for b in {1..5}; do
		for c in {1..5}; do
			for d in {1..5}; do
				for e in {1..5}; do
					if [ $a -ne $b ] && [ $a -ne $c ] && [ $a -ne $d ] && [ $a -ne $e ] &&
					   [ $b -ne $c ] && [ $b -ne $d ] && [ $b -ne $e ] &&
					   [ $c -ne $d ] && [ $c -ne $e ] &&
					   [ $d -ne $e ]; then
						test_push_swap "$a $b $c $d $e" 12 $TEST_CASE "size_5"
						((TEST_CASE++))
					fi
				done
			done
		done
	done
done
