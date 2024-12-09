# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run_test_cub_3D.sh                                 :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfordoxc <nfordoxc@42luxembourg.lu>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 09:46:31 by nfordoxc          #+#    #+#              #
#    Updated: 2024/12/09 13:48:45 by nfordoxc         ###   Luxembourg.lu      #
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
	.cub
	C_noexist.cub
	C_novalid.cub
	EA_noexist.cub
	EA_novalid.cub
	F_noexist.cub
	F_novalid.cub
	FT_novalid.cub
	Map_noclose.cub
	Map_noexist.cub
	Map_novalid.cub
	NO_noexist.cub
	NO_novalid.cub
	not_cub
	SO_noexist.cub
	SO_novalid.cub
	WE_noexist.cub
	WE_novalid.cub
)

list_valid_map=(
	
)

chmod -r ./maps/error_test/no_read.cub
make re
clear

echo -e "\033[1;94m _______   ______   _______    _______       ______\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|     /      |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |       /  / |  |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |      /__/  |  |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |            |  |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|            |__|\033[0m"
echo ""

for i in "${!params[@]}"
do
	echo -e "\033[1;94mTEST $((i + 1)): ./cube3D ${params[i]}\033[1;93m"
	./cube3D ${params[i]}
done

for i in "${!list_error_map[@]}"
do
	echo -e "\033[1;94mTEST $((i + 1)): ./cube3D ./maps/error_test/${list_error_map[i]}\033[1;93m"
	./cube3D ./maps/error_test/${list_error_map[i]}
done

: <<'EOF'
echo -e "\033[1;94m _______   ______   _______    _______      ________\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|    /  __    |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |      /__/  /  /\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |          /  /\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |        /  /____\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|       |________|\033[0m"
echo ""

for prefix in s w e p r
do
	case $prefix in
		s|w) max=5;;
		e) max=6;;
		p) max=4;;
		r) max=1;;
		ok) max=16;;
	esac
	for i in $(seq 1 $max)
	do
		echo -e "\033[1;94m${prefix}_${i}.ber\033[1;93m"
		./so_long ./test/mandatory/maps/${prefix}_${i}.ber
	done
done

echo -e "\033[1;94m _______   ______   _______    _______      _______\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|    |____   |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |          __|  |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |         |__   |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |        ____|  |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|       |_______|\033[0m"
echo ""

for i in "${!list_valid_map[@]}"
do
	echo -e "\033[1;94mTEST $((i + 1)): ./so_long ./test/mandatory/maps/${list_valid_map[i]}\033[1;93m"
	./so_long ./test/mandatory/maps/${list_valid_map[i]}
done

echo -e "\033[1;94m _______   ______   _______    _______      __\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|    |  |   __\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |       |  |__|  |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |       |_____   |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |             |  |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|             |__|\033[0m"
echo ""

error_count=0

