#pragma once // _ATRIBUTOS_H_
#include <stdexcept> 

//#pragma once é uma diretiva de pré-processador que garante que um arquivo de cabeçalho seja incluído apenas uma vez durante a compilação de um programa. Isso ajuda a evitar problemas de redefinição de símbolos e de dependências circulares

//Criando um ENUM para os atributos para facilitar a manipulação dos mesmos e fazer sistemas de buffs e debuffs mais simples

enum class TipoAtributo {
    HP,                               //Vida || Health Points
    STR,                              //Força || Strength
    DEF,                              //Defesa || Defense
    INT,                              //Inteligência || Intelligence
    LUK,                              //Sorte || Luck
    DEX                               //Destreza || Dexterity
};

//Criação de uma struct para os atributos para utilização em uma classe futura
struct Atributos{

  int healthPoints;                  //Vida = HP
  int strength;                      //Força = STR
  int defense;                       //Defesa = DEF
  int intelligence;                  //Inteligência = INT
  int luck;                          //Sorte = LUK
  int dexterity;                     //Destreza = DEX  

//Criando um construtor padrão para inicializar os atributos com os valores padrão 0
Atributos() : 
  healthPoints(0), 
  strength(0), 
  defense(0), 
  intelligence(0), 
  luck(0), 
  dexterity(0) {}

//Criando um construtor para inicializar os atributos com os valores passados como parâmetro
Atributos(int healthPoints, int strength, int defense, int intelligence, int luck, int dexterity) :
  healthPoints(healthPoints), 
  strength(strength), 
  defense(defense), 
  intelligence(intelligence), 
  luck(luck), 
  dexterity(dexterity) {}

//criando um getter para acessar os atributos e acessa-los através de métodos de outras classes
int getAtributo(TipoAtributo tipo) const {
    switch (tipo) {
        case TipoAtributo::HP: return healthPoints;
        case TipoAtributo::STR: return strength;
        case TipoAtributo::DEF: return defense;
        case TipoAtributo::INT: return intelligence;
        case TipoAtributo::LUK: return luck;
        case TipoAtributo::DEX: return dexterity;
        default: throw std::invalid_argument("Atributo inválido");
    }
}

//Criando um método para alterar os atributos
//Aqui criamos a função alterarAtributo que recebe um tipo de atributo e um valor, e altera o atributo correspondente
//O switch case é utilizado para verificar qual atributo deve ser alterado e o valor é somado ao atributo correspondente
//O usuário vai receber X pontos ao subir de nível, por exemplo, e esses pontos serão distribuídos nos atributos que ele quiser.
void alterarAtributo(TipoAtributo tipo, int valor) {
  switch (tipo) {
    case TipoAtributo::HP:
      healthPoints += valor;
      break;
    case TipoAtributo::STR:
      strength += valor;
      break;
    case TipoAtributo::DEF:
      defense += valor;
      break;
    case TipoAtributo::INT:
      intelligence += valor;
      break;
    case TipoAtributo::LUK:
      luck += valor;
      break;
    case TipoAtributo::DEX:
      dexterity += valor;
      break;
    default:
      throw std::invalid_argument("Tipo de atributo inválido");
      break;
  }
}

};

