									#include <unistd.h>
									#include <stdio.h>
									#include <stdlib.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "famille.h"
									
									int main(int argc , char ** argv)
									{
										SEQUENCE D[21] ;
										initialiser_tab_seq(D,argv[1]);
										afficher_tab(D);
										LISTE *l = creer_liste_initiale(D,"partie2-Liste_distances"
																		,"partie2-Liste_seq_modif");
										
										
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
											char *fileName = famille_fileName(i);
											ecrire_fich_fam(f[i],T,fileName);

											for(int j = 0 ; j < taille ; j++)
											{
												supp_numero_seq(l,T[j]);
											}
											ecrire_fichier_liste_fin(l,"partie2-Liste_seq_modif");	
											i++;				
										}
						
										
										exit(0);
									}
									
									
									
									
