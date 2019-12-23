									#include <unistd.h>
									#include <stdio.h>
									#include <stdlib.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "famille.h"
									
									int main(int argc , char ** argv)
									{
										clean_fichier(argv[23]);
										clean_fichier(argv[22]);
										clean_fichier(argv[21]);
										SEQUENCE D[21] ;
										initialiser_tab_seq(D,argv);
										afficher_tab(D);
										LISTE *l = creer_liste_initiale(D,argv);
										
										
										int T[10] , numero , taille ;
										float d ;
										FAMILLE f[6];
										int i ;
										i = 0 ;
										while(!est_vide(l))
										{
											d = recherche_distance_min(l);
											numero  = get_num_freq_max(d,l);
											T[0] = numero  ;
											taille =get_num_autre(T,d,numero,l);
											f[i] = creer_famille_initiale(taille);
											remplir_famille(f[i],T,D);
											ecrire_fich_fam(f[i],T,argv[23+i]);
									
											for(int j = 0 ; j < taille ; j++)
											{
												supp_numero_seq(l,T[j]);
											}
											ecrire_fichier_liste_fin(l,argv[22]);
											i++;	
										}
						
										
										exit(0);
									}
									
									
									
									
