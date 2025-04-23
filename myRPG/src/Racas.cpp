#include <iostream>
#include <string>
#include "Personagem.hpp"
#include "Atributos.hpp"
#include "Racas.hpp"



//Criando o construtor da classe Humano
Humano::Humano(const std::string& nome,Racas& raca ,ClasseProfissao& classe, int nivel) :
Personagem(nome, atributosPadraoHumano(), raca ,classe, nivel) {}


//Criando o construtor da classe Elfo
Elfo::Elfo(const std::string& nome,Racas& raca, ClasseProfissao& classe, int nivel) : 
Personagem(nome, atributosPadraoElfo(),raca ,classe ,nivel) {}

//Criando o construtor da classe Anao
Anao::Anao(const std::string& nome,Racas& raca,ClasseProfissao& classe ,int nivel) : 
Personagem(nome, atributosPadraoAnao(),raca, classe ,nivel) {}

//Criando o construtor da classe Orc
Orc::Orc(const std::string& nome,Racas& raca, ClasseProfissao& classe ,int nivel) : 
Personagem(nome, atributosPadraoOrc(),raca, classe ,nivel) {}