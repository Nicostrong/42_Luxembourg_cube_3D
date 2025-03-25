# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_test_cube3D.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42.luxembourg.lu>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 09:46:31 by nfordoxc          #+#    #+#              #
#    Updated: 2025/03/19 09:35:11 by nfordoxc         ###   Luxembourg.lu      #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

params=(
	""
	"toto"
	"4545"
	"Makefile"
	"./images/w_img.xpm"
	"./maps/.cub"
	"./maps/toto.cub"
)

list_error_map=(
	./maps/bad/.cub
	./maps/bad/C_noexist.cub
	./maps/bad/C_novalid.cub
	./maps/bad/EA_noexist.cub
	./maps/bad/EA_novalid.cub
	./maps/bad/F_noexist.cub
	./maps/bad/F_novalid.cub
	./maps/bad/map_noexist.cub
	./maps/bad/map_novalid_1.cub
	./maps/bad/map_novalid_2.cub
	./maps/bad/multi_player.cub
	./maps/bad/multi_texture.cub
	./maps/bad/no_closed_1.cub	
	./maps/bad/no_closed_2.cub
	./maps/bad/no_closed_3.cub
	./maps/bad/no_closed_4.cub
	./maps/bad/no_closed_5.cub
	./maps/bad/no_closed_6.cub
	./maps/bad/no_closed_7.cub
	./maps/bad/no_closed_8.cub
	./maps/bad/no_closed_9.cub
	./maps/bad/no_closed_10.cub
	./maps/bad/NO_noexist.cub
	./maps/bad/NO_novalid.cub
	./maps/bad/no_player.cub
	./maps/bad/not_cub
	./maps/bad/No_F_key.cub
	./maps/bad/No_C_key.cub
	./maps/bad/SO_noexist.cub
	./maps/bad/SO_novalid.cub
	./maps/bad/tab_map.cub
	./maps/bad/WE_noexist.cub
	./maps/bad/WE_novalid.cub
	./maps/bad/Zarbi.cub
)

list_valid_map=(
	./maps/valid/CT_noexist.cub
	./maps/valid/CT_novalid.cub
	./maps/valid/FT_noexist.cub
	./maps/valid/FT_novalid.cub
	./maps/valid/map_0.cub
	./maps/valid/map_1.cub
	./maps/valid/map_2.cub
	./maps/valid/map_3.cub
	./maps/valid/map_4.cub
	./maps/valid/map_5.cub
	./maps/valid/map_6.cub
	./maps/valid/map_7.cub
	./maps/valid/map_8.cub
	./maps/valid/map_9.cub
	./maps/valid/map_10.cub
	./maps/valid/map_11.cub
	./maps/valid/map_12.cub
)

error_count=0

chmod -r ./maps/bad/no_read.cub

