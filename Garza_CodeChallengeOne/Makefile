INCLUDE_DIRS := ./
CC 		:= g++
CFLAGS 		 := -I$(INCLUDE_DIRS)

make: class_template.cpp customErrorClass.cpp
	$(CC) -g -o Garza_CodeChallengeOne class_template.cpp customErrorClass.cpp $(CFLAGS)

.PHONY: clean all

clean:
	rm Garza_CodeChallengeOne

customErrorClass.o: customErrorClass.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

customErrorHandling.o: customErrorHandling.cpp ${DEPS}
	$(CC) -c -o $@ $(CFLAGS) $<

errorTutorial: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)