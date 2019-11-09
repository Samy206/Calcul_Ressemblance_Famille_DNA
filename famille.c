									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									
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
									
									int get_num_freq_max( float distance , char **argv)
									{
										float f = 0 ;
										int cmp = 0 ;
										int max = 0 ;
										int numero ;
										for(int i = 20 ; i >= 1 ; i--)
										{
											SEQUENCE A = initialiser_sequence(argv[i]);
											for(int j = 20 ; j >= 1 ; j--)
											{
												if(i != j)
												{
													SEQUENCE B = initialiser_sequence(argv[j]);
													f=distance_sequence_avec_insertions(&A,&B);
													if(f == distance)
													{
														cmp++;
													}
													liberer_seq(&B);
												}
											}
											liberer_seq(&A);
											if(cmp > max )
											{
												max = cmp ;
												numero = i;
											}
											cmp = 0 ;
										}
										return numero ;
									}
									
									LISTE * creer_liste_initiale(SEQUENCE D[] , char ** argv)
									{
										float d ;
										LISTE *l = initialiser_liste();
										for(int i = 19 ; i >= 0 ; i--)
										{
											for(int j = 19 ; j >= 0 ; j--)
											{
												if( i != j)
												{
													d = distance_sequence_avec_insertions(&D[i],&D[j]);
													push_liste(l,d,get_indice(argv[i])+1,get_indice(argv[j])+1);
												}
											}
										}
										ecrire_fichier_liste_fin(l,argv[21]);
										
										return l ;
									}
									
									int get_num_autre(int *T , int numero , float distance , char **argv)
									{
										float d ;
										int taille = 0 ;
										SEQUENCE A = initialiser_sequence(argv[numero]);
										for(int j = 20 ; j >= 1 ; j--)
										{
											if(numero != j)
											{
												SEQUENCE B = initialiser_sequence(argv[j]);
												d = distance_sequence_avec_insertions(&A,&B);
												if( d == distance )
												{
													taille++;
												}
												liberer_seq(&B);	
											}
										}
										liberer_seq(&A);
										taille = 0 ;
										SEQUENCE C = initialiser_sequence(argv[numero]);
										for(int j = 20 ; j >= 1 ; j--)
										{
											if(numero != j)
											{
												SEQUENCE B = initialiser_sequence(argv[j]);
												d = distance_sequence_avec_insertions(&C,&B);
												if( d == distance )
												{
													T[taille] = j ;
													taille++ ;
												}
												liberer_seq(&B);	
											}
										}
										liberer_seq(&A);
										return taille ;
									}
									

									
