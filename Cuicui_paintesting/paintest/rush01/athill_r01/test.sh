#!/bin/bash

TIMEOUT=2

BOLD="\033[1m"
RED="\033[1;31m"
GREEN="\033[1;32m"
YELLOW="\033[1;33m"
PURPLE="\033[1;35m"
END="\033[0m"

TIMEOUT=3

POSITIONAL_ARGS=()
while [[ $# -gt 0 ]]; do
  case $1 in
    -t|--timeout)
      TIMEOUT="$2"
      shift
      shift
      ;;
    -m|--mandatory)
      MAND=YES
      shift
      ;;
    -b|--bonus)
      BONUS="$2"
      shift
      shift
      ;;
    -a|--all)
      ALL=YES
      shift
      ;;
    -o|--optimize)
      OPT="-O3"
      shift
      ;;
    -*|--*)
	  HELP=YES
      shift
      ;;
    *)
      POSITIONAL_ARGS+=("$1") # save positional arg
      shift
      ;;
  esac
done
set -- "${POSITIONAL_ARGS[@]}" # restore positional parameters

if [[ ! -z $HELP || -z $MAND$ALL$BONUS ]]; then
	echo "usage: $0 [OPTIONS]..."
	echo -e $BOLD"options"$END
	echo -e $BOLD"	-m "$END"	run mandatory tests"
	echo -e $BOLD"	-t [n]"$END"	automatic timeout in seconds, default is 3"
	echo -e $BOLD"	-b [n]"$END"	run tests for a grid of size n×n"
	echo -e $BOLD"	-a"$END"	run tests for all grid sizes from 1 to 9"
	echo -e $BOLD"	-o"$END"	compile program with -O3 optimizations"
	exit 1
fi


compile() {
	echo "compiling tester"
	CC="cc -g $OPT -Wall -Wextra -Werror -o tester main.c get_next_line.c"
	echo "$CC"
	$CC
	if [ $? -ne "0" ]; then
		echo -e $YELLOW"failed to compile tester???"$END
		clean_up
		exit 1
	fi

	echo "compiling rush"
	CC="cc -g $OPT -Wall -Wextra -Werror -o rush-01 ../../../../ex00/*.c"
	echo "$CC"
	$CC
	if [ $? -ne "0" ]; then
		echo -e $RED"failed to compile"$END
		echo "check that there is an ex00 folder containing the required files"
		echo -e "also check that you have copied the test folder correctly$BOLD NEXT TO$END the ex00 folder"
		clean_up
		exit 1
	fi
}

clean_up() {
	for FILE in rush-01 tester; do
		if [ -f "$FILE" ]; then
			rm "$FILE"
		fi
	done
}

compile
if [ ! -z $ALL ]; then
	./tester "./rush-01" -t $TIMEOUT"000" -a
elif [ ! -z $BONUS ]; then
	./tester "./rush-01" -t $TIMEOUT"000" -b $BONUS
else
	./tester "./rush-01" -t $TIMEOUT"000"
fi
clean_up
