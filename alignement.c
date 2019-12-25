									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "alignement.h"
									#include "famille.h"
									
									
									void creer_familles(char **argv , FAMILLE *f , SEQUENCE *D)
									{
										initialiser_tab_seq(D,argv);
										afficher_tab(D);
										LISTE *l = creer_liste_initiale(D,argv);
										
										
										int T[10] , numero , taille ;
										float d ;
										int i = 0 ;
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
									}

									
									void align (CHAINES *S , int i , int j , float **T) {
//A diagonal arrow represents a match or mismatch, so the letter of the column and the letter 
//of the row of the origin cell will align.
//A horizontal or vertical arrow represents an indel. 
//Horizontal arrows will align a gap ("-") to the letter of the row (the "side" sequence), 
//vertical arrows will align a gap to the letter of the column (the "top" sequence).
//If there are multiple arrows to choose from, they represent a branching of the 
									
									
										float enHaut = 1000;
										float aGauche = 1000;
										float diag = 1000;
							
										do {
											if (i > 0 && j >=0) {
												enHaut = T[i-1][j];
											} else {
												enHaut = 1000;
											}

											if (j > 0&& i >=0) {
												aGauche = T[i][j-1];
											} else {
												aGauche = 1000;
											}
											if (i > 0 && j > 0) {
												diag = T[i-1][j-1];
											} else {
												diag = 1000;
											}
											
									
											if (enHaut < aGauche && enHaut < diag) {
												S->bnew = prepend(S->bnew, '-'); 
												S->anew = prepend(S->anew, S->a[i]);
												//printf("%f %f %f %c \n", enHaut, aGauche,  diag, '-');

												printf("%c\n", S->a[i]);
												i--;
											}
											else if (aGauche < diag) {
												S->bnew = prepend(S->bnew, S->b[j]); 
												S->anew = prepend(S->anew, '-');
												printf("%c\n", '-');
												j--;
											}
											else {
												
												S->bnew = prepend(S->bnew, S->b[j]); 
												S->anew = prepend(S->anew, S->a[i]);
												printf("%c\n", S->a[i]);
												i--;
												j--;
											}

										}
										while ( i >= 0 && j>=0 );

									
									}



									char * prepend(char* s, const char t)
									{
										
										if (s == NULL) {
											s = malloc(1);
											s[0] = t;
										} else {
										
											int length = strlen(s);
											char *tmp = malloc(length + 1);
											tmp[0] = t;
											for(int i = 1; i < length + 1; i++) {
												tmp[i] = s[i - 1];
											}
											strcpy(s, tmp);
											//free(tmp);
										}

										
										return s;
									}

								
							
																					
