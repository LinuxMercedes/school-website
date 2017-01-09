CC=g++
CFLAGS=-g
DISASSEMBLER=objdump -CdSM intel
HTML=vim -c :TOhtml -c :wqa

SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:%.cpp=%-${CC})
ASSEMBLIES=$(SOURCES:%.cpp=%-asm)
HTMLS=$(SOURCES:%=%.html)
HTMLS+=$(ASSEMBLIES:%=%.html)

.PHONY: all html clean

all: ${ASSEMBLIES}

html: ${HTMLS}

%-asm: %-${CC}
	${DISASSEMBLER} $< > $@

%-${CC}: %.cpp
	${CC} ${CFLAGS} $< -o $@

%.html: %
	${HTML} $<

clean:
	-@rm -f ${ASSEMBLIES}
	-@rm -f ${HTMLS}