philosophers: philosophers.o philosopherFunctions.o chopstickFunctions.o utility.o
	gcc -o philosophers *.o -lpthread

philosophers.o: tableStuff.h

chopstickFunctions.o: tableStuff.h

philosopherFunctions.o: tableStuff.h
	
clean:
	rm philosophers *.o
	
	#bb: bb-harness.o bb-sync.o bb-cs.o consumer.o producer.o utility.o
#	gcc -o bb *.o -lpthread
#
#bb-harness.o: bb-sync.h

#bb-cs.o: bb-cs.h buffer.h

#bb-sync.o: bb-sync.h buffer.h

#consumer.o: bb-cs.h bb-sync.h buffer.h utility.h

#producer.o: bb-cs.h bb-sync.h buffer.h utility.h

#utility.o: utility.h
