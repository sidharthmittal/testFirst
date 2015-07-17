SRC += src/testFirst/testcmd.c \
	src/testFirst/testfirst.c

CC := gcc
CXX :=g++
LD := g++
CP :=cp

PROG :=abc

MODULES := \
	$ (wildcard src/ext) src/misc/ext \
	src/testFirst \
	src/base/abc src/base/abci src/base/cmd src/base/io \
	src/base/main src/base/ver src/base/test \
	src/bdd/cudd src/bdd/dsd src/bdd/epd src/bdd/mtr \
	src/bdd/parse \
 
