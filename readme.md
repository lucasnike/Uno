# Uno
Antes de prosseguir veja o vídeo de apresentação do projeto: [vídeo](https://www.loom.com/share/6dd991e2abef48618560d80ae4c8bfdb)

## Repositório do Github
[Repositório do projeto](https://github.com/lucasnike/Uno)
Nesse repositório você irá encontrar todo o projeto para que você possa clona-lo ou baixa-lo em sua máquina, compilar e executar

## O que é?

### Sobre o projeto
Esse projeto foi realizado para obtenção de nota na disciplina de Introdução a técnicas de programação (ITP) turma 07 no ano 2022.2 do curso de Tecnologia da informação (UFRN/BTI). O docente responsável pela turma é o professor Wellington Silva de Souza.

O código foi programado na linguagem C.

### Criadores
Discente                            | Matrícula		
---------                           | -----------
Lucas Vinicius Pereira da Silva     | 20220060694      
João Antonio Costa Paiva Chagas     | 20200046544          


## Regras
Uno é um jogo de cartas de pelo menos dois jogadores. No início das partidas, os jogadores recebam uma seleção de cartas para jogar. Durante o jogo, os jogadores tomam turnos descartando ou comprando cartas enquanto seguem as regras do jogo.

No início de cada partida são distribuídas 7 cartas de números e naipes aleatórios para cada jogador. Adicionalmente, é escolhida aleatoriamente uma carta da pilha de compra para começar na pilha de descarte.

Um jogador só pode realizar suas ações quando for a sua vez.

Durante o turno do jogador, o mesmo pode realizar três ações: Dizer algo, comprar cartas da pilha de compra, descartar cartas na pilha de descarte.

Um jogador não pode comprar e descartar cartas no mesmo turno.

Um jogador só pode descartar cartas do mesmo número ou naipe que a carta que está na pilha de descarte, com exceção das Coringa e Ás que sempre podem ser descartadas.

Algumas cartas quando descartadas tem efeitos especiais na partida:

Código    | Nome			  | Função
--------- | ----------- | --------------
V         | Valete      | Compre 2
R         | Rei         | Pula a vez
D         | Dama        | Inverter
C         | Coringa     | Compre 4 
A         | Ás          | Troque a cor

* Caso Valete ou Coringa: O jogador do turno subsequente deve comprar 2 (caso do valete) ou 4 (caso do coringa) cartas.
* Caso Ás ou Coringa: O jogador responsável pelo descarte deve escolher um naipe para a pilha de descarte.
* Caso Rei: O jogador do turno subsequente não poderá jogar nesse turno.
* Caso Dama: O sentido dos turnos dos jogadores muda de horário pra anti-horário ou vice-versa.

O jogador que almeja vencer uma partida de Uno precisa descartar todas as suas cartas ou então, alternativamente, ter o menor número possível de cartas entre os jogadores da partida no momento que acabam as cartas da pilha de compra.

Se houver empate no segundo caso de vitória, os jogadores que empataram vencem a partida.

## Arquivos e diretórios do projeto

Nosso projeto tem 4 diretórios importantes que dividem partes diferente para a compilação do bot

### Diretórios ./headers
Essa pasta contem todos os arquivos de cabeçalho, os arquivos de cabeçalho guardam as declarações de funções e estruturas que serão usados em todo o projeto.

### Diretórios ./src
Essa pasta contem a maior parte do código fonte do projeto, que mostra como nós organizamos nosso código, nossas estratégias e quais recursos da linguagem C usamos.

### Diretórios ./obj
O diretório ./obj contem partes pré compiladas do bot para melhorar a eficiência do compilador, não é um diretório para prestar muita atenção.

### Diretórios ./bin
Esse diretório contem todos os bots, os pré compilados que deixamos por padrão e o que será compilado com o comando make.

### Arquivo ./main.c
Esse arquivo é onde nosso programa faz tudo, é onde ele executa e usa todas as funções criadas nos outros arquivos de código fonte.

### Arquivo ./uno
Esse arquivo

## Como executar o bot?
Para executar e ver o bot em funcionamento é necessário ter uma distribuição linux instalada no seu computador, ou o WSL2 instalado no Windows, e o compilador gcc, isso é necessário pois o gerenciador do uno foi compilado para linux.

Agora basta abrir o terminal do linux e executar o comando a seguir para compilar o bot
~~~bash
make
~~~
Por padrão nós deixamos três bots pré compilados na pasta bin, para que você pudesse testar o jogo com o número máximo de jogadores (4).

##### Jogo com 2 bots:
~~~bash
./uno bin/brain bin/bot_A
~~~
##### Jogo com 3 bots:
~~~bash
./uno bin/brain bin/bot_A bin/bot_B
~~~
##### Jogo com 4 bots:
~~~bash
./uno bin/brain bin/bot_A bin/bot_B bin/inocente2
~~~

#### Flags importantes do gerenciador do Uno
Flag      | Descrição   
--------- | -----------
-q        | Mostra o resultado final da partida, sem mostrar as ações dos outros jogadores      
-v        | Mostra as ações de todos os jogadores detalhadamente         
-s        | Executa uma seed específica

## Estratégia do bot
A estratégia do bot é defensiva:

O bot evita ao máximo puxar mais cartas.

O bot evita jogar Ás ou Coringa, para que sempre tenha como sair de situações em que teria que comprar cartas por não ter o mesmo naipe ou número da carta do topo da pilha de descarte.

Quando o bot tem a chance de mudar o naipe da mesa, sempre será selecionado o naipe com maior população em sua mão, o mais confortável para as opções que possui.

Para cartas de ataque como Rei, Valete e Coringa, o bot salva o Coringa para situações de crise e não dá preferência ao descarte de Rei ou Valete.
