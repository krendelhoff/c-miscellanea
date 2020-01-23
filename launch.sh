#!/bin/zsh
gcc -o executable $1
if [[ -n $2 ]]
then
	./executable < $2
else
      	./executable
fi
rm -f executable
