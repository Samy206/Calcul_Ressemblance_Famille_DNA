							#include <unistd.h>
							#include <stdio.h>
							#include <stdlib.h>
							#include "sequence.h"
							#include "distance.h"
							
							int main(int argc , char **argv)
							{
								float d ;
								LISTE *l = initialiser_liste();
								SEQUENCE D[21];
								initialiser_tab_seq(D,argv[1]);
								float **T = malloc(19*sizeof(float*));
								for(int i = 0 ; i < 19 ; i++ )
								{
									T[i] = malloc(19*sizeof(float));
								}
										
								for(int i = 20 ; i >= 1 ; i--)
								{
									for(int j = 20 ; j >= 1 ; j--)
									{
										if( i != j )
										{	
											remplir_tab(T,19,19);
											d = distance_dyn(D[i].s,D[j].s,D[i].taille-1,D[j].taille-1,T);
											push_liste(l,d,i,j);
											}
										}
									}
								ecrire_fichier_liste_fin(l,"partie1-Liste_distances");
								free(T);
								
								exit(0);
							}
