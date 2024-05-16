<h1 align="center"> Projeto Protótipo de IoT: Controle de Temperatura Ambiente </h1>

<img align="center" src="https://github.com/jessicaamorim19/mack2024/assets/85135086/9ba7597f-bb46-4537-9cc4-d2b707d62c41"> <br> <br>

<h3 align="left"> Objetivo </h3>
Este artigo foi desenvolvido durante o curso da disciplina de ‘Objetos Inteligentes Conectados’, da graduação de “Análise e Desenvolvimento de Sistemas”, conectando o potencial transformador da IoT e Sociedade 5.0 através de soluções cotidianas simples e criativos, melhorando a qualidade de vida e promovendo desenvolvimento sustentável.
<br><br>

<h3 align="left"> Componentes </h3>
Este projeto envolveu a construção de um protótipo de IoT conectando:
  <ol>
  <li>Plataforma Arduino com programação em C++</li>
  <li>Comunicação com a internet</li>
  <li>Protocolo MQTT</li>
  <li>Sensor DHT11</li>
  <li>Módulo ESP8266</li>
  <li>Atuador relé 1 canal</li>
  <li>Interface de resultados com programação Python</li>
  </ol>

<h3 align="left"> Montagem </h3>
<ol>
<li>Conexão de todos os componentes físicos do módulo eletrônico</li>
<li>Programação em linguagem C++ dos comandos necessários para efetuar a leitura da temperatura pelo sensor DHT 11 na IDE do Arduino</li>
<li>Programação em linguagem C++ dos comandos necessários para atuar sobre o componente de Relê para acionamento dado a medida de temperatura que será recebida via internet</li>
<li>Programação em C++ para conexão das duas placas ESP8266 NodeMCU em uma rede de internet Wifi para conexão com a internet</li>
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



i)        Uma breve descrição do funcionamento e uso para quem quiser reproduzir.
ii)       O software desenvolvido e a documentação de código.
iii)      A descrição do hardware utilizado (plataformas de desenvolvimento, sensores, atuadores, impressão 3D de peças, medidas de peças e caixas etc.)
iv)      A documentação das interfaces, protocolos e módulos de comunicação.
v)       O projeto deve possuir comunicação/controle via internet (TCP/IP) e uso do Protocolo MQTT.
