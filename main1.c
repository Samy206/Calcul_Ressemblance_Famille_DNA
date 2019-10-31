							#include <unistd.h>
							#include <stdio.h>
							#include <stdlib.h>
							#include "sequence.h"
							#include "distance.h"
							
							int main(int argc , char **argv)
							{
								float distance ;
								LISTE *l = initialiser_liste();
								for(int i = 20 ; i >= 1 ; i--)
								{
									SEQUENCE *A = initialiser_sequence(argv[i]);
									for(int j = 20 ; j >= 1 ; j--)
									{
										if(i != j)
										{
												SEQUENCE *B = initialiser_sequence(argv[j]);
												distance = distance_sequence_avec_insertions(A,B);
												push_liste(l,distance,get_indice(argv[i]),get_indice(argv[j]));
												liberer_seq(B);	
										}
									}
									liberer_seq(A);
								}
								
								ecrire_fichier_fin(l,argv[21]);
								float min = recherche_min_distance(l);
								printf("distance min : %f\n",min);
								
								exit(0);
							}
