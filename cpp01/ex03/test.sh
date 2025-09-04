#!/bin/bash

clean()
{
  make fclean
}

test()
{
  output="$1"
	exp_output="Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club"

	if [[ "$output" != "$exp_output" ]]
	then
    printf "output = \"%s\"" "$output" 1>&2
  else
    printf "OK\n"
	fi
  clean
}

make re
if [[ $? -eq 0 ]]
then
  output="$(make run)" && test "$output"
else
  printf "makefile error\n" 1>&2
fi

