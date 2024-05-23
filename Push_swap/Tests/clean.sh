#!/bin/bash

# Directories and files to remove
ITEMS=("identity" "size_*" "valgrind-out.txt")

# Loop over the items and remove them
for item in ${ITEMS[@]}; do
	if [ -d "$item" ]; then
		echo "Removing directory: $item"
		rm -rf "$item"
	elif [ -f "$item" ]; then
		echo "Removing file: $item"
		rm "$item"
	else
		echo "Item not found: $item"
	fi
done

echo "Cleanup complete."
