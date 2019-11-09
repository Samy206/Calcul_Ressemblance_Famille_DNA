									#include <unistd.h>
									#include <stdio.h>
									#include <stdlib.h>
									#include "sequence.h"
									#include "distance.h"
									#include "famille.h"
									
									int main(int argc , char ** argv)
									{
										SEQUENCE D[20] ;
										initialiser_tab_seq(D,argv);
										
										for ( int i = 0 ; i < 20 ; i++)
										{
											printf("D[%2d] : %s , taille : %d\n",i,D[i].s,D[i].taille);
										}
										/*LISTE *l =creer_liste_initiale(D,argv);
										for ( int i = 0 ; i < 20 ; i++)
										{
											printf("D[%2d] : %s , taille : %d\n",i,D[i].s,D[i].taille);
										}*/
										float dist = distance_sequence_avec_insertions(&D[0],&D[4]);
										printf("dist : %f\n",dist);
										
										exit(0);
									}
									
									
									
