/*
   Projeto 3 - Paradigmas de Programação
     Fabio Moreira - 14200727
     João Pedro Bresolin Ortigara - Id
     UFSC - July 2016

   Parte I do trabalho
   Algoritmo de reconhecimento e classificação de imagens ineficiente
   
   Forma 'ineficiente' onde se compara com as imagens na base de dados e aquela com menor distância em relação à nova imagem será candidata a ser
   a classe da nova imagem, se for ok e adiciona na base de dados e 
   se não for compatível pergunta ao usuário qual é a classificação correta e adiciona na base de dados.
   
   Problemas Controlados - (ou seja, esperados de um Algoritmo ineficiente)
   - Lentidão - Cada nova imagem seja ela pertencente a uma classe já presente na base de dados ou não será adicionada, o que resultará em uma
   grande quantidade de imagens para ser calculado a distância, acarretando lentidão.
   - Taxa de erros grande - Dependendo de como a imagem é desenhada mesmos números podem ter números de Hu muito diferentes e como não há um mecanismo
   de otimização a taxa de erros será alta.
*/

:- ['hu.pl','imgs.pl'],initialization(load),initialization(loadTemp).

:- dynamic resultadoTemp/1.

% Adiciona imagem na base de dados
newIm(X,I1,I2,I3,I4,I5,I6,I7) :- assert(img(X,I1,I2,I3,I4,I5,I6,I7)).
commit :- open('imgs.pl',write,Stream),
			   telling(Screen),
			   tell(Stream),
			   listing(img),
			   tell(Screen),
			   close(Stream).

% Exibi imagem e verifica se foi bem classificada - O usuário decide a imagem que ele quer classificar
viewUsuario(Img) :- transformar(Img,Pgm,Xpm),readPGM(Pgm, Mom), writeXPM(Xpm, Mom),viewXPM(Xpm),
				compararBaseDados(Mom,Ok), distanciaMin(N),findClasse(N,Classe),
				(Ok == -1,write('Essa imagem já foi analisada'); Ok \= -1,
					write('Essa imagem é da classe -- '),
						(Ok == 0,write(Ok),nl; Ok == 1, write(Classe),nl),					
				write('Essa imagem foi classificada corretamente?'),
				nl,write('s - sim'),nl, write('n - não'),nl,read(Resposta),verificar(Resposta,Classe,Mom)),!.

verificar(X,Y,M) :- X == 's',write('Foi classificada corretamente'),gravar(Y,M),loadTemp.
verificar(X,_,M) :- X == 'n',write('A qual classe essa imagem pertence?'),nl,read(Y),gravar(Y,M),loadTemp.

% Grava na Base de dados.
gravar(X,M) :- momentum(M, _, I1, I2, I3, I4, I5, I6, I7), newIm(X,I1, I2, I3, I4, I5, I6, I7).

% concantenar número escolhido pelo usuário com .pgm/.xpm
transformar(X,Pgm,Xpm) :- atom_concat('imgs/',X,Z), atom_concat(Z,'.pgm',Pgm),atom_concat(Z,'.xpm',Xpm).

% Usar a fórmula que está no pdf da tarefa : M - nome da imagem, X - -1 já há essa imagem/ 1 há imagens / 0 não há imagens na base de dados
compararBaseDados(M,X) :- momentum(M, _, I1, I2, I3, I4, I5, I6, I7), img(_,I1,I2,I3,I4,I5,I6,I7),X = -1,!.	% Imagem já analisada
compararBaseDados(M,1) :- acharClasse(M).
compararBaseDados(_,X) :- X = 0,!.	% Não há imagens na base de dados

% usa findall pra pegar todas as imagens isso vai criar uma lista e dessa lista nós criamos outra com a classe e a distância entre ela e a nova imagem
acharClasse(M) :- findall([Classe,E1,E2,E3,E4,E5,E6,E7],img(Classe,E1,E2,E3,E4,E5,E6,E7),Z), calcula(M,Z).
calcula(_,[]).
calcula(M,[[X,E1,E2,E3,E4,E5,E6,E7]|Xs]) :- momentum(M, _, I1, I2, I3, I4, I5, I6, I7), soma([I1, I2, I3, I4, I5, I6, I7],[E1,E2,E3,E4,E5,E6,E7],0,N),
										  Somatorio is sqrt(N),guardarResultado(X,Somatorio), calcula(M,Xs).

% Cálculo pra encontrar o valor e comparar com os outros
soma([],[],N1,N) :- N = N1.
soma([X|Xs],[Y|Ys],N1,N) :- N2 is N1+(X-Y)**2, soma(Xs,Ys,N2,N).

% Guarda o resultado do cálculo da distância entre duas imagens (nova e da base de dados) para futura comparação
guardarResultado(X,N) :- assert(resultadoTemp([X,N])).

% Limpa resultadoTemp depois de conhecida a classificação da imagem
loadTemp :- retractall(resultadoTemp(_)).

% Limpa da memória e carrega as imagens da base de dados
load :-
    retractall(img(_,_,_,_,_,_,_,_)),
    open('imgs.pl', read, Stream),
    repeat,
        read(Stream, Data),
        (Data == end_of_file -> true ; assert(Data), fail),
        !,
        close(Stream).

% Menor distância entre as imagens
distanciaMin(N) :- findall(X,resultadoTemp(X),Z),min(Z,N).

% Acha a classe que possui esse número
findClasse(N,X) :- resultadoTemp([X,N]).
findClasse(_,X) :- X = 0.

% Calcular menor distância
min([],99).
min([[X|X1]],X) :- X1=[X|_].
min([[_|X1]|Xs],X) :- X1=[X|_], min(Xs,Y), X =< Y.
min([[_|X1]|Xs],N) :- X1=[X|_], min(Xs,N), N < X.