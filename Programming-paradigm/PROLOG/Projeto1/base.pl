% Trabalho feito por
% Fabio Moreira
% João Pedro Bresolin Ortigara
% INE5416 - Paradigmas de Programação


% Base de Dados
disciplina(ine5401, ic, 'Introducao Computacao', 1).
disciplina(ine5402, pooI, 'Programacao Orientada a Objetos I', 1).
disciplina(ine5402, fmd, 'Fundamentos de Matematica Discreta', 1).
disciplina(eel5105, ctd, 'Circuitos e Tecnicas Digitas', 1).
disciplina(mtm5161, ca, 'Calculo A', 1).

disciplina(ine5404, pooII, 'Programacao Orientada a Objetos II', 2).
disciplina(ine5405, pe, 'Probabilidade e Estatistica', 2).
disciplina(ine5406, sd, 'Sistemas Digitais', 2).
disciplina(ine5407, cts, 'Ciencia Tecnologia e Sociedade', 2).
disciplina(mtm5512, ga, 'Geometria Analitica', 2).
disciplina(mtm7174, cb, 'Calculo B para Computacao', 2).

disciplina(ine5408, ed, 'Estrutura de Dados', 3).
disciplina(ine5409, cn, 'Calculo numerico', 3).
disciplina(ine5410, pc, 'Programacao Concorrente', 3).
disciplina(ine5411, org, 'Organizacao de Computadores', 3).
disciplina(mtm5245, al, 'Algebra Linear', 3).

disciplina(ine5417, esI, 'Engenharia de Software I', 4).
disciplina(ine5413, gf, 'Grafos', 4).
disciplina(ine5415, tc, 'Teoria da Computacao', 4).
disciplina(ine5416, pp, 'Paradigmas da Programacao', 4).
disciplina(ine5412, soI, 'Sistemas Operacionais I', 4).
disciplina(ine5414, rI, 'Redes I', 4).

disciplina(ine5419, esII, 'Engenharia de Software II', 5).
disciplina(ine5423, bdI, 'Banco de Dados I', 5).
disciplina(ine5420, cg, 'Computacao Grafica', 5).
disciplina(ine5421, lf, 'Linguagens Formais', 5).
disciplina(ine5418, cd, 'Computacao Distribuida', 5).
disciplina(ine5422, rII, 'Redes II', 5).

disciplina(ine5427, pgp, 'Planejamento e Gestão de Projetos', 6).
disciplina(ine5453, itcc, 'Introducao a TCC', 6).
disciplina(ine5425, ms, 'Modelagem e Simulacao', 6).
disciplina(ine5430, ia, 'Inteligencia Artificial', 6).
disciplina(ine5426, cc, 'Construcao de Compiladores', 6).
disciplina(ine5424, soII, 'Sistemas Operacionais II', 6).

disciplina(ine5433, tccI, 'TCC I', 7).
disciplina(ine5432, bdII, 'Banco de Dados II', 7).
disciplina(ine5429, sc, 'Seguranca em Computacao', 7).
disciplina(ine5431, sm, 'Sistemas Multimidia', 7).
disciplina(ine5428, is, 'Informatica e Sociedade', 7).

disciplina(ine5434, tccII, 'TCC II', 8).

prerequisito(pooII, pooI).
prerequisito(pe, ca).
prerequisito(sd, ctd).
prerequisito(cb, ca).

prerequisito(ed,pooII).
prerequisito(pc, pooII).
prerequisito(cn, ga).
prerequisito(cn, cb).
prerequisito(al, ga).
prerequisito(org, sd).

prerequisito(esI, ed).
prerequisito(gf, ed).
prerequisito(gf, fmd).
prerequisito(tc, ed).
prerequisito(tc, fmd).
prerequisito(pp, ed).
prerequisito(soI, org).
prerequisito(soI, pc).
prerequisito(rI, pooII).

prerequisito(esII,esI).
prerequisito(bdI,ed).
prerequisito(cg, cb).
prerequisito(cg, ed).
prerequisito(cg, al).
prerequisito(lf, tc).
prerequisito(cd, soI).
prerequisito(cd, rI).
prerequisito(rII, rI).

prerequisito(pgp, esI).
prerequisito(itcc, esI).
prerequisito(ms, pe).
prerequisito(ia, pe).
prerequisito(ia, pp).
prerequisito(ia, gf).
prerequisito(cc, lf).
prerequisito(soII, soI).

prerequisito(tccI, itcc).
prerequisito(tccI, pgp).
prerequisito(bdII, bdI).
prerequisito(sc, fmd).
prerequisito(sc, rI).
prerequisito(sm, rI).
prerequisito(is, cts).

prerequisito(tccII, tccI).

% -------------------------------------

ppreq(X,Y) :- prerequisito(_,X) , prerequisito(X,Y).

% Auxiliares 2
faseComum(X,Y,Q) :- disciplina(_,X,_,Q), disciplina(_,Y,_,Q).
prereqComum(X,Y,Z) :-  prerequisito(X,Z) , prerequisito(Y,Z).

