run : partie3
	mkdir Familles
	./partie3 sequences distance_sequences_a_modif liste_seq_modif 

run2 : partie2
	./partie2 sequences distance_sequences_a_modif liste_seq_modif 

run1 : partie1
	./partie1 sequences 	

partie3 :main3.o sequence.o distance.o famille.o alignement.o
	gcc -Wall -Wextra main3.o sequence.o distance.o famille.o alignement.o -o partie3 -g

partie2 :main2.o sequence.o distance.o famille.o 
	gcc -Wall -Wextra main2.o sequence.o distance.o famille.o -o partie2 -g

partie1 :main1.o sequence.o distance.o
	gcc -Wall -Wextra main1.o sequence.o distance.o -o partie1 -g

main3.o : main3.c
	gcc -Wall -c main3.c -g
	
main2.o : main2.c
	gcc -Wall -c main2.c -g
	
main1.o : main1.c
	gcc -Wall -c main1.c -g
	
alignement.o : alignement.c
	gcc -Wall -c alignement.c -g

famille.o : famille.c
	gcc -Wall -c famille.c -g

sequence.o : sequence.c
	gcc -Wall -c sequence.c -g
	
distance.o : distance.c
	gcc -Wall -c distance.c -g

archive :
	mkdir -p BOUMALI_DJORDJIC
	cp -r sequences/ BOUMALI_DJORDJIC/sequences/
	cp *.c BOUMALI_DJORDJIC
	cp *.h BOUMALI_DJORDJIC
	cp Makefile BOUMALI_DJORDJIC
	tar -cvf BOUMALI_DJORDJIC.tar BOUMALI_DJORDJIC
	rm -rf BOUMALI_DJORDJIC
	
clean : 
	rm -f *.o	
	rm partie3
	rm -rf Familles
	ls 
	
