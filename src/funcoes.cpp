#include "funcoes.hpp"
using namespace std;

void processa(vector<int> elementos, int linha, int coluna, int cont_matriz)
{
    int mat[linha][coluna];
    int k = 0, i_inicio, j_inicio;
    int i_atual, j_atual;
    int total = 0;
    ifstream inicio;
    vector<int> resultado;

    inicio.open("inicio.txt");
    if (inicio.is_open())
    {
        inicio >> i_inicio >> j_inicio;
        i_atual = i_inicio;
        j_atual = j_inicio;

        inicio.close();

        for (int i = 0; i < linha; i++)
        {
            for (int j = 0; j < coluna; j++)
            {
                mat[i][j] = elementos[k];
                k++;
            }
        }
        
        cout << "Matriz " << cont_matriz << ": " << endl;

        while ((i_atual != linha - 1) || (j_atual != coluna - 1))
        {
            if (i_atual != linha - 1 && j_atual == 0) // coluna 0, linha diferente da linha 6
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
            if (i_atual == linha - 1 && j_atual != coluna - 1) // ultima linha
            {
                if (mat[i_atual][j_atual + 1] != -1)
                {
                    resultado.push_back(mat[i_atual][j_atual]);
                    mat[i_atual][j_atual] = -1;
                    j_atual++;
                }
            }

            if (i_atual == linha - 1 && j_atual == coluna - 1) // fim da matriz
            { 
                resultado.push_back(mat[i_atual][j_atual]);
                mat[i_atual][j_atual] = -1;
            }

            for (int i = 0; i < linha; i++)
            {
                for (int j = 0; j < coluna; j++)
                {
                    cout << mat[i][j] << " ";
                }
                cout << endl;
            }
            cout << "\npos atual: " << "i = " << i_atual << " " << "j = " << j_atual << "\n\n"
                 << endl;
        }
        for (long unsigned int i = 0; i < resultado.size(); i++)
        {
            cout << "Caminho: " << resultado[i] << endl;
            total += resultado[i];
        }

        cout << "Total: " << total << endl;
    }
    total = 0;
}
