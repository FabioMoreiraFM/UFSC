/*
   Projeto 3 - Paradigmas de Programação
     Fabio Moreira
     João Pedro Bresolin Ortigara
     UFSC - July 2016

   Parte II do trabalho
   Algoritmo de reconhecimento e classificação de imagens eficiente
   
   Forma Eficiente
   Otimizada - Faz a média dos momentos de Hu de números com a mesma classificação.
   Rápida - Não adiciona na base de dados (a menos que ainda não esteja nela), mas faz uma média com os momentos de Hu da nova imagem
   e o valores que já estão presentes na base de dados.
*/

:- ['hu.pl','imgs.pl'],initialization(load),initialization(loadTemp).

% resultadoTemp é a distância entre a nova imagem em relação às presentes na base de dados 
:- dynamic resultadoTemp/1.

% Cria nova classificação
newIm(X,I1,I2,I3,I4,I5,I6,I7) :- assert(img(X,I1,I2,I3,I4,I5,I6,I7)).

% Adiciona imagem na base de dados
commit :- open('imgs.pl',write,Stream),
			   telling(Screen),
			   tell(Stream),
			   listing(img),
			   tell(Screen),
			   close(Stream).

% Exibi imagem e verifica se foi bem classificada, Ok = 0 não há imagens na base de dados. 
viewUsuario(Img) :- transformar(Img,Pgm,Xpm),readPGM(Pgm, Mom), writeXPM(Xpm, Mom),viewXPM(Xpm),
				compararBaseDados(Mom,Ok), distanciaMin(N),findClasse(N,Classe),
				write('Essa imagem é da classe -- '),
						(Ok == 0,write(Ok),nl; Ok == 1, write(Classe),nl),					
				write('Essa imagem foi classificada corretamente?'),
				nl,write('s - sim'),nl, write('n - não'),nl,read(Resposta),verificar(Resposta,Classe,Mom),!.

verificar(X,Y,M) :- X == 's',write('Foi classificada corretamente'),
                            (img(Y,_,_,_,_,_,_,_), gravarMedia(Y,M); \+img(Y,_,_,_,_,_,_,_), gravar(Y,M)),loadTemp.
verificar(X,_,M) :- X == 'n',write('A qual classe essa imagem pertence?'),nl,read(Y),
                            (img(Y,_,_,_,_,_,_,_), gravarMedia(Y,M); \+img(Y,_,_,_,_,_,_,_), gravar(Y,M)),loadTemp.

% Grava na Base de dados.
gravar(X,M) :- momentum(M, _, I1, I2, I3, I4, I5, I6, I7), newIm(X,I1, I2, I3, I4, I5, I6, I7).

% Faz a média e grava
gravarMedia(Y,M) :- momentum(M, _, I1, I2, I3, I4, I5, I6, I7), 
                    img(Y,A1,A2,A3,A4,A5,A6,A7),
                    E1 is (I1+A1)/2, E2 is (I2+A2)/2, E3 is (I3+A3)/2, E4 is (I4+A4)/2, E5 is (I5+A5)/2, E6 is (I6+A6)/2, E7 is (I7+A7)/2,
                    retractall(img(Y,_,_,_,_,_,_,_)),
                    newIm(Y,E1, E2, E3, E4, E5, E6, E7),!.

% concantenar número escolhido pelo usuário com .pgm/.xpm
transformar(X,Pgm,Xpm) :- atom_concat('imgs/',X,Z), atom_concat(Z,'.pgm',Pgm),atom_concat(Z,'.xpm',Xpm).

% Verifica se há predicados na base de dados.
compararBaseDados(M,1) :- acharClasse(M),!.
compararBaseDados(_,X) :- X = 0,!.	% Não há imagens na base de dados

% Usa findall pra pegar todas as imagens presentes na base de dados
% isso vai criar uma lista e dessa lista nós criamos outra com a classe e a distância entre ela e a nova imagem
acharClasse(M) :- findall([Classe,E1,E2,E3,E4,E5,E6,E7],img(Classe,E1,E2,E3,E4,E5,E6,E7),Z), calcula(M,Z).

% Calcula a distância entre nova imagem e média das imagens na base de dados.
calcula(_,[]).
calcula(M,[[X,E1,E2,E3,E4,E5,E6,E7]|Xs]) :- momentum(M, _, I1, I2, I3, I4, I5, I6, I7), soma([I1, I2, I3, I4, I5, I6, I7],[E1,E2,E3,E4,E5,E6,E7],0,N),
										  Somatorio is sqrt(N),guardarResultado(X,Somatorio), calcula(M,Xs).

% Fórmula presente no enunciado do trabalho
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