if [ $# -eq 0 ]; then
    echo "Usage: bash ./run_test_cube3D.sh \"make || make bonus\" \"PROG_NAME\""
    exit 1
fi

NAME=$2

eval "$1"

clear

echo -e "\033[1;94m _______   ______   _______    _______       _____\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|     /     |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |       /  /|  |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |      /__/ |  |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |           |  |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|           |__|\033[0m"
echo ""
echo -e "\t\t\033[1;93mBAD ARGUMENT.\033[0m"
echo ""

for i in "${!params[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./$NAME ${params[i]}\033[1;93m"
	./$NAME ${params[i]} &> $TEMPFILE

	if grep -q "Error" $TEMPFILE || grep -q "Usage" $TEMPFILE; then
		echo -e "\033[1;92mOK => Bad argument catching.\033[0m"
	else
		echo -e "\033[1;91mKO => Bad argument not catching.\033[0m"
		((error_count++))
	fi

	rm $TEMPFILE
done

echo -e "\033[1;94m _______   ______   _______    _______      ______\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|    /  __   \\ \033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |      /__/  /  /\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |          /  /\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |        /  /___\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|       (_______)\033[0m"
echo ""
echo -e "\t\t\033[1;93mBAD MAP.\033[0m"
echo ""

for i in "${!list_error_map[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./$NAME ${list_error_map[i]}\033[1;93m"
	./$NAME ${list_error_map[i]} 2> $TEMPFILE

	if grep -q "Error" $TEMPFILE; then
		echo -e "\033[1;92mOK => Error message detected.\033[0m"
	else
		echo -e "\033[1;91mKO => Error message not detected.\033[0m"
		((error_count++))
	fi

	rm $TEMPFILE
done

echo -e "\033[1;94m _______   ______   _______    _______      _______\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|    |____   |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |          __|  |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |         |__   |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |        ____|  |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|       |_______|\033[0m"
echo ""
echo -e "\t\t\033[1;93mGOOD MAP.\033[0m"
echo ""

for i in "${!list_valid_map[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./$NAME ${list_valid_map[i]}\033[1;93m"
	./$NAME ${list_valid_map[i]} &> $TEMPFILE

	if grep -q "Error" $TEMPFILE; then
		echo -e "\033[1;91mKO => Error message detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92mOK => Error message not detected.\033[0m"
	fi

	rm $TEMPFILE
done

echo -e "\033[1;94m _______   ______   _______    _______      __\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|    |  |   __\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |       |  |__|  |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |       |_____   |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |             |  |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|             |__|\033[0m"
echo ""
echo -e "\t\t\033[1;93mBAD ARGUMENT VALGRIND.\033[0m"
echo ""

for i in "${!params[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST VALGRIND $((i + 1)): ./$NAME ${params[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes ./$NAME ${params[i]} &> $TEMPFILE

	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91mMemory leaks detected :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92mNo memory leaks detected.\033[0m"
	fi

	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94total heap usage :\033[0m"
		echo "$HEAP_USAGE"
	fi

	FD_COUNT=$(grep -E "FILE DESCRIPTORS: [0-9]+ open" $TEMPFILE | awk '{print $4}')
	if [ -n "$FD_COUNT" ] && [ "$FD_COUNT" -gt 3 ]; then
		echo -e "\033[1;91mFile descriptor open detected :\033[0m"
		grep -A 3 "FILE DESCRIPTORS:" $TEMPFILE | grep -v "std"
		((error_count++))
	else
		echo -e "\033[1;92mNo file descriptor detected.\033[0m"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\033[1;94m _______   ______   _______    _______       __        __\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|      \\ \\      / /\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |          \\ \\    / /\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |           \\ \\  / /\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |            \\ \\/ /\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|             \\\__/\033[0m"
echo ""
echo -e "\t\t\033[1;93mBAD MAP VALGRIND.\033[0m"
echo ""

for i in "${!list_error_map[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./$NAME ${list_error_map[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes ./$NAME ${list_error_map[i]} &> $TEMPFILE

	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91mDes fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92mAucune fuite de mémoire détectée.\033[0m"
	fi

	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
	fi

	FD_COUNT=$(grep -E "FILE DESCRIPTORS: [0-9]+ open" $TEMPFILE | awk '{print $4}')
	if [ -n "$FD_COUNT" ] && [ "$FD_COUNT" -gt 3 ]; then
		echo -e "\033[1;91mDes descripteurs de fichiers non fermés ont été détectés :\033[0m"
		grep -A 3 "FILE DESCRIPTORS:" $TEMPFILE | grep -v "std"
		((error_count++))
	else
		echo -e "\033[1;92mAucun descripteur de fichier non fermé détecté.\033[0m"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\033[1;94m _______   ______   _______    _______       __        __  _\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|      \\ \\      / / | |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |          \\ \\    / /  | |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |           \\ \\  / /   | |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |            \\ \\/ /    | |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|             \\__/     |_|\033[0m"
echo ""
echo -e "\t\t\033[1;93mGOOD MAP VALGRIND.\033[0m"
echo ""

for i in "${!list_valid_map[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./$NAME ${list_valid_map[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes ./$NAME ${list_valid_map[i]} &> $TEMPFILE
	
	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91mDes fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92mAucune fuite de mémoire détectée.\033[0m"
	fi

	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
	fi

	FD_COUNT=$(grep -E "FILE DESCRIPTORS: [0-9]+ open" $TEMPFILE | awk '{print $4}')
	if [ -n "$FD_COUNT" ] && [ "$FD_COUNT" -gt 3 ]; then
		echo -e "\033[1;91mDes descripteurs de fichiers non fermés ont été détectés :\033[0m"
		grep -A 3 "FILE DESCRIPTORS:" $TEMPFILE | grep -v "std"
		((error_count++))
	else
		echo -e "\033[1;92mAucun descripteur de fichier non fermé détecté.\033[0m"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo -e "\033[1;94m _______  _   ___    _\033[0m"
echo -e "\033[1;94m|  ____| |_| |   \  | |\033[0m"
echo -e "\033[1;94m| |__     _  | |\ \ | |\033[0m"
echo -e "\033[1;94m|  __|   | | | | \ \| |\033[0m"
echo -e "\033[1;94m| |      | | | |  \ | |\033[0m"
echo -e "\033[1;94m|_|      |_| |_|   \__|\033[0m"
echo ""

if ((error_count == 0)); then
	echo -e "\033[1;92mAucune erreur détectée.\033[0m"
else
	echo -e "\n\033[1;91mNombre total d'erreurs détectées : $error_count\033[0m"
fi

chmod +r ./maps/bad/no_read.cub

make fclean > /dev/null 2>&1
