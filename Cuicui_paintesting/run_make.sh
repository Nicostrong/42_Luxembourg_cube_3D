# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_make.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 08:09:39 by nfordoxc          #+#    #+#              #
#    Updated: 2024/10/14 10:05:26 by phkevin          ###   Luxembour.lu       #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

cd ..

 WATCH_DIRS=(
	"./"
) 

COMMAND="make re"

calculate_checksum()
{
	for dir in "${WATCH_DIRS[@]}"
	do
		find "$dir" -type f \( -name "*.c" -o -name "*.h" -o -name "Makefile" -o -name "makefile" \) -exec md5sum {} \;
	done | sort -k 2 | md5sum
}

previous_checksum=$(calculate_checksum)

while true
do
	current_checksum=$(calculate_checksum)
	
	if [ "$previous_checksum" != "$current_checksum" ]
	then
		clear
		$COMMAND
		echo "Dernière compilation : $(date '+%Y-%m-%d %H:%M:%S')" > /dev/tty
		previous_checksum=$current_checksum
	fi
done


