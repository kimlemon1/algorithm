#include <stdio.h>
#include <stdlib.h>
#include "Electronics.h"

int main() {
  Electronics* e1 = new TV(600);
  Electronics* e2 = new Cellphone(160);
  Laptop * e3 = new Laptop(330);

  Computer * GPU1 = new Computer(50);

  // 어떤 electronics이든 사용 가능해졌다!
  //TV * GPU1 = new TV(50);

  Computer * GPU2 = new Computer(20);
  
  e3->AddGPU(GPU1);
  e3->AddGPU(GPU2);
  //e1->SetSize(500);
  e1->PrintSelf();
  e2->PrintSelf();
  e3->PrintSelf();


  delete e1;
  delete e2;
  delete e3;
  delete GPU1;
  delete GPU2;

  return EXIT_SUCCESS;
}
