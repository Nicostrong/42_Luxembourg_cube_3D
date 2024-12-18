# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_make.sh                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 08:09:39 by nfordoxc          #+#    #+#              #
#    Updated: 2024/12/18 08:33:47 by nfordoxc         ###   Luxembourg.lu      #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

WATCH_DIRS=(
	"./src"
	"./includes"
	"./lib"
) 

COMMAND="make"

calculate_checksum()
{
	for dir in "${WATCH_DIRS[@]}"
	do
		find "$dir" -type f \( -name "*.c" -o -name "*.h" \) -exec md5sum {} \;
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
