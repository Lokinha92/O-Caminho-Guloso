<h1 align = center> O CAMINHO GULOSO</h1>
<h2 align = center>  🧩 OBJETIVO </h2>

<p><strong>Caminhar por um conjunto de matrizes fornecidas como entrada, objetivando encontrar o maior valor final segundo o conjunto de regras preestabelecidas.</strong></p>

<h2 align = center>  🧭 REGRAS: </h2> 

- 1 - Criar um sistema que leia K matrizes quadradas no tamanho NxN.
- --
- 2 - Seu programa deve enumerá-las, de forma a deixa-las organizadas para processamento. 
- --
- 3 - Partindo da primeira matriz, você deve iniciar de um ponto preestabelecido, esse pode ser fornecido pelo usuário ou estar contido em arquivos extras de configuração. Não é permitido definir diretamente no código. 
- --

- 4 - A partir da primeira matriz, você tem como regras: (a) avançar para a próxima coluna; (b) retroceder para coluna anterior; (c)  saltar para a linha de baixo; (d) ir em diagonal para baixo. Todas essas regras só se aplicam se a casa (posição i,j da matriz) ainda não tenha sido descoberta ou já processada. 
- --

- 5 - Para caminhar você deve sempre optar pelo valor da próxima casa, valor esse que deve ser o maior dentre eles. Caso haja empate entre casas, crie uma regra para adotar sempre uma mesma decisão de caminhamento.
- --
- 6 - Ao alcançar a última linha e coluna da matriz, selecione a próxima matriz e repita todo o processo novamente. Por fim, apresente ao usuário qual foi o caminho adotado e qual a soma obtida do caminho realizado.
- --

<h2 align=center>📚BIBLIOTECAS UTILIZADAS</h2>
- Durante a implementação do algoritmo, as bibliotecas utilizadas foram:

<table align = center>
     <tr>
        <td> std::iostream </td>    
    </tr>
    <tr>
        <td> std::string </td>    
    </tr>
    <tr>
        <td>fstream</td>
    </tr>
        <tr>
        <td>vector</td>
    </tr>
</table>

<h2 align = center>📄 ARQUIVOS UTILIZADOS</h2>

<h3><b>Arquivos de codificação: </b></h3>
<table>
<tr>
        <td> main.cpp </td>    
    </tr>
    <tr>
        <td> funcoes.hpp </td>    
    </tr>
    <tr>
        <td>funcoes.cpp</td>
    </tr>
</table>

<b> main.cpp: Contém o código que será executado pelo terminal</b>

<b> funcoes.hpp: Contém a declaração das bibliotecas, funções utilizadas e seus parâmetros</b>

<b> funcoes.cpp: Contém a implementação do funcionamento das funções utilizadas</b>

<strong>OBS: O arquivo "funcoes.hpp" deve estar incluso aos arquivos "main.cpp" e "funcoes.cpp"</strong>

<h3><b>Arquivos de leitura: </b></h3>
<table>
<tr>
        <td> input.data </td>    
    </tr>
    <tr>
        <td> inicio.txt </td>    
    </tr>
</table>

<b>input.data: Contém em sua primeira linha a quantidade de linhas e colunas que as matrizes geradas terão e, no resto do documento, os valores que irão compor essas matrizes</b>

<b>inicio.txt: Contém a posição na qual o sistema iniciará o processamento da matriz</b>

<h2 align = center> 💡ALGORITMO </h2>

- 1: No arquivo "main.cpp", foram feitas as declarações:
```c++
int linha, coluna, aux;
    ifstream doc;
    int cont = 0;
    int cont_matriz = 1;
    vector<int> elementos;
```

<b>As variáveis "linha" e "coluna" vão armazenar a quantidade de linhas e colunas, respectivamente, das matrizes que serão geradas</b>

<b>A variável "aux" servirá para ler os elementos que irão compor as matrizes formadas</b>

<b>A variável "doc" servirá para ler o arquivo "input.data"</b>

<b>A variável "cont" servirá como um contador para verificar quantos elementos estão dentro do vector "elementos" </b>

