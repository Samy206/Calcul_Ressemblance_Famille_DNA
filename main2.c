									#include <unistd.h>
									#include <stdio.h>
									#include <stdlib.h>
									#include "sequence.h"
									#include "distance.h"
									#include "famille.h"
									
									int main(int argc , char ** argv)
									{
										int T[10];
										int taille ;
										
										LISTE *l = creer_liste_initiale(argv);
										
										float d = recherche_distance_min(l);
										printf("distance_min : %f\n",d);
										
										int numero = get_num_freq_max(d,argv);
										printf("numero : %d\n",numero);
										
										 taille = get_num_autre(T,numero,d,argv);
										
										for(int i = 0 ; i < taille ; i++)
										{
											printf("T[%d] : %d\n",i,T[i]);
										}
										
										
										supp_numero_seq(l,numero);
										
										for(int j = 0 ; j < taille ; j++)
										{
											supp_numero_seq(l,T[j]);
										}
										
										ecrire_fichier_liste_fin(l,argv[21]);
										
										exit(0);
									}
									
									
									
