class IA:
	def __init__(self, tabuleiro):
		self.pecaEscolhida = None								    # Melhor Jogada
		self.verificar = [[0],[0,0,0,0,0,0],[0,0,0,0,0,0]] 			# Lista com os encadeamentos atualizados do jogo
		self.verificarMiniMax = [[0],[0,0,0,0,0,0],[0,0,0,0,0,0]]	# Lista com os encadeamentos de um certo estado do miniMax
		self.historicoMiniMax = []									# Lista que armazena varios verificarMiniMax
		self.tabuleiro = tabuleiro 									# Referencia para o tabuleiro do jogo
		self.COMPUTADOR = 1 										# Jogador computador
		self.JOGADOR = 2											# Jogador humano

	# Algoritmo MiniMax com podas alpha e beta
	def miniMax(self, profundidade, alpha, beta, minmax, p):
		# Atualiza os encadeamentos
		if minmax:
			self.hu(p, self.JOGADOR,0)
		else:
			self.hu(p, self.COMPUTADOR,0)

		# Se a profundidade eh zero, significa nodo folha, logo calcula a heuristica/utilidade
		if profundidade[0] == 0:
			points =  self.heuristica(p)
			# Adicionado 01/09
			if points > alpha:
				self.pecaEscolhida = p
			#print "Pontuacao para: " + str(p.getCoordenada()) + " = " + str(points)
			return points

		# Cada peca disponivel do tabuleiro se tornara um filho do ponto p (parametro) e, consequentemente, um estado do miniMax
		for i in self.tabuleiro.espacosDisponiveisNoTabuleiro():
			if minmax: 
				# Insere peca
				self.tabuleiro.inserirPeca(1, i.getCoordenada()) 
				i.setDono(self.COMPUTADOR) 
				
				# Verifica se o valor da profundidade imediatamente posterior eh maior que a atual, se for adiciona
				# a peca que trouxe esse valor como filho
				tmpalpha = self.miniMax([profundidade[0]-1], alpha, beta, False, i)
				alpha = max(alpha, tmpalpha)
				
				# Removido depois 01/09
				#if (alpha == tmpalpha and i.getDono() == 1 and profundidade == 1):
				#	self.pecaEscolhida = i

				# Remove uma lista do historico e uma peca do tabuleiro (Como nao eh feito uma copia do tabuleiro, eh necessario
				# garantir sua integridade)
				self.atualizaHistorico()
				self.tabuleiro.removerPeca(i)
				if alpha >= beta:
					break # Poda
			else:
				# Insere peca
				self.tabuleiro.inserirPeca(2, i.getCoordenada()) 
				i.setDono(self.JOGADOR)
				
				# Verifica se o valor da profundidade imediatamente posterior eh maior que a atual, se for adiciona
				# a peca que trouxe esse valor como filho
				tmpbeta = self.miniMax([profundidade[0]-1], alpha, beta, True, i)
				beta = min(beta, tmpbeta)
				
				# Removido depois 01/09
				#if (beta == tmpbeta and i.getDono() == 1 and profundidade == 1):
				#	self.pecaEscolhida = i
				
				# Remove uma lista do historico e uma peca do tabuleiro (Como nao eh feito uma copia do tabuleiro, eh necessario
				# garantir sua integridade)
				self.atualizaHistorico()
				self.tabuleiro.removerPeca(i)
				if alpha >= beta:
					break # Poda		
		if minmax:
			return alpha
		else:
			return beta 
			
	# Atualiza os encadeamentos. 
	# Operacao = 1: atualiza os encadeamentos do jogo
	# Operacao = 2: atualiza os encadeamentos de um certo estado do MiniMax
	def hu(self, ultimoPontoInserido, jogador, operacao):
		if (operacao):
			self.BuscaPontual(ultimoPontoInserido,self.verificar[jogador])
		else:
			self.BuscaPontual(ultimoPontoInserido,self.verificarMiniMax[jogador])
			tmp = [self.verificarMiniMax[0][:],self.verificarMiniMax[1][:],self.verificarMiniMax[2][:]]
			self.historicoMiniMax.append(tmp)

	def heuristica(self, ponto):
		somatorioComputador = 0
		somatorioJogador = 0
		tebC = 1
		tebJ = 1

		# TEB PC
		if(ponto.getDono() == 1):
			tebC += self.fatorTEB(ponto, 2)/1.5

		# TEB JOGADOR
		if(ponto.getDono() == 2):
			tebJ += self.fatorTEB(ponto, 1)

		# Somatorio Computador
		for i in range(0, len(self.verificarMiniMax[1])):
			somatorioComputador += (i**4)*self.verificarMiniMax[1][i]

		# Somatorio Jogador
		for i in range(0, len(self.verificarMiniMax[2])):
			somatorioJogador += (i**4)*self.verificarMiniMax[2][i]

		return somatorioComputador*tebC*4 - somatorioJogador*tebJ

	# Fator de bloqueio de jogada, retorna quantos pontos o ponto informado conseguiu bloquear
	# Ex. Encadeamento de tamanhos 3 e 1, logo a peca bloqueou 4 pontos 
	def fatorTEB(self,ponto, operacao):
		ponto.setVisitado(True)
		x = 0
		vizinhos = self.getFiltro(ponto, operacao)
		if (len(vizinhos) == 0):
			return 1
		for i in range(0,len(vizinhos)):
			for j in range(0,len(vizinhos[i])):
				if (not vizinhos[i][j].getVisitado()):
					x += self.recursaoTEB(vizinhos[i][j], i)
		ponto.setVisitado(False)			
		return x

	# Equivalente ao cadeiaDirecao(), busca os vizinhos de um ponto em determinada direcao
	def recursaoTEB(self, ponto, direcao):
		ponto.setVisitado(True)
		vizinhos = self.getFiltro(ponto, 1)
		if(len(vizinhos[direcao]) == 0):
			ponto.setVisitado(False)
			return 0
		if(len(vizinhos[direcao]) >= 1):
			for x in range(0,len(vizinhos[direcao])):
				if(not vizinhos[direcao][x].getVisitado()):
					tmp = self.recursaoTEB(vizinhos[direcao][x], direcao)
					ponto.setVisitado(False)
					return (1 + tmp)
		ponto.setVisitado(False)
		return 1

	# Faz o filtro dos vizinhos de um certo ponto retornando apenas os vizinhos que sao do mesmo dono que esse ponto
	def getFiltro(self, ponto, operacao):
		vizinhos = self.tabuleiro.getVizinhos(ponto.getCoordenada())
		if(operacao == ponto.getDono()):
			operacao = ponto.getDono()
		else:
			operacao = 2
		for i in range(0, len(vizinhos)):
			if (vizinhos[i][0].getDono() != operacao):
				del vizinhos[i][0]
				if (vizinhos[i][0].getDono() != operacao):
					del vizinhos[i][0]
			else:
				if (vizinhos[i][1].getDono() != operacao):
					del vizinhos[i][1]
		return vizinhos

	# Faz a atualizacao da lista de encadeamentos
	# Dado um certo ponto, ele verifica se esse ponto quando inserido aumenta algum encadeamento
	# presente no jogo.
	def BuscaPontual(self,ponto,sequencia):
		ponto.setVisitado(True)
		vizinhos = self.getFiltro(ponto, 1)
		soma = [1]
		temp = 0
		for i in range(0, len(vizinhos)): # V, H ou DP ou DS -> 0, 1, 2 ou 3
			for j in range(0, len(vizinhos[i])):
				if (not vizinhos[i][j].getVisitado()):
					temp = self.cadeiaDirecao(vizinhos[i][j], i)
					sequencia[temp] -= 1
					if sequencia[temp] < 0:
						sequencia[temp] = 0
					soma[0] += temp
			if (soma[0] != 1 and soma[0] <=5):
				sequencia[soma[0]] += 1
			if (soma[0] != 1 and soma[0] >5):
				sequencia[5] += 1	
			soma[0] = 1
		
		if(len(vizinhos[0])==0 and len(vizinhos[1])==0 and len(vizinhos[2])==0 and len(vizinhos[3])==0):
			sequencia[1] += 1 
		ponto.setVisitado(False) 
	
	# Dado um certo ponto, retorna a quantidade de elementos que ele possui nas Verticais (Esquerda ou Direita), Horizontais
	# e/ou Diagonais
	def cadeiaDirecao(self, ponto, direcao):
		ponto.setVisitado(True)
		vizinhos = self.getFiltro(ponto, 1)
		soma = [1]
		if(len(vizinhos[direcao]) == 1):
			ponto.setVisitado(False)
			return soma[0]
		if(len(vizinhos[direcao]) > 1): 
			for x in range(0,len(vizinhos[direcao])):
				if(not vizinhos[direcao][x].getVisitado()):
					tmp = self.cadeiaDirecao(vizinhos[direcao][x], direcao)
					ponto.setVisitado(False)
					return soma[0] + tmp	
		if(len(vizinhos[direcao]) == 0):
			ponto.setVisitado(False)
			return 0	

	# Retorna a melhor jogada
	def melhorJogada(self):
		return self.pecaEscolhida

	# atualizaVerificacaoMiniMax()
	# Copia da lista que mantem o controle dos encadeamentos do jogo.
	# Utilizado no miniMax para manter o controle dos encadeamentos dos estados.
	def atualizaVerificacaoMiniMax(self):
		self.verificarMiniMax[0] = self.verificar[0][:]
		self.verificarMiniMax[1] = self.verificar[1][:]
		self.verificarMiniMax[2] = self.verificar[2][:]

	# atualizaHistorico() 
	# Atualiza historico de encadeamentos
	# Eh necessario para que, no miniMax, ao encontrar um nodo folha e retornar, a configuracao dos encadeamentos anteriores
	# nao esteja corrompido, tamanhoMax = profundidade
	def atualizaHistorico(self):
		self.historicoMiniMax.pop()
		self.verificarMiniMax[0] = self.historicoMiniMax[-1:][0][0][:]
		self.verificarMiniMax[1] = self.historicoMiniMax[-1:][0][1][:]
		self.verificarMiniMax[2] = self.historicoMiniMax[-1:][0][2][:]
	
	def fimDeJogo(self):
		if(self.verificar[2][5] == 1):
			return 2
		elif(self.verificar[1][5] == 1):
			return 1
		return 0		