# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_make_mac.sh                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 09:58:49 by nfordoxc          #+#    #+#              #
#    Updated: 2025/01/23 09:19:58 by nfordoxc         ###   Luxembourg.lu      #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

WATCH_DIRS=(
	"./src"
	"./bonus"
	"./includes"
	"./lib"
) 

if [ -z "$1" ]
	then
		echo "Command to execute needed like \"make bonus\" !!"
		exit 1
fi

COMMAND=$1

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
