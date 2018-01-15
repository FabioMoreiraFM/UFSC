class Automato:
	def __init__(self):
		self.Simbolos = []
		self.Estados = []
		self.Transicao = {}
		self.EstadosFinais = []
		self.EstadoInicial = []

	def adicionaSimbolo(self, simbolo):
		if simbolo not in self.Simbolos:
			self.Simbolos.append(simbolo)

	def adicionaEstado(self, estado):
		if estado not in self.Estados:
			self.Estados.append(estado)

	def estadosFinais(self, estado):
		self.EstadosFinais.append(estado)

	def estadoInicial(self,estado):
		self.EstadoInicial.append(estado)

	def transicao(self,estadoAtual, transitaPara, simbolo):
		if estadoAtual in self.Estados:
			if simbolo in self.Simbolos:
				if estadoAtual in self.Transicao:
					if type(transitaPara) is not list:
						self.Transicao[estadoAtual][simbolo] = []
						self.Transicao[estadoAtual][simbolo].append(transitaPara)
					else:
						self.Transicao[estadoAtual][simbolo] = transitaPara
				else :
					self.Transicao[estadoAtual] = {}
					self.Transicao[estadoAtual][simbolo] = []
					if type(transitaPara) is list:
						for x in range(0,len(transitaPara)):
							self.Transicao[estadoAtual][simbolo].append(transitaPara[x])
					else:
						self.Transicao[estadoAtual][simbolo].append(transitaPara)
					
	
	def getSimbolos(self):
		return self.Simbolos

	def getEstados(self):
		return self.Estados

	def getTransicao(self):
		return self.Transicao

	def getEstadosFinais(self):
		return self.EstadosFinais

	def getEstadoInicial(self):
		return self.EstadoInicial
