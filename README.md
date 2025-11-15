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

### Experiment 7
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| First and Follow (`FirstFollow.c`) | Computes FIRST and FOLLOW sets for a given grammar | [See below](#first-and-follow-firstfollowc) |

### Experiment 8
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Operator Precedence Parser (`op.c`) | Implements operator precedence parsing for expressions | [See below](#operator-precedence-parser-opc) |

### Experiment 9
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Three Address Code Generator (`3ac.c`) | Generates three-address code from arithmetic expressions | [See below](#three-address-code-generator-3acc) |

### Experiment 10
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Intermediate Code Representations (`qt.c`) | Generates intermediate code representation (Quadruple & Triple) | [See below](#intermediate-code-representations-qtc) |

### Experiment 11
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Constant Propagation (`cp.c`) | Performs constant propagation optimization | [See below](#constant-propagation-cpc) |

### Experiment 12
| Program Name | Description | Instructions |
|--------------|-------------|--------------|
| Machine Code Generator (`mc.c`) | Generates 8086 assembly code from intermediate representation | [See below](#machine-code-generator-mcc) |

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

# Experiment 7

## First and Follow (`FirstFollow.c`)

**Description:**  
A C program that computes the FIRST and FOLLOW sets for a given context-free grammar. These sets are essential for constructing predictive parsers and LL(1) parsing tables.

**Requirements:**  
- C compiler (gcc)
- Input: Number of productions
- Format: Productions in the form `A-alpha` where A is a non-terminal and alpha is a string of terminals/non-terminals

**How to Run:**
1. Navigate to the `experiment_7` directory.
2. Compile the program:
   ```sh
   gcc FirstFollow.c -o firstfollow.exe
   ```
3. Run the executable:
   ```sh
   ./firstfollow.exe
   ```
4. Enter the grammar productions when prompted
5. The program will display the FIRST and FOLLOW sets for each non-terminal.

---

# Experiment 8

## Operator Precedence Parser (`op.c`)

**Description:**  
A C program that implements an operator precedence parser for arithmetic expressions. It uses a shift-reduce parsing technique with operator precedence rules to validate expressions. The parser supports multiple operators with proper precedence and associativity rules, as well as parentheses for grouping.

**Supported Features:**
- Identifiers (represented as 'i')
- Operators: `+`, `-`, `*`, `/`, `^` (power)
- Parentheses: `(`, `)`
- Operator precedence: `^` (highest) > `*`, `/` > `+`, `-` (lowest)
- Right associativity for power operator (`^`)

**Requirements:**  
- C compiler (gcc)
- User input (arithmetic expression)

**How to Run:**
1. Navigate to the `experiment_8` directory.
2. Compile the program:
   ```sh
   gcc op.c -o op.exe
   ```
3. Run the executable:
   ```sh
   ./op.exe
   ```
4. Enter an expression using 'i' for identifiers and operators
5. The program will display the parsing steps with input, stack, and action columns.

---

# Experiment 9

## Three Address Code Generator (`3ac.c`)

**Description:**  
A C program that converts infix arithmetic expressions to postfix notation and then generates three-address code (intermediate representation). Three-address code uses temporary variables and simple operations with at most three operands.

**Requirements:**  
- C compiler (gcc)
- User input (arithmetic expression without spaces)
- Supports: single-letter operands, operators (+, -, *, /, ^), parentheses

**How to Run:**
1. Navigate to the `experiment_9` directory.
2. Compile the program:
   ```sh
   gcc 3ac.c -o 3ac.exe
   ```
3. Run the executable:
   ```sh
   ./3ac.exe
   ```
4. Enter an expression (e.g., "a+b*c", "(a+b)*(c-d)/e")
5. The program will display the postfix expression and generated three-address code.

**Example:**
```
Input: a+b*c
Postfix: abc*+
Three Address Code:
t1 = b * c
t2 = a + t1
```

---

# Experiment 10

## Intermediate Code Representations (`qt.c`)

**Description:**  
A C program that extends the three-address code generator to produce multiple intermediate code representations: Three-Address Code (TAC), Quadruple, and Triple formats. These are different ways to represent intermediate code in compiler design, each with its own advantages for optimization and code generation phases.

**Representations Generated:**
1. **Three-Address Code**: Human-readable format with temporary variables
2. **Quadruple**: 4-tuple format (Operator, Arg1, Arg2, Result) with explicit result field
3. **Triple**: 3-tuple format (Operator, Arg1, Arg2) where results are referenced by position indices

**Requirements:**  
- C compiler (gcc)
- User input (arithmetic expression without spaces)
- Supports: single-letter/digit operands, operators (+, -, *, /, ^), parentheses

**How to Run:**
1. Navigate to the `experiment_10` directory.
2. Compile the program:
   ```sh
   gcc qt.c -o qt.exe
   ```
3. Run the executable:
   ```sh
   ./qt.exe
   ```
4. Enter an expression (e.g., "a+b*c", "(a+b)*(c-d)")
5. The program will display:
   - Postfix expression
   - Three-address code
   - Quadruple representation (with id, op, arg1, arg2, result columns)
   - Triple representation (with id, op, arg1, arg2 - using position references)

**Example:**
```
Input: a+b*c
Postfix expression: abc*+

Three Address Code:
t1 = b * c
t2 = a + t1

Quadruple Representation:
id  Op  Arg1  Arg2  Result
1   *   b     c     t1
2   +   a     t1    t2

Triple Representation:
id  Op  Arg1  Arg2
0   *   b     c
1   +   a     (0)
```

---

# Experiment 11

## Constant Propagation (`cp.c`)

**Description:**  
A C program that demonstrates constant propagation optimization on three-address code. It takes an arithmetic expression and constant values for variables, then performs constant propagation by replacing variable references with their constant values throughout the intermediate code. Finally, it evaluates the expression to compute the final result.

**Optimization Process:**
1. Generates three-address code from the input expression
2. Replaces variable names with their constant values in the TAC
3. Evaluates the optimized code to produce the final result

**Requirements:**  
- C compiler (gcc)
- User input: 
  - Arithmetic expression (without spaces)
  - Constant values for variables a, b, x, y
- Supports: operators (+, -, *, /), parentheses

**How to Run:**
1. Navigate to the `experiment_11` directory.
2. Compile the program:
   ```sh
   gcc cp.c -o cp.exe
   ```
3. Run the executable:
   ```sh
   ./cp.exe
   ```
4. Enter the expression (e.g., "a*b+x-y")
5. Provide constant values for each variable (a, b, x, y)
6. The program will display:
   - Postfix expression
   - Original three-address code
   - Three-address code after constant propagation
   - Final computed result

**Example:**
```
Input expression: a*b+x-y
Enter value of a: 5
Enter value of b: 3
Enter value of x: 10
Enter value of y: 2

Postfix Expression: ab*x+y-

Three Address Code:
t0 = a * b
t1 = t0 + x
t2 = t1 - y

After Constant Propagation:
t0 = 5 * 3
t1 = 15 + 10
t2 = 25 - 2

Final Result = 23
```

---

# Experiment 12

## Machine Code Generator (`mc.c`)

**Description:**  
A C program that generates assembly-like machine code from three-address code (intermediate representation). It translates each three-address instruction into a sequence of register-based assembly instructions using MOV (move), ADD (addition), SUB (subtraction), MUL (multiplication), and DIV (division) operations. This demonstrates the final code generation phase of a compiler.

**Code Generation Process:**
1. Reads three-address code statements (format: `result=operand1 operator operand2`)
2. For each statement, generates three assembly instructions:
   - MOV: Load first operand into register
   - Operation (ADD/SUB/MUL/DIV): Perform operation with second operand
   - MOV: Store result from register to variable

**Requirements:**  
- C compiler (gcc)
- User input: 
  - Number of three-address code statements
  - Three-address code statements in format: `t=a+b` (no spaces between operators)
- Supports: operators (+, -, *, /)
- Uses: Register allocation (R0, R1, R2, ...)

**How to Run:**
1. Navigate to the `experiment_12` directory.
2. Compile the program:
   ```sh
   gcc mc.c -o mc.exe
   ```
3. Run the executable:
   ```sh
   ./mc.exe
   ```
4. Enter the number of three-address code statements
5. Enter each statement in the format `result=arg1 op arg2` (e.g., `t=a+b`)
6. The program will display the generated assembly code

**Example:**
```
Input:
Enter the number of intermediate statements: 3
t=a+b
u=t*c
v=u-d

Output (Generated Assembly Code):
MOV R0,a
ADD R0,b
MOV t,R0
MOV R1,t
MUL R1,c
MOV u,R1
MOV R2,u
SUB R2,d
MOV v,R2
```

---