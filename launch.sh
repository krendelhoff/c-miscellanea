#!/usr/bin/zsh
gcc -g -o executable $1 -lm
if [[ -n $2 ]]
then
	./executable < $2
else
      	./executable
fi
rm -f executable