<b>A variável "cont_matriz" servirá para enumerar as matrizes formadas</b>

<b>O vector de elementos tipo inteiro "elementos" servirá para armazenar os elementos que vão compor as matrizes</b>

- 2: O numero de linhas e colunas das matrizes a serem geradas são lidos do arquivo "input.data" e armazenado nas variáveis "linha" e "coluna": 
```c++
doc.open("input.data");
    if(doc.is_open()){
        doc >> linha >> coluna;
```

- 3: Os elementos que irão compor a matriz começam a ser lidos, e enviados para o vector "elementos": 
```c++
while(doc >> aux){
            elementos.push_back(aux);
            cont ++;
```
<b>A variável "cont" é incrementada cada vez que um elemento é adicionado ao vector "elementos"</b>

- 4: Quando a quantidade de elementos no vector atinge o valor suficiente para formar uma matriz (que é dado pelo número de linhas multiplicado pelo número de colunas) a função "processa" é chamada, a matriz é percorrida e após chegar à posição final, o contador que representa o número de elementos no vector "elementos" volta a zero, o vector "elementos" é apagado e o contador que numera as matrizes é incrementado, fazendo com que a próxima matriz seja processada e percorrida. 
```c++
            if(cont == linha*coluna){
                processa(elementos, linha, coluna, cont_matriz);
                cout << endl << endl << endl;
                cont = 0;
                elementos.clear();
                cont_matriz++;
            }
```


<h2 align = center>👨‍💻 PERCORRENDO AS MATRIZES</h2>

<strong>Quando o objetivo é caminhar por matrizes, existem restrições: </strong>
<div align = center> <img align src = exemplo.png> </div>

<b>Exemplificando com uma matriz 7x7 e tendo como objetivo alcançar a ultima posição da matriz (em preto), algumas restrições são observadas: </b>

- Na cor verde, estão os casos onde a posição é referente à primeira coluna e diferente da ultima linha. Nesse caso, só é possível se movimentar em 3 direções: Para a direita, para a diagonal baixa da direita e para baixo.

- Na cor amarela, estão os casos onde a posição é referente à ultima coluna e diferente da ultima linha. Nesse caso, também só é possível se movimentar para 3 lados: Para a esquerda, para a diagonal baixa da esquerda e para baixo.

- Na cor azul, estão os casos onde a posição é referente à ultima linha da matriz (exceto a ultima posição). Para esses casos, a matriz será percorrida sempre se movimentando para a direita.

- Em branco, estão os casos onde é possível se movimentar para todas as direções, exceto para cima.

- --

A função "processa" é a responsável por organizar os elementos contidos no vector "elementos" na forma de matriz, percorrê-la de acordo com as regras e restrições, mostrar ao usuário o caminho adotado e a soma dos elementos do caminho. Ela está declarada no arquivo "funcoes.hpp" e sua estrutura está abaixo: 

```c++
void processa(vector<int> elementos, int linha, int coluna, int cont_matriz);
```

Segue um detalhamento do seu funcionamento:

<strong>No arquivo "funcoes.cpp": </strong>

- 1: São feitas as declarações, além dos parâmentros da função:
```c++
    int mat[linha][coluna];
    int k = 0, i_inicio, j_inicio;
    int i_atual, j_atual;
    int total = 0;
    ifstream inicio;
    vector<int> resultado;
```
<b>mat[linha][coluna]: É a estrutura de matriz onde os elementos serão inseridos

k: Servirá como contador de itens que serão passados para a estrutura de matriz

i_inicio e j_inicio: Essas variáveis vão armazenar a posição de onde a matriz começará a ser processada

i_atual e j_atual: Essas variáveis representam a linha e coluna que está sendo processada no momento

total: Essa variável representará a soma dos valores por onde a matriz foi percorrida

inicio: Essa variável será usada para ler o arquivo "inicio.txt"

O vector do tipo inteiro "resultado" servirá para armazenar o valor das posições por onde a matriz ja foi percorrida.</b>

- 2: A variável "inicio" é usada para ler o arquivo "inicio.txt" e a posição de início é definida e armazenada nas variáveis "i_inicio" e j_inicio"

