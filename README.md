<div align="center">

# Compiler Design Lab

This repository contains source code and instructions for various experiments conducted as part of the Compiler Design Lab. Each experiment demonstrates key concepts in compiler construction, such as lexical analysis, parsing, and code generation.

</div>

## Table of Contents

| Experiment Name         | Description                      | Instructions                |
|------------------------|----------------------------------|-----------------------------|
| Lexical Analyzer (`lex.c`) | Identifies tokens in C source code | [See below](#lexical-analyzer-lexc) |

---

## Lexical Analyzer (`lex.c`)

**Description:**  
The lexical analyzer reads a C source file (`input.c`) and identifies tokens such as keywords, identifiers, numbers, operators, separators, and preprocessor directives. The results are written to `output.txt`.

**Requirements:**  
- Input file: `input.c` (C source code to analyze)
- Output file: `output.txt` (tokens will be written here)

**How to Run:**
1. Place your C source code in a file named `input.c` in the repository directory.
2. Compile the lexical analyzer:
   ```sh
   gcc lex.c -o a.exe
   ```
3. Run the executable:
   ```sh
   ./a.exe
   ```
4. Check `output.txt` for the list of tokens