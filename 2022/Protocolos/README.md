# Ligando Arduinos

[Ligacao de 2 Arduino usando Software Serial no TinkerCad](https://www.tinkercad.com/things/kE2oykfE4eb-software-serial) : Problemas na simulação no Print string serial do Tinkercad

[Nodemcu e hc12](https://www.esp8266.com/viewtopic.php?f=160&t=14367)
[webserve nodemcu](https://rees52.com/iot/4821-turn-onoff-led-via-web-server-using-nodemcu-esp8266-12e-board-kt574)
[webserver send/receive](https://randomnerdtutorials.com/esp8266-nodemcu-web-server-sent-events-sse/)

# Codigos da aula

## NodeMCU e HC12

* D7 é o RX do nodemcu que conecta no TX da placa HC12
* D8 é o TX do nodemcu que conecta no RX da placa HC12
* ALimentação do 3.3v **DEVE SER DESLIGADA para FAZER O UPLOAD com a IDE Arduino**
![](https://github.com/arduinoufv/inf351/blob/master/2022/Protocolos/Captura%20de%20tela%20de%202022-11-19%2013-07-43.png?raw=true)
* download dos códigos onde **emissor** envia o caracter 1 e alterna seu led a cada 1 segundo, o **receptor** ao receber o caracter 1 alterna o led.
    * [Emissor](https://github.com/arduinoufv/inf351/blob/master/2022/Protocolos/emissor_node_hc12.ino)
    * [Recpetor](https://github.com/arduinoufv/inf351/blob/master/2022/Protocolos/receptor_node_12.ino)

## Webserver 

* Código com 2 leds conectados ao NodeMCU que funciona no modo AP standalone e prover internet. Conectar na rede NodeMCU no IP 192.168.4.1
* tem 2 botões para ligar e desligar os leds e um contador é mostrado no led1. 
* [codigo](https://github.com/arduinoufv/inf351/blob/master/2022/Protocolos/webserver_standalone_node_2led_d3_d5.ino)


## Webserver nodemcu conectado a rede local

* instalar as bibliotecas [webserver assincrono](https://github.com/me-no-dev/ESPAsyncWebServer/archive/master.zip) e do [tcp assincrono](https://github.com/me-no-dev/ESPAsyncTCP/archive/master.zip)
* colocar a senha do WIFI local
* Codigo imprime três contadores no servidor [código](https://github.com/arduinoufv/inf351/blob/master/2022/Protocolos/webserver_conectado_WIFI_local_node.ino)

## Esp32 e NRF24L01

[exemplo](https://how2electronics.com/stm32-nrf24l01-node-with-esp32-nrf24l01-gateway/)
![](https://how2electronics.com/wp-content/uploads/2020/10/circuit-ESP32-nRF24L01-442x360.png)
```
NRF24L01 VCC ………………………………………… 3.3V of ESP32
NRF24L01 CSN ………………………………………… D5 of ESP32    const static uint8_t PIN_RADIO_CSN = 5;
NRF24L01 MOSI ………………………………………… D23 of ESP32  const static uint8_t PIN_RADIO_MOSI = 23;
NRF24L01 GND ………………………………………… GND of ESP32
NRF24L01 CE ………………………………………… D4 of ESP32  const static uint8_t PIN_RADIO_CE = 4;
NRF24L01 SCK ………………………………………… D18 of ESP32 const static uint8_t PIN_RADIO_SCK = 18;
NRF24L01 MISO ………………………………………… D19 of ESP32 const static uint8_t PIN_RADIO_MISO = 19;
```
![](https://components101.com/sites/default/files/component_pin/nRF24L01-Pinout.png)

* [codigo transmissor Gera um pacote, alterna o led (alguns placas não tem Led no pino 2), envio com o tempo Millis](https://github.com/arduinoufv/inf351/blob/master/2022/Protocolos/Basic_TX_ESP32_led_rf24.ino)
* [Codigo Receptor Recebe o pacote e mostra o timestamp, alterna o led](https://github.com/arduinoufv/inf351/blob/master/2022/Protocolos/Basic_TX_ESP32_led_rf24.ino)

Usa a biblioteca rf24l01 lite instalada a partir da IDE, o codigo é uma pequena modificação do exemplo base para o esp32. Outras bibliotecas podem dar problema para compilar para o esp32. 

# teoria
[assincrono](https://media.geeksforgeeks.org/wp-content/uploads/20190523143244/Untitled-Diagram-421.png)

[Transmissao Sincrona](https://media.geeksforgeeks.org/wp-content/uploads/20190523143224/Untitled-Diagram-411.png)

[Serial com Clock](https://circuitdigest.com/sites/default/files/inlineimages/u/Serial-communication.png)

[Paralela com clock](https://circuitdigest.com/sites/default/files/inlineimages/u/Parallel-communication.png)

[Detalhe do Sincrono com clk](https://circuitdigest.com/sites/default/files/inlineimages/u1/Synchronous-Serial-Communication.png)

[Detalhe do Assincrono sem clk](https://circuitdigest.com/sites/default/files/inlineimages/u1/Asynchronous-Serial-Communication.png)

[SPI](https://circuitdigest.com/sites/default/files/inlineimages/u/SPI-communication.png)

[I2C](https://circuitdigest.com/sites/default/files/inlineimages/u/I2C-Communication-Working.png)

[fsk modulacao frequencia](https://www.elprocus.com/wp-content/uploads/2016/10/Frequency-Shift-Keying.png)

[led ws2812](https://cpldcpu.files.wordpress.com/2014/01/ws2812_protocol.png?w=527&h=230)

[fita led](https://hackaday.com/wp-content/uploads/2014/12/programming_incorrect.png?w=800)

[I2C 2 Arduinos](https://www.arduino.cc/wiki/static/4c35b7e5d5136ddeac81c1672a6abc7b/5a190/Master_Sender_bb.png)

[I2C 2 Arduinos Esquematico](https://www.arduino.cc/en/uploads/Tutorial/Master_Sender_sch.png)


# Exemplos com Arduinos

* [Dois Arduinos e Protocolo I2C](https://www.arduino.cc/en/Tutorial/LibraryExamples/MasterWriter)

* [SPI Dois Arduinos](http://arduino-er.blogspot.com/2014/09/communication-betweeen-arduinos-using.html)
