#***********************************************************
# Makefile Genérico para programas pequenos em C/C++       *
# Autor:  Árton Pereira Dorneles                           *
# E-mail: artondorneles@gmail.com                          *
# Alterado em: 15/04/2008                                  *
#                                                          *
# Uso - Este makefile deve ser junto com o código fonte    *
# ou um nível acima. Configure as variáveis que precisar   *
# a seguir PROG_NAME,CC,ARCH,SRC_EXTENSION,SRCS,MODE,      *
#          DEBUG_FLAGS,RELEASE_FLAGS,LDFLAGS,CFLAGS        *
#                                                          *
# Comandos úteis:                                          *
#                                                          *
#  make -> Compila no modo padrão                          *
#  make debug -> Compila usando as DEBUG_FLAGS             *
#  make release -> Compila usando as RELEASE_FLAGS         *
#  make clean -> Limpa os arquivos binários e backups      *
#  make run -> Compila no modo padrão e executa o programa *
#                                                          *
# A extensão do executável gerado será .debug ou .release  *
# Importante:                                              *       
#                                                          *
#  Ao alternar de um modo para o outro utilize make clean  *
#                                                          *
#***********************************************************
 
# Variáveis que voce pode modificar ------------------------

# Nome do programa
PROG_NAME  = bkt

#Parametros do make run
PARAMETERS="SJC10X3.dat"

# Compilador 
CC      = g++

# Arquitetura pretendida
ARCH = k8 

# Extensao dos fontes 
SRC_EXTENSION = cpp

# Nome dos fontes necessários para construir o executável
# O Código abaixo detecta os fontes com a extensão escolhida recursivamente
SRCS    = $(shell find -L . -name \*.$(SRC_EXTENSION))
# Caso queira selecionar manualmente os fontes comente a linha acima e faça algo como a linha abaixo:
# SRCS = main.cpp meuoutroarquivo.cpp subdiretorio1/outroarquivo.cpp 

#Modo default de compilação
#Aceita debug ou release
MODE=release

# Opções do compilador para os modos debug e release
# -g    :ativa debug no binário mas não garante maiores informações
# -ggdb :ativa debug o mais informativo possível
# -std=c99 : permite somente o padrao c99
DEBUG_FLAGS = -ggdb
RELEASE_FLAGS = -O3

#LDFLAGS = -L.
OBJECT_LIBS =  

# -lm     :math por exemplo
LDLIBS  = -lm 
   
# ---------------------------------------------------------------------
# NÃO MODIFIQUE DAQUI PARA BAIXO AO MENOS QUE SAIBA O QUE ESTA FAZENDO!
#
MODE_FLAGS = $(DEBUG_FLAGS)
PROG=$(PROG_NAME).$(MODE)
#CFLAGS  = $(MODE_FLAGS) -Wall -march=$(ARCH) -mtune=$(ARCH)
CFLAGS  = $(MODE_FLAGS) -fopenmp -Wall -lrt -march=$(ARCH) -mtune=$(ARCH) -DIL_STD 


#Isso aqui cria uma lista de objetos a partir da lista de fontes
OBJS = $(SRCS:.$(SRC_EXTENSION)=.o)
#Isso aqui cria uma lista de headers dos fontes
HEADERS = $(SRCS:.$(SRC_EXTENSION)=.h)


all: depend $(PROG)
	@echo "Make concluído em [MODO "`echo $(MODE) | tr a-z A-Z`"]"

run: all
	@./$(PROG)	$(PARAMETERS)

kdbg: all 
	@kdbg ./$(PROG) 

valgrind: all 
	@valgrind --leak-check=full --show-reachable=yes ./$(PROG) $(PARAMETERS)

$(PROG): $(OBJS)
	@echo "Linkando" $(PROG)"..."
	@$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(PROG) $(OBJS) $(OBJECT_LIBS) -m64 -lm -pthread 
	@echo Total de Linhas do programa: `cat $(SRCS) $(HEADERS) -s 2>/dev/null | wc -l`     	

#Isso aki verifica cada fonte do tipo SRC_EXTENSION e gera o seu .o
#Representa todas as dependencias de objetos
.$(SRC_EXTENSION).o:
	@echo "Compilando "$*"..."
	@$(CC) $(CFLAGS) -c $< -o $@     


clean:
#apaga todos os arquivos objetos gerados, programa e backups
	@echo "Removendo binarios..."
	@rm -f $(OBJS) *.o *~ $(PROG_NAME).release $(PROG_NAME).debug
	@echo "Pronto."

debug:
	@make MODE=debug MODE_FLAGS=$(DEBUG_FLAGS)

release: 
	@make MODE=release MODE_FLAGS=$(RELEASE_FLAGS)

depend:
	@makedepend -Y -- $(CFLAGS) -- $(SRCS) 2>/dev/null
	@rm -f makefile.bak Makefile.bak
	@echo "Dependências atualizadas."
	
# DO NOT DELETE

./BackTracking.o: BackTracking.h Estrutura.h
./Estrutura.o: Estrutura.h
./main.o: timeutil.h BackTracking.h Estrutura.h
