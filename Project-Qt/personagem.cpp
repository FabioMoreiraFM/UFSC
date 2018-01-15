#include "personagem.h"

Personagem::Personagem(int life, QString nome, QString classe)
{
    this->life = life;
    this->nome = nome;
    this->classe = classe;
}

QString Personagem::getNome()
{
    return nome;
}

int Personagem::getLife()
{
    return life;
}

QString Personagem::getClasse()
{
    return classe;
}
