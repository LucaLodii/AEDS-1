//A VERSÃO BONITA FOI PERDIDA
int main()
{
    int empregados, salario_min = 1518, count_sm = 0, salario = 1, maior_salario, menor_salario, percentual, amplitude;

    printf("\nInforme o numero empregados tem em sua empresa: ");
    scanf("%d",&empregados);
    printf("\nInforme o salario: ");
    scanf("%d",&salario);

    menor_salario = maior_salario = salario;

    do{

                    if (salario == 1518){
                count_sm++;
            }
                if(salario > maior_salario){
                    maior_salario = salario;
                } else {menor_salario = salario;}

        printf("\nInforme o salario: ");
        scanf("%d",&salario);

    } while (salario > 0);

    percentual = (count_sm/empregados) * 100;
    amplitude = maior_salario - menor_salario;
    printf("\nO percentual de empregados com o salario minimo eh: %d",percentual);
    printf("\nA amplitude salarial eh de: %d",amplitude);



    return 0;
}
//A VERSÃO BONITA FOI PERDIDA