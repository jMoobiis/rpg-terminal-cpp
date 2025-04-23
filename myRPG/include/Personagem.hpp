#pragma once // _PERSONAGEM_H_
#include <string>
#include "Atributos.hpp" //incluindo o arquivo de cabeçalho Atributos.h para utilizar a struct Atributos


//CRIANDO UM ENUM PARA ENTITULAR AS RAÇAS
enum class Racas {
  HUMANO,
  ELFO,
  ANAO,
  ORC
};


//criando um ENUM para classes/profissões porém sem alterar atributos
//por hora é apenas para "titularidade"
enum class ClasseProfissao {
  GUERREIRO,
  MAGO,
  LADINO,
  PALADINO,
  ARQUEIRO,
  MONGE,
  NENHUM
};


//criando a classe base Personagem

class Personagem{

protected:
  std::string nome;
  Atributos atributos;
  Racas raca;
  ClasseProfissao classe;
  int nivel;

public:
  //Criando o construtor para definir um valor 0 para nivel
  //Personagem() : nome(""), nivel(0) {}
  
  //Criando o construtor Personagem para passagem e inicialização dos atributos
  Personagem(const std::string& nome, const Atributos& atributos,Racas& raca ,ClasseProfissao& classe, int nivel); 
  virtual ~Personagem() = default; // Destrutor da classe

  //==================================================
  //CRIANDO UM SWITCH PARA ATRIBUIR RACA A STRING
  //==================================================
  std::string getRaca() const {
    switch (raca) {
      case Racas::HUMANO:
        return "Humano";
      case Racas::ELFO:
        return "Elfo";
      case Racas::ANAO:
        return "Anao";
      case Racas::ORC:
        return "Orc";
      default:
        return "Nenhum";
    }
  }


  //==================================================
  //CRIANDO UM SWITCH CASE PARA ATRIBUIR O ENUM A STRING
  //==================================================
  std::string getClasse() const {
    switch (classe) {
      case ClasseProfissao::GUERREIRO:
        return "Guerreiro";
      case ClasseProfissao::MAGO:
        return "Mago";
      case ClasseProfissao::LADINO:
        return "Ladino";
      case ClasseProfissao::PALADINO:
        return "Paladino";
      case ClasseProfissao::ARQUEIRO:
        return "Arqueiro";
      case ClasseProfissao::MONGE:
        return "Monge";
      default:
        return "Nenhum";
    }
  }

  //=================================================

  //==================================================
  //Criando pos métodos getter para chamar as caracteristicas dos personagens
  //==================================================
  //1. Nome
  const std::string& getNome() const {return nome;}

  //2.Atributos //

  //====================================================================================================
  //Esta forma de definição é específica, fazendo a chamada direta dos atributos
  //Evitando assim criar um getter genério que chama o atributo no main de forma que tenha que declarar
  //Qual atributo quiser
  //====================================================================================================

  //2.1. Vida -> HP (healthPoints)
  int getVida() const {return atributos.getAtributo(TipoAtributo::HP);}

  //2.2  Força -> STR (strength)
  int getForca() const {return atributos.getAtributo(TipoAtributo::STR);}

  //2.3 Defesa -> DEF (defense)
  int getDefesa() const {return atributos.getAtributo(TipoAtributo::DEF);}

  //2.4 Inteligência -> INT (intelligence)
  int getInteligencia() const {return atributos.getAtributo(TipoAtributo::INT);}

  //2.5 Sorte -> LUK (Luck)
  int getSorte() const {return atributos.getAtributo(TipoAtributo::LUK);}

  //2.6 Destreza -> DEX (Dexterity)
  int getDestreza() const {return atributos.getAtributo(TipoAtributo::DEX);}

  //2.7 Nivel -> LVL (Level)
  int getNivel() const {return nivel;}
  //==================================================

  //==================================================
  //Criando pos métodos setter para chamar as caracteristicas dos personagens
  //==================================================
  void mostrarPersonagem() const;

  //Todos os métodos abaixo serão virtuais e vão ser sobrescritos nas classes derivadas
  //Criando a assinatura dos métodos de combate

  //Metodo de Combate: 
  //Metodo para atacar
  virtual void atacarFisico(Personagem& alvo); 
  void atacarMagico(Personagem& alvo);
  //Metodo para receber dano
  void receberDanoFisico(int danoFisicoFinal);
  void receberDanoMagico(int danoMagicoFinal);


  //metodos dos calculos
  virtual int calcularDanoFisico() const;
  virtual int calcularDanoMagico() const;
  virtual int calcularDefesaFisica() const;
  int calcularDefesaMagica() const;
  //método para recuperar a vida do personagem
  void recuperarVida(int valor);
 
};