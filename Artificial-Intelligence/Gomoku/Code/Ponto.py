# Classe Ponto: 
# Eh qualquer peca do tabuleiro

class Ponto:
	def __init__(self, dono, coordenada):
		self.dono = dono 					# dono (Computador (2), Jogador(1) ou EspacoDisponivel(0))
		self.coordenada = coordenada 		# coordenada - posicao no tabuleiro
		self.visitado = False 				# util para algoritmos de busca de encadeamentos
		
	def getVisitado(self):
		return self.visitado

	def getDono(self):
		return self.dono

	def getCoordenada(self):
		return self.coordenada

	def setVisitado(self, visitado):
		self.visitado = visitado

	def setDono(self, dono):
		self.dono = dono