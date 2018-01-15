import Ponto as p
import IA as ia #tmp, remover depois 
import sys

class Tabuleiro:

	# Inicializa o tabuleiro preenchendo os espacos com pecas disponiveis para os jogadores
	def __init__(self):
		#iniciado 16x16 para evitar busca fora do arranjo, jogadores nao podem jogar quando x ou y = [0|15]
		self.posicoes = [[p.Ponto(0,[x,y]) for y in range(17)] for x in range(17)] 
		for y in range(0,16):
			for x in range(0,16):
				if(x == 0 or x == 16 or y == 0 or y == 16):
					self.posicoes[x][y] = p.Ponto(3,[x,y]) # Evita Inserir Peca em posicoes fora do tabuleiro
		self.tamanhoSubtabuleiro = []


	# Muda o dono da peca da coordenada informada de espaco disponivel para o dono informado
	def inserirPeca(self,dono, coordenada):
		if(coordenada[0] <= 0 or coordenada[0] >= 16 or coordenada[1] <= 0 or coordenada[1] >= 16):
			print 'JOGADA INCORRETA'
			return None
		if (self.posicoes[coordenada[0]][coordenada[1]].getDono() == 0):
			self.posicoes[coordenada[0]][coordenada[1]].setDono(dono)
		else: 
			print 'NAO EH POSSIVEL INSERIR NESSA POSICAO'
			return None

	# Retorna os espacos disponiveis no tabuleiro para que se possa criar os n estados do miniMax
	def espacosDisponiveisNoTabuleiro(self):
		espacosDisponiveis = []
		for y in range(self.tamanhoSubtabuleiro[0], self.tamanhoSubtabuleiro[2]):
			for x in range(self.tamanhoSubtabuleiro[1],self.tamanhoSubtabuleiro[3]):
				if self.posicoes[x][y].getDono() == 0:
					espacosDisponiveis.append(self.posicoes[x][y])
		return espacosDisponiveis

	# Remover a peca do tabuleiro, apenas seta o dono para Espaco Disponivel(0)
	def removerPeca(self, ponto):
		ponto.setDono(0)
	
	# Pega os vizinhos de uma determinada coordenada
	def getVizinhos(self,coordenada):

		vizinhos = [
		#Horizontal
		[self.posicoes[coordenada[0]-1][coordenada[1]],	 #CE
		self.posicoes[coordenada[0]+1][coordenada[1]]
		],	 #CD
		#Vertical
		[self.posicoes[coordenada[0]][coordenada[1]-1],	 #SC
		self.posicoes[coordenada[0]][coordenada[1]+1]
		],   #IC
		#Diagonal Esquerda
		[self.posicoes[coordenada[0]-1][coordenada[1]-1], #SE
		self.posicoes[coordenada[0]+1][coordenada[1]+1]
		], #ID
		#Diagonal Direita
		[self.posicoes[coordenada[0]+1][coordenada[1]-1], #SD
		self.posicoes[coordenada[0]-1][coordenada[1]+1]  #IE
		]
		] 		
		
		return vizinhos

	# Exibe o tabuleiro
	def displayTabuleiro(self):
		linha = ''
		print '######TABULEIRO ATUAL########'
		for y in range(1,16):
			for x in range(1,16):
				linha += str(self.posicoes[x][y].getDono()) + ' '	
			print linha
			linha = ''

	# Atualiza o subTabuleiro, verifica se a peca jogada esta dentro dele
	# Se sim, mantem seu tamanho. Caso contrario, aumenta o subtabuleiro ate que a peca esteja contida nele.
	# Alterado depois 01/09
	def atualizaSubTabuleiro(self, coordenada):
		if len(self.tamanhoSubtabuleiro) != 0:
			if self.tamanhoSubtabuleiro[0] >= coordenada[0]:
				self.tamanhoSubtabuleiro[0] = max(1, coordenada[0]-1)
			if self.tamanhoSubtabuleiro[1] >= coordenada[1]:
				self.tamanhoSubtabuleiro[1] = max(1,coordenada[1]-1)
			if self.tamanhoSubtabuleiro[2] <= coordenada[0]:
				self.tamanhoSubtabuleiro[2] = min(15, coordenada[0]+1)
			if self.tamanhoSubtabuleiro[3] <= coordenada[1]:
				self.tamanhoSubtabuleiro[3] = min(15, coordenada[1]+1)
		elif len(self.tamanhoSubtabuleiro) == 0:
			self.tamanhoSubtabuleiro = [0,0,0,0]
			self.tamanhoSubtabuleiro[0] = max(1, coordenada[0]-2) 
			self.tamanhoSubtabuleiro[1] = max(1, coordenada[1]-2)
			self.tamanhoSubtabuleiro[2] = min(16,coordenada[0]+6)
			self.tamanhoSubtabuleiro[3] = min(16,coordenada[1]+6)
    
    # Verifica se a jogada foi invalida (fora do tabuleiro ou em um espaco ja ocupado por uma peca)
	def jogadaInvalida(self, coordenada):
		if (self.posicoes[coordenada[0]][coordenada[1]].getDono() != 0  or coordenada[0] <= 0 
			or coordenada[0] >= 16 or coordenada[1] <= 0 or coordenada[1] >= 16):
			return True
		return False