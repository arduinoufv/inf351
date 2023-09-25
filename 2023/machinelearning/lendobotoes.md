# Colab

## Ideia
* Coleta de dados dos "cliques" no botao no arduino
* Enviar para o serial
* Gravar no Computador os "dados coletados"
* Ler no Colab, fazer um machine learning
* Usar um gerador de codigo para voltar com o ML para o Arduino
* testar o modelo no arduino

### Coleta de dados

* [versao 1 no Arduino](https://github.com/arduinoufv/inf351/blob/master/2023/machinelearning/aula25_09_23_BUTTON-ARQUIVO_NODEMCU_PYTHON.ino)
     * espera o botão ir para zero, coleta dados de 10 em 10ms, para de coletar se passar 1 segundo sem mudança.

### Coleta do Arduino via python para data.cvs

[Codigo base em python, lembrar de não conectar a IDE do arduino](https://github.com/arduinoufv/inf351/blob/master/2023/machinelearning/getserial.py)

## Treinamento no Colab
[lendo dados do serial](https://colab.research.google.com/drive/1IwT91mlsW-kxw5-muHK1JVMrr378bihX?usp=sharing)
