									#include <unistd.h>
									#include <stdio.h>
									#include <stdlib.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "famille.h"
									#include "combi.h"
									
									int main(int argc , char ** argv)
									{
										clean_fichier(argv[23]);
										clean_fichier(argv[22]);
										clean_fichier(argv[21]);
										SEQUENCE D[21] ;
										initialiser_tab_seq(D,argv);
										afficher_tab(D);
										LISTE *l = initialiser_liste();
										LISTE *M = creer_liste_initiale(l,D,argv);
										
										
										int T[10] , numero , taille ;
										float d ;
										FAMILLE *f;
										int i = 0 ;
										for(i = 0 ; i < 5 ; i++)
										{
											
											d = recherche_distance_min(l);
											numero  = get_num_freq_max(d,l);
											T[0] = numero  ;
											taille =get_num_autre(T,d,numero,l);
											f = creer_famille_initiale(taille);
											for(int i = 0 ; i < taille ; i++)
											{
												printf("T[%d] : %d\n",i,T[i]);
											}
											remplir_famille(f,T,D);
											ecrire_fich_fam(f,T,argv[23]);
									
											for(int j = 0 ; j < taille ; j++)
											{
												supp_numero_seq(l,T[j]);
											}
											ecrire_fichier_liste_fin(l,argv[22]);
											free(f->table);
											free(f);
											
										}

										/*float d  =distance_sequence_avec_insertions(l,D[2],D[5],2,5,argv[22]);
										printf("d : %f\n",d);
										afficher_liste(l);*/
										
										/*afficher_liste(l);
										printf("\n");
										printf("\n");
										afficher_liste(M);*/
										exit(0);
									}
									
									
									
									
