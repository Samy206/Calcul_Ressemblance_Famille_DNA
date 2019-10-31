									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									
									LISTE * initialiser_liste()
									{
										LISTE * l = malloc(sizeof(LISTE*));
										DISTANCE *d = malloc(sizeof(DISTANCE*));
										if(l == NULL || d == NULL)
										{
											printf("Pas assez de mémoire pour l ou d \n");
											exit(2);
										}
										l->nombre = 1 ;
										printf("before premier %p\n", l);
										d->val = 0.0 ;
										d->indiced = 0 ;
										d->indiceg = 0 ;
										d->suiv = NULL ;
										l->premier = d ;
										
										printf("la liste est créee %p\n",l);
										return l ;
									}
									
									int get_indice(char *argv)
									{
										
										int i ;
										char* c;
										char s[2];
										s[0] = argv[3];
										s[1] = argv[4];
										i = strtol(s,&c,0);
										return i ;
									}
									
									void push_liste(LISTE *l , float distance , int a , int b)
									{
										if(l == NULL )
										{
											printf("la liste n'a pas été crée\n");
											exit(6);
										}
										
										if(l->premier->indiced == 0 && l->premier->indiceg == 0)
										{
											l->premier->val = distance ;
											l->premier->indiceg = a;
											l->premier->indiced = b;
										}
										
										else
										{
											DISTANCE *d = malloc(sizeof(DISTANCE*));
											if(d == NULL)
											{
												printf("la distance n'a pas été créée\n");
												exit(7);
											}
											d->val = distance ;
											d->indiced = b;
											d->indiceg = a;
											d->suiv = l->premier ;
											l->premier = d ;
											(l->nombre)++ ;
										}
									}
									
									void afficher_liste(LISTE *l)
									{
										DISTANCE *d ;
										d = l->premier ;
										printf("la liste de distance  est [\n");
										while(d != NULL)
										{
											printf("distance entre les séquences %d et %d : %f \n",d->indiceg,d->indiced,d->val);
											d = d->suiv ;
										}
										printf("]\n");
									}
										
									
									
									
								
											
									
										
									