% 2 - Disciplinas que tem pre-requisito (imediatamente anterior) em comum.
prereqAnt(X,Y) :- prereqComum(X,Y,Z), faseComum(X,Y,Q) , disciplina(_,Z,_, U), U is Q-1. 

% 3 - Disciplinas que sao pre-requisito de pre-requisitos
ppreq(X) :- prerequisito(Y,X), prerequisito(_,Y).

% 4 - Disciplinas que estao em uma determinada fase e sao 
% pre-requisitos de outras disciplinas
fase(X,Y) :- disciplina(_,Y,_,X) , prerequisito(_,Y). 

% 5 - Disciplinas que estao em uma determinada fase
% e tem pre-requisitos para serem cursadas
preReqFase(X,Y) :- disciplina(_,Y,_,X) , prerequisito(Y,_).

% 6 - Disciplinas que estao em uma determinada fase, 
% tem pre-requisitos em comum e sao pre-requisitos de outras disciplinas
perg6(X,Y,Z) :- faseComum(Y,Z,X) , prereqComum(Y,Z,_) , prerequisito(_,Y) , prerequisito(_,Z), Y \= Z. 

% 7 - Encadeamento total de pre-requisitos de uma dada disciplina
perg7(X,Y) :- prerequisito(X,Y).
perg7(X,Y) :- prerequisito(X,Z), perg7(Z,Y).


% Pergunta 8 - saber se determinada disciplina tem prerequisito, se houver,
% descobrir se há um prerequisito em uma determinada fase
% X = disc Y = fase Z = prereq na fase Y
perg8(X,Y,Z) :- prerequisito(X,Z) , disciplina(_,Z,_,Y).

tprint([]).
tprint([X|Y]):- nl, write(X), tprint( Y ).

% ------------------------------------------------------------------------------------------

% Parte C

% 1 - Quantas disciplinas ha em uma dada fase
quantDiscFase(X,L,S) :- findall(Y, disciplina(_,Y,_,X), L) , length(L,S).

% 2 - Quantas disciplinas ha no curso
quantDisc(L,S) :- findall(Y, disciplina(_,_,Y,_), L) , length(L,S).

% 3 - Quantas disciplinas tem pre-requisito
quantPre(L,S) :- setof(X, Y ^ prerequisito(X,Y), L) , length(L,S). 

% 4 - Quantas disciplinas sao pre-requisitios
quantSaoPre(L,S) :- setof(Y, X ^ prerequisito(X,Y), L) , length(L,S).

% 5 - Quantas pre-requisitos há para uma dada disciplina
quantPreDisc(X,L,S):- setof(Y, X ^ prerequisito(X,Y), L), length(L, S). % questao 5
qtdPreDisc(X,L,S):- bagof(Y, prerequisito(X,Y), L), length(L, S). % questao 5 obrigatório o uso p/ questao 6

% predicado necessário para as próximas questões
max([],0).
max([[X|X1]],X) :- X1=[X|_].
max([[_|X1]|Xs],X) :- X1=[X|_], max(Xs,Y), X >= Y.
max([[_|X1]|Xs],N) :- X1=[X|_], max(Xs,N), N > X.

% 6 - Qual a disciplina com a maior quantidade de pre-requisitos 
discMaxPre(S):- findall([X,S],qtdPreDisc(X,_,S),L), max(L,N), findall([X,N],qtdPreDisc(X,_,N),S). 

% 7 - Quantas disciplinas tem como pre-requisito uma dada disciplina
quest7(D,L,S) :- setof(Y, D ^ prerequisito(Y,D), L), length(L,S).

% 8 - Qual a disciplina e pre-requisito da maior quantidade de 
% disciplinas (mais importante)
% L = disciplina 'mais importante'
discPre(X,S) :- bagof(Y,prerequisito(Y,X),L), length(L,S). 
quest8(L):- findall([X,S],discPre(X,S),C), max(C,N), findall([X,N],discPre(X,N),L).

% 9 - Dado o encadeamento de pre-requisitos (implementado, por exemplo, pelo ’seq’ abaixo), 
% qual o maior encadeamento identificado na matriz?
% C = retorna as disciplinas com os maiores encadeamentos
seq(X,[]) :- \+prerequisito(X,_).
seq(X,[Y|L]) :- prerequisito(X,Y), seq(Y,L).
prequest9(X,S):- bagof(C,seq(X,C),L), length(L,S).
quest9(C):- findall([X,S],prequest9(X,S),L), max(L,N), findall([X,N],prequest9(X,N),C).
 
% 10 - Qual a disciplina tem a maior quantidade de pré-requisitos imediatamente anterior a sua fase.
% C = retorna as disciplinas com essa propriedade.

preAnterior(X,Y) :- disciplina(_,X,_,F), disciplina(_,Y,_,F1), F1 is F-1, prerequisito(X,Y).
prequest10(X,S):- bagof(Y,preAnterior(X,Y),L), length(L,S).  
quest10(C):- findall([X,S], prequest10(X,S), L), max(L,N), findall([X,N], prequest10(X,N),C).
