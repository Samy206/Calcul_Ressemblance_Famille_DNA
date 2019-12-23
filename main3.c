									#include <stdio.h>
									#include <stdlib.h>
									#include <unistd.h>
									#include <string.h>
									#include "sequence.h"
									#include "distance.h"
									#include "alignement.h"
									#include "famille.h"
									
									int main(int argc , char ** argv )
									{
										srand(getpid());
										//int alea1 , alea2 ;
										FAMILLE f[6];
										SEQUENCE D[21];
										creer_familles(argv,f,D);
										CHAINES S ;
										S.a = malloc(20);
										
										S.b = malloc(20);
										
										S.anew = malloc(100);
										S.bnew = malloc(100);
										
										float **T = malloc(19*sizeof(float));
										for(int i = 0 ; i < 19 ; i++ )
										{
											T[i] = malloc(19*sizeof(float));
										}
										float d;
										int  nouvelletailleA ;
										int  nouvelletailleB ;
										for(int i = 0 ; i < 1 ; i++)
										{
											remplir_tab(T,19,19);
											//alea1 = (rand()%19)+1 ;
											//alea2 = (rand()%19) +1;
											strcpy(S.a,D[17].s);
											strcpy(S.b,D[5].s);
											strcpy(S.anew,D[17].s);
											strcpy(S.bnew,D[5].s);
											nouvelletailleA = strlen(S.anew)+1 ;
											nouvelletailleB = strlen(S.bnew)+1 ;
											printf("S.a : %s , S.b : %s \n",D[17].s,D[5].s);
											d = distance_rec(S,D[17].taille-1,D[5].taille-1,0.0,&nouvelletailleA,&nouvelletailleB,T);
											printf("anew : %s \nbnew : %s , distance : %f \n",S.anew,S.bnew,d);
										}
										exit(0);
									}
