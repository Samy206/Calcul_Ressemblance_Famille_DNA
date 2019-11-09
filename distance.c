									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "famille.h"
									
									LISTE * initialiser_liste()
									{
										LISTE * l = malloc(sizeof(LISTE*));
										DISTANCE *d = malloc(sizeof(DISTANCE));
										if(l == NULL || d == NULL)
										{
											printf("Pas assez de mémoire pour l ou d \n");
											exit(2);
										}
										l->nombre = 1 ;
										d->val = 0.0 ;
										d->indiced = 0 ;
										d->indiceg = 0 ;
										d->suiv = NULL ;
										l->premier = d ;
									
										return l ;
									}
									
									void liberer_liste(LISTE *l)
									{
										DISTANCE *e = l->premier ;
										while(e != NULL)
										{
											DISTANCE *e = l->premier ;
											DISTANCE *f = e->suiv  ;
											l->premier = f ;
											free(e);
										}
										free(l);
									}
										
									
									int get_indice(char *argv)
									{
										
										int i ;
										char* c;
										char s[2];
										s[0] = argv[13];
										s[1] = argv[14];
										i = strtol(s,&c,10);
										return i ;
									}
									
									
									int liste_vide(LISTE *l)
									{
										if(l->premier == NULL)
										{
											return 0 ;
										}
										else
										{
											return 1 ;
										}
									}
																	
									
									void push_liste(LISTE *l , int val , int a , int b)
									{
										if(l == NULL )
										{
											printf("la liste n'a pas été crée\n");
											exit(6);
										}
										
										if(l->premier->indiced == 0 && l->premier->indiceg == 0)
										{
											l->premier->val = val;
											l->premier->indiceg = a;
											l->premier->indiced = b;
										}
										
										else
										{
											DISTANCE *d = malloc(sizeof(DISTANCE));
											if(d == NULL)
											{
												printf("la distance n'a pas été créée\n");
												exit(7);
											}
											d->val = val;
											d->indiceg = a;
											d->indiced = b;
											d->suiv = l->premier ;
											
											l->premier = d ;
											(l->nombre)++ ;
										}
									}
									
									float pop_liste_place( LISTE *l , int place)
									{
										float valeur ;
										if(l == NULL)
										{
											printf("la liste n'a pas été crée\n");
											exit(7);
										}
										
										DISTANCE *d = l->premier ;
										if(place < l->nombre)
										{
											if(place != 0)
											{
												for(int i = 1 ; i < place ; i++)
												{
													d = d->suiv ;
												}
												
												DISTANCE *e = d->suiv ;
												DISTANCE *f = e->suiv ;
												valeur = e->val ;
												d->suiv = f ;
												free(e);
												(l->nombre)--;
											}
											else 
											{
												DISTANCE *e = d->suiv ;
												l->premier = e ;
												valeur = d->val ;
												free(d);
											}
										}
										else if(place > l->nombre)
										{
											printf("la place est en dehors de la liste\n");
										}
										return valeur ;
									}
											
									void ecrire_fichier_liste_fin(LISTE *l , char * argv)
									{
										FILE *F = fopen(argv,"w");
										if(F == NULL)
										{
											printf("problème d'ouverture de fichier ecriture\n");
											exit(3);
										}
										
										DISTANCE *d = l->premier ;
										fprintf(F,"La liste de distance est [ \n");
										while( d != NULL)
										{
											fprintf(F,"la distance entre les séquences numéro %2d et numéro %2d est est %f\n",d->indiceg,d->indiced,d->val);
											d = d->suiv ;
										}
										fprintf(F,"]\n");
										fprintf(F,"il y a %d éléments.\n",l->nombre);
										fclose(F);	
									}
									
									
									void ajouter_fichier_fin(LISTE *l , char * argv)
									{
										FILE *F = fopen(argv,"a");
										if(F == NULL)
										{
											printf("problème d'ouverture de fichier ecriture\n");
											exit(3);
										}
										
										DISTANCE *d = l->premier ;
										fprintf(F,"La liste de distance est [ \n");
										
										while( d != NULL)
										{
											fprintf(F,"la distance entre les séquences numéro %2d et numéro %2d est est %f\n",d->indiceg,d->indiced,d->val);
											d = d->suiv ;
										}
										fprintf(F,"]\n");
										fprintf(F,"il y a %d éléments.\n",l->nombre);
										fclose(F);	
									}		
									
									
									void afficher_liste(LISTE *l)
									{
										DISTANCE *d ;
										d = l->premier ;
										printf("la liste de distance  est \n");
										printf("[ \n");
										while(d != NULL)
										{
											printf("distance entre les séquences %d et %d : %f \n",d->indiceg,d->indiced,d->val);
											d = d->suiv ;
										}
										printf("]\n");
									}
									
									
									int get_numero_distance(LISTE *l , int indiceg , int indiced)
									{
										DISTANCE *d = l->premier ;
										int cmp = 0;
										while(d != NULL)
										{
											if(d->indiceg == indiceg && d->indiced == indiced)
											{
												printf("distance recherchée : %f\n",d->val);
												return cmp ;
											}
											else
											{
												d = d->suiv ;
												(cmp)++;
											}
										}
										printf("la distance cherchée n'existe pas ou plus dans la liste\n");
										return 0 ;
									}
									
									void supp_numero_seq(LISTE *l , int numero)
									{
										int indice ;
										for(int i = 20 ; i >= 1 ; i--)
										{
											if(i != numero)
											{
												indice = get_numero_distance(l,numero,i);
												printf("indice a supp : %d \n",i);
												pop_liste_place(l,indice);
											}
										}
									}
										
										
									
									
									
								
											
									
										
									
