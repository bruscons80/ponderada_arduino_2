class Led {
  int pino;
public:
  Led(int _pino) {
    pino = _pino;
    pinMode(pino, OUTPUT);
  }
  void on() { digitalWrite(pino, HIGH); }
  void off() { digitalWrite(pino, LOW); }
};

class Semaforo {
  Led vermelho, amarelo, verde;
public:
  Semaforo(int pVermelho, int pAmarelo, int pVerde)
    : vermelho(pVermelho), amarelo(pAmarelo), verde(pVerde) {}

  void ciclo() {
    vermelho.off(); amarelo.on(); verde.off();
    delay(2000);


    amarelo.off(); vermelho.on(); verde.off();
    delay(6000);


    vermelho.off(); amarelo.off(); verde.on();
    delay(4000);
  }
};

Semaforo semaforo(10, 9, 8);

void setup() {
}

void loop() {
  semaforo.ciclo();
}