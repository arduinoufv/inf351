import serial

# Porta serial e taxa de transmissão
serial_port = '/dev/ttyUSB0'
baud_rate = 115200

# Abra a porta serial
ser = serial.Serial(serial_port, baud_rate)

# Nome do arquivo de saída
output_file = 'data.csv'

try:
    # Abra o arquivo de saída para escrita
    with open(output_file, 'w') as file:
        while True:
            # Leia uma linha da porta serial
            line = ser.readline().decode('utf-8').strip()
            
            # Escreva a linha no arquivo de saída
            file.write(line + '\n')
            
            # Exiba a linha no console
            print(line)
except KeyboardInterrupt:
    # Se o usuário pressionar Ctrl+C, encerre o programa de forma segura
    ser.close()
except Exception as e:
    print(f"Erro: {e}")
    ser.close()

# Feche a porta serial
ser.close()

