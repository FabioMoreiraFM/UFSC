#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
from automato import Automato
from autDet import AutomatoDeterminizado
from autDetE import AutomatoDeterminizadoEpsilon

entrada = sys.argv[1]

# Abre o arquivo 
f = open(entrada + ".in")
Input = f.read()
tabela = []
exec(Input)

#Inicializa o automato
aut = Automato()

# Adiciona estado inicial, considerando que o primeiro sempre sera inicial
aut.estadoInicial(tabela[1][1])

# Adiciona o conjunto de simbolos sigma
for i in range(1,len(tabela[0])):
	aut.adicionaSimbolo(tabela[0][i])

# Adiciona os estados presentes no automato e adiciona os estados finais
for i in range(1,len(tabela)):
	if tabela[i][0] == "*":
		aut.estadosFinais(tabela[i][1])
	aut.adicionaEstado(tabela[i][1])

#Adiciona a tabela do arquivo ao automato como tabela de transicao de estados
for i in range(1,len(tabela)):
	for j in range(2,len(tabela[i])):
		aut.transicao(tabela[i][1],tabela[i][j],tabela[0][j-1])

# ------ Tabela de transicao Automato Finito Nao-Deterministico -----
resultado = False

if '&' not in aut.getSimbolos(): 
	# ------------- Determinizar sem Epsilon -------------------
	afd = AutomatoDeterminizado(aut)
	afd.transicao(aut.getEstadoInicial())
	afd.atualizaEstadosFinais()
	resultado = True
else:
	# ------------- Determinizar com Epsilon ---------
	afde = AutomatoDeterminizadoEpsilon(aut)
	afde.retornaFecho(aut.getEstadoInicial()[0],[])   # Cria os fechos transitivos
	afde.novoEstadoInicial()
	afde.transicao(afde.EstadoInicial)
	afde.atualizaEstadosFinais()

if resultado:
	result = afd
else:
	result = afde

f.close()
f = open(sys.argv[1] + ".out","w")
texto = []
texto.append("tabela   = [  \"  \"        " + "          ".join(result.getSimbolos()))
texto.append("\n")
chaves = list(result.getTransicao().keys())
chaves.sort()
for x in range(0,len(chaves)):
	excesso = 2
	texto.append("             ")
	if chaves[x] == result.transformaString(result.getEstadoInicial()):
		if result.pertenceEstadoFinal(chaves[x]):
			texto.append("->*" + chaves[x])
			excesso = len(chaves[x]) + 3
		else:
			texto.append("->" + chaves[x])
			excesso = len(chaves[x]) + 2
	elif result.pertenceEstadoFinal(chaves[x]):
		texto.append("*" + chaves[x])
		excesso = len(chaves[x]) + 1
	else:
		texto.append(chaves[x])
		excesso = len(chaves[x])
	texto.append(" "*(12-excesso) + "".join(result.getTransicao()[chaves[x]][result.getSimbolos()[0]]))
	for j in range(1,len(result.getSimbolos())):
		if result.getSimbolos()[j] != "&":
			a = len("".join(result.getTransicao()[chaves[x]][result.getSimbolos()[j-1]]))
			texto.append(" "*(12-a) + "".join(result.getTransicao()[chaves[x]][result.getSimbolos()[j]]))
		else:
			texto.append(" "*(8-len(result.getTransicao()[chaves[x]][result.getSimbolos()[j-1]])) + " - ")
	texto.append('\n')
texto.append("           ]")
f.writelines(texto)
f.close()
