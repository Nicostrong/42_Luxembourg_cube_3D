# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    cuicui_paintesting.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 14:27:58 by phkevin           #+#    #+#              #
#    Updated: 2024/11/18 12:02:35 by phkevin          ###   Luxembour.lu       #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Définir les couleurs avant de les utiliser
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # Pas de couleur

# Fonction pour vérifier si une entrée est un entier
function is_integer() {
    [[ "$1" =~ ^[0-9]+$ ]]
}

# Fonction principale
main() {

	COUNT=1
	clear

	# Affichage de la bannière avec la couleur CYAN
	echo -e "${CYAN} 
	  ____      _            _                              
	 | ___|   _(_) ___ _   _(_)                             
	 | |  | | | | || __| | | | |                             
	 | |__| |_| | | (__| |_| | |                             
	 |____|__ _|_||___||__ _|_|__         _   _             
	 |  _ | __ _(_)_ __     |_   _|__  ___| |_(_)_ __   __ _ 
	 | |_) | _  | |  _ | _____| || _ \| __| __| |  _ | | _  |
	 |  __| (_| | | | | |_____| |  __/|__ | |_| | | | | (_| |
	 |_|   |__ _|_|_| |_|     |_||___||___||__|_|_| |_||__  |
		                                              |___|${NC}"

	# Fonction pour vérifier si une entrée est un entier
	function is_integer() {
		[[ "$1" =~ ^[0-9]+$ ]]
	}

	# Affichage du menu d'options
	echo -e "${CYAN}Choisissez une option :${NC}"
	echo -e "${YELLOW}1) Lancer l'auto-compilateur${NC}"
	echo -e "${YELLOW}2) Lancer des tests${NC}"
	echo -e "${YELLOW}3) Clean${NC}"
	echo -e "${YELLOW}4) Quitter${NC}"

	# Lire le choix de l'utilisateur
	read -p "Votre choix : " CHOICE

	# Traitement du choix
	case "$CHOICE" in
		1)
		    echo -e "${GREEN}Lancement de l'auto-compilateur...${NC}"
		    # Ajoutez ici les commandes pour compiler votre programme
		    gnome-terminal -- bash -c "bash run_make.sh; bash"
		    ;;
		2)
		    # Sous-menu pour les tests
		    echo -e "${CYAN}Choisissez un test :${NC}"
		    echo -e "${YELLOW}1) Philosopher${NC}"
			echo -e "${YELLOW}2) MiniTalk${NC}"
		    echo -e "${YELLOW}3) Rush 01${NC}"
		    echo -e "${YELLOW}4) Rush 02${NC}"
		    echo -e "${YELLOW}5) Quitter${NC}"
		    
		    read -p "Votre choix : " TEST_CHOICE
		    
		    case "$TEST_CHOICE" in
		    	#######################################################
		    	#
		        # PHILOSOPHER
		        #
		        #######################################################
		        1)
		            # Demander à l'utilisateur de saisir le nombre de tests
		            read -p "Entrez le nombre de tests à lancer : " COUNT
		            
		            # Vérification que l'entrée est bien un entier
                    if is_integer "$COUNT"; then
		                echo -e "${GREEN}Lancement de $COUNT tests...${NC}"
		                
		                gnome-terminal -- bash -c "bash make.sh; exit"
		                sleep 1
		                
		                # Boucle pour lancer les tests
		                for ((i = 1; i <= COUNT; i++))
		                do
		                    gnome-terminal -- bash -c "bash paintest/test_philo.sh; bash"
		                done 
		            else
		                echo -e "${RED}Erreur : Vous devez entrer un nombre entier valide.${NC}"
		            fi
		            ;;
		    	#######################################################
		    	#
		        # MINITALK
		        #
		        #######################################################
		        2)
					#options
					#-a test tout
					#-m teste la mandatory
					#-b teste les bonus
					#-q	quitte le tester
					
					# Sous-menu pour le test
					echo -e "${CYAN}Choisissez une option pour le test de minitalk :${NC}"
					echo -e "${YELLOW}1) All${NC}"
		    		echo -e "${YELLOW}2) Mandatory${NC}"
					echo -e "${YELLOW}3) Bonus${NC}"
					echo -e "${YELLOW}4) Quitter${NC}"
					
					read -p "Votre choix : " MINI_CHOICE

					case "$MINI_CHOICE" in
					#######################################################
					#
				    # ALL
				    #
				    #######################################################
				    1)
						gnome-terminal -- bash -c "python3 ./paintest/minitalk/minitalk_tester.py -a; bash"
						;;
                    #######################################################
					#
				    # MANDATORY
				    #
				    ####################################################### 
				    2)
						gnome-terminal -- bash -c "python3 ./paintest/minitalk/minitalk_tester.py -m; bash"
						;;
                    #######################################################
					#
				    # BONUS
				    #
				    ####################################################### 
				    3)
						gnome-terminal -- bash -c "python3 ./paintest/minitalk/minitalk_tester.py -b; bash"
						;;
                    #######################################################
					#
				    # QUITTER
				    #
				    ####################################################### 
				    4)
				        echo -e "${CYAN}Merci d'avoir utilisé Cuicui Pain-testing.${NC}"
				        exit
				  	  ;;
				esac
				;;
		    	#######################################################
		    	#
		        # RUSH 01
		        #
		        #######################################################
		        3)
					# Sous-menu pour le rush01
					echo -e "${CYAN}Choisissez une action pour Rush 01 :${NC}"
					echo -e "${YELLOW}1) Generer des map${NC}"
		    		echo -e "${YELLOW}2) Lancer le test${NC}"
					echo -e "${YELLOW}3) Quitter${NC}"
					
		   	 		read -p "Votre choix : " RUSH01_CHOICE
		   	 		
		    		case "$RUSH01_CHOICE" in
					#######################################################
					#
				    # GENERATEUR MAP
				    #
				    #######################################################
				    1)
		                read -p "Entrez la taille de la map (1 - 9) : " SIZE
		                read -p "Entrez le nombre de générations à lancer : " COUNT
		                
		                if is_integer "$COUNT"; then
		                    if [ "$SIZE" -ge 1 ] && [ "$SIZE" -le 9 ]; then
		                        echo -e "${GREEN}Lancement de $COUNT générations...${NC}"
		                        
		                        for ((i = 1; i <= COUNT; i++)); do
		                            gnome-terminal -- bash -c "echo -e \"\n\" >> paintest/rush01/map$SIZE; exit"
		                            gnome-terminal -- bash -c "echo -e \"\n\" >> paintest/rush01/map$SIZE; exit"
		                            gnome-terminal -- bash -c "python3 paintest/rush01/generator.py \"$SIZE\" >> paintest/rush01/map$SIZE"
		                        done
		                    else
		                        echo -e "${RED}Option invalide. Veuillez relancer le script et choisir une valeur de 4 à 9.${NC}"
		                    fi
		                else
		                    echo -e "${RED}Erreur : Vous devez entrer un nombre entier valide.${NC}"
		                fi
		                ;;
                    #######################################################
					#
				    # LANCE LE TEST
				    #
				    ####################################################### 
				    2)
				    	#options
						#-m 	run mandatory tests
						#-t [n]	automatic timeout in seconds, default is 3
						#-b [n]	run tests for a grid of size n×n
						#-a	run tests for all grid sizes from 1 to 9
						#-o	compile program with -O3 optimizations
						
						# Sous-menu pour le test
						echo -e "${CYAN}Choisissez une action pour le test Rush 01 :${NC}"
						echo -e "${YELLOW}1) Mandatory tests${NC}"
						echo -e "${YELLOW}2) Automatic timeout - seconds, default a 3 sc${NC}"
						echo -e "${YELLOW}3) Run tests pour une grille de taille n×n${NC}"
						echo -e "${YELLOW}4) Run tests pour tout les taille de grille (1 a 9)${NC}"
						echo -e "${YELLOW}5) Compile le program avec -O3 optimisattion${NC}"
						echo -e "${YELLOW}6) Quitter${NC}"
						
			   	 		read -p "Votre choix : " RUSH01_OPT
			   	 		
						case "$RUSH01_OPT" in
							#######################################################
							#
							# MANDATORY
							#
							####################################################### 
							1)
								gnome-terminal -- bash -c "cd paintest/rush01/athill_r01/ && bash test.sh -m; bash"
								;;
							#######################################################
							#
							# AUTOMATIC TIMEOUT
							#
							####################################################### 
							2)
								# Demander à l'utilisateur de saisir le nombre
		           				read -p "Entrez le temps en seconde avant le timeout : " TIME
		           				
								# Vérification que l'entrée est bien un entier
						        if is_integer "$TIME"; then
									gnome-terminal -- bash -c "cd paintest/rush01/athill_r01/ && bash test.sh -t \"$TIME\"; bash"
								else
								    echo -e "${RED}Erreur : Vous devez entrer un nombre entier valide.${NC}"
								fi
								;;
							#######################################################
							#
							# RUN TEST SIZE GRIDE
							#
							####################################################### 
							3)
								# Demander à l'utilisateur de saisir le nombre
		           				read -p "Entrez la taille de la grille : " TIME
		           				
								# Vérification que l'entrée est bien un entier
						        if is_integer "$TIME"; then
									gnome-terminal -- bash -c "cd paintest/rush01/athill_r01/ && bash test.sh -b \"$TIME\"; bash"
								else
								    echo -e "${RED}Erreur : Vous devez entrer un nombre entier valide.${NC}"
								fi
								;;
							#######################################################
							#
							# ALL TEST FOR SIZE
							#
							####################################################### 
							4)
								gnome-terminal -- bash -c "cd paintest/rush01/athill_r01/ && bash test.sh -a; bash"
								;;
							#######################################################
							#
							# COMPILE WITH OPTION
							#
							####################################################### 
							5)
								gnome-terminal -- bash -c "cd paintest/rush01/athill_r01/ && bash test.sh -o; bash"
								exit
								;;
							#######################################################
							#
							# EXIT
							#
							####################################################### 
							6)
								echo -e "${CYAN}Merci d'avoir utilisé Cuicui Pain-testing.${NC}"
								exit
								;;
							#######################################################
							#
							# ERROR
							#
							####################################################### 
						  	*)
								echo -e "${RED}Option invalide. Veuillez relancer le script et choisir 1 ou 2.${NC}"
								;;
				    	esac
						;;
				    #######################################################
					#
				    # EXIT
				    #
				    ####################################################### 
				    3)
				        echo -e "${CYAN}Merci d'avoir utilisé Cuicui Pain-testing.${NC}"
				        exit
				        ;;
					#######################################################
					#
					# ERROR
					#
					####################################################### 
				  	*)
				        echo -e "${RED}Option invalide. Veuillez relancer le script et choisir 1 ou 2.${NC}"
				        ;;
				esac
				;;
			    #######################################################
				#
			    # RUSH 02
			    #
			    ####################################################### 
			    4)
			        gnome-terminal -- bash -c "cd paintest/rush02/athill_r02/ && python3 tester.py; bash"
			        exit
			        ;;
		    	#######################################################
		    	#
		        # EXIT
		        #
		        ####################################################### 
		        5)
		            echo -e "${CYAN}Merci d'avoir utilisé Cuicui Pain-testing.${NC}"
		            exit
		            ;;
				#######################################################
				#
				# ERROR
				#
				####################################################### 
		        *)
		            echo -e "${RED}Option invalide. Veuillez relancer le script et choisir 1 ou 2.${NC}"
		            ;;
		    esac
		    ;;
		#######################################################
		#
		# CLEAN
		#
		####################################################### 
		3)
		    # Sous-menu pour clean
		    echo -e "${CYAN}Confirmer le clean:${NC}"
		    echo -e "${YELLOW}1) Oui${NC}"
		    echo -e "${YELLOW}2) Non${NC}
		    "
		    # Lire le choix de l'utilisateur
		    read -p "Votre choix : " CONF

		    case "$CONF" in
		        1)
		            echo -e "${CYAN}Merci d'avoir utilisé Cuicui Pain-testing.${NC}"
		            echo -e "${RED}********** Auto destruction du program **********${NC}"
		            sleep 1
		            echo -e "${RED}********** Epandage de l'essence.${NC}"
		            sleep 1
		            echo -e "${RED}********** Etincelle du piaf en preparation.${NC}"
		            sleep 1
		            echo -e "${RED}********** FEUUUUUUUUUU.${NC}"
		            sleep 1
		            echo -e "${RED}********** SA CRAMMMMEEE.${NC}"
		            gnome-terminal -- bash -c "bash clean.sh; exit"
		            exit
		            ;;
		        2)
		            echo -e "${RED}*************************************************${NC}"
		            echo -e "${RED}*            CLEAN ANNULER                      *${NC}"
		            echo -e "${RED}*************************************************\n${NC}"
		            echo -e "${CYAN}Merci d'avoir utilisé Cuicui Pain-testing.${NC}"
		            exit
		            ;;
		    esac
		    ;;
		#######################################################
		#
		# EXIT
		#
		####################################################### 
		4)
		    echo -e "${CYAN}Merci d'avoir utilisé Cuicui Pain-testing.${NC}"
		    exit
		    ;;
		#######################################################
		#
		# ERROR
		#
		####################################################### 
		*)
		    echo -e "${RED}Option invalide. Veuillez relancer le script et choisir 1, 2 ou 3.${NC}"
		    ;;
	esac
}

main
 