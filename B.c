#include <stdio.h>
#include <math.h>
int main()
{
    int lenght, distance, kmCost, price, custo_pedagio, total_cost, qtd_pedagio, tripCost;
    scanf("%d %d", &lenght, &distance);
    scanf("%d %d", &kmCost, &price);

    if ((lenght >= 1 && lenght <= pow(10, 4)) && (distance >= 1 && distance <= pow(10, 4)) && (kmCost >= 1 && kmCost <= pow(10, 4)) && (price >= 1 && price <= pow(10, 4)))
    {
        qtd_pedagio = lenght / distance;
        custo_pedagio = qtd_pedagio * price;
        tripCost = kmCost * lenght;
        total_cost = custo_pedagio + tripCost;
        printf("%d/n", total_cost);
    }
    return 0;
}
