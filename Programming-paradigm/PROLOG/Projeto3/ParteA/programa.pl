/*

   RECOMENDACOES:
   
   - O nome deste arquivo deve ser 'programa.pl'
   
   - O nome do banco de dados deve ser 'desenhos.pl'
   
   - Dicas de uso podem ser obtidas na execucação: 
     ?- menu.
     
   - Exemplo de uso:
     ?- load.
     ?- searchAll(id1).
     
   - Fabio Moreira 
   - João Pedro Bresolin Ortigara	
*/

% Apaga os predicados 'xy' da memoria e carrega os desenhos a partir de um arquivo de banco de dados
load :-
    retractall(xy(_,_,_)),
    open('desenhos.pl', read, Stream),
    repeat,
        read(Stream, Data),
        (Data == end_of_file -> true ; assert(Data), fail),
        !,
        close(Stream).

% Ponto de deslocamento, se <Id> existente
new(Id,X,Y) :-
    xy(Id,_,_),
    assertz(xy(Id,X,Y)),
    !.

% Ponto inicial, caso contrario
new(Id,X,Y) :-
    asserta(xy(Id,X,Y)),
    !.

% Exibe opcoes de busca
search :-
    write('searchAll(Id).     -> Ponto inicial e todos os deslocamentos de <Id>'), nl,
    write('searchFirst(Id,N). -> Ponto inicial e os <N-1> primeiros deslocamentos de <Id>'), nl,
    write('searchLast(Id,N).  -> Lista os <N> ultimos deslocamentos de <Id>').

searchAll(Id) :-
    listing(xy(Id,_,_)).

% Exibe opcoes de alteracao
change :-
    write('change(Id,X,Y,Xnew,Ynew).  -> Altera um ponto de <Id>'), nl,
    write('changeFirst(Id,Xnew,Ynew). -> Altera o ponto inicial de <Id>'), nl,
    write('changeLast(Id,Xnew,Ynew).  -> Altera o deslocamento final de <Id>').

% Grava os desenhos da memoria em arquivo
commit :-
    open('desenhos.pl', write, Stream),
    telling(Screen),
    tell(Stream),
    listing(xy),
    tell(Screen),
    close(Stream).

% Exibe menu principal
menu :-
    write('load.        -> Carrega todos os desenhos do banco de dados para a memoria'), nl,
    write('new(Id,X,Y). -> Insere um deslocamento no desenho com identificador <Id>'), nl,
    write('                (se primeira insercao, trata-se de um ponto inicial)'), nl,
    write('search.      -> Consulta pontos dos desenhos'), nl,
    write('change.      -> Modifica um deslocamento existente do desenho'), nl,
    write('remove.      -> Remove um determinado deslocamento existente do desenho'), nl,
    write('undo.        -> Remove o deslocamento inserido mais recentemente'), nl,
    write('commit.      -> Grava alteracoes de todos dos desenhos no banco de dados').

% AQUI COMECA O TRABALHO

% Altera um ponto qualquer
change(Id,X,Y,Xnew,Ynew) :- retract(xy(Id,X,Y)), assertz(xy(Id,Xnew,Ynew)), commit,!.

% Exibe menu remover
remove :-
	 write('remove(Id) 	 -> Remove o desenho com identificador <Id>').

% Remove o desenho com o identificador <Id>
remove(Id) :- retractall(xy(Id,_,_)),!.

% Remove um ponto qualquer do identificador <Id>
remove(Id,X,Y) :- retract(xy(Id,X,Y)),!.

% Altera o ponto inicial do identificado <id>
changeFirst(Id,Xnew,Ynew) :- retract(xy(Id,_,_)), ! , asserta(xy(Id,Xnew,Ynew)).

% Altera o deslocamento final de Id.
changeLast(Id,Xnew,Ynew) :- criaLista(Id,Xnew, Ynew).

% Lista o ponto inicial e N-1 deslocamentos iniciais do <Id>
searchFirst(Id,N) :- criaLista(Id, N).

% Lista os N últimos deslocamentos de ld
searchLast(Id,N) :- criaListaL(Id,N).

% Undo - Consertar, esta apagando o vertice inicial tambem
undo :- xy(Id,_,_),xy(Id,_,_), criaLista(Id). % Caso 2 - ponto de deslocamento
undo :- retract(xy(_,_,_)), !.  % Caso 1 - ponto inicial foi adicionado

% cria uma nova figura com ao menos 5 coordenadas
criaPonto(Id,N):-   N > 0 , N1 is N-1, write('Entre com uma coord. X: '),
					read(A),
					write('Encontre com uma coord. Y: '),
					read(B),
					new(Id,A,B),criaPonto(Id,N1).
figura(Id,X,Y) :- new(Id,X,Y),criaPonto(Id,5).

% Replica
copia(Id,NovoId) :- xy(Id,X,Y), new(NovoId,X,Y).
replicar(Id,Dx,Dy,NovoId) :- xy(Id,X,Y),!,A is X+Dx, C is Y+Dy, new(NovoId,A,C),copia(Id,NovoId),remove(NovoId,X,Y).
replicate(Id,N,Dx,Dy,Px,Py):- N > 0, concatena(Id,NovoId,N), X is Dx+Px, Y is Dy+Py,replicar(Id,X,Y,NovoId),N1 is N-1,replicate(Id,N1,Dx,Dy,X,Y).
replica(Id,N,Dx,Dy) :- replicate(Id,N,Dx,Dy,0,0). 

% Quadrado
quadrado(Id,X,Y,Lado) :- N is Lado * -1, P is Lado, new(Id,X,Y), new(Id,P,0), new(Id,0,P), new(Id,N,0), new(Id,0,N).

% Auxiliar Replica - Concatena
concatena(Id,NovoId,N) :- atom_concat(Id,'rp',Novo), atom_concat(Novo,N,NovoId).

% Auxiliares - SearchFirst
mostrar([X|Xs], N) :- N > 0, N1 is N-1, write(X), nl, mostrar(Xs, N1).
criaLista(Id,N) :- findall(xy(Id,X,Y), xy(Id,X,Y),Z),!,mostrar(Z,N).

% Auxiliares - Change Last
altera(X, Xnew, Ynew, Id) :- retract(X), assert(xy(Id,Xnew,Ynew)).
alterar([X], Xnew, Ynew, Id) :- X = xy(_,_,_), altera(X,Xnew, Ynew, Id).
alterar([_|Xs], Xnew, Ynew, Id) :- alterar(Xs, Xnew, Ynew, Id).
criaLista(Id, Xnew, Ynew) :- findall(xy(Id,X,Y), xy(Id,X,Y),Z),!,alterar(Z, Xnew, Ynew, Id).

% Auxiliares - Undo
deletar([X]) :- retract(X).
deletar([_|Xs]) :- deletar(Xs).
criaLista(Id) :- !,findall(xy(Id,X,Y), xy(Id,X,Y),Z),deletar(Z).

% Auxiliares - SearchLast
reverse([],Z,Z).
reverse([H|T],Z,Acc) :- reverse(T,Z,[H|Acc]).
criaListaL(Id,N) :- findall(xy(Id,X,Y), xy(Id,X,Y),Z),!,reverse(Z,L,[]),mostrar(L,N).
