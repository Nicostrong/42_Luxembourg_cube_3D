# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_philo.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 15:36:34 by nfordoxc          #+#    #+#              #
#    Updated: 2024/09/12 14:59:05 by phkevin          ###   Luxembour.lu       #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

not_valid_arg=(
	""
	"toto"
	"300 200 100 50"
	"300 toto 542 35"
	"12 toto 452 652"
	"3 2147483647 2147483648 2"
	"4 500 -54 50"
	"6 500 64 -32 60"
	"1 100 200 100"
	"2147483648 2147483648 2147483648 2147483648"
	"-2147483648 -2147483648 -2147483648 -2147483648"
	"4 4 4 7 19"
	"9 50 100 100"
)

die=(
	"1 400 100 100"
	"1 800 200 200"
	"15 350 200 200"
	"1 800 200 200"
	"4 310 200 100"
	"5 410 200 200"
	"1 400 100 100 2"
	"2 300 200 100 3"
	"6 310 100 200 12"
	"154 400 200 200 20"
)

live_end=(
	"2 400 100 100 12"
	"5 800 200 200 7"
	"8 410 200 200 5"
	"8 410 200 200 1"
	"12 500 100 100 50"
	"50 410 200 100 2"
	"22 410 200 200 2"
	"22 410 200 200 1"
)

live_end_limit=(
	"3 310 100 100 5"
	"5 610 200 200 5"
	"9 610 200 200 5"
	"11 310 100 100 5"
	"13 905 300 200 5"
	"21 605 200 100 5"
	"51 610 200 200 1"
	"155 910 300 300 1"
)

live_end_utlime_limit=(
	"3 301 100 100 5"
	"5 601 200 200 5"
	"9 601 200 200 5"
	"11 301 100 100 5"
	"13 901 300 200 5"
	"21 601 200 100 5"
	"51 601 200 200 5"
)

never_die=(
	"2 400 100 100"
	"8 410 200 200"
	"4 410 200 200"
	"12 500 100 100"
	"50 410 200 100"
	"5 800 200 200"
	"4 410 200 100"
	"8 405 200 200"
)

error_count=0

cd ..
clear

echo -e "\033[1;94m _______   ______   _______    _______        _\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|      | |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |         | |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |         | |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |         | |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|         |_|\033[0m"
echo ""
echo -e "\t\t\033[1;93mNOT VALID ARGS.\033[0m"
echo ""

for i in "${!not_valid_arg[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./philo ${not_valid_arg[i]}\033[1;93m"
	./philo ${not_valid_arg[i]} &> $TEMPFILE

	if grep -q "Error" $TEMPFILE || grep -q "Usage" $TEMPFILE; then
		echo -e "\033[1;92m\tOK => Bad arg catching.\033[0m"
	else
		echo -e "\033[1;91m\tKO => Bad arg not cathing.\033[0m"
		((error_count++))
	fi
done

