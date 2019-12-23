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

									
									float distance_rec(CHAINES S , int i , int j ,float distance, int *nouvelletailleA , int *nouvelletailleB , float **T)
									{
										float d1,d2,d3,m;
										if(i == 0 && j > 0)
										{	
											//printf("i : %d , j : %d 1\n",i,j);	
											/*for(int rep = 0 ; rep < j ; rep++)
											{
												S.anew[(*nouvelletailleA)+1] = '\0' ;
												for(int k = (*nouvelletailleA) ; k > 0 ; k--)
												{
													S.anew[k] = S.anew[k-1] ;
												}
												S.anew[0] = '-' ;
												printf("nouvelletailleA00 : %d i \n",*nouvelletailleA);
												(*nouvelletailleA)++;
											}*/
											
											return ( distance + 1.5 * j );
										}
												
										else if ( j == 0 && i > 0)
										{
											//printf("i : %d , j : %d 2\n",i,j);
											/*for(int rep = 0 ; rep < i ; rep++)
											{
												S.bnew[(*nouvelletailleB)+1] = '\0' ;
												for(int k = (*nouvelletailleB) ; k > 0 ; k--)
												{
													S.bnew[k] = S.bnew[k-1] ;
												}
												S.bnew[0] = '-' ;
												printf("nouvelletailleB00 : %d j \n",*nouvelletailleB);
												(*nouvelletailleB)++;
											}*/
											return (distance + 1.5 *i );
										}
											
										else if ( i == 0 && j == 0)
										{
											//printf("3 : dist = %f\n",(distance+ compare_carac(S.a[i],S.b[j])));
											return (distance+ compare_carac(S.a[i],S.b[j])) ;	
										}
											
										else if ( T[i][j] != -(1) )
										{
											return T[i][j] ;
										}
										
										else
										{
											d1 = distance_rec(S,i-1,j-1,distance,nouvelletailleA,nouvelletailleB,T) + compare_carac(S.a[i],S.b[j]) ;	
											d2 = distance_rec(S,i-1,j,distance,nouvelletailleA,nouvelletailleB,T) + compare_carac(S.a[i],'-') ;
											d3 = distance_rec(S,i,j-1,distance,nouvelletailleA,nouvelletailleB,T) + compare_carac('-',S.b[j]) ;
											
											if( d1 <= d2 && d1 <= d3 )
											{
												m = d1 ;
											}
											
											//else if( i > j )
											//{
												else if ( d2 < d3 && d2 <= d1 )
												{
													//printf("nouvelletailleB : %d (d2 , 1),",(*nouvelletailleB));
													S.bnew[(*nouvelletailleB)+1] = '\0' ;
													for(int k = (*nouvelletailleB) ; k > j+1; k--)
													{
														S.bnew[k] = S.bnew[k-1] ;
													}													
													S.bnew[j+1] = '-' ;
													printf("anew : %s \nbnew : %s\n",S.anew,S.bnew);
													(*nouvelletailleB) = (*nouvelletailleB)+1;
													//printf(" S.bnew : %s (d2,1)\n",S.bnew);	
													m = d2 ;
												}
												
												else
												{
													//printf("nouvelletailleA : %d (d3 , 1),",(*nouvelletailleA));												
													S.anew[(*nouvelletailleA)+1] = '\0' ;
													for(int k = (*nouvelletailleA) ; k > i+1 ; k--)
													{
														S.anew[k] = S.anew[k-1] ;
													}	
													S.anew[i+1] = '-' ;
													(*nouvelletailleA) = (*nouvelletailleA)+1;
													printf("anew : %s \nbnew : %s\n",S.anew,S.bnew);
													//printf(" S.anew : %s (d3,1)\n",S.anew);													
													m = d3 ;
												}
											//}
											/*else 
											{
												if ( d3 <= d2 )
												{
													S.anew[(*nouvelletailleA)+1] ='\0' ;
													//printf("nouvelletailleA : %d (d3 , 2),",(*nouvelletailleA));
													for(int k = (*nouvelletailleA) ; k > i+1 ; k--)
													{
														S.anew[k] = S.anew[k-1] ;
													}																						
													S.anew[i+1] = '-' ;
													(*nouvelletailleA) = (*nouvelletailleA)+1;	
													//printf(" S.anew : %s (d3,2)\n",S.anew);
													m = d3 ;
												}
												
												else 
												{
													//printf("nouvelletailleB : %d (d2 , 2),",(*nouvelletailleB));
													S.bnew[(*nouvelletailleB)+1] = '\0' ;
													for(int k = nouvelletailleB ; k > j+1; k--)
													{
														S.bnew[k] = S.bnew[k-1] ;
													}
													S.bnew[j+1] = '-' ;
													(*nouvelletailleB) = (*nouvelletailleB)+1;
													//printf("S.bnew : %s (d2,2)\n",S.bnew);
													m = d2 ;
												}
											}*/
																					
											T[i][j] = m ;
										}
											
										return T[i][j] ;		
									}
											
										
