#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    float numero;   
    char operador;  
    int nuOp;// 1 = numero, 0 = operador
} NumOpe;

float calcular(float a, float b, char op)
{
    float r = 0;
    
    if (op == '+')
    {
        r = a + b;
    }
    else if (op == '-')
    {
        r = a - b;
    }
    else if (op == '*')
    {
        r = a * b;
    }
    else if (op == '/')
    {
        r = a / b;
    }
    else if (op == '^')
    {
        r = 1;
        for (int i = 0; i < (int)b; i++)
        {
            r = r * a;
        }
    }
    return r;
}

int converterExpressao(char* exp, NumOpe vet[])
{
    int i = 0, pos = 0;
    char numeroReal[10];
    int nt = 0;

    while (exp[i] != '\0')
    {
        if ((exp[i] >= '0' && exp[i] <= '9') || exp[i] == '.')
        {
            numeroReal[nt] = exp[i];
            nt++;
        }
        else
        {
            numeroReal[nt] = '\0';
            vet[pos].numero = atof(numeroReal);
            vet[pos].nuOp = 1;
            pos++;
            
            vet[pos].operador = exp[i];
            vet[pos].nuOp = 0;
            pos++;
            
            nt = 0;
        }
        i++;
    }

    numeroReal[nt] = '\0';
    vet[pos].numero = atof(numeroReal);
    vet[pos].nuOp = 1;
    pos++;

    vet[pos].nuOp = -1;
    return pos;
}

void nivel(NumOpe atual[], NumOpe prox[], char operadores[])
{
    int i = 0;
    int pos = 0;
    float a, b, r;

    while (atual[i].nuOp != -1)
    {
        if (atual[i].nuOp == 0 && strchr(operadores, atual[i].operador) != NULL)
        {
            a = prox[pos-1].numero;
            b = atual[i+1].numero;
            r = calcular(a, b, atual[i].operador);
            prox[pos-1].numero = r;
            i += 2;
        }
        else
        {
            prox[pos] = atual[i];
            pos++;
            i++;
        }
    }

    prox[pos].nuOp = -1;
}

void resolverExpressao(char* exp)
{
    NumOpe n1[50], n2[50], n3[50], n4[50];

    converterExpressao(exp, n1);
    nivel(n1, n2, "^");
    nivel(n2, n3, "*/");
    nivel(n3, n4, "+-");

    printf("Resultado: %.2f\n", n4[0].numero);
}

int main()
{
    char expressao[50];

    printf("Digite a expressão: ");
    scanf("%s", expressao);

    resolverExpressao(expressao);

    return 0;
}
