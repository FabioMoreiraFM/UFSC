class AutomatoDeterminizadoEpsilon:
	def __init__(self,aut):
		self.Simbolos = aut.getSimbolos()
		self.VEstados = aut.getEstados()
		self.Estados = []
		self.Transicao = {}
		self.Fecho = {}
		self.VTransicao = aut.getTransicao()
		self.EstadosFinais = aut.getEstadosFinais()
		self.VEstadoInicial = aut.getEstadoInicial()
		self.EstadoInicial = ""
		self.Fecho['q-'] = ['q-']

	def adicionaEstado(self, estado):
		estado.sort()
		self.Estados.append(estado)

	def estadosFinais(self):
		return self.EstadosFinais

	def atualizaEstadosFinais(self):
		estFinal = self.EstadosFinais[0]
		self.EstadosFinais.remove(self.EstadosFinais[0]) # VERIFICAR SE CONTINUA CORRETO
		for x in range(0,len(self.Estados)):
			if estFinal in self.Estados[x] and self.Estados[x] not in self.EstadosFinais:
				self.EstadosFinais.append(self.Estados[x])

	def getSimbolos(self):
		return self.Simbolos

	def getTransicao(self):
		return self.Transicao

	def getEstadosFinais(self):
		return self.EstadosFinais

	def getEstadoInicial(self):
		return self.EstadoInicial

	def getFecho(self):
		return self.Fecho

	def novoEstadoInicial(self):
		self.EstadoInicial = self.Fecho[self.VEstadoInicial[0]]

	def transicaoEstado(self,estado,simbolo):
		return self.VTransicao[estado][simbolo]

	def adicionaTransicao(self,estado,simbolo,transitaPara):
		transitaPara.sort()
		if estado not in self.Transicao:
			self.Transicao[estado] = {}
		self.Transicao[estado][simbolo] = transitaPara

	def retornaFecho(self,estado,jaVisitados):
		novaLista = []
		if estado not in jaVisitados:
			jaVisitados.append(estado)
			novaLista.append(estado)
			tmp = self.transicaoEstado(estado,'&')
			novaLista.append(tmp)
			for x in range(0,len(tmp)):
				novaLista.append(self.retornaFecho(tmp[x], jaVisitados))
			novaLista = self.tiraArgumentos(novaLista)
			if 'q-' in novaLista:
				novaLista.remove('q-')
			self.Fecho[estado] = list(set(novaLista))
			return novaLista
		return []

	def transicao(self,estado):
		estado.sort()
		if estado not in self.Estados:
			self.adicionaEstado(estado)
			for x in range(0,len(self.Simbolos)-1):
				novaLista = []
				for j in range(0,len(estado)):
					if 'q-' not in self.transicaoEstado(estado[j],self.Simbolos[x]):
						novaLista.append(self.transicaoEstado(estado[j],self.Simbolos[x]))
						novaLista.append(self.Fecho[estado[j]])
				novaLista = self.tiraArgumentos(novaLista)
				novaLista= list(set(novaLista))
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

	def pertenceEstadoFinal(self,estado):
		for x in range(0,len(self.EstadosFinais)):
			if estado == self.transformaString(self.EstadosFinais[x]):
				return True
		return False
