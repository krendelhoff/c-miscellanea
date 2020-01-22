#!/usr/bin/zsh
ls
let "counter = 0"
while [[ $counter -lt 10 ]]
do
  ls
  let "counter = counter + 1"
done
