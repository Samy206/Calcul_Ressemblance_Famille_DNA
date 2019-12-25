									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "famille.h"
									
									
									FAMILLE creer_famille_initiale(int nb)
									{
										FAMILLE f ;
										f.table = malloc(nb*sizeof(SEQUENCE));
										f.n = nb ;
										return f ;
									}
									
									
									void remplir_famille(FAMILLE f , int T[] ,SEQUENCE D[])
									{
										for(int i = 0 ; i < f.n ; i++)
										{
											f.table[i] = D[T[i]];
										}
									}
									
									void ecrire_fich_fam(FAMILLE f  , int T[] , char *argv)
									{
										FILE *F = fopen(argv,"w");
									
										fprintf(F,"La famille est [\n");
										for(int i = 0 ; i < f.n ; i++)
										{
											fprintf(F,"la sequence %2d est : %s \n",T[i],f.table[i].s);
										}
										fprintf(F,"]\n");
										fprintf(F,"il y a %d sequences.\n\n",f.n);
										
										fclose(F);	
									}
									
									float recherche_distance_min(LISTE *l)
									{
										DISTANCE *d = l->premier ;
										float min = l->premier->val ;
										while(d != NULL)
										{
											if(min > d->val)
											{
												min = d->val;
											}
											d = d->suiv ;
										}
										return min ;
									}
									
									int get_num_freq_max( float distance , LISTE *l)
									{
										int max , cmp , numero ;
										max = 0 ;
										DISTANCE *e ; 
										for(int i  = 1 ; i < 21 ; i++)
										{
											e = l->premier ;
											cmp = 0 ;
											while(e != NULL)
											{
												if(e->val == distance && e->indiceg == i )
												{
													cmp++;
												}
												e = e->suiv ;
											}
											if(cmp >= max )
											{
												max = cmp ;
												numero = i ;
											}
										}
										return numero ;
									}
										
									
									LISTE * creer_liste_initiale(SEQUENCE D[] , char ** argv)
									{
										float d ;
										float **T ;
										LISTE *l = initialiser_liste();
										T = malloc(19*sizeof(float));
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
										ecrire_fichier_liste_fin(l,argv[21]);
										ecrire_fichier_liste_fin(l,argv[22]);
										free(T);
										return l;
									}
									
									
									
									
									int get_num_autre(int *T , float distance , int numero , LISTE *l)
									{
										DISTANCE *e = l->premier ;
										int  i = 1 ;
										while(e != NULL)
										{
											if(e->val == distance && e->indiceg == numero)
											{
												T[i] = e->indiced ;
												i++;
											}
											e = e->suiv ;
										}			
										return i ;
									}
										
									

									
