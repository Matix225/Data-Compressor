# Data Compression Tool in C++

## Overview

This project is a C++ implementation of lossless data compression algorithms, focusing on **Huffman Coding** and **LZ77**. The goal is to explore fundamental concepts in data compression, memory management, and algorithm optimization.

The program reads input data from a file, analyzes its structure, and applies a selected compression algorithm to reduce its size without losing information.

---

## Features

* File-based input (supports text and binary data)
* Implementation of:

  * Huffman Coding (frequency-based compression)
  * LZ77 (sliding window compression)
* Custom-built data structures:

  * Priority queue (min-heap) for Huffman tree construction
* Frequency analysis of input data
* Modular design for easy extension and testing

---

## Algorithms

### Huffman Coding

Huffman coding is a variable-length encoding algorithm that assigns shorter codes to more frequent symbols and longer codes to less frequent ones.

Steps:

1. Count frequency of each symbol
2. Build a priority queue (min-heap)
3. Construct a binary tree by merging the two least frequent nodes
4. Generate binary codes from the tree

---

### LZ77 (in progress)

LZ77 compresses data by replacing repeated sequences with references to previous occurrences.

Concept:

* Uses a sliding window over the data
* Encodes repeated patterns as (offset, length, next character)

---

## Project Structure

* `main.cpp` – program entry point, handles file input
* `huffman.cpp / huffman.h` – Huffman algorithm implementation
* `lz77.cpp / lz77.h` – LZ77 implementation

---

##  How It Works

1. User provides a file name via console
2. Program reads the file and analyzes its contents
3. User selects compression algorithm (or it is chosen automatically)
4. Data is compressed and saved to an output file

---

## Example Usage

```
Enter file name: input.txt
Choose algorithm:
1. Huffman
2. LZ77
```

Output:

```
Compression completed successfully.
Output file: input.huff
```

---
##  Requirements

* C++ compiler supporting C++11 or newer
* Standard libraries (`<iostream>`, `<fstream>`, `<map>`, etc.)

---

##  License

This project is open-source and free to use for educational purposes.
