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


										SEQUENCE *d ;

										SEQUENCE ***T ;

										T = malloc(19*sizeof(SEQUENCE));
										for(int i = 0 ; i < 19 ; i++ )
										{
											T[i] = malloc(19*sizeof(SEQUENCE));
										}
										remplir_tab(T,19,19);

										d = distance_dyn("ACGT","AGA",3,2,T);

										printf("%f %s %s\n", d->distance, d->a, d->b);
										liberer_seq(d);



										exit(0);
									}
