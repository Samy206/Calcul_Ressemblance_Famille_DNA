run1 : partie1
	./partie1 seq15.txt seq05.txt


partie1 : main1.o sequence.o distance.o 
	gcc -Wall main1.o sequence.o distance.o -o partie1 -g

main1.o : main1.c 
	gcc -Wall -c main1.c -g

sequence.o : sequence.c
	gcc -Wall -c sequence.c -g
	
distance.o : distance.c
	gcc -Wall -c distance.c -g

clean : 
	rm -f *.o
	rm partie1
	ls -l
	
