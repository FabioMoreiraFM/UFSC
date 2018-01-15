import Tabuleiro as tabule
import IA as ia
import sys
import os,subprocess

class Controlador:
	def __init__(self):
		self.tabule = tabule.Tabuleiro() # Tabuleiro
		self.ia = ia.IA(self.tabule) # IA para executar o MiniMax
		self.iniciarJogo()

	# Limpa a tela
	def clear(self):
	    if os.name in ('nt','dos'):
	        subprocess.call("cls")
	    elif os.name in ('linux','osx','posix'):
	        subprocess.call("clear")
	    else:
	        print "\n"*120

	def iniciarJogo(self):
		jogada = [0, 0] # Var que armazena a posicao onde o jogador humano deseja jogar
		self.clear()
		print 'Bem Vindo ao Gomoku. \n Escolha quem comecara o jogo.'
		print '1 - Jogador 2 - Computador.'

		turno = int(input())
		self.clear()
		
		if (turno == 2): 								# Caso o jogador inicie
			self.tabule.inserirPeca(1, [2,2])			# Insere a peca
			self.ia.hu(self.tabule.posicoes[2][2],1,1)	# Atualiza lista de encadeamentos
			self.tabule.atualizaSubTabuleiro([2,2])		# Atualiza tamanho do subtabuleiro
			self.tabule.displayTabuleiro()				# Exibe o tabuleiro
			turno = 1 									# Vez do computador
		
		
		# Continua ate o termino do jogo
		while(self.ia.fimDeJogo() == 0):	

			if(turno == 1):
				print 'Insira as coordenadas da sua jogada'
				print 'No formato x y'

				# Entrada da coordenada informada pelo jogador, Formato: X Y
				jogada = [int(y) for y in raw_input().split()]

				# Limpa a tela
				self.clear()

				# Verifica se a jogada eh valida
				while(self.tabule.jogadaInvalida(jogada)):		
					self.tabule.displayTabuleiro()			
					print 'Jogada Invalida. \n Jogue Novamente:'
					jogada = [int(y) for y in raw_input().split()]

				# Insere peca, atualiza subTabuleiro e troca a vez para o computador
				self.tabule.inserirPeca(2, jogada)
				self.tabule.atualizaSubTabuleiro(jogada)
				turno = 2	
			elif self.ia.fimDeJogo() == 0:
				print 'Vez do computador'

				# Atualiza lista de encadeamentos do MiniMax, verificar documentacao do metodo
				self.ia.atualizaVerificacaoMiniMax()	
				
				# Executa MiniMax
				self.ia.miniMax([3], -sys.maxsize, sys.maxsize, True, self.tabule.posicoes[jogada[0]][jogada[1]]) 
				
				# Insere a melhor jogada encontrada
				self.tabule.inserirPeca(1, self.ia.melhorJogada().getCoordenada())
				# Atualiza a lista de encadeamentos do jogador e computador, ele atualiza a ultima jogada adversaria aqui para nao conflitar com o ia.hu do minimax
				self.ia.hu(self.tabule.posicoes[jogada[0]][jogada[1]],2,1)
				self.ia.hu(self.ia.melhorJogada(), 1, 1)
				
				# Atualiza subTabuleiro e exibe o tabuleiro atualizado
				self.tabule.atualizaSubTabuleiro(jogada)
				self.tabule.displayTabuleiro()
				
				# Vez do Jogador Humano
				turno = 1
				
				# Exibe o controle dos encadeamentos, para a avaliacao do professor. Demonstrando que o controle dos encadeamentos eh
				# feito corretamente
				print self.ia.verificar

		# Fim de Jogo
		if(self.ia.fimDeJogo() == 1):
			print 'Voce Perdeu'
		else:
			print 'Voce Ganhou'

control = Controlador()