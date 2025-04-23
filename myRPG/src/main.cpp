#include <iostream>
#include <windows.h>
#include "../include/Personagem.hpp"
#include "../include/Atributos.hpp"
#include "../include/Utilidades.hpp"
#include "../include/Racas.hpp"



void arteProjeto(){
    std::cout << "\033[35m";
    std::cout << R"(
                                                                                                    
          ____                                                              ,-.----.                
        ,'  , `.                                                 ,-.----.   \    /  \    ,----..    
     ,-+-,.' _ |            ,---,     ,--,                       \    /  \  |   :    \  /   /   \   
  ,-+-. ;   , ||   ,---.  ,---.'|   ,--.'|                       ;   :    \ |   |  .\ :|   :     :  
 ,--.'|'   |  ;|  '   ,'\ |   | :   |  |,      .--.--.           |   | .\ : .   :  |: |.   |  ;. /  
|   |  ,', |  ': /   /   |:   : :   `--'_     /  /    '          .   : |: | |   |   \ :.   ; /--`   
|   | /  | |  ||.   ; ,. ::     |,-.,' ,'|   |  :  /`./          |   |  \ : |   : .   /;   | ;  __  
'   | :  | :  |,'   | |: :|   : '  |'  | |   |  :  ;_            |   : .  / ;   | |`-' |   : |.' .' 
;   . |  ; |--' '   | .; :|   |  / :|  | :    \  \    `.         ;   | |  \ |   | ;    .   | '_.' : 
|   : |  | ,    |   :    |'   : |: |'  : |__   `----.   \        |   | ;\  \:   ' |    '   ; : \  | 
|   : '  |/      \   \  / |   | '/ :|  | '.'| /  /`--'  /        :   ' | \.':   : :    '   | '/  .' 
;   | |`-'        `----'  |   :    |;  :    ;'--'.     /         :   : :-'  |   | :    |   :    /   
|   ;/                    /    \  / |  ,   /   `--'---'          |   |.'    `---'.|     \   \ .'    
'---'                     `-'----'   ---`-'                      `---'        `---`      `---`      
                                                                                                    
)";
    std::cout<<"\033[0m";
}

void testarDanoFisico() {
    std::cout << "\033[32m" <<"\n=== TESTE DE DANO FÍSICO ===\n\n" << "\033[0m";
    Atributos stats{100, 10, 5, 0, 0, 0}; // HP, STR, DEF, INT, LUK, DEX
    ClasseProfissao classe = ClasseProfissao::GUERREIRO; 
    Racas raca = Racas::ANAO;
    Personagem p("Teste", stats, raca ,classe, 1); 
    
    for(int i = 0; i < 10; i++) {
        int dano = p.calcularDanoFisico();
        std::cout << "Ataque " << i+1 << ": " << dano << " | ";
        if(dano < 5) std::cout << "FALHA CRÍTICA";
        else if(dano > 15) std::cout << "CRÍTICO!";
        std::cout << "\n";
    }

}

void testarDefesa() {

    std::cout << "\033[32m" <<"\n=== TESTE DE DEFESA ===\n\n" << "\033[0m";
    
    Atributos atacanteStats{100, 15, 0, 0, 0, 0};
    Atributos defensorStats{100, 0, 10, 0, 0, 0};
    ClasseProfissao classe = ClasseProfissao::GUERREIRO; 
    Racas raca = Racas::HUMANO;
    
    Personagem atacante("Atacante", atacanteStats, raca ,classe, 1); 
    Personagem defensor("Defensor", defensorStats, raca ,classe, 1); 
    
    for(int i = 0; i < 5; i++) {
        atacante.atacarFisico(defensor);
        std::cout << "Vida do defensor: " << defensor.getVida() << "\n\n";
    }
    
}

void testarCombateCompleto() {
    std::cout << "\033[32m" <<"\n=== TESTE DE COMBATE COMPLETO ===\n\n" << "\033[0m";
    Atributos heroStats{100, 20, 5, 10, 5, 5};
    Atributos enemyStats{80, 15, 8, 5, 5, 5};
    ClasseProfissao classeHeroi = ClasseProfissao::GUERREIRO; 
    Racas racaHeroi = Racas::HUMANO;
    ClasseProfissao classeInimigo = ClasseProfissao::GUERREIRO; 
    Racas racaInimigo = Racas::ORC;
    
    Personagem hero("Herói", heroStats, racaHeroi ,classeHeroi, 1); 
    Personagem inimigo("Vilão", enemyStats,  racaInimigo,classeInimigo, 1); 
    
    int turno = 1;
    while(hero.getVida() > 0 && inimigo.getVida() > 0) {
        std::cout << "\n=== TURNO " << turno++ << " ===\n";
        hero.atacarFisico(inimigo);
        if(inimigo.getVida() > 0) {
            inimigo.atacarFisico(hero);
        }
    }
    
    std::cout << "\n=== RESULTADO FINAL ===\n";
    std::cout << "Vida do Herói: " << hero.getVida() << "\n";
    std::cout << "Vida do Inimigo: " << inimigo.getVida() << "\n";
}

void testeMostrarPersonagem() {
    std::cout << "\033[32m" <<"\n=== TESTE DE FICHAMENTO DE PERSONAGEM ===\n\n" << "\033[0m";
    Atributos heroStats{100, 20, 5, 10, 5, 5};
    Atributos enemyStats{80, 15, 8, 5, 5, 5};
    ClasseProfissao classeHeroi = ClasseProfissao::GUERREIRO; 
    Racas racaHeroi = Racas::HUMANO;
    ClasseProfissao classeInimigo = ClasseProfissao::GUERREIRO; 
    Racas racaInimigo = Racas::ORC;
    
    Personagem hero("Herói", heroStats,racaHeroi ,classeHeroi, 1); 
    Personagem inimigo("Vilão", enemyStats,racaInimigo ,classeInimigo, 1); 
    hero.mostrarPersonagem();
    inimigo.mostrarPersonagem();

}


int main() {
    // Configuração do terminal
    SetConsoleOutputCP(65001);
    if (GetConsoleWindow() == NULL) {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
    }

    //Imprimindo arte inicial
    arteProjeto();

    // Execução dos testes
    testeMostrarPersonagem();
    testarDanoFisico();
    testarDefesa();
    testarCombateCompleto();

    system("pause");
    return 0;
}