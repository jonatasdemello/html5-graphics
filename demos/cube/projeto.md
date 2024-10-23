# Cubo 3D

## Projeto:

Elaborar um programa orientado a objetos para a manipulação de um cubo em 3 (três) dimensões (eixos X, Y e Z). O cubo é denhado na tela e pode ser ampliado ou reduzido (escala), rotacionado (rotação) ou movimentado no espaço (translação).

O objeto Cubo é inicializado com as suas coordenadas iniciais (8 pontos no espaço que formarão as arestas) e cada ponto no formato P(x, y, z)

O Objeto deve ter métodos para mostrar e apagar (desenhar) o cubo no espaço. Métodos para aumentar e reduzir o objeto (escalar), mover no espaço e girar em qualquer eixo.

A representação deve ser feita na tela (um ambiente em 2 dimensões x e y) então na representação tem que existir a conversão de um sistema tridimensional (espaço) para um sistema bidimensional (tela ou plano). Toda a representação foi elaborada no sistema de coordenadas cartesianas (x,y,z).

Todo o processo de manipulação dos objetos é feito através da utilização de matrizes.


## Considerações Preliminares

## Transformações Geométricas

Todo desenho é composto por primitivos (pontos) cujos parâmetros são coordenadas em relação à origem de um sistema cartesiano. Sua transformação é obtida transformando-se todas as coordenadas que são parâmetros destes primitivos.

Tipos fundamentais de transformação:
- escala
- translação
- rotação em torno da origem


## Escala

Chama-se transformação em escala a amplialção ou redução de uma figura.
A transformação em escala é obtida pela multiplicação de todas as coordenadas que definem o desenho (pontos) por fatores de escala não nulos. No caso bidimensional, estes fatores são: fator de escala horizontal que multiplica as coordenadas referentes ao eixo X do sistema cartesiano e o fator de escala vetical que multiplica as coordenadas referentes ao eixo Y do sistema cartesiano.

Chamando-se os fatores de escala horizontal e vertical de Ex e Ey, as coordenadas (x',y') obtidas pela transformação de escala das coordendadas (x,y) valem:

x' = Ex * x
y' = Ey * y

Um fator de escala maior que 1 provoca um ampliação na imagem na direção do eixo afetado pelo fator. Um fator de escala entre 0 e 1 provoca uma redução. Um fator negativo provoca um espelhamento da imagem em relação ao eixo não afetado por este fator.

Quando os dois fatores Ex e Ey são iguais, a figura obtida é semelhante a original, ou seja, não sofre distorção. Quando os fatores de escala são diferentes, obtém-se figuras distorcidas em relação à original.

Observe que quando se aplica uma transfomação em escala a um desenho, não só seu tamanho se altera mas também a distância de seus pontos à origem do sistema de coordenadas, pois o ponto (0,0) é o centro da escala. Para se fazer a escala em relação a um ponto que não a origem, deve ser feita uma combinação de transformações de translação e escala.

## Translação

Chama-se translação à movimentação de uma figura para uma outra posição no sistema de coordenadas, de modo que todos os pontos da imagem sejam deslocados de uma mesma distância em relação à sua posição anterior.

A transformação de translação é obitda adicionando-se a todas as coordenadas que definem o desenho, as constantes de translação. No caso bidimensional, existem duas constantes: uma referente ao deslocamento paralelo ao eixo X e outra referente ao deslocamento paralelo ao eixo Y. Chamando-se essas constantes de Tx e Ty, as coordenadas (x',y') obtidas pela translação do ponto de coordenadas (x,y) valem:

x' = Tx + x
y' = Ty + y

## Rotação em Torno da origem

Chama-se rotação em torno da origem à movimentação de uma figura para uma outra posição, de modo que todos os pontos da imagem mantenham a mesma distância da origem que possuíam antes da transformação. Para a obtenção de uma rotação em torno de um ponto qualquer, deve-se fazer uma combinação de transformações de translação e de rotação em torno da origem.

O único parâmetro da transformação de rotação é o ângulo Ф, que indica o valor do deslocamento angular no sentido anti-horário.

As coordenadas (x',y') obtidas pela rotação do ponto de coordenadas (x,y) de um ângulo Ф em torno da origem, valem:

x' = x * cos Ф - y * sen Ф
y' = y * cos Ф + y * sen Ф



