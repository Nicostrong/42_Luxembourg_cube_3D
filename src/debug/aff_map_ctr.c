/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_map_ctr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:37:33 by phkevin           #+#    #+#             */
/*   Updated: 2024/12/04 13:16:31 by phkevin          ###   Luxembourg.lu     */
/*                                                                            */
/* ************************************************************************** */

#include "../src.h"

/*void	aff_map_ctr(t_data *f)
{
	int i;
	int ii;
 
	if (DEBUG == 1)
	{
		printf("Size map X %d Y %d\n", f->ymap, f->xmap);
		printf("X Y %d / %d - Dir %d\n", f->userd.coox, f->userd.cooy, f->userd.dir);
		i = 0;
		while (f->map[i] != NULL)
		{
			ii = 0;
			while (f->map[i][ii] != '\0')
			{
				if (i == f->userd.cooy && ii == f->userd.coox)
					printf("P");
				else
					printf("%c", f->map[i][ii]);
				ii++;
			}
			i++;
			printf("\n");
		}
	}
}*/

void aff_map_ctr(t_data *f)
{
	int i, ii;

	if (DEBUG == 1)
	{
		printf("\n\nSize map X %d Y %d\n", f->ymap, f->xmap);
		printf("X Y %d / %d - Dir %d\n", f->userd.coox, f->userd.cooy, f->userd.dir);
		
		// Affichage des indices de colonnes
		printf("   ");
		for (ii = 0; ii < f->ymap; ii++)
			printf("|%02d", ii);
		printf("|\n");

		// Ligne séparatrice entre les indices et la carte
		printf("__|");
		for (ii = 0; ii < f->ymap; ii++)
			printf("|__");
		printf("|\n");
		
		i = 0;
		while (f->map[i] != NULL)
		{
			// Affichage de l'indice de ligne
			printf("%02d||", i);
			ii = 0;
			while (f->map[i][ii] != '\0')
			{
				if (i == f->userd.coox && ii == f->userd.cooy)
					printf("%s%2c%s|", YELLOWG, 'P',NOCOLORS);
				else
					printf("%2c|", f->map[i][ii]);
				ii++;
			}
			i++;
			printf("|\n");
		}
	}
}