for i in "${!params[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST VALGRIND $((i + 1)): ./so_long ${params[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes ./so_long ${params[i]} &> $TEMPFILE

	# Variables pour stocker les valeurs de fuites de mémoire
	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	# Vérifie les fuites de mémoire
	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91mDes fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92mAucune fuite de mémoire détectée.\033[0m"
	fi

	# Affiche l'utilisation de la heap
	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
	fi

	# Vérifie les descripteurs de fichiers non fermés
	FD_COUNT=$(grep -E "FILE DESCRIPTORS: [0-9]+ open" $TEMPFILE | awk '{print $4}')
	if [ -n "$FD_COUNT" ] && [ "$FD_COUNT" -gt 3 ]; then
		echo -e "\033[1;91mDes descripteurs de fichiers non fermés ont été détectés :\033[0m"
		grep -A 3 "FILE DESCRIPTORS:" $TEMPFILE | grep -v "std"
		((error_count++))
	else
		echo -e "\033[1;92mAucun descripteur de fichier non fermé détecté.\033[0m"
	fi

	# Affiche les autres erreurs possibles
	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	# Nettoyage
	rm $TEMPFILE
done

# Bouclage sur les arguments du tableau list_error_map
for i in "${!list_error_map[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./so_long ./test/mandatory/maps/${list_error_map[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes ./so_long ./test/mandatory/maps/${list_error_map[i]} &> $TEMPFILE

	# Variables pour stocker les valeurs de fuites de mémoire
	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	# Vérifie les fuites de mémoire
	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91mDes fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92mAucune fuite de mémoire détectée.\033[0m"
	fi

	# Affiche l'utilisation de la heap
	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
	fi

	# Vérifie les descripteurs de fichiers non fermés
	FD_COUNT=$(grep -E "FILE DESCRIPTORS: [0-9]+ open" $TEMPFILE | awk '{print $4}')
	if [ -n "$FD_COUNT" ] && [ "$FD_COUNT" -gt 3 ]; then
		echo -e "\033[1;91mDes descripteurs de fichiers non fermés ont été détectés :\033[0m"
		grep -A 3 "FILE DESCRIPTORS:" $TEMPFILE | grep -v "std"
		((error_count++))
	else
		echo -e "\033[1;92mAucun descripteur de fichier non fermé détecté.\033[0m"
	fi

	# Affiche les autres erreurs possibles
	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	# Nettoyage
	rm $TEMPFILE
done

for prefix in s w e p r
do
	case $prefix in
		s|w) max=5;;
		e) max=6;;
		p) max=4;;
		r) max=1;;
		ok) max=16;;
	esac
	for i in $(seq 1 $max)
	do
		TEMPFILE=$(mktemp)
		echo -e "\033[1;94m${prefix}_${i}.ber\033[1;93m"
		valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes ./so_long ./test/mandatory/maps/${prefix}_${i}.ber &> $TEMPFILE

		# Variables pour stocker les valeurs de fuites de mémoire
		def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
		ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
		pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
		still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
		suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

		# Vérifie les fuites de mémoire
		if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
			echo -e "\033[1;91mDes fuites de mémoire ont été détectées :\033[0m"
			grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
			((error_count++))
		else
			echo -e "\033[1;92mAucune fuite de mémoire détectée.\033[0m"
		fi

		# Affiche l'utilisation de la heap
		HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
		if [ -n "$HEAP_USAGE" ]; then
			echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
			echo "$HEAP_USAGE"
		fi

		# Vérifie les descripteurs de fichiers non fermés
		FD_COUNT=$(grep -E "FILE DESCRIPTORS: [0-9]+ open" $TEMPFILE | awk '{print $4}')
		if [ -n "$FD_COUNT" ] && [ "$FD_COUNT" -gt 3 ]; then
			echo -e "\033[1;91mDes descripteurs de fichiers non fermés ont été détectés :\033[0m"
			grep -A 3 "FILE DESCRIPTORS:" $TEMPFILE | grep -v "std"
			((error_count++))
		else
			echo -e "\033[1;92mAucun descripteur de fichier non fermé détecté.\033[0m"
		fi

		# Affiche les autres erreurs possibles
		ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
		if [ -n "$ERROR_SUMMARY" ]; then
			echo -e "\033[1;94mERROR SUMMARY:\033[0m"
			echo "$ERROR_SUMMARY"
		fi

		# Nettoyage
		rm $TEMPFILE
	done
done

for i in "${!list_valid_map[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./so_long ./test/mandatory/maps/${list_valid_map[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes ./so_long ./test/mandatory/maps/${list_valid_map[i]} &> $TEMPFILE
	
	# Variables pour stocker les valeurs de fuites de mémoire
	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	# Vérifie les fuites de mémoire
	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91mDes fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92mAucune fuite de mémoire détectée.\033[0m"
	fi

	# Affiche l'utilisation de la heap
	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
	fi

	# Vérifie les descripteurs de fichiers non fermés
	FD_COUNT=$(grep -E "FILE DESCRIPTORS: [0-9]+ open" $TEMPFILE | awk '{print $4}')
	if [ -n "$FD_COUNT" ] && [ "$FD_COUNT" -gt 3 ]; then
		echo -e "\033[1;91mDes descripteurs de fichiers non fermés ont été détectés :\033[0m"
		grep -A 3 "FILE DESCRIPTORS:" $TEMPFILE | grep -v "std"
		((error_count++))
	else
		echo -e "\033[1;92mAucun descripteur de fichier non fermé détecté.\033[0m"
	fi

	# Affiche les autres erreurs possibles
	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	# Nettoyage
	rm $TEMPFILE
done
EOF

# Bouclage sur tout avec valgrind
echo -e "\033[1;94m _______  _   ___    _\033[0m"
echo -e "\033[1;94m|  ____| |_| |   \  | |\033[0m"
echo -e "\033[1;94m| |__     _  | |\ \ | |\033[0m"
echo -e "\033[1;94m|  __|   | | | | \ \| |\033[0m"
echo -e "\033[1;94m| |      | | | |  \ | |\033[0m"
echo -e "\033[1;94m|_|      |_| |_|   \__|\033[0m"
echo ""

# Affiche le nombre total d'erreurs détectées
echo -e "\n\033[1;93mNombre total d'erreurs détectées : $error_count\033[0m"

chmod +r ./maps/error_test/no_read.cub
