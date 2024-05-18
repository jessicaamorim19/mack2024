<h1 align="center"> Projeto Protótipo de IoT+Sociddade 5.0: <br>
  Controle de Temperatura Ambiente </h1>

<img align="center" src="https://github.com/jessicaamorim19/mack2024/assets/85135086/7599013a-b751-446d-b367-3fb1676e7d8f"><br> <br>



<h3 align="left"> Objetivo </h3>
Este artigo foi desenvolvido durante o curso da disciplina de ‘Objetos Inteligentes Conectados’, da graduação de “Análise e Desenvolvimento de Sistemas”, conectando o potencial transformador da IoT e Sociedade 5.0 através de soluções cotidianas simples e criativos, melhorando a qualidade de vida e promovendo desenvolvimento sustentável.
Basicamente foi construído um Módulo de Controle de Temperatura Ambiente, conectado pela internet à um programa desenvolvido via Arduino em C++ e uma interface desenvolvida em Python. 
<br>

<h3 align="left"> Componentes </h3>
  <ol>
  <li>Plataforma Arduino com programação em C++</li>
  <li>Comunicação com a internet</li>
  <li>Protocolo MQTT</li>
  <li>Broker Mosquitto</li>
  <li>Biblioteca PubSubClient</li>
  <li>Interface de relatórios com programação Python</li>
  <li>Comunicação com a internet (TCP/IP)</li>
  <li>Sensor DHT11 (adquirido pela plataforma de compra e venda Mercado Livre)</li>
  <li>2 Módulos ESP8266 (adquiridos pela plataforma de compra e venda Mercado Livre)</li>
  <li>Atuador relé 1 canal (adquirido pela plataforma de compra e venda Mercado Livre)</li>
    </ol>

<h3 align="left"> Montagem </h3>
<ol>
<li>Conexão de todos os componentes físicos do módulo eletrônico</li>
<li>Programação em linguagem C++ dos comandos necessários para efetuar a leitura da temperatura pelo sensor DHT 11 na IDE do Arduino</li>
<li>Programação em linguagem C++ dos comandos necessários para atuar sobre o componente de Relê para acionamento dado a medida de temperatura que será recebida via internet</li>
<li>Programação em C++ para conexão das duas placas ESP8266 NodeMCU em uma rede de internet Wifi para conexão com a internet</li>
<li>Programação em C++ em cada uma das placas para comunicação via internet utilizando o protocolo MQTT. A placa do sensor de temperatura foi programada para publicar eventos no tópico do broker MQTT, enquanto a placa do relê foi programada para se inscrever e receber os eventos que chegam no tópico em questão do broker;</li>
<li>Programação em Python de um subscriber para poder gerar o relatório de envio e recebimento de mensagens para contabilizar os tempos entre envio da mensagem e recebimento da mesma pelos dispositivos inscritos no tópico.</li>
</ol>


<h3 align="left"> Funcionamento </h3>
<ol>
<li>O Sensor DHT11 lê a temperatura 	do ambiente</li>
<li>Os valores lidos são armazenados em variáveis</li>
<li>Os valores de temperatura são convertidos para Graus Celsius para comunicação MQTT</li>
<li>O módulo Arduino estabelece uma conexão com o servidor MQTT utilizando a biblioteca Firmata</li>
<li>A conexão é feita através da rede Wi-Fi utilizando as placas ESP8266</li>
<li>O módulo Arduino publica mensagens no tópico MQTT com os valores de temperatura</li>
<li>As mensagens são publicadas no sistema Python desenvolvido para o projeto</li>
<li>O módulo Arduino verifica se há novas mensagens no tópico MQTT de recebimento de comandos do servidor</li>
<li>Com base nos comandos recebidos do servidor, o módulo Arduino aciona ou desliga o relé</li>
<li>O relé controla o acionamento de um dispositivo de aquecimento ou refrigeração</li>
<li>O processo se repete continuamente, monitorando a temperatura, publicando mensagens, recebendo comandos e controlando o relé</li>
</ol>

<h3 align="left"> Aplicação </h3>

A documentação completa do projeto encontra-se neste repositório, contando ainda como uma execução disponível no link abaixo:
<ol>
  - Link do vídeo de execução: https://youtu.be/6acWel4Fs0Y/
</ol>

<h3 align="left"> Conclusão </h3>
O desenvolvimento de um controlador de temperatura residencial inteligente demonstra a viabilidade da IoT na construção da Sociedade 5.0. O sistema apresentado permite o monitoramento remoto da temperatura, o controle automatizado do ar-condicionado ou aquecedor e a integração com plataformas de monitoramento online. Dessa forma é possível expandir as funcionalidades do sistema para integrar outros dispositivos inteligentes, como assistentes virtuais, sensores de presença e sistemas de iluminação, prever padrões de uso e otimizar ainda mais o controle da temperatura. Outros modelos podem considerar fontes de energia renováveis e práticas sustentáveis.
 

