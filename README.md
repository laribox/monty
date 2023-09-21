# 0x19. C - Stacks, Queues - LIFO, FIFO

## Description

This is a C-based interpreter for Monty ByteCode files, developed as part of a CGroup project. Monty is a scripting language that relies on a unique stack with specific instructions to manipulate it.

## Table of Contents

- [0x19. C - Stacks, Queues - LIFO, FIFO](#0x19-c---stacks-queues---lifo-fifo)
  - [Description](#description)
  - [Table of Contents](#table-of-contents)
  - [General Information](#general-information)
  - [Project Description](#project-description)
    - [Monty ByteCode Files](#monty-bytecode-files)

## General Information

This project aims to create an interpreter for Monty ByteCode files, allowing users to execute Monty scripts using a custom stack data structure.

## Project Description

### Monty ByteCode Files

Monty ByteCode files are text files containing Monty instructions, typically with a `.m` extension. Each instruction is on a separate line, and there can be any number of spaces before or after the opcode and its argument.

Example Monty ByteCode file (`example.m`):

```plaintext
push 0
push 1
pop
pall
```
