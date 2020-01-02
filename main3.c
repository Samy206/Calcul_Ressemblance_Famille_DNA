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
										FAMILLE f[6];
										SEQUENCE D[21];
										
										creer_familles(argv,f,D);
										int T[f[3].n];
										for(int i = 0 ; i < f[3].n ; i++){
												T[i] = 0 ;
											}
										char **Sek  = { { 0 } };
										Sek = malloc(f[3].n*sizeof(char*));
										
									
										aligne_famille(Sek,f[3],T);	

										
										for (int i= 0 ; i<f[3].n; i++){
											printf("%s\n" , Sek[i]);
										}

										char *con = creer_seq_consensus (Sek , f[3].n);
										printf("%s\n" , con);

										exit(0);
									}


