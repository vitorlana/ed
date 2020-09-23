#include <cstdio> // em C substituir por #include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "headers/Nave.h"
#include "headers/Fila.h"
#include "headers/Pilha.h"

//um exemplo de como incluir cabeçalhos de outros arquivos criados

int main() {

  /**
   * ? Estruturas necessárias
   * Pilhas
   * -> Remover Item
   * -> Adicionar Item
   * -> Imprimir Pilha
   * Fila
   * -> Remover Item
   * -> Remover por pesquisa
   * -> Adcionar Item
   * -> Imprimir Fila
   * 
   * ? Entradas possíveis
   * N -> Contendo informando todas as naves do imperador
   *   -> A seguir vai ser inserido os identificadores de todas essas naves na pilha
   * 
   * 0 -> Pegar a nave mais apta da pilha de preparacao e adicionar na fila de combate, essa ação deve também remover a nave da pilha de preparacao
   * X (identificador) -> Pega o código passado e envia via parâmetro para para uma funcao que irá pesquisar na fila de naves em combate, adicionar essa nave na fila da manutencao, essa ação também deve remover essa nave da fila de naves em combate.
   * -1 -> Pegar a nae que está ponta da fila da manutencao e envia a mesma para a fila de preparacao, essa nave será a próxima a ser chamada quando for solicitado uma nave para combate
   * -2 -> Imprimir Preparacao
   * -3 -> Imprimir Manutencao
   * 
   * */

  Pilha *preparacao = new Pilha;
  Fila *combate = new Fila;
  Fila *manutencao = new Fila;

  int tamanhoFrota;
  int ident;
  int aux;

  int valorOpId;

  std::cin >> tamanhoFrota;
  
  // Inserir a frota
  for (int i = 0; i < tamanhoFrota; i++)
  {
    std::cin >> ident;
    preparacao->addPilha(ident);
  }

  while (std::cin >> valorOpId)
  {
    switch (valorOpId)
    {
    case 0:{
      aux = preparacao->remPilha();
      combate->addFila(aux);
      std::cout << "nave " << aux << " em combate" << std::endl;
      break;
    }
    case -1:{
      aux = manutencao->remFila();
      preparacao->addPilha(aux);
      std::cout << "nave " << aux << " consertada" << std::endl;
      break;
      }
    case -2:{
      preparacao->impPilhaInv();
      break;
      }
    case -3:{
      manutencao->impFila();
      break;
      }
    default:{
      combate->busRemFila(valorOpId);
      manutencao->addFila(valorOpId);
      std::cout << "nave " << valorOpId << " avariada" << std::endl;
      break;
    }
    }
  }

  // _Nave nave;
  // nave->addNave(12345);
  // nave.addNave(23455);
  // nave.remNave();
  // nave.remNave();
  // nave.addNave(34343);
  // nave.addNave(53232);
  // nave.imprimeNave();

  return 0;
  
}
