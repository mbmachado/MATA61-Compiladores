# MATA61-Compiladores

> Compilador para a linguagem Robot-L

```diff
O compilador construído possui os seguintes blocos: analisador léxico, analisador sintático, 
analisador semântico, e gerador de código em linguagem de montagem (Assembly Intel 8086).
```

## Como utilizar?

- Modifique o programa fonte em `syntactic.cpp`:
```c
// Programa fonte de Exemplo 
file.open("lexical/source-program-1.txt");
```
- Compile com o comando `g++ main.cpp lexical/lexical.cpp symbol/symbol.cpp syntactic/syntactic.cpp semantic/semantic.cpp code-generator/code.cpp -std=c++11`.
