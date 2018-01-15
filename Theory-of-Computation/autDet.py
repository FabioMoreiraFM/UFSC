# -*- coding: utf-8 -*-
class AutomatoDeterminizado:
	def __init__(self,aut):
		self.Simbolos = aut.getSimbolos()
		self.Estados = []
		self.Transicao = {}
		self.VTransicao = aut.getTransicao()
		self.EstadosFinais = aut.getEstadosFinais()
		self.EstadoInicial = aut.getEstadoInicial()

	def adicionaEstado(self, estado):
		if type(estado) is list:
			estado.sort()
		if estado not in self.Estados:
			self.Estados.append(estado)

	def estadosFinais(self):
		return self.EstadosFinais

	def getSimbolos(self):
		return self.Simbolos
	
	def atualizaEstadosFinais(self):
		estFinal = self.EstadosFinais[0]
		self.EstadosFinais.remove(self.EstadosFinais[0]) # VERIFICAR SE CONTINUA CORRETO
		for x in range(0,len(self.Estados)):
			if estFinal in self.Estados[x] and self.Estados[x] not in self.EstadosFinais:
				self.EstadosFinais.append(self.Estados[x])

	def getTransicao(self):
		return self.Transicao

	def getCompara(self,estado):
		estado.sort()
		if estado not in self.Estados:
			return True
		else:
			return False

	def transicaoEstado(self,estado,simbolo):
		return self.VTransicao[estado][simbolo]

	def adicionaTransicao(self,estado,simbolo,transitaPara):
		if estado not in self.Transicao:
			self.Transicao[estado] = {}
		self.Transicao[estado][simbolo] = transitaPara

	def transicao(self,estado):
		if len(estado) == 1:
			if estado[0] not in self.Estados:
				self.adicionaEstado(estado[0])
				self.Transicao[estado[0]] = self.VTransicao[estado[0]]
				for x in range(0, len(self.Simbolos)):
					# if 'q-' not in self.Transicao[estado[0]][self.Simbolos[x]]:	NÃO PRECISA, TESTAR DEPOIS PARA TER CERTEZA
						self.transicao(self.Transicao[estado[0]][self.Simbolos[x]])
		else:
			if self.getCompara(estado):
				self.adicionaEstado(estado)
				for x in range(0,len(self.Simbolos)):
					novaLista = []
					for j in range(0,len(estado)):
						if 'q-' not in self.transicaoEstado(estado[j],self.Simbolos[x]):
							novaLista.append(self.transicaoEstado(estado[j],self.Simbolos[x]))
					novaLista = self.tiraArgumentos(novaLista)
					novaLista = list(set(novaLista))
					if len(novaLista) > 1 and 'q-' in novaLista :
						novaLista.remove('q-')
					tmp = self.transformaString(estado)
					self.adicionaTransicao(tmp,self.Simbolos[x],novaLista)
					self.transicao(novaLista)

	def tiraArgumentos(self,estado):
		novaLista = []
		for x in range(0,len(estado)):
			if estado[x] == 1 or type(estado[x]) is str:
				novaLista.append(estado[x])
			else:
				for j in range(0,len(estado[x])):
					novaLista.append(estado[x][j])
		return novaLista

	def transformaString(self,estado):
		string = ''
		for x in range(0,len(estado)):
			string += estado[x]
		return string

	def getEstadosFinais(self):
		return self.EstadosFinais
	
	def getEstadoInicial(self):
		return self.EstadoInicial

	def pertenceEstadoFinal(self,estado):
		for x in range(0,len(self.EstadosFinais)):
			if estado == self.transformaString(self.EstadosFinais[x]):
				return True
		return False
