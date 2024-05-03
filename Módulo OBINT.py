# -*- coding: utf-8 -*-
"""
Programa: Controle de temperatura e rele com Arduino e DHT11

Este programa utiliza um sensor DHT11 para ler a temperatura ambiente e controlar
um relé por meio de um Arduino. O usuário pode definir uma temperatura máxima
e o relé será acionado se a temperatura ambiente ultrapassar esse valor.

Autor: Jessica Campos Fanti Amorim
Data: 2024-05-14
"""

import serial
from . import DHT
from . import U8glib

# Definição de constantes
TEMP_SENSOR_PIN = A0  # Pino do sensor DHT11
DHT_TYPE = DHT11  # Tipo de sensor DHT
RELAY_PIN = 7  # Pino do relé
MAX_TEMP_BUTTON_PIN = 5  # Pino do botão para aumentar a temperatura máxima
MIN_TEMP_BUTTON_PIN = 4  # Pino do botão para diminuir a temperatura máxima
SERIAL_BAUD_RATE = 9600  # Taxa de baud da porta serial

# Inicialização do sensor DHT11
sensor = DHT.DHT(TEMP_SENSOR_PIN, DHT_TYPE)

# Inicialização da serial
serial_port = serial.Serial()
serial_port.baudrate = SERIAL_BAUD_RATE
serial_port.open()

# Inicialização do display OLED
display = U8glib.U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NONE)

# Variáveis globais
max_temp = 20  # Temperatura máxima inicial
current_temp = 0  # Temperatura atual
relay_state = False  # Estado do relé (ligado ou desligado)

def setup():
    """
    Configuração inicial do hardware e variáveis.
    """
    # Configuração dos pinos como entrada ou saída
    pinMode(RELAY_PIN, OUTPUT)
    pinMode(MAX_TEMP_BUTTON_PIN, INPUT)
    pinMode(MIN_TEMP_BUTTON_PIN, INPUT)

    # Inicialização do sensor DHT11
    sensor.begin()

# Função para ler a temperatura do sensor DHT11
def read_temperature():
    """
    Lê a temperatura do sensor DHT11 e retorna o valor em graus Celsius.
    """
    try:
        return sensor.readTemperature()
    except Exception as e:
        print(f"Erro ao ler temperatura: {e}")
        return 0

# Função para atualizar a tela OLED