# Detecção de Comunidades

Implementação do algoritmo de Zhao et al. de Detecção de Comunidades para a disciplina de Grafos DIM0549 do curso Bacharelado em Tecnologia da Informação da Universidade Federal do Rio Grande do Norte período 2023.1.

Alunos:

-   João Guilherme Lopes Alves da Costa (20200045609)
-   Matheus Leão de Carvalho (20210050003)

## Compilação

```bash
g++ -Wall -std=c++17 -g src/main.cpp -I src/include -o build/run
```

## Execução

Manualmente:

```bash
build/run data/<input_file.txt> results/<output_file.txt>
```

Pode-se usar o script `run.sh`:

```bash
./run.sh <arquivo_de_teste.txt>
```

OBS: Antes de poder executar o script, dê permissão de execução a este arquivo utilizando o comando `chmod +x run.sh`.
