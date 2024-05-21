#!/bin/bash

ROOT=..
RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

make -C $ROOT
clear

if [[ -f "$ROOT/push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\ncheck if the variable ROOT in basic_test.sh is correct\n"
	exit 1
fi

# Function to test push_swap with given arguments
test_push_swap() {
	local ARG="$1"
	local MAX_OPS="$2"
	local TEST_CASE="$3"
	local DIR="$4"
	mkdir -p "$DIR/output"
	echo $ARG > "$DIR/test_case_$TEST_CASE.txt"
	./push_swap "$DIR/test_case_$TEST_CASE.txt" > "$DIR/output/output_$TEST_CASE.txt"
	local RESULT=$(wc -l < "$DIR/output/output_$TEST_CASE.txt")
	if [ $RESULT -le $MAX_OPS ]; then
		echo "Test case $TEST_CASE: OK"
	else
		echo "Test case $TEST_CASE: KO"
	fi
	local CHECKER_RESULT=$(./checker_linux "$DIR/test_case_$TEST_CASE.txt" < "$DIR/output/output_$TEST_CASE.txt")
	echo "Checker result for test case $TEST_CASE: $CHECKER_RESULT"
}
