# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_make_mac.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 09:58:49 by nfordoxc          #+#    #+#              #
#    Updated: 2024/12/17 08:59:59 by nfordoxc         ###   Luxembourg.lu      #
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
		find "$dir" -type f \( -name "*.c" -o -name "*.h" \) -exec md5 {} \;
	done | sort -k 2 | md5
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