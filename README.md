<div align="center">

# Compiler Design Lab

This repository contains source code and instructions for various experiments conducted as part of the Compiler Design Lab. Each experiment demonstrates key concepts in compiler construction, such as lexical analysis, parsing, and code generation.

</div>

## Table of Contents

### Experiment 1
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Lexical Analyzer (`lex.c`) | Identifies tokens in C source code | [See below](#lexical-analyzer-lexc) |

### Experiment 2 
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Vowel/Consonant Counter (`part1.l`) | Counts vowels and consonants in input text | [See below](#vowelconsonant-counter-part1l) |
| Character/Word/Line Counter (`part2.l`) | Counts characters, words, and lines in a file | [See below](#characterwordline-counter-part2l) |
| LEX Lexical Analyzer (`part3.l`) | LEX-based token identifier for C source code | [See below](#lex-lexical-analyzer-part3l) |
| Email Validator (`part4.l`) | Validates email addresses using LEX | [See below](#email-validator-part4l) |

### Experiment 3
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Identifier Validator (`identifier.y/.l`) | Validates C identifiers using YACC/LEX | [See below](#identifier-validator-identifiery-l) |
| Expression Validator (`expression.y/.l`) | Validates arithmetic expressions using YACC/LEX | [See below](#expression-validator-expressiony-l) |
| Calculator (`calc.y/.l`) | Simple calculator with arithmetic operations | [See below](#calculator-calcy-l) |
| String Recognizer (`recog.y/.l`) | Recognizes strings of form a^n b^n | [See below](#string-recognizer-recogy-l) |

### Experiment 4
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Epsilon Closure (`E-closure.c`) | Finds epsilon closure of states in an Epsilon-NFA | [See below](#epsilon-closure-e-closurec) |

### Experiment 5
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| E-NFA to NFA Converter (`EnfaToDfa.c`) | Converts Epsilon-NFA to NFA using epsilon closure elimination | [See below](#e-nfa-to-nfa-converter-enfatodfac) |

### Experiment 6
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Recursive Descent Parser (`RecursiveDescentParser.c`) | Implements recursive descent parsing for arithmetic expressions | [See below](#recursive-descent-parser-recursivedescentparserc) |

---

# Experiment 1

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

# Experiment 2

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

## LEX Lexical Analyzer (`part3.l`)

**Description:**  
A LEX-based lexical analyzer that reads a C source file and identifies various tokens including keywords, identifiers, numbers, operators, separators, and preprocessor directives. Results are written to an output file.

**Requirements:**  
- LEX/Flex compiler
- Input file: `input.c` (C source code to analyze)
- Output file: `output.txt` (tokens will be written here)

**How to Run:**
1. Navigate to the `experiment_2` directory.
2. Create an `input.c` file with the C source code you want to analyze.
3. Compile the LEX file:
   ```sh
   flex part3.l
   gcc lex.yy.c -o part3.exe
   ```
4. Run the executable:
   ```sh
   ./part3.exe
   ```
5. Check `output.txt` for the list of identified tokens.

---

## Email Validator (`part4.l`)

**Description:**  
A LEX program that validates email addresses. It checks if the entered email follows the basic pattern of having alphanumeric characters, dots, underscores before the @ symbol, followed by a domain ending with .com.

**Requirements:**  
- LEX/Flex compiler
- User input (email address entered via keyboard)

**How to Run:**
1. Navigate to the `experiment_2` directory.
2. Compile the LEX file:
   ```sh
   flex part4.l
   gcc lex.yy.c -o part4.exe
   ```
3. Run the executable:
   ```sh
   ./part4.exe
   ```
4. Enter an email address to validate and press Enter to see if it's valid or invalid.

---

# Experiment 3

## Identifier Validator (`identifier.y/.l`)

**Description:**  
A YACC/LEX program that validates C identifiers. It checks if the entered string follows the rules for valid C identifiers (starts with letter or underscore, followed by letters, digits, or underscores).

**Requirements:**  
- YACC/Bison compiler
- LEX/Flex compiler
- User input (identifier to validate)

**How to Run:**
1. Navigate to the `experiment_3/part1` directory.
2. Compile the YACC and LEX files:
   ```sh
   yacc -d identifier.y
   flex identifier.l
   gcc y.tab.c lex.yy.c -o identifier.exe
   ```
3. Run the executable:
   ```sh
   ./identifier.exe
   ```
4. Enter an identifier to validate and press Ctrl+D to see if it's valid or invalid.

---

## Expression Validator (`expression.y/.l`)

**Description:**  
A YACC/LEX program that validates arithmetic expressions. It checks if the entered expression follows proper arithmetic syntax with correct operator precedence and parentheses matching.

**Requirements:**  
- YACC/Bison compiler
- LEX/Flex compiler
- User input (arithmetic expression to validate)

**How to Run:**
1. Navigate to the `experiment_3/part2` directory.
2. Compile the YACC and LEX files:
   ```sh
   yacc -d expression.y
   flex expression.l
   gcc y.tab.c lex.yy.c -o expression.exe
   ```
3. Run the executable:
   ```sh
   ./expression.exe
   ```
4. Enter an arithmetic expression and press Ctrl+D to see if it's valid.

---

## Calculator (`calc.y/.l`)

**Description:**  
A YACC/LEX program that implements a simple calculator capable of performing arithmetic operations (+, -, *, /), handling unary minus, and respecting operator precedence and parentheses.

**Requirements:**  
- YACC/Bison compiler
- LEX/Flex compiler
- User input (arithmetic expressions to calculate)

**How to Run:**
1. Navigate to the `experiment_3/part3` directory.
2. Compile the YACC and LEX files:
   ```sh
   yacc -d calc.y
   flex calc.l
   gcc y.tab.c lex.yy.c -o calc.exe
   ```
3. Run the executable:
   ```sh
   ./calc.exe
   ```
4. Enter arithmetic expressions and press Enter to see the results. Press Ctrl+D to quit.

---

## String Recognizer (`recog.y/.l`)

**Description:**  
A YACC/LEX program that recognizes strings of the form a^n b^n (equal number of 'a's followed by equal number of 'b's). This demonstrates context-free grammar parsing.

**Requirements:**  
- YACC/Bison compiler
- LEX/Flex compiler
- User input (string to validate)

**How to Run:**
1. Navigate to the `experiment_3/part4` directory.
2. Compile the YACC and LEX files:
   ```sh
   yacc -d recog.y
   flex recog.l
   gcc y.tab.c lex.yy.c -o recog.exe
   ```
3. Run the executable:
   ```sh
   ./recog.exe
   ```
4. Enter a string (e.g., "aabb", "aaabbb") and press Enter to see if it matches the pattern a^n b^n.

---

# Experiment 4

## Epsilon Closure (`E-closure.c`)

**Description:**  
A C program that finds the epsilon closure (ε-closure) of each state in an Epsilon-NFA. The epsilon closure of a state is the set of all states reachable from that state using only epsilon (ε) transitions.

**Requirements:**  
- C compiler (gcc)
- Input: Number of states, number of transitions, and transition details
- Format: `from_state symbol to_state` (use 'e' for epsilon transitions)

**How to Run:**
1. Navigate to the `experiment_4` directory.
2. Compile the program:
   ```sh
   gcc E-closure.c -o e_closure.exe
   ```
3. Run the executable:
   ```sh
   ./e_closure.exe
   ```
4. Enter the input in the following format:
   - First line: Number of states
   - Second line: Number of transitions
   - Next lines: Transition details (from_state symbol to_state)
5. The program will output the epsilon closure for each state.

---

# Experiment 5

## E-NFA to NFA Converter (`EnfaToDfa.c`)

**Description:**  
A C program that converts an Epsilon-NFA (ε-NFA) to an equivalent NFA by eliminating epsilon transitions. The program uses epsilon closure computations to construct the equivalent NFA without epsilon transitions.

**Requirements:**  
- C compiler (gcc)
- Input: Number of states, number of transitions, and transition details of the ε-NFA
- Format: `from_state symbol to_state` (use 'e' for epsilon transitions)

**How to Run:**
1. Navigate to the `experiment_5` directory.
2. Compile the program:
   ```sh
   gcc EnfaToDfa.c -o enfa_to_nfa.exe
   ```
3. Run the executable:
   ```sh
   ./enfa_to_nfa.exe
   ```
4. Enter the input in the following format:
   - First line: Number of states
   - Second line: Number of transitions
   - Next lines: Transition details (from_state symbol to_state)
5. The program will output the equivalent NFA transition function without epsilon transitions.

---

# Experiment 6

## Recursive Descent Parser (`RecursiveDescentParser.c`)

**Description:**  
A C program that implements a recursive descent parser for arithmetic expressions. The parser validates expressions based on the grammar: 
```sh
E → T E'
E' → T E' | ε
T → F T'
T' → * F T' | ε
F → (E) | id
```
It demonstrates top-down parsing techniques.

**Requirements:**  
- C compiler (gcc)
- User input (arithmetic expression to parse)
- Supports: identifiers (letters), multiplication (*), and parentheses

**How to Run:**
1. Navigate to the `experiment_6` directory.
2. Compile the program:
   ```sh
   gcc RecursiveDescentParser.c -o parser.exe
   ```
3. Run the executable:
   ```sh
   ./parser.exe
   ```
4. Enter an arithmetic expression (e.g., "a*b", "a*(b*c)", "(a*b)*c")
5. The program will output whether the expression is syntactically valid or show a syntax error.

---