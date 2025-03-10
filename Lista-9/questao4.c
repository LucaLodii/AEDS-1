#include <stdio.h>
int main(){

    float termo = 1.0/1.0, razao = 1.0/2.0;

    for(int i=0; i<10; i++){
        printf("\n%.3f", termo);
        termo *= razao;
    }

    return 0;
}
// OU DA PRA FAZER ASSIM:
// DA FORMA A BAIXO DA PRA VER O NUMERO NA FORMA DE FRAÇÃO, E NAO DECIMAL
//#include <stdio.h>
//int main() {
//
//   int denominador = 1;  // Começa com 1/1
//
//  for (int i = 0; i < 10; i++) {
//        printf("1/%d ", denominador);  // Exibe a fração 1/denominador
//        denominador *= 2;  // O denominador dobra a cada termo
//    }
//
//    return 0;
//}

