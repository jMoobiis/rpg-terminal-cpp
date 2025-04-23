#pragma once // _CONSTANTES_H_


namespace Constantes{

//Criando constantes para manipulação de atributos
  //Criando efeitos de buffs:
  namespace Buffs{
    
    //poção de vida/cura
     constexpr int POCAO_VIDA_MENOR = 20;
     constexpr int POCAO_VIDA_MEDIA = 50;
     constexpr int POCAO_VIDA_MAIOR = 100;

     //poção de força - aumenta o atributo força/strength (amplifica ataques físicos e habilidades/armas que dependem       de força)
     constexpr int POCAO_FORCA_MENOR = 5;
     constexpr int POCAO_FORCA_MEDIA = 10;
     constexpr int POCAO_FORCA_MAIOR = 20;

     //poção de defesa - aumenta o atributo defesa/defense
     constexpr int POCAO_DEFESA_MENOR = 5;
     constexpr int POCAO_DEFESA_MEDIA = 10;
     constexpr int POCAO_DEFESA_MAIOR = 20;

     //poção de inteligência - aumenta o atributo inteligência/intelligence (amplifica magias)
     constexpr int POCAO_INTELIGENCIA_MENOR = 5;
     constexpr int POCAO_INTELIGENCIA_MEDIA = 10;
     constexpr int POCAO_INTELIGENCIA_MAIOR = 20;

     //poção de sorte - aumenta o atributo sorte/luck (aumenta a chance de acerto crítico)
     constexpr int POCAO_SORTE_MENOR = 5;
     constexpr int POCAO_SORTE_MEDIA = 10;
     constexpr int POCAO_SORTE_MAIOR = 20;

     //poção de destreza - aumenta o atributo destreza/dexterity (aumenta a chance de esquiva e manejo de armas)
     constexpr int POCAO_DESTREZA_MENOR = 5;
     constexpr int POCAO_DESTREZA_MEDIA = 10;
     constexpr int POCAO_DESTREZA_MAIOR = 20;
  };

  //Criando efeitos de debuffs:
  namespace Debuffs{

    //dano de vida 
    constexpr int DANO_VIDA_MENOR = -25;
    constexpr int DANO_VIDA_MEDIA = -50;
    constexpr int DANO_VIDA_MAIOR = -75;

    //dano de força - diminui o atributo força/strength (reduz ataques físicos e habilidades/armas que dependem de         força)
    constexpr int DANO_FORCA_MENOR = -5;
    constexpr int DANO_FORCA_MEDIA = -10;
    constexpr int DANO_FORCA_MAIOR = -20;

    //dano de defesa - diminui o atributo defesa/defense
    constexpr int DANO_DEFESA_MENOR = -5;
    constexpr int DANO_DEFESA_MEDIA = -10;
    constexpr int DANO_DEFESA_MAIOR = -20;

    //dano de inteligência - diminui o atributo inteligência/intelligence (reduz magias)
    constexpr int DANO_INTELIGENCIA_MENOR = -5;
    constexpr int DANO_INTELIGENCIA_MEDIA = -10;
    constexpr int DANO_INTELIGENCIA_MAIOR = -20;

    //dano de sorte - diminui o atributo sorte/luck (reduz a chance de acerto crítico)
    constexpr int DANO_SORTE_MENOR = -5;
    constexpr int DANO_SORTE_MEDIA = -10;
    constexpr int DANO_SORTE_MAIOR = -20;

    //dano de destreza - diminui o atributo destreza/dexterity (reduz a chance de esquiva e manejo de armas)
    constexpr int DANO_DESTREZA_MENOR = -5;
    constexpr int DANO_DESTREZA_MEDIA = -10;
    constexpr int DANO_DESTREZA_MAIOR = -20;
    
  }

  //Criando uma constante para duração de buffs e debuffs
  namespace Duracao {
    constexpr int DURACAO_MENOR = 3;
    constexpr int DURACAO_MEDIA = 5;
    constexpr int DURACAO_MAIOR = 7;
  }
  //Criando uma constante para o nível máximo de um personagem
  constexpr int NIVEL_MAXIMO = 100;
}