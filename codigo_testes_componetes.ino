#include "DHT.h"
#include "U8glib.h"
 
#define DHTPIN A1 // pino que estamos conectado
#define DHTTYPE DHT11 // DHT 11
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);

DHT dht(DHTPIN, DHTTYPE);

void draw(float t)
{
  //Retangulo temperatura atual
  u8g.drawRFrame(3, 17, 123, 46, 2);
  u8g.setFont(u8g_font_fub20);
  //Atualiza a temperatura no display
  u8g.setPrintPos(13, 50);
  u8g.print(t);
  //Circulo grau
  u8g.drawCircle(90, 33, 3);
  u8g.drawStr( 95, 50, "C");
  //Box superior amarelo
  u8g.setFont(u8g_font_8x13B);
  u8g.drawRBox(0, 0, 127, 16, 2);
  u8g.setColorIndex(0);
  u8g.drawStr( 21, 13, "TEMPERATURA");
  u8g.setColorIndex(1);
}
 
void setup() 
{
  Serial.begin(9600);
  Serial.println("DHT11 teste!");
  dht.begin();
  pinMode(8, OUTPUT);
}
 
void loop() 
{
  // A leitura da temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  delay(500);
  // testa se retorno é valido, caso contrário algo está errado.
  if (isnan(t) || isnan(h)) 
  {
    Serial.println("Failed to read from DHT");
  } 
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" \t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");

    if (t > 26.6f){
      // Aciona o relé
      digitalWrite(8, LOW);
    }
    else {
      // Desliga o relé
      digitalWrite(8, HIGH);
    }

    u8g.firstPage();
    // Chama a rotina de desenho na tela
    do
    {
      draw(t);
    }
    while ( u8g.nextPage() );
    delay(50);

  }
}
