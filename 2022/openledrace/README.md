
# Projeto OpenLedrace

[Codigo Original](https://github.com/gbarbarov/led-race)

[Exemplo com um carrinho com efeito do fogo](https://github.com/cacauvicosa/openledrace/tree/master/led_race_fire) mais o [video](https://www.youtube.com/watch?v=Rl4G2aO0dno)
* botões estão no D2 e D1 do Esp8266 e a fita de led no D3.


[Código com duas trilhas](https://github.com/arduinoufv/inf351/blob/master/2022/openledrace/dual_track.ino)
* botões estão no D2,D6 (swap) e D1,D5 (swap) do Esp8266 e a fita de led no D3.

[código base com MQTT](https://github.com/cacauvicosa/openledrace/blob/master/led_race_mqtt_speed/led_race_mqtt_speed.ino)

[How to create the MQTT control button for Dual Track](https://www.youtube.com/watch?v=Ag7PvNm-0Yc&t=18s)
     
[How to create feedback for Speed (gauge/line graphic)](https://www.youtube.com/watch?v=pTobk1r-fdk)

# Opções para Tarefa com OpenLedRace

1. Correção do bloqueio de ultrapassagem na versão 2 trilhas
2. 2 trilhas com 4 carros
3. 2 trilhas com 4 carros + volta de marcar o tempo
4. 2 trilhas com 2 carros mais obstáculos que podem acelerar ou reduzir a velocidade
5. 2 Trilhas com MQTT, correção da ultrapassagem [codigo base](https://github.com/cacauvicosa/openledrace/blob/master/led_race_mqtt_dual_track/led_race_mqtt_dual_track.ino)
6. 2 Trilhas com MQTT e vários carros + velocidade [código base](https://github.com/cacauvicosa/openledrace/tree/master/led_race_mqtt_speed)
7. Talles e Lucas - versão bluetooth e esp32
8. Versao 1 trilha com M5stick e MQTT usando o acelerometro do M5 posicionado na canela
9. Versao 2 trilhas com M5stick e MQTT usando o acelerometro do M5 posicionado na canela
10. Versao com Python com programação sem fio
11. Versao com servidor HTTP e pagina WEB 
12. Versao que permitir incluir várias jogos e faz a seleção qual tipo de corrida será
13. Versão com efeito de agua [este video com fastled e git](https://www.youtube.com/watch?v=ydqEkpHzb54)

