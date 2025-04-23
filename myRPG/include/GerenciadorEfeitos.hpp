#pragma once // _GERENCIADOREFEITOS_H_

#include "Atributos.hpp"
#include "Constantes.hpp"


//Neste arquivo será criado um gerenciador de efeitos para aplicar buffs e debuffs complexos aos personagens 
//durante a partida

class GerenciadorEfeitos {
public:
  // Método para aplicar um buff se valor fixo (inteiro)
  static void aplicarBuff(Atributos& alvo, TipoAtributo tipo, int valorFixo){};

  // Método para aplicar um buff se valor variável (porcentagem)
  static void aplicarBuffPercentual(Atributos& alvo, TipoAtributo tipo, float porcentual){};

  // Método para aplicar um debuff se valor fixo (inteiro)
  static void aplicarDebuff(Atributos& alvo, TipoAtributo tipo, int valorFixo){
    aplicarBuff(alvo, tipo, -valorFixo); // reutiliza o método de buff para aplicar um debuff
  };

  // Método para aplicar um debuff se valor variável (porcentagem)
  static void aplicarDebuffPercentual(Atributos& alvo, TipoAtributo tipo, float porcentual){
    aplicarBuffPercentual(alvo, tipo, -porcentual); // reutiliza o método de buff para aplicar um debuff
  };
};