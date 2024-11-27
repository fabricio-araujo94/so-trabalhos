CC = gcc
CFLAGS = -g -Wall -Wextra -Wno-unused-result

ALOCACAO = alocacao
PROMPT = prompt

all: main

$(ALOCACAO).o: $(ALOCACAO).h $(ALOCACAO).c
$(PROMPT).o: $(PROMPT).h $(PROMPT).c

main: $(ALOCACAO).o $(PROMPT).o main.c

clean:
	rm -f *~ *.o $(ALL)
