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
										
										afficher_tab(D);
										printf("\n");
										printf("\n");
										float distanced = distance_sequence_sans_insertions(D[0],D[17],&D[0].taille,&D[17].taille);
										float distance = distance_sequence_avec_insertions(D[0],D[17]);
										afficher_tab(D);
										printf("distance : %f \n",distanced);
										

										
										exit(0);
									}
									
									
									
