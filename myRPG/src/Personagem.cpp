#include <iostream>
#include <string>
#include <algorithm>
#include "Personagem.hpp"
#include "Atributos.hpp"
#include "Utilidades.hpp"


//Criando o construtor para a classe personagem
Personagem::Personagem(const std::string& nome, const Atributos& atributos,Racas& raca ,ClasseProfissao& classe ,int nivel) :
    nome(nome),
    atributos(atributos),
    raca(raca),
    classe(classe),
    nivel(nivel) {}


//Criando a lógica através das assinaturas no arquivo personagem.h

//=======================================
//IMPLEMENTANDO LÓGICA  DA ASSINATURA MOSTRARPERSONAGEM
//=======================================

void Personagem::mostrarPersonagem() const {
  std::cout <<"\033[32m" << "\n\n====== FICHA DE PERSONAGEM ======\n\n" << "\033[0m\n";
  std::cout <<"\033[31m\n";
  std::cout << "Nome: " << getNome() << "\n";
  std::cout << "Raça: " << getRaca() << "\n";
  std::cout << "Nível: " << getNivel() << "\n";
  std::cout << "Classe: " << getClasse() << "\n";
  std::cout <<"\033[0m";

  std::cout <<"\033[32m" << "\n\n====== ATRIBUTOS ======\n\n" << "\033[0m\n";
  std::cout << "\033[33m";
  std::cout << "HP: " << getVida() << "\n";
  std::cout << "STR:" << getForca() << "\n";
  std::cout << "DEF:" << getDefesa() << "\n";
  std::cout << "INT:" << getInteligencia() << "\n";
  std::cout << "LUK:" << getSorte() << "\n";
  std::cout << "DEX:" << getDestreza() << "\n";
  std::cout <<"\033[0m";
}

//=======================================
//CRIANDO OS MÉTODOS PARA CALCULAR A ESTURURA DE DANO
//=======================================

//implementação do método para calcular o dano baseado nos atributos
int Personagem::calcularDanoFisico() const {
  int baseDamage = atributos.getAtributo(TipoAtributo::STR);
  int rolarDado = Utilidades::rolarDado(6);


  //Condição para caso o dado rolar 1 - Falha Critica!
  //Consição para caso o dado rolar 6 - Sucesso Critico!
  if (rolarDado == 1) {
    std::cout << "💢 FALHA CRÍTICA!\n" << std::endl; 
    return baseDamage = (atributos.getAtributo(TipoAtributo::STR) + rolarDado) * 0.5; ;
  } else if (rolarDado == 6) {
    std::cout << "🔥 ATAQUE CRÍTICO!\n" << std::endl;
    return baseDamage = (atributos.getAtributo(TipoAtributo::STR) + rolarDado) * 1.5;
  } else {
    return baseDamage = (atributos.getAtributo(TipoAtributo::STR) + rolarDado);
  }
}

//implementação do método para calcular o dano mágico baseado nos atributos
int Personagem::calcularDanoMagico() const{

  int baseDamage = atributos.getAtributo(TipoAtributo::INT);
  int rolarDado = Utilidades::rolarDado(6);

  

  //Condição para caso o dado rolar 1 - Falha Critica!
  //Consição para caso o dado rolar 6 - Sucesso Critico!
  if (rolarDado == 1) {
    std::cout << "💢 FALHA CRÍTICA! (-50% de dano)\n" << std::endl;
    return baseDamage = (atributos.getAtributo(TipoAtributo::INT) + rolarDado) * 0.5;
  } else if (rolarDado == 20) {
    std::cout << "🔥 CRÍTICO! (+50% de dano)\n" << std::endl;
    return baseDamage = (atributos.getAtributo(TipoAtributo::INT) + rolarDado) * 1.5;
  } else {
    return baseDamage = (atributos.getAtributo(TipoAtributo::INT) + rolarDado);
  }
}

//implementação do atributo defesa Fisica
int Personagem::calcularDefesaFisica() const {
  return atributos.getAtributo(TipoAtributo::DEF);
}

//==================================
//CRIANDO OS MÉTODOS PARA DIRECIONAR O DANO AO ALVO
//==================================

//ATRIBUINDO LÓGICA A FUNÇÃO RECEBER DANO
//Aqui o ALVO  quem vai receber a função/dano
void Personagem::receberDanoFisico(int danoRecebido) {
  
  int defesa    = calcularDefesaFisica();
  int danoFinal =  std::max(1, danoRecebido - defesa);

  std::cout<< "A defesa segurou: " << std::max(1, defesa - danoRecebido) << " de dano!\n"
              "O dano final foi de: " << danoFinal << "!\n";

}


//DIRECIONAMENTO DE DANO FISICO
//VAI RECEBER O CALCULO DE calcularDanoFisico() E REPASSAR NA FUNÇÃO
void Personagem::atacarFisico(Personagem& alvo) {

  //1. Calculo do dano
  int dano = this->calcularDanoFisico();

  //2.Passagem de valores (direcionamento)
  alvo.receberDanoFisico(dano);
  alvo.atributos.alterarAtributo(TipoAtributo::HP, - dano);

  //3.Reação do sistema para o que aconteceu
  std::cout<< this->nome <<" atacou -> " << alvo.getNome() << 
              " causando " << dano << " de dano!\n";

  //4.Condicional para verificar se sobreviveu ou não
  if(alvo.getVida() <= 0){
    std::cout << alvo.getNome() << " não suportou aos danos recebidos e foi derrotado!\n";
  };

}

