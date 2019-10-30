							#include <unistd.h>
							#include <stdio.h>
							#include <stdlib.h>
							#include "sequence.h"
							#include "distance.h"
							
							int main( int argc , char **argv)
							{
								SEQUENCE *A = initialiser_sequence(argv[1]);
								SEQUENCE *B = initialiser_sequence(argv[2]);
								
								LISTE *l = initialiser_liste();
								
								push_liste(l,A,B,argv[1],argv[2]); 
								//afficher_liste(l);
								
								exit(0);
							}
