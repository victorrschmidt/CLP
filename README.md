# Trabalho de implementação de CLP

## Arquivos de texto para teste
Os arquivos de texto para teste estão no diretório texts. Eles podem ser
referenciados para a execução dos testes dos requisitos do relatório.

- vf1.txt (arquivo válido)
- vf2.txt (arquivo válido)
- vf3.txt (arquivo válido)
- ef.txt (arquivo vazio)
- if.txt (arquivo contendo #ERRO#)

## Instruções de compilação

### C++
Compile os arquivos através do comando

#### Linux
```bash
g++ -std=c++17 cpp\main.cpp -o cpp\analyzer
```

#### Windows
```bash
g++ -std=c++17 cpp\main.cpp -o cpp\analyzer.exe
```

Execute o programa através do comando

#### Linux
```bash
./cpp/analyzer {args}
```

#### Windows
```bash
cpp\analyzer.exe {args}
```

Onde {args} é a lista de arquivos a serem lidos.

#### Exemplo (Linux)
```bash
./cpp/analyzer vf1.txt if.txt
```

#### Exemplo (Windows)
```bash
cpp\analyzer.exe vf1.txt if.txt
```

### Java
Compile os arquivos através do comando

```bash
javac java/*.java
```

Execute o programa através do comando

```bash
java -cp java Main {args}
```

Onde {args} é a lista de arquivos a serem lidos.

#### Exemplo

```bash
java -cp java Main vf1.txt if.txt
```
