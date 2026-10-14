# Robô Desvia-Obstáculos com ESP32

## Sobre o projeto

Este projeto consiste no desenvolvimento de um carrinho robótico autônomo capaz de percorrer uma pista, semelhante a um circuito de Fórmula 1, identificando obstáculos e desviando deles automaticamente.

O sistema utiliza um ESP32 para controlar dois motores DC e interpretar as informações de três sensores ultrassônicos HC-SR04. Com base nas distâncias medidas, o carrinho decide quando seguir em frente, virar ou recuar.

## Componentes utilizados

- **ESP32 DevKit V1:** microcontrolador responsável pelo processamento e controle do carrinho.
- **3 sensores ultrassônicos HC-SR04:** utilizados para detectar obstáculos.
- **Ponte H L9110S:** responsável pelo controle dos motores.
- **2 motores DC:** responsáveis pela movimentação do carrinho.
- **Chassi robótico:** estrutura para montagem dos componentes.
- **Fonte de alimentação:** responsável por alimentar o sistema.

## Posicionamento dos sensores

O projeto utiliza três sensores HC-SR04 posicionados na parte frontal do carrinho:

| Sensor | Posição | Função |
|---|---|---|
| Sensor esquerdo | Lateral superior esquerda | Detectar obstáculos à esquerda |
| Sensor central | Frontal | Detectar obstáculos à frente |
| Sensor direito | Lateral superior direita | Detectar obstáculos à direita |

Os sensores laterais podem ser orientados para a frente e para fora, ampliando a área de detecção do carrinho.

## Mapeamento dos pinos

### Ponte H — L9110S

| Pino do ESP32 | Função |
|---|---|
| GPIO 21 | Motor A — IN1 |
| GPIO 18 | Motor A — IN2 |
| GPIO 22 | Motor B — IN1 |
| GPIO 23 | Motor B — IN2 |

### Sensores ultrassônicos — HC-SR04

| Sensor | TRIG | ECHO |
|---|---|---|
| Esquerdo | GPIO 13 | GPIO 14 |
| Central | GPIO 25 | GPIO 26 |
| Direito | GPIO 32 | GPIO 33 |

**Atenção:** os pinos ECHO dos HC-SR04 operam normalmente em 5 V. Como os GPIOs do ESP32 trabalham com lógica de 3,3 V, é necessário utilizar divisores de tensão nos sinais ECHO para evitar danos ao microcontrolador.

## Funcionamento do sistema

O funcionamento do carrinho é dividido em quatro etapas:

1. **Leitura dos sensores:** os três sensores medem continuamente a distância dos obstáculos.
2. **Processamento:** o ESP32 analisa as distâncias obtidas e identifica possíveis obstáculos.
3. **Tomada de decisão:** o programa determina a direção mais adequada para o desvio.
4. **Movimentação:** a ponte H controla os motores para executar os movimentos necessários.

### Estratégia de desvio

O algoritmo utiliza a seguinte lógica:

- **Caminho livre:** o carrinho segue em frente.
- **Obstáculo à frente:** verifica as distâncias laterais e escolhe o lado com mais espaço disponível.
- **Obstáculo à esquerda:** realiza uma manobra para a direita.
- **Obstáculo à direita:** realiza uma manobra para a esquerda.
- **Obstáculos em todas as direções:** recua e tenta realizar uma curva.

A distância mínima inicial para considerar um obstáculo é de 25 cm, podendo ser ajustada conforme os testes realizados na pista.

## Tecnologias utilizadas

- Linguagem C/C++ para programação do ESP32.
- Arduino IDE para desenvolvimento e compilação do código.
- Sensores ultrassônicos HC-SR04 para medição de distância.
- Controle digital dos motores por meio da ponte H.

## Objetivos do projeto

- Desenvolver um sistema de navegação autônoma.
- Aplicar conceitos de sistemas embarcados e robótica.
- Implementar leitura de sensores e tomada de decisão.
- Controlar motores DC utilizando uma ponte H.
- Desenvolver um algoritmo de desvio de obstáculos.
- Testar o comportamento de um robô em uma pista com obstáculos.

## Possíveis melhorias

- Ajustar a velocidade dos motores utilizando PWM.
- Implementar curvas mais precisas.
- Otimizar o algoritmo para evitar movimentos repetitivos.
- Adicionar sensores para ampliar a capacidade de percepção do ambiente.
- Melhorar o desempenho do carrinho em curvas e espaços estreitos.

## Status do projeto

**Em desenvolvimento.**

O projeto está na fase de implementação do sistema de controle dos motores e integração dos três sensores ultrassônicos. Os próximos passos envolvem testes práticos, calibração das distâncias e ajustes da lógica de desvio.

---

**Desenvolvido como projeto de robótica e sistemas embarcados utilizando ESP32.**