```c++
    inicio.open("inicio.txt");
    if (inicio.is_open())
    {
        inicio >> i_inicio >> j_inicio;
        i_atual = i_inicio;
        j_atual = j_inicio;

        inicio.close();
```
- 3: Os elementos são retirados do vector "elementos" e são passados para o formato de matriz: 
```c++
        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                mat[i][j] = elementos[k];
                k++;
            }
        }
```
- 4: É referenciado a enumeração da matriz que está sendo processada: 
```c++
cout << "Matriz " << cont_matriz << ": " << endl;
```

- 5: O processo de percorrer a matriz começa, a partir da posição inicial que foi lida do arquivo "inicio.txt"

O laço de repetição While é usado para restringir o processamento da matriz a todos os elementos, exceto o último:
```c++
while ((i_atual != linha - 1) || (j_atual != coluna - 1))
        {
```
dentro do laço, as restrições começam a ser verificadas e tratadas para que o percorrimento ocorra de acordo com as regras: 

<strong>Caso 1: Estando na primeira coluna e fora da ultima linha: </strong>
```c++
            if (i_atual != linha - 1 && j_atual == 0) // coluna 0, linha diferente da ultima
            {
                if ((mat[i_atual][j_atual + 1] >= mat[i_atual + 1][j_atual]) && (mat[i_atual][j_atual + 1] >= mat[i_atual + 1][j_atual + 1]))
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    j_atual++; // p/ a direita
                }
                else if (mat[i_atual + 1][j_atual + 1] >= mat[i_atual + 1][j_atual])
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    i_atual++;
                    j_atual++; // diagonal direita
                }
                else
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    i_atual++; // p/baixo
                }
            }
```
As três posições possíveis ao redor do valor atual são verificadas. Quando o maior valor entre as posições é encotrado, o valor da posição atual é inserido no vector "resultado", substituído por -1, e a posição atual passa a ser do maior valor encontrado.

<strong>Caso 2: Quando é possível andar para todos os lados, exceto pra cima: </strong>
```c++
if (i_atual != linha - 1 && j_atual != coluna - 1 && j_atual != 0) // quem vai pra todos os lados
            {
                if (mat[i_atual][j_atual + 1] >= mat[i_atual + 1][j_atual + 1] && mat[i_atual][j_atual + 1] >= mat[i_atual + 1][j_atual] && mat[i_atual][j_atual + 1] >= mat[i_atual + 1][j_atual - 1] && mat[i_atual][j_atual + 1] >= mat[i_atual][j_atual - 1])
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    j_atual++; // p/ a direita
                }
                else if (mat[i_atual + 1][j_atual + 1] >= mat[i_atual + 1][j_atual] && mat[i_atual + 1][j_atual + 1] >= mat[i_atual + 1][j_atual - 1] && mat[i_atual + 1][j_atual + 1] >= mat[i_atual][j_atual - 1])
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    i_atual++;
                    j_atual++; // p/ a diagonal direita
                }
                else if (mat[i_atual + 1][j_atual] >= mat[i_atual + 1][j_atual - 1] && mat[i_atual + 1][j_atual] >= mat[i_atual][j_atual - 1])
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    i_atual++; // p/baixo
                }
                else if (mat[i_atual + 1][j_atual - 1] >= mat[i_atual][j_atual - 1] && mat[i_atual + 1][j_atual - 1] >= mat[i_atual + 1][j_atual] && mat[i_atual + 1][j_atual - 1] > mat[i_atual + 1][j_atual + 1] && mat[i_atual + 1][j_atual - 1] >= mat[i_atual][j_atual + 1])
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    i_atual++;
                    j_atual--; // diagonal p/ esquerda
                }
                else if (mat[i_atual][j_atual - 1] >= mat[i_atual + 1][j_atual - 1] && mat[i_atual][j_atual - 1] >= mat[i_atual + 1][j_atual] && mat[i_atual][j_atual - 1] > mat[i_atual + 1][j_atual + 1] && mat[i_atual][j_atual - 1] > mat[i_atual][j_atual + 1])
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    j_atual--; // p/ esquerda
                }
            }
```
As cinco posições possíveis ao redor do valor atual são verificadas. Quando o maior valor entre as posições é encotrado, o valor da posição atual é inserido no vector "resultado", substituído por -1, e a posição atual passa a ser do maior valor encontrado.

