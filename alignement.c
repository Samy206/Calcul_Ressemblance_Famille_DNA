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
									
									void liberer_chaine(CHAINES S)
									{
										free(S.a);
										free(S.b);
										free(S.anew);
										free(S.bnew);
										free(&S);
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
											//printf("i : %d , j : %d \n",i,j);
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

												//printf("%c\n", S->a[i]);
												i--;
											}
											else if (aGauche < diag) {
												S->bnew = prepend(S->bnew, S->b[j]); 
												S->anew = prepend(S->anew, '-');
												//printf("%c\n", '-');
												j--;
											}
											else {
												
												S->bnew = prepend(S->bnew, S->b[j]); 
												S->anew = prepend(S->anew, S->a[i]);
												//printf("%c\n", S->a[i]);
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
											//printf("s : %s , strlen(s) : %d \n",s,strlen(s));
											char *tmp = malloc(length+1);
											tmp[length+1] = '\0' ;
											tmp[0] = t;
											for(int i = 1; i < length+1 ; i++) {
												tmp[i] = s[i - 1];
												//printf("tmp : %s \n",tmp);
											}
											tmp[length+1] = '\0' ;
											strcpy(s, tmp);
											free(tmp);
										}

										
										return s;
									}

									CHAINES initialiser_chaines(char *a , char*b)
									{
										CHAINES S ;
										S.a = malloc(strlen(a)+1);
										S.b = malloc(strlen(b)+1);
										strcpy(S.a,a);
										strcpy(S.b,b);
										S.anew = malloc(strlen(a)+5);
										S.bnew = malloc(strlen(b)+5);
										
										return S; 
									}
									
									int verif_tab(int T[] , int n )
									{
										for(int i  = 0 ; i < n ; i++)
										{
											if((T[i]) != 0)
												return 0 ;
										}
										return 1 ;
									}
									
									ALIGNEMENT creer_alignement ( int nb )
									{
										ALIGNEMENT A ;
										A.nb = nb ;
										A.s = NULL ;
										return A ;
									}
									
									char **creer_seq(FAMILLE f)
									{
										char **Tab_seq = malloc(f.n*sizeof(char*));
										int Tab_marqueur[f.n];
										for(int i = 0 ; i < f.n ; i++)
											Tab_marqueur[i] = 1 ;
											
										float minDist , d ;
										int indiceDist ;
										minDist = 30 ;
										float **T = malloc(19*sizeof(float*));
										for(int i = 0 ; i < 19 ; i++ )
										{
											T[i] = malloc(19*sizeof(float));
											for(int j = 0 ; j < 19 ; j++)
											{
												T[i][j] = -1;
											}
									
										}
										for(int i = 1 ; i < f.n ; i++)
										{
											d = distance_dyn(f.table[0].s,f.table[i].s,f.table[0].taille-1,f.table[i].taille-1,T);
											if(minDist > d)
											{
												minDist = d ;
												indiceDist = i ;
											}
										}
										
										CHAINES S = initialiser_chaines(f.table[0].s,f.table[indiceDist].s);
										align(&S,f.table[0].taille-1,f.table[indiceDist].taille-1,T);
										Tab_seq[0] = malloc(sizeof(S.anew)+1);
										Tab_marqueur[0] = 0 ;
										Tab_marqueur[indiceDist] = 0 ;
										Tab_seq[indiceDist] = malloc(sizeof(S.bnew)+1);
										strcpy(Tab_seq[0],S.anew);
										strcpy(Tab_seq[indiceDist],S.bnew);
										free(&S);
										int l = 0 ;
										
										while(l < f.n-2 )
										{
											int num = 1 ;
											while(Tab_marqueur[num] == 0)
												num++;
											
											remplir_tab(T,19,19);
											
											for(int i = num+1 ; i < f.n ; i++)
											{
												if(Tab_marqueur[i] != 0 && i != num)
												{
													d = distance_dyn(f.table[num].s,f.table[i].s,f.table[num].taille-1,f.table[i].taille-1,T);
													if(minDist > d)
													{
														minDist = d ;
														indiceDist = i ;
													}
												}
											}
											CHAINES S = initialiser_chaines(f.table[num].s,f.table[indiceDist].s);
											align(&S,f.table[num].taille-1,f.table[indiceDist].taille-1,T);
											Tab_seq[num] = malloc(sizeof(S.anew)+1);
											Tab_marqueur[num] = 0 ;
											Tab_marqueur[indiceDist] = 0 ;
											Tab_seq[indiceDist] = malloc(sizeof(S.bnew)+1);
											strcpy(Tab_seq[num],S.anew);
											strcpy(Tab_seq[indiceDist],S.bnew);
											free(&S);
										}
										return Tab_seq;
									}
																					
