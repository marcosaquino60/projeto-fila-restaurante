Primeiramente criamos nosso projeto priorizando a fila de clientes/comandas. Ou seja, a inserção de produtos consumidos foi feita de forma aleatória, que será explicada posteriormente. Outro detalhe importante é que o nosso cliente é representado e indentificado pela própria comanda. 

- Início de tudo.

A primeira questão a ser pensada foi sobre como criariamos o cardápio, até que chegamos a conclusão que seria mais adequado criar um arquivo.txt e manipula-lo.

A idéia foi criar uma struct Item que possuía um id, nome e preço, e uma struct cardapio(lista estática) que continha MAX elementos tipo Item, o arquivo lido é especificamente armazenado na lista.

A maior dificuldade do trabalho foi essa questão de ler o arquivo e salvar em uma variável, já que strings com espaço eram lidas incorretamente e comprometia ao erro o resto das variáveis seguintes. Depois de muita pesquisa descobrimos o uso de fscanf com a formatação "[^\n]\n", que foi de grande valia para o funcionamento da função carregaCardapio().

Fonte: https://wiki.portugal-a-programar.pt/dev_geral:c:scanfparastrings

-Structs

Feita, os passos seguintes foram bem mais fáceis e bem-sucedidos, criamos todas as TAD's restantes, em geral estáticas, e todas as funções necessárias para sua execução.

- Como as comandas são criadas?

A lógica mais diferencial do nosso código, e também uma das maiores dificuldades foi a criação de comandas com consumos aletórios. Com a função geradorDeComandas(), uma Comanda* passada por parâmetro juntamente com o Cardapio* era preenchida através da função buscaID que recebia por parâmetro um inteiro aleatório gerado por rand() ,que é uma função da lib "time.h", e achava o id de um determinado item do cardápio.

Um dos problemas enfrentados foi a repetição das comandas, cada uma realmente gerava os items aleatorios , o problema estava no fato de todas elas possuírem os mesmos items na mesma ordem, o que foi resolvido, após pesquisas, usando a função "srand(time(NULL))" dentro da main antes do laço de repetição que gera as comandas.

Fonte: https://pt.stackoverflow.com/questions/64838/gerando-numero-aleat%C3%B3rio-na-linguagem-c

Pós isso foram feitos os detalhes de menu interativo dentro do main, a modularização do código, e os comentários in-line no arquivo funcao.h.

