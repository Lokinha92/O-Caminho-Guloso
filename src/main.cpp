#include "funcoes.hpp"
using namespace std;



int main() {
    int linha, coluna, aux;
    ifstream doc;
    int cont = 0;
    int cont_matriz = 1;
    vector<int> elementos;

    doc.open("input.data");
    if(doc.is_open()){
        doc >> linha >> coluna;
        while(doc >> aux){
            elementos.push_back(aux);
            cont ++;
            if(cont == linha*coluna){
                processa(elementos, linha, coluna, cont_matriz);
                cout << endl << endl << endl;
                cont = 0;
                elementos.clear();
                cont_matriz++;
            }

        }
    }
    
    return 0;
}