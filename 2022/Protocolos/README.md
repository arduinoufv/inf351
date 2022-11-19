# Ligando Arduinos

[Ligacao de 2 Arduino usando Software Serial no TinkerCad](https://www.tinkercad.com/things/kE2oykfE4eb-software-serial) : Problemas na simulação no Print string serial do Tinkercad

[Nodemcu e hc12](https://www.esp8266.com/viewtopic.php?f=160&t=14367)
[webserve nodemcu](https://rees52.com/iot/4821-turn-onoff-led-via-web-server-using-nodemcu-esp8266-12e-board-kt574)
[webserver send/receive](https://randomnerdtutorials.com/esp8266-nodemcu-web-server-sent-events-sse/)

## Codigos da aula

* D7 é o RX do nodemcu que conecta no TX da placa HC12
* D8 é o TX do nodemcu que conecta no RX da placa HC12
* ALimentação do 3.3v **DEVE SER DESLIGADA para FAZER O UPLOAD com a IDE Arduino**
[Emissor]()
[Recpetor]()



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