<strong>Caso 3: Estando na ultima coluna e fora da ultima linha: </strong>
```c++
if (i_atual != linha - 1 && j_atual == linha - 1) // ultima coluna
            {
                if (mat[i_atual + 1][j_atual] >= mat[i_atual + 1][j_atual - 1] && mat[i_atual + 1][j_atual] >= mat[i_atual][j_atual - 1])
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    i_atual++; // p/ baixo
                }
                else if (mat[i_atual + 1][j_atual + 1] >= mat[i_atual][j_atual - 1])
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    i_atual++;
                    j_atual--; // diagonal esquerda baixo
                }
                else
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    j_atual--; // p/esquerda
                }
            }
```
As três posições possíveis ao redor do valor atual são verificadas. Quando o maior valor entre as posições é encotrado, o valor da posição atual é inserido no vector "resultado", substituído por -1, e a posição atual passa a ser do maior valor encontrado.

<strong>Caso 4: Estando na ultima linha</strong>
```c++
if (i_atual == linha - 1 && j_atual != coluna - 1) // ultima linha
            {
                if (mat[i_atual][j_atual + 1] != -1)
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    j_atual++;
                }
            }
```
A fim de evitar que seja impossível chegar à ultima posição da matriz, ao alcançar a última linha, o sistema se movimenta para a direita rumo ao ultimo elemento da matriz. O valor da posição anterior é adicionado ao vector "resultado" e substituído por -1.

<strong>Chegando à ultima posição: </strong>
```c++
 if (i_atual == linha - 1 && j_atual == coluna - 1) // fim da matriz
            { 
                resultado.push_back(mat[i_atual][j_atual]);
                mat[i_atual][j_atual] = -1;
            }
```
Chegando a ultima posição da matriz, o valor é adicionado ao vector resultado e substituído por -1.
- --

A cada vez que o sistema altera a sua posição na matriz, ela é exibida na tela, assim como a linha e coluna em que o sistema se encontra atualmente.
```c++
            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
            cout << "\npos atual: " << "i = " << i_atual << " " << "j = " << j_atual << "\n\n"<< endl;
        }
```
- 6: Após alcançar a última posição da matriz, o caminho que foi adotado para percorre-la é mostrado na tela, assim como a soma desses valores.
```c++
for (long unsigned int i = 0; i < resultado.size(); i++)
        {
            cout << "Caminho: " << resultado[i] << endl;
            total += resultado[i];
        }

        cout << "Total: " << total << endl;
    }
    total = 0;
```
A variável "total" é resetada para que a soma do caminho da próxima matriz seja realizada sem erros.

<strong>Esse processo é repetido até que todas as matrizes sejam processadas.</strong>

- --

<h2 align = center>📈 Resultados esperados</h2>

<b>É esperado que o sistema seja capaz de ler, processar, enumerar e percorrer de acordo com as regras quaisquer matrizes de tamanho NxN, partindo de qualquer posição.</b>

Para exemplificar, a seguinte matriz de tamanho 7x7 foi processada pelo sistema: 

<div align = center> <img align src = matriz_exemplo.png> </div>

Partindo do ponto 0,0 (valor 478), é esperado que o sistema alcance o ultimo valor da matriz (263) optando sempre pelo caminho que contém o maior valor numérico. Ao fim exibir o caminho feito durante o processamento e a soma desses valores.
<p> O ARQUIVO A SEGUIR LEVARÁ A UM TXT CONTENDO A SAÍDA ESPERADA NO PROCESSAMENTO DA MATRIZ A CIMA ----> 
<a href="saida.txt">SAÍDA.TXT</a>.
</p>



<h2 align = center>🔧 Compilação e execução </h2>
</h2>

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |                                     
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             


