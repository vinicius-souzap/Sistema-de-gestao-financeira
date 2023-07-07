CC=g++
CFLAGS=-std=c++17 -Wall
TARGET=program

DIR_BUILD = ./build
DIR_SRC = ./src
DIR_INCLUDE = ./include


${DIR_BUILD}/${TARGET}: ${DIR_BUILD}/Proposta.o ${DIR_BUILD}/OrdemServico.o ${DIR_BUILD}/Funcionario.o ${DIR_BUILD}/Orcamentista.o ${DIR_BUILD}/Engenheiro.o ${DIR_BUILD}/Contador.o ${DIR_BUILD}/main.o 
	${CC} ${CFLAGS} ${DIR_BUILD}/*.o -o $/${TARGET}

${DIR_BUILD}/Proposta.o: ${DIR_INCLUDE}/Proposta.hpp ${DIR_SRC}/entidades/Proposta.cpp 
	${CC} ${CFLAGS} -I ${DIR_INCLUDE}/ -c ${DIR_SRC}/entidades/Proposta.cpp -o ${DIR_BUILD}/Proposta.o

${DIR_BUILD}/OrdemServico.o: ${DIR_INCLUDE}/OrdemServico.hpp ${DIR_SRC}/entidades/OrdemServico.cpp 
	${CC} ${CFLAGS} -I ${DIR_INCLUDE}/ -c ${DIR_SRC}/entidades/OrdemServico.cpp -o ${DIR_BUILD}/OrdemServico.o

${DIR_BUILD}/Funcionario.o: ${DIR_INCLUDE}/Funcionario.hpp ${DIR_SRC}/entidades/Funcionario.cpp 
	${CC} ${CFLAGS} -I ${DIR_INCLUDE}/ -c ${DIR_SRC}/entidades/Funcionario.cpp -o ${DIR_BUILD}/Funcionario.o

${DIR_BUILD}/Orcamentista.o: ${DIR_INCLUDE}/Orcamentista.hpp ${DIR_SRC}/entidades/Orcamentista.cpp 
	${CC} ${CFLAGS} -I ${DIR_INCLUDE}/ -c ${DIR_SRC}/entidades/Orcamentista.cpp -o ${DIR_BUILD}/Orcamentista.o

${DIR_BUILD}/Engenheiro.o: ${DIR_INCLUDE}/Engenheiro.hpp ${DIR_SRC}/entidades/Engenheiro.cpp 
	${CC} ${CFLAGS} -I ${DIR_INCLUDE}/ -c ${DIR_SRC}/entidades/Engenheiro.cpp -o ${DIR_BUILD}/Engenheiro.o

${DIR_BUILD}/Contador.o: ${DIR_INCLUDE}/Contador.hpp ${DIR_SRC}/entidades/Contador.cpp 
	${CC} ${CFLAGS} -I ${DIR_INCLUDE}/ -c ${DIR_SRC}/entidades/Contador.cpp -o ${DIR_BUILD}/Contador.o

${DIR_BUILD}/main.o: ${DIR_INCLUDE}/Proposta.hpp ${DIR_INCLUDE}/OrdemServico.hpp ${DIR_INCLUDE}/Funcionario.hpp ${DIR_INCLUDE}/Orcamentista.hpp ${DIR_INCLUDE}/Engenheiro.hpp ${DIR_INCLUDE}/Contador.hpp ${DIR_SRC}/main.cpp 
	${CC} ${CFLAGS} -I ${DIR_INCLUDE}/ -c ${DIR_SRC}/main.cpp -o ${DIR_BUILD}/main.o

# Rule for execute program.
# Call 'make run' to use it

run:
	./${TARGET}

# Rule for cleaning files generated during compilation.
# Call 'make clean' to use it

clean:
	rm -f ${DIR_BUILD}/*