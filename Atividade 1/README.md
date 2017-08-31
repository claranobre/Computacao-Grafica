Neste trabalho você deve submeter a primeira versão do seu renderizador.
Esta versão deve gerar uma imagem PPM a partir de um arquivo de descrição de cena.
O arquivo deve ser fornecido através de argumentos de linha de comando, como em:
./render arquivo_cena.txt
O arquivo de cena deverá conter as seguintes informações:
NAME = background.ppm
TYPE = PPM
CODIFICATION = binary # aqui poderia ser: ascii
WIDTH = 200
HEIGHT = 100
UPPER_LEFT = 0 255 0    # Cor do canto superior esquerdo (verde)
LOWER_LEFT = 0 0 0      # Cor do canto inferior esquerdo (preto)
UPPER_RIGHT = 255 255 0 # Cor do canto superior direito (amarelo)
LOWER_LEFT = 255 0 0    # Cor do canto inferior direito (vermelho)
Este é apenas a primeira sugestão de arquivo de entrada, descrevendo a cena (por enquanto vazia, apenas com o background).
Note que o seu progama deve gerar as cores do restante da imagem através da interpolação linear das cores atribuída aos cantos.
