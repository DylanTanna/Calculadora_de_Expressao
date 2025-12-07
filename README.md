# Calculadora de Expressões em C  
*Interpretador desenvolvido como desafio da disciplina de Estrutura de Dados.*

---

![Status](https://img.shields.io/badge/Status-Vers%C3%A3o%20Inicial-yellow)
![Projeto](https://img.shields.io/badge/Tipo-Projeto%20Acad%C3%AAmico-blue)
![Linguagem](https://img.shields.io/badge/Linguagem-C-lightgrey)
![Paradigma](https://img.shields.io/badge/Parser-Sem%20P%C3%B3s--Fixo-orange)
![Licença](https://img.shields.io/badge/Licen%C3%A7a-MIT-green)

---

## Sobre o projeto

A **Calculadora de Expressões em C** foi desenvolvida como parte da disciplina de **Estrutura de Dados**, como um desafio cujo objetivo era implementar um **interpretador matemático**:

- ❌ Sem utilizar **notação pós-fixa (RPN)**  
- ❌ Sem percorrer o vetor da expressão mais de uma vez  
- ✔️ Respeitando rigorosamente a precedência dos operadores  
- ✔️ Implementando o próprio sistema de parsing  

O foco do projeto foi o aprendizado de:

- Manipulação de vetores  
- Uso de `struct` para tokenização  
- Processamento sequencial  
- Lógica de precedência  
- Parsing manual  

---

## O que o projeto faz

-  Tokeniza expressões em **números e operadores**
-  Aplica níveis de precedência:
  - `^` → potência  
  - `*` e `/` → multiplicação e divisão  
  - `+` e `-` → soma e subtração  
-  Lê a expressão **apenas uma vez**
-  Suporta **números decimais**
-  Calcula tudo com funções próprias
-  Retorna o resultado formatado

---

## Por que o projeto é útil

O interpretador demonstra:

- Como criar um **parser manual** em C  
- Como manipular vetores e `struct`  
- Como implementar precedência sem pós-fixo  
- Como estruturar código limpo e modular  
- Como montar um mini-interpretador didático  


---

## Modelagem Interna

### Estrutura principal (`struct`)

````c
typedef struct {
    float numero;
    char operador;
    int nuOp; // 1 = número, 0 = operador, -1 = fim
} NumOpe;
````

### Ciclo de processamento

````c
nivel(n1, n2, "^");
nivel(n2, n3, "*/");
nivel(n3, n4, "+-");
````

---

## Exemplos de uso

### Entrada:
```
2+3*4
```

### Saída:
```
Resultado: 14.00
```

---

### Entrada:
```
2^3+1
```

### Saída:
```
Resultado: 9.00
```

---

## Tecnologias utilizadas

- **C (GCC)**  
- **Terminal (Linux/Windows)**  
- **GitHub**  

---

## Como compilar e executar

### Linux / WSL
````bash
gcc src/main.c -o calculadora
./calculadora
````

### Windows (MinGW)
````bash
gcc src/main.c -o calculadora.exe
.\calculadora.exe
````

---

## Estrutura do projeto

```
calculadora-expressao/
│
├── src/
│   └── main.c
│
└── README.md
```

---

## Tabela de Requisitos

### Requisitos Funcionais

| Código | Descrição |
|:------:|-----------|
| RF01 | Ler a expressão como string. |
| RF02 | Não percorrer a mesma string mais de uma vez. |
| RF03 | Aplicar precedência corretamente. |
| RF04 | Aceitar números decimais. |
| RF05 | Calcular operações básicas e potência. |

### Requisitos Não Funcionais

| Código | Descrição |
|:------:|-----------|
| RNF01 | Não utilizar notação pós-fixa. |
| RNF02 | Não é necessária alta performance. |
| RNF03 | Código modular e evolutivo. |
| RNF04 | Parênteses não obrigatórios na versão inicial. |

---

## Consultas e experimentos sugeridos

```
2+2*3
10/2+4
2^3*2
3.5*2+1.2
```

---

## Roadmap (melhorias futuras)

- [ ] Suporte a **parênteses**
- [ ] Suporte a **números negativos**
- [ ] Validação de erros robusta
- [ ] Implementação de **AST**
- [ ] Otimização com ponteiros dinâmicos
- [ ] Interface visual simples (2.0)

---

## Onde obter ajuda

- Abra uma *Issue* neste repositório  
- Contato: **Dylan Ximenes de Abreu**

---

## Créditos

| Função | Nome |
|--------|------|
| Autor | **Dylan Ximenes de Abreu Tanna** |
| Orientação | **Max Gontijo de Oliveira** |

---

## Licença

````text
MIT License

Copyright (c) 2025 Dylan

Permission is hereby granted, free of charge...

