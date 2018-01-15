#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <QString>

class Personagem
{
public:
    Personagem(int life, QString nome, QString classe);
    QString getNome();
    int getLife();
    QString getClasse();
private:
    int life;
    QString nome;
    QString classe;
};

#endif // PERSONAGEM_H

// Quando criar um método aqui, botão direito->refactor para criar o método no .cpp
// Se algum parâmetro for alterado aqui ou no .cpp aparecerá uma
// lâmpada e ao clicar sobre ela atualizará o arquivo.
