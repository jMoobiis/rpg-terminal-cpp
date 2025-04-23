#include "Utilidades.hpp"
#include <chrono>

int Utilidades::rolarDado(int faces) {
    // =============================================
    // GERADOR DE NÚMEROS ALEATÓRIOS PARA RPG
    // =============================================
    // 
    // Mecânica: Combina duas fontes de aleatoriedade:
    // 1. random_device (depende do hardware/SO)
    // 2. Tempo atual em nanossegundos
    //
    // Por que usar static?
    // - Evita recriar os objetos a cada chamada
    // - Mantém o estado entre rolagens
    // =============================================

    // 1. Dispositivo de aleatoriedade nativo
    static std::random_device rd; // Fonte de entropia do sistema

    // 2. Semente híbrida (hardware + tempo)
    static unsigned semente_aleatoria = rd() ^ static_cast<unsigned>(
        // chrono fornece o tempo atual desde a "epoch" (1/1/1970)
        // Contador em nanossegundos garante unicidade
        std::chrono::system_clock::now().time_since_epoch().count()
    );

    // 3. Motor Mersenne Twister (melhor qualidade que rand())
    static std::mt19937 gen(semente_aleatoria); // MT19937: algoritmo padrão ouro

    // 4. Distribuição uniforme (valores igualmente prováveis)
    std::uniform_int_distribution<> distribuidor(1, faces); // [1, faces] inclusivo

    return distribuidor(gen); // Retorna valor aleatório dentro do intervalo
}