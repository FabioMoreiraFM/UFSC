/*
   RECOMENDACOES:
   
   - O nome deste arquivo deve ser 'programa.pl'
   - O nome do banco de dados deve ser 'desenhos.pl'
   - O nome do arquivo de gramatica deve ser 'gramatica.pl'
   
   - Dicas de uso podem ser obtidas na execucação: 
     ?- menu.
     
   - Exemplo de uso:
     ?- load.
     ?- searchAll(id1).

   - Exemplo de uso da gramatica:
     ?- comando([repita, '8', '[', pf, '50', gd, '45', ']'], []).
     Ou simplesmente:
     ?- cmd("repita 8[pf 50 gd 45]").
     
     Fabio Moreira
     João Pedro Bresolin Ortigara 
*/


:- initialization(new0).

% Coloca tartaruga no centro da tela (de 1000x1000)

new0 :-
    consult('gramatica.pl'),
    load,
    xylast(X,Y),new(id1, X, Y),retractall(angulo(_)),assertz(angulo(0)),faztudo,!.

% Limpa os desenhos e reinicia no centro da tela (de 1000x1000)

tartaruga :-
    retractall(xy(_,_,_)),
    new(id1, 500, 500),
    retractall(xylast(_,_)),
    asserta(xylast(500, 500)),
	retractall(angulo(_)),
	assertz(angulo(0)).

% Para frente N passos
parafrente(N) :-
    write('Para Frente: pf '), writeln(N),angulo(A),xylast(X,Y),
    Xnovo is (N)*round(cos((A*pi)/180)),
    Ynovo is (N)*round(sin((A*pi)/180)),
    Xlast is X+Xnovo,Ylast is Y+Ynovo, 
    (escreve(s),concatena(Novo),    
     (C is Xnovo,D is Ynovo;
      true,C = Xlast, D = Ylast),
    new(Novo, C, D),
    retractall(xylast(_,_)),
    asserta(xylast(Xlast,Ylast)),!;
    retractall(xylast(_,_)), asserta(xylast(Xlast,Ylast))).


% Para tras N passos
paratras(N) :- 
    write('Para trás: pt '), writeln(N),xylast(X, Y), angulo(A),
    Xnovo is (N)*round(cos((A*pi)/180)), 
    Ynovo is (N)*round(sin((A*pi)/180)),
    Xlast is X-Xnovo,Ylast is Y-Ynovo,
    (escreve(s),concatena(Novo),    
     (C is -Xnovo,D is -Ynovo;
      true,C = Xlast, D = Ylast),
    new(Novo, C, D),
    retractall(xylast(_,_)),
    asserta(xylast(Xlast, Ylast)),!;
    retractall(xylast(_,_)), asserta(xylast(Xlast,Ylast))).

% Gira a direita G graus
giradireita(G) :- 
    write('gira direita: gd '), writeln(G),
    G1 is -1*G,
    trocaAngulo(G1).        

% Gira a esquerda G graus
giraesquerda(G) :- 
    write('gira esquerda: ge '), writeln(G),
    trocaAngulo(G).

% Use nada (levanta lapis)
usenada :- 
    write('use nada: un '),
    (escreve(s),retractall(escreve(_)),assert(escreve(n)),!;
     escreve(n),nl,write('O lapis já está levantado')).

% Use lapis
uselapis :- 
    write('usa lapis: ul '),
    (escreve(n),retractall(escreve(_)),assert(escreve(s)),idAtual(X),retractall(idAtual(_)),X1 is X+1, asserta(idAtual(X1)),pontaDoLapis,!;
     escreve(s), nl,write('lapis já está sendo usado')).

% Após colocar o lápis de volta, criará um novo ponto que está no mesmo local que xylast
pontaDoLapis :- concatena(Novo), xylast(X,Y),new(Novo,X,Y).

% Lista os desenhos feitos até o momento
listar :- listing(xy(_,_,_)).

% Mostra posição atual da tartaruga
postar :- listing(xylast(_,_)).

% ---------------------------------------------------


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
    listing(xylast),
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

% ----------- TRABALHO COMEÇA AQUI ------------------

:- dynamic escreve/1.
:- dynamic idAtual/1.

% verifica se pode escrever ou não
escreve(s).

% usado para criar um novo Id.
idAtual(1).

% ferramenta para listar os predicados necessários
faztudo :- load,cmd("tartaruga"),retractall(escreve(_)),assert(escreve(s)),retractall(idAtual(_)),assert(idAtual(1)),listing(xy(_,_,_)), listing(xylast(_,_)), listing(angulo(_)),!.

%lista os predicados necessários
listatudo :- listing(xy(_,_,_)), listing(xylast(_,_)), listing(angulo(_)).

% troca o ângulo
trocaAngulo(X) :- angulo(Y), retractall(angulo(_)), Z is Y+X, assert(angulo(Z)),!.

% Concatena para criar novo ID
concatena(Novo) :- idAtual(X),atom_concat(id,X,Novo).

% -----------------------------------------------------