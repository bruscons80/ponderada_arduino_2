# Montagem do Semáforo com Arduino Uno

Este passo a passo explica, em ordem, como montar na prática um semáforo simples usando Arduino Uno, protoboard, LEDs e resistores, ilustrando cada etapa com as fotos do projeto.

---

## Materiais

- 1 Arduino Uno  
- 1 Protoboard  
- 3 LEDs (vermelho, amarelo, verde)  
- 3 resistores (220 Ω ou 330 Ω)  
- Jumpers (fios de conexão)

---

## Passo a Passo

### 1. Conecte o GND do Arduino à Protoboard

Ligue um fio preto do pino GND do Arduino para a barra azul (linha de GND) lateral da protoboard. Isso irá distribuir o terra para todo o circuito.

<br>
<div align="center">
<sub>GND</sub>
</div>
<br>
<div align="center">
<img width=100% height=100% alt="VGND" src="../ponderada_arduino_2/Vídeo:Fotos/7.jpeg"/>
</div>
<br>
<div align="center">
</div>
<br>

Logo após isso, leve a tensão elétrica para seção da protoboard que será utilizada. 

<br>
<div align="center">
<sub>Jumper</sub>
</div>
<br>
<div align="center">
<img width=100% height=100% alt="VGND" src="../ponderada_arduino_2/Vídeo:Fotos/6.jpeg"/>
</div>
<br>
<div align="center">
</div>
<br>


### 2. Ligue um Resistor a cada jumper utilizado. 
(Foto: "3.jpg", "4.jpg")

Ligue um resistor (220 Ω ou 330 Ω) ao jumper que será ligado ao catodo, conectando a outra extremidade do resistor à linha azul da protoboard (terra/GND). Assim cada LED terá sua própria proteção de corrente.

<br>
<div align="center">
<sub>Resistor</sub>
</div>
<br>
<div align="center">
<img width=100% height=100% alt="VGND" src="../ponderada_arduino_2/Vídeo:Fotos/5.jpeg"/>
</div>
<br>
<div align="center">
</div>
<br>

---

### 3. Posicione e Conecte os LEDs
(Foto: "4.jpg")

Insira na protoboard os três LEDs (vermelho, amarelo e verde) em colunas diferentes. Coloque cada LED com o anodo (perna maior) para um lado e catodo (perna menor) para o outro. Deixe espaço suficiente para conectar os resistores em sequência.

<br>
<div align="center">
<sub>LED</sub>
</div>
<br>
<div align="center">
<img width=100% height=100% alt="VGND" src="../ponderada_arduino_2/Vídeo:Fotos/1.jpeg"/>
</div>
<br>
<div align="center">
</div>
<br>


---

### 4. Conecte os Anodos dos LEDs aos Pinos do Arduino

Conecte cada anodo dos LEDs aos pinos corretos da placa Arduino usando jumpers:

- LED Vermelho → Pino Digital 10
- LED Amarelo → Pino Digital 9
- LED Verde → Pino Digital 8

Faça a ligação direta com fios do Arduino para os anodos dos respectivos LEDs.

<br>
<div align="center">
<sub>Resistor</sub>
</div>
<br>
<div align="center">
<img width=100% height=100% alt="VGND" src="../ponderada_arduino_2/Vídeo:Fotos/4.jpeg"/>
</div>
<br>
<div align="center">
</div>
<br>

<br>
<div align="center">
<sub>GND</sub>
</div>
<br>
<div align="center">
<img width=100% height=100% alt="VGND" src="../ponderada_arduino_2/Vídeo:Fotos/3.jpeg"/>
</div>
<br>
<div align="center">
</div>
<br>

---
### Agora você tem um semáforo completo!
<br>
<div align="center">
</div>
<br>
<div align="center">
<img width=100% height=100% alt="VGND" src="../ponderada_arduino_2/Vídeo:Fotos/2.jpeg"/>
</div>
<br>
<div align="center">
</div>
<br>

## Funcionamento

Com o código carregado no Arduino, os LEDs devem acender conforme o ciclo do semáforo:  
- Um LED aceso por vez (vermelho, depois amarelo, depois verde), respeitando os tempos programados.

---

**Dica:** Confira sempre polaridade dos LEDs (anodo/perna longa para o pino digital, catodo/perna curta para o GND via resistor) e evite fios soltos ou mal conectados!

---

# Explicação do Código do Semáforo Arduino

O código abaixo controla três LEDs (vermelho, amarelo e verde) conectados a um Arduino para simular as fases de um semáforo.

``` 
int vermelho = 10;
int amarelo = 9;
int verde = 8;

void setup() {
pinMode(vermelho, OUTPUT);
pinMode(amarelo, OUTPUT);
pinMode(verde, OUTPUT);
}

void loop() {
digitalWrite(vermelho, LOW);
digitalWrite(amarelo, HIGH);
digitalWrite(verde, LOW);
delay(2000);

digitalWrite(amarelo, LOW);
digitalWrite(vermelho, HIGH);
delay(6000);

digitalWrite(verde, HIGH);
digitalWrite(vermelho, LOW);
delay(4000);
} 
```
### Declaração dos Pinos
Define em quais pinos do Arduino cada LED está conectado.
- `int vermelho = 10;` → LED vermelho no pino 10
- `int amarelo = 9;` → LED amarelo no pino 9
- `int verde = 8;` → LED verde no pino 8

### Configuração Inicial (setup)
No bloco `setup()`, indica ao Arduino que esses pinos serão usados para saída de energia (OUTPUT), ou seja, vão acender e apagar os LEDs.

### Ciclo de Controle (loop)

O bloco `loop()` executa continuamente e define a lógica do semáforo:

- **Fase Amarela (2 segundos)**
  - Liga o LED amarelo.
  - Apaga LEDs verde e vermelho.
  - Espera 2 segundos (`delay(2000);`).

- **Fase Vermelha (6 segundos)**
  - Apaga o LED amarelo.
  - Liga o LED vermelho.
  - O LED verde permanece apagado.
  - Espera 6 segundos (`delay(6000);`).

- **Fase Verde (4 segundos)**
  - Liga o LED verde.
  - Apaga o LED vermelho.
  - O LED amarelo permanece apagado.
  - Espera 4 segundos (`delay(4000);`).

Depois disso, o ciclo reinicia, repetindo continuamente o funcionamento do semáforo.


