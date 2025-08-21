<div align="center">

# Compiler Design Lab

This repository contains source code and instructions for various experiments conducted as part of the Compiler Design Lab. Each experiment demonstrates key concepts in compiler construction, such as lexical analysis, parsing, and code generation.

</div>

## Table of Contents

| Experiment Name         | Description                      | Instructions                |
|------------------------|----------------------------------|-----------------------------|
| Lexical Analyzer (`lex.c`) | Identifies tokens in C source code | [See below](#lexical-analyzer-lexc) |
| Vowel/Consonant Counter (`part1.l`) | Counts vowels and consonants in input text | [See below](#vowelconsonant-counter-part1l) |
| Character/Word/Line Counter (`part2.l`) | Counts characters, words, and lines in a file | [See below](#characterwordline-counter-part2l) |

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
4. Check `output.txt` for the list of tokens identified.

---

## Vowel/Consonant Counter (`part1.l`)

**Description:**  
A LEX program that counts the number of vowels and consonants in user input. The program reads input from the user and displays the count of vowels and consonants.

**Requirements:**  
- LEX/Flex compiler
- User input (entered via keyboard)

**How to Run:**
1. Navigate to the `experiment_2` directory.
2. Compile the LEX file:
   ```sh
   flex part1.l
   gcc lex.yy.c -o part1.exe
   ```
3. Run the executable:
   ```sh
   ./part1.exe
   ```
4. Enter your text and press Ctrl+D (or Ctrl+Z on Windows) to see the vowel and consonant count.

---

## Character/Word/Line Counter (`part2.l`)

**Description:**  
A LEX program that counts the number of characters, words, and lines in a text file. The program reads from `input.txt` and displays the statistics.

**Requirements:**  
- LEX/Flex compiler
- Input file: `input.txt` (text file to analyze)

**How to Run:**
1. Navigate to the `experiment_2` directory.
2. Create an `input.txt` file with the text you want to analyze.
3. Compile the LEX file:
   ```sh
   flex part2.l
   gcc lex.yy.c -o part2.exe
   ```
4. Run the executable:
   ```sh
   ./part2.exe
   ```
5. The program will display the count of characters, words, and lines.

---

*You can prompt to update this README as new experiments are added.*