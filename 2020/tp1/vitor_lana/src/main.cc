#include <cstdio> // em C substituir por #include <stdio.h>
#include "headers/foo.h"
#include "headers/nave.cc"
 //um exemplo de como incluir cabeçalhos de outros arquivos criados

int main() {
  /** Desenvolvimento do código, quais as funções necessárias, quais as estruturas que devem ser implementadas
   * Estrutura a ser implementada: pilha
   * Funcoes da pilha: adicionar, remover, imprimir pilha, impressao inversa
   * 
   * A pilha vai ser utilizada para adicionar as naves na fila de combate, como ela se utiliza da funcao FILO isso supre a necessidade da implementacação
   * 
   * Estrutura a ser implementada: fila
   * Funcoes da fila: adiconar, remover, imprimir pilha, pesquisa na fila, remoção por pesquisa
   * 
   * A fila vai ser utilizada tanto na funcao de ir para o centro de reparos, tanto para a área de batalha 
   * TODO: Implementar a funcao de pilha para uma struct com ponteiros para o anterior e o próximo
   * TODO: Implementar a funcao de fila para uma struct com ponteiros para o anterior e o próximo
   * */
  
  // int num_frotas;
  // scanf("%d",&num_frotas);
  // int i;
  // for(i=0; i < num_frotas; i++){
  //   int id_nave;
  //   scanf("%d",&id_nave);
  //   //desenvolver o código para inserção correta das naves que são lidas
  // }
  // int operacao;
  // while(scanf("%d", &operacao) != EOF) {
  //   //desenvolver o código relacionado as operações a serem realizadas
  // }
  _Nave nave;
  Nave n;
  nave.addNave(12345);
  nave.addNave(23455);
  // nave.remNave();
  nave.addNave(34343);
  nave.addNave(53232);

  nave.imprimeNave();

  return 0;
  
}
