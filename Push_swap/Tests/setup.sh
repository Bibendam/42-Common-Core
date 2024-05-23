#!/bin/bash

ROOT=..
RED='\033[0;31m'
GREEN='\033[0;32m'
NOCOLOR='\033[0m'

# Error tests
error_tests() {
	echo -e "${GREEN}\nRunning error tests:${NOCOLOR}"
	local TEST_CASES=("1 2 abc" "1 2 3 2" "1 2 3 22222222222222" "")
	for index in "${!TEST_CASES[@]}"; do
		local TEST_CASE=(${TEST_CASES[$index]})
		local OUTPUT=$($ROOT/push_swap "${TEST_CASE[@]}" 2>&1)  # Redirect stderr to stdout
		# If the output is not empty, trim leading and trailing whitespace
		if [[ -n "$OUTPUT" ]]; then
			OUTPUT=$(echo -e "$OUTPUT" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')  # Trim whitespace
		fi
		echo -ne "test_case_$((index+1))\toutput : ${GREEN}$OUTPUT${NOCOLOR}\n"  # Use -ne to prevent newline after output :
	done
}

make -C $ROOT
clear

if [[ -f "$ROOT/push_swap" ]]
then
	printf "${GREEN}push_swap compilation ok${NOCOLOR}\n\n"
else
	printf "${RED}push_swap compilation ko${NOCOLOR}\ncheck if the variable ROOT in basic_test.sh is correct\n"
	exit 1
fi

# Call the error tests
error_tests

test_push_swap() {
	local ARG="$1"
	local MAX_OPS="$2"
	local TEST_CASE="$3"
	local TEST_TYPE="$4"  # New parameter for test type
	local DIR="./$TEST_TYPE"  # Directory now includes test type
	mkdir -p "$DIR/output_$TEST_CASE"
	echo $ARG > "$DIR/output_$TEST_CASE/test_case_$TEST_CASE.txt"
	# Check if the list is already sorted
	if [[ $(echo "$ARG" | tr ' ' '\n' | sort -n | tr '\n' ' ' | xargs) == $(echo $ARG | xargs) ]]; then
		echo -e "$TEST_CASE\tchecker result : ${GREEN}OK${NOCOLOR}"
		return 0
	fi
	local OUTPUT=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt $ROOT/push_swap $ARG)
	if [[ ! -z "$OUTPUT" ]]; then
		OUTPUT=$(echo "$OUTPUT" | tr ' ' '\n')
		local RESULT=$(echo "$OUTPUT" | wc -l)
	else
		local RESULT=0
		OUTPUT=$'\n'
	fi
	echo "$OUTPUT" > "$DIR/output_$TEST_CASE/output_$TEST_CASE.txt"
	local CHECKER_RESULT=$($ROOT/checker_linux $ARG < "$DIR/output_$TEST_CASE/output_$TEST_CASE.txt")
	if [ "$CHECKER_RESULT" == "OK" ]; then
		CHECKER_RESULT="${GREEN}OK${NOCOLOR}"
	else
		CHECKER_RESULT="${RED}KO${NOCOLOR}"
	fi
	if [ $RESULT -eq 0 ]; then
		echo -e "$TEST_CASE\tchecker result : $CHECKER_RESULT"
	else
		echo -e "$TEST_CASE\tinstructions amounts : $RESULT\tchecker result : $CHECKER_RESULT"
	fi
	if [ $RESULT -le $MAX_OPS ]; then
		return 0
	else
		return 1
	fi
}

# Identity tests
echo -e "${GREEN}\nRunning identity tests:${NOCOLOR}"
identity_tests=("" "1" "42" "0 1 2 3" "0 1 2 3 4 5 6 7 8 9" "2147483647" "-2147483648")
for index in "${!identity_tests[@]}"; do
	test="${identity_tests[$index]}"
	test_push_swap "$test" 0 "test_case_$((index+1))" "identity"
done

# Test all permutations of 3 arguments
echo -e "${GREEN}\nTesting size_3 permutations:${NOCOLOR}"
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

# Test all permutations of 5 arguments
echo -e "${GREEN}\nTesting size_5 permutations:${NOCOLOR}"
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

# Define ARGS as the array of arguments passed to the script
ARGS=("$@")
# Define PAIRS as half the number of arguments
PAIRS=$(( $# / 2 ))

# Test all permutations of NUMBERS arguments, TIMES times, for each pair of arguments
for ((j=0; j<$PAIRS; j++)); do
	NUMBERS=${ARGS[j*2]}
	TIMES=${ARGS[j*2+1]}
	echo -e "${GREEN}\nTesting size_${NUMBERS} permutations:${NOCOLOR}"
	TOTAL_INSTRUCTIONS=0
	MAX_INSTRUCTIONS=0
	MIN_INSTRUCTIONS=999999999
	for ((i=1; i<=TIMES; i++)); do
		TEST_CASE=$i
		# Generate a list of NUMBERS unique random numbers
		ARG=$(shuf -i 1-$NUMBERS -n $NUMBERS | tr '\n' ' ')
		RESULT=$(test_push_swap "$ARG" $((NUMBERS*2)) $TEST_CASE "size_${NUMBERS}")
		echo "$RESULT"
		INSTRUCTIONS=$(echo "$RESULT" | awk '{print $5}')
		TOTAL_INSTRUCTIONS=$((TOTAL_INSTRUCTIONS + INSTRUCTIONS))
		if (( INSTRUCTIONS > MAX_INSTRUCTIONS )); then
			MAX_INSTRUCTIONS=$INSTRUCTIONS
		fi
		if (( INSTRUCTIONS < MIN_INSTRUCTIONS )); then
			MIN_INSTRUCTIONS=$INSTRUCTIONS
		fi
	done
	AVERAGE_INSTRUCTIONS=$((TOTAL_INSTRUCTIONS / TIMES))
	echo -e "${GREEN}Maximum number of instructions for size_${NUMBERS} permutations:${NOCOLOR} $MAX_INSTRUCTIONS"
	echo -e "${GREEN}Minimum number of instructions for size_${NUMBERS} permutations:${NOCOLOR} $MIN_INSTRUCTIONS"
	echo -e "${GREEN}Average number of instructions for size_${NUMBERS} permutations:${NOCOLOR} $AVERAGE_INSTRUCTIONS\n"
done

# Check for memory leaks
LEAKS=$(grep "no leaks are possible" valgrind-out.txt)
if [[ -z "$LEAKS" ]]; then
	echo -e "${RED}Memory leak KO! Check valgrind-out.txt for details.${NOCOLOR}"
else
	echo -e "${GREEN}Memory leak OK.${NOCOLOR}"
fi