echo ""
echo -e "\033[1;94m _______   ______   _______    _______        _   _\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|      | | | |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |         | | | |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |         | | | |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |         | | | |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|         |_| |_|\033[0m"
echo ""
echo -e "\t\t\033[1;93mMUST DIE.\033[0m"
echo ""
for i in "${!die[@]}"
do
	TEMPFILE=$(mktemp)
	echo -e "\033[1;94mTEST $((i + 1)): ./philo ${die[i]}\033[1;93m"
	./philo ${dead[i]} &> $TEMPFILE

	is_die=$(grep "died" $TEMPFILE | wc -l)

	if [[ $is_die ]]; then
		echo -e "\033[1;92m\tOK => One philosopher is die.\033[0m"
	else
		echo -e "\033[1;91m\tKO => One philosopher must die.\033[0m"
		((error_count++))
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\033[1;94m _______   ______   _______    _______        _   _   _\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|      | | | | | |\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |         | | | | | |\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |         | | | | | |\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |         | | | | | |\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|         |_| |_| |_|\033[0m"
echo ""
echo -e "\t\t\033[1;93mMUST END.\033[0m"
echo ""

for i in "${!live_end[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): ./philo ${live_end[i]}\033[1;93m"
	./philo ${live_end[i]} &> $TEMPFILE

	nb_philo=$(echo ${live_end[i]} | awk '{print $1}')
	nb_eat=$(echo ${live_end[i]} | awk '{print $5}')
	is_eating=$(grep -c "eating" $TEMPFILE)

	if [[ $((is_eating / nb_eat)) -ge $nb_philo ]]; then
		echo -e "\033[1;92m\tOK => number of eat.\033[0m"
	else
		echo -e "\033[1;91m\tKO => number of eat.\033[0m"
		((error_count++))
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\t\t\033[1;93mMUST END LIMIT TIME TO DIE.\033[0m"
echo ""

for i in "${!live_end_limit[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): ./philo ${live_end_limit[i]}\033[1;93m"
	./philo ${live_end_limit[i]} &> $TEMPFILE

	nb_philo=$(echo ${live_end_limit[i]} | awk '{print $1}')
	nb_eat=$(echo ${live_end_limit[i]} | awk '{print $5}')
	is_eating=$(grep -c "eating" $TEMPFILE)

	if [[ $((is_eating / nb_eat)) -ge $nb_philo ]]; then
		echo -e "\033[1;92m\tOK => number of eat.\033[0m"
	else
		echo -e "\033[1;91m\tKO => number of eat.\033[0m"
		((error_count++))
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\t\t\033[1;93mMUST END ULTIME LIMIT TIME TO DIE.\033[0m"
echo ""

for i in "${!live_end_utlime_limit[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): ./philo ${live_end_utlime_limit[i]}\033[1;93m"
	./philo ${live_end_utlime_limit[i]} &> $TEMPFILE

	nb_philo=$(echo ${live_end_live_end_utlime_limitlimit[i]} | awk '{print $1}')
	nb_eat=$(echo ${live_end_utlime_limit[i]} | awk '{print $5}')
	is_eating=$(grep -c "eating" $TEMPFILE)

	if [[ $((is_eating / nb_eat)) -ge $nb_philo ]]; then
		echo -e "\033[1;92m\tOK => number of eat.\033[0m"
	else
		echo -e "\033[1;91m\tKO => number of eat.\033[0m"
		((error_count++))
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\033[1;94m _______   ______   _______    _______        _   __        __\033[0m"
echo -e "\033[1;94m|__   __| |  ____| |   ____|  |__   __|      | |  \\ \\      / /\033[0m"
echo -e "\033[1;94m   | |    | |___   |  |____      | |         | |   \\ \\    / /\033[0m"
echo -e "\033[1;94m   | |    |  ___|  |_____  |     | |         | |    \\ \\  / /\033[0m"
echo -e "\033[1;94m   | |    | |____   _____| |     | |         | |     \\ \\/ /\033[0m"
echo -e "\033[1;94m   |_|    |______| |_______|     |_|         |_|      \\__/\033[0m"
echo ""
echo -e "\t\t\033[1;93mNEVER END.\033[0m"
echo ""

for i in "${!never_die[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): ./philo ${never_die[i]}\033[1;93m"
	timeout 10s ./philo ${never_die[i]} &> $TEMPFILE

	if grep -q "die" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Died detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No died detected.\033[0m"
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
echo -e "\t\t\033[1;93mNOT VALID ARG.\033[0m"
echo ""

for i in "${!not_valid_arg[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./philo ${not_valid_arg[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./philo ${not_valid_arg[i]} &> $TEMPFILE

	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')


	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91m\tKO => Des fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => Aucune fuite de mémoire détectée.\033[0m"
	fi

	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\t\t\033[1;93mMUST DIE.\033[0m"
echo ""

for i in "${!die[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./philo ${dead[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./philo ${die[i]} &> $TEMPFILE

	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91m\tKO => Des fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => Aucune fuite de mémoire détectée.\033[0m"
	fi

	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\t\t\033[1;93mMUST END.\033[0m"
echo ""

for i in "${!live_end[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./philo ${live_end[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./philo ${live_end[i]} &> $TEMPFILE

	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91m\tKO => Des fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => Aucune fuite de mémoire détectée.\033[0m"
	fi

	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\t\t\033[1;93mNEVER DIE.\033[0m"
echo ""

for i in "${!never_die[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./philo ${never_die[i]}\033[1;93m"
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all timeout 15s ./philo ${never_die[i]} &> $TEMPFILE

	def_lost_bytes=$(grep "definitely lost:" $TEMPFILE | awk '{print $4}')
	ind_lost_bytes=$(grep "indirectly lost:" $TEMPFILE | awk '{print $4}')
	pos_lost_bytes=$(grep "possibly lost:" $TEMPFILE | awk '{print $4}')
	still_reach_bytes=$(grep "still reachable:" $TEMPFILE | awk '{print $4}')
	suppressed_bytes=$(grep "suppressed:" $TEMPFILE | awk '{print $4}')

	if [[ $def_lost_bytes -gt 0 || $ind_lost_bytes -gt 0 || $pos_lost_bytes -gt 0 || $still_reach_bytes -gt 0 || $suppressed_bytes -gt 0 ]]; then
		echo -e "\033[1;91m\tKO => Des fuites de mémoire ont été détectées :\033[0m"
		grep -E "definitely lost:|indirectly lost:|possibly lost:|still reachable:|suppressed:" $TEMPFILE
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => Aucune fuite de mémoire détectée.\033[0m"
	fi

	HEAP_USAGE=$(grep -E "total heap usage:|in use at exit:" $TEMPFILE)
	if [ -n "$HEAP_USAGE" ]; then
		echo -e "\033[1;94mUtilisation totale de la heap :\033[0m"
		echo "$HEAP_USAGE"
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
echo -e "\t\t\033[1;93mNOT VALID ARGS.\033[0m"
echo ""

for i in "${!not_valid_arg[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): valgrind --tool=helgrind ./philo ${not_valid_arg[i]}\033[1;93m"
	valgrind --tool=helgrind ./philo ${not_valid_arg[i]} &> $TEMPFILE

	if grep -q "violated" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Mutex violation detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No mutex violation detected.\033[0m"
	fi

	if grep -q "data race" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Data race detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No data race detected.\033[0m"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\t\t\033[1;93mMUST DIE.\033[0m"
echo ""

for i in "${!die[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): valgrind --tool=helgrind ./philo ${dead[i]}\033[1;93m"
	valgrind --tool=helgrind ./philo ${die[i]} &> $TEMPFILE

	if grep -q "violated" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Mutex violation detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No mutex violation detected.\033[0m"
	fi

	if grep -q "data race" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Data race detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No data race detected.\033[0m"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\t\t\033[1;93mMUST END.\033[0m"
echo ""

for i in "${!live_end[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): valgrind --tool=helgrind ./philo ${live_end[i]}\033[1;93m"
	valgrind --tool=helgrind ./philo ${live_end[i]} &> $TEMPFILE

	if grep -q "violated" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Mutex violation detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No mutex violation detected.\033[0m"
	fi

	if grep -q "data race" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Data race detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No data race detected.\033[0m"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo ""
echo -e "\t\t\033[1;93mNEVER DIE.\033[0m"
echo ""

for i in "${!never_die[@]}"
do
	TEMPFILE=$(mktemp)

	echo -e "\033[1;94mTEST $((i + 1)): valgrind --tool=helgrind timeout 10s ./philo ${never_die[i]}\033[1;93m"
	valgrind --tool=helgrind timeout 10s ./philo ${never_die[i]} &> $TEMPFILE

	if grep -q "violated" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Mutex violation detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No mutex violation detected.\033[0m"
	fi

	if grep "data race" $TEMPFILE; then
		echo -e "\033[1;91m\tKO => Data race detected.\033[0m"
		((error_count++))
	else
		echo -e "\033[1;92m\tOK => No data race detected.\033[0m"
	fi

	ERROR_SUMMARY=$(grep -E "ERROR SUMMARY:" $TEMPFILE)
	if [ -n "$ERROR_SUMMARY" ]; then
		echo -e "\033[1;94mERROR SUMMARY:\033[0m"
		echo "$ERROR_SUMMARY"
	fi

	rm $TEMPFILE
done

echo -e "\n\033[1;93mNombre total d'erreurs détectées : $error_count\033[0m"

echo ""
echo -e "\033[1;94m _______  _   ___    _\033[0m"
echo -e "\033[1;94m|  ____| |_| |   \  | |\033[0m"
echo -e "\033[1;94m| |__     _  | |\ \ | |\033[0m"
echo -e "\033[1;94m|  __|   | | | | \ \| |\033[0m"
echo -e "\033[1;94m| |      | | | |  \ | |\033[0m"
echo -e "\033[1;94m|_|      |_| |_|   \__|\033[0m"
echo ""
