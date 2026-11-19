# Trabalho Compiladores 26.2

## 1. Scanner Manual (C)

Entre na pasta do scanner:
```bash
cd compilador_cm/scanner_cm
```

Compile e execute passando o arquivo de teste:
```bash
gcc main.c scan.c -o teste_scan
./teste_scan teste_sem_erros.cm
```

Arquivos de teste na pasta:
- `teste_sem_erros.cm`
- `teste_com_erros.cm`
- `teste.cm`

---

## 2. Scanner com Flex

Entre na pasta do Flex:
```bash
cd compilador_cm/scanner_cm/scanner-flex
```

Para compilar (caso altere o `scanner.l`) e executar:
```bash
flex scanner.l
gcc lex.yy.c util.c -o flex_exec -lfl
./flex_exec teste2.cm
```

---

## 3. Parser LL(1)

Entre na pasta do parser:
```bash
cd parte2-ex_01
```

Compile e execute passando o arquivo de teste:
```bash
gcc main.c scan.c parser.c -o main
./main teste1.cm
```

Arquivos de teste na pasta:
- `teste1.cm`
- `teste2.cm`
- `teste3.cm`
- `teste4_erro.cm` (teste de erro sintático)
