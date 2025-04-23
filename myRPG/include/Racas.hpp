#pragma once
#include "Personagem.hpp"
#include "Atributos.hpp"



//========================================
//CRIANDO AS RAÇAS DERIVADAS SEPARADAS DA CLASSE PRINCIPAL (PERSONAGEM.H)
//========================================


//CRIANDO A RAÇA -> HUMANO
//VALORES BASE EM TODOS OS ATRIBUTOS:
/*
HP      ->   10
STR     ->   10
DEF     ->   10
INT     ->   10
LUK     ->   10
DEX     ->   10
*/

class Humano : public Personagem {
    private:

    //DECLARANDO OS VALORES BASE

    static Atributos atributosPadraoHumano(){
        Atributos base(10,10,10,10,10,10); //Humanos não tem alterações iniciais
        return base;
    }

    public:

    //CRIANDO O CONSTRUTOR PARA A SUB-CLASSE "HUMANO"
    Humano(const std::string& nome,Racas& raca ,ClasseProfissao& classe, int nivel);
};

//CRIANDO A RAÇA -> ELFO
//VALORES BASE EM TODOS OS ATRIBUTOS:
/*
HP      ->   10
STR     ->   8
DEF     ->   8
INT     ->   13
LUK     ->   10
DEX     ->   12
*/

class Elfo : public Personagem {

    private:
    //DECLARANDO OS VALORES BASE PARA A SUB-CLASSE "ELFO"
    static Atributos atributosPadraoElfo(){
        Atributos base(10,10,10,10,10,10); // TODOS OS ATRIBUTOS BASE 10
        base.alterarAtributo(TipoAtributo::STR, -2); // -2 EM FORÇA         (STR)
        base.alterarAtributo(TipoAtributo::DEF, -2); // -2 EM DEFESA        (DEF)
        base.alterarAtributo(TipoAtributo::INT, +3); // +3 EM INTELIGÊNCIA  (INT)
        base.alterarAtributo(TipoAtributo::DEX, +2); // +2 EM DESTREZA      (STR)
        return base;
    }

    public:

    //CRIANDO O COSNTRUTOR PARA  A CLASSE
    Elfo(const std::string& nome,Racas& raca ,ClasseProfissao& classe,int nivel);
};

//CRIANDO A RAÇA -> ANÃO (DWARF)
/*
HP      ->   13
STR     ->   10
DEF     ->   13
INT     ->   10
LUK     ->   14
DEX     ->   7
*/

class Anao : public Personagem{
    //CRIANDO OS VALORES BASE PARA A SUB-CLASSE "ANÃO"
    private:
    static Atributos atributosPadraoAnao(){
        Atributos base(10,10,10,10,10,10);
        base.alterarAtributo(TipoAtributo::HP,  +3); // +3 EM VIDA     ->   (HP)
        base.alterarAtributo(TipoAtributo::DEF, +3); // +3 EM DEFESA   ->   (DEF)
        base.alterarAtributo(TipoAtributo::LUK, +4); // +4 EM SORTE    ->   (LUK)
        base.alterarAtributo(TipoAtributo::DEX, -3); // -3 EM DEZTREZA ->   (DEF)
        return base;
    }

    public:
    Anao(const std::string& nome,Racas& raca ,ClasseProfissao& classe ,int nivel);
};

//CRIANDO A RAÇA -> ORC 
/*
HP      ->   14
STR     ->   13
DEF     ->   13
INT     ->   6
LUK     ->   9
DEX     ->   8
*/

class Orc :public Personagem {
    //CRIANDO OS ATRIBUTOS BASE DE ORC
    static Atributos atributosPadraoOrc(){
        Atributos base(10,10,10,10,10,10);
        base.alterarAtributo(TipoAtributo::HP,  +4);
        base.alterarAtributo(TipoAtributo::STR, +3);
        base.alterarAtributo(TipoAtributo::DEF, +3);
        base.alterarAtributo(TipoAtributo::INT, -4);
        base.alterarAtributo(TipoAtributo::LUK, -1);
        base.alterarAtributo(TipoAtributo::DEX, -2);
        return base;
    }

    public:
    Orc(const std::string& nome,Racas& raca, ClasseProfissao& classe ,int nivel);
};