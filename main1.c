							#include <unistd.h>
							#include <stdio.h>
							#include <stdlib.h>
							#include "sequence.h"
							#include "distance.h"
							
							int main(int argc , char **argv)
							{
								LISTE *l = initialiser_liste();
								for(int i = 1 ; i <= 20 ; i++)
								{
									SEQUENCE *A = initialiser_sequence(argv[i]);
									for(int j = 1 ; j <= 20 ; j++)
									{
										if(i != j)
										{
											SEQUENCE *B = initialiser_sequence(argv[j]);
											printf("seq%d : %s\n",get_indice(argv[i]),A->s);
											printf("seq%d : %s\n",get_indice(argv[j]),B->s);
											push_liste(l,distance_sequence_avec_insertions(A,B),get_indice(argv[i]),get_indice(argv[j]));
											afficher_liste(l);
											liberer_seq(B);
										}
										else 
											;
									}
									liberer_seq(A);
								}
								
								exit(0);
							}
