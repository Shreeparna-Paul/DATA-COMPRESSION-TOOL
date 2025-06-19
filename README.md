# DATA-COMPRESSION-TOOL

*COMPANY*: CODTECH IT SOLUTIONS

*NAME*: SHREEPARNA PAUL

*INTERN ID*: CT04DL1292

*DOMAIN*: C PROGRAMING

*DURATION*: 4 WEEKS

*MENTOR*: NEELA SANTOSH

**This repository delivers a clear, ANSI C implementation of a Run‑Length Encoding (RLE) compression and decompression tool built specifically to support multi‑line text files. RLE is a classic lossless compression method that replaces consecutive runs of identical characters with a single character followed by a count—ideal for text files or data streams with repetitive content 
csfieldguide.org.nz
+15
en.wikipedia.org
+15
cefns.nau.edu
+15
. The program includes two core functions: compressFile(...) reads the input file character by character via fgetc(), counts successive duplicates, and writes tokens of the form cN to the output. Newlines receive special treatment, encoded as \nN, ensuring that multiple consecutive newlines are preserved accurately in the output. When a different character appears—or the file ends—the count is flushed, and the process continues. The counterpart, decompressFile(...), uses fscanf() to read characters or the newline escape sequence along with their counts, then reconstructs the original sequence by writing the character or newline repeatedly based on the parsed count. The code handles edge cases like empty files and errors in file operations cleanly, providing user-friendly error messages.

Developed entirely with the C standard library (<stdio.h>, <stdlib.h>), the tool remains free from external dependencies, guaranteeing compatibility with GCC, Clang, and various platforms—from Linux and macOS to Windows. Editing and development can be conducted in any C-supporting environment—VS Code, Sublime Text, Vim, Code::Blocks, or CLion—with compilation via the command line. A simple build command such as gcc -std=c99 -o rle_tool rle_tool.c yields the executable. On running ./rle_tool, users are greeted with a menu for choosing compression or decompression, followed by prompts to specify input and output filenames, making usage straightforward for both interactive and scripted environments.

RLE’s simplicity belies its power: it operates in linear time (O(n)) with equally linear space complexity, making it an excellent demonstration of efficient algorithm design 
medium.com
. The approach is well-suited to files with long runs—common in plain text, formatted code, server logs, and configuration files—where the method can significantly reduce file size by collapsing repeated characters 
dev.to
+1
fastpix.io
+1
. Beyond teaching fundamental compression techniques, this program can serve as a groundwork for real-world utilities: compressing logs before archival or transmission, optimizing source code packages, or prepping response-heavy text files for bandwidth-limited networks.

Because newline characters are encoded and decoded correctly, the tool preserves file structure, which is crucial for multi-line configurations, code snippets, or documentation. While highly functional as-is, the codebase is ready for enhancements: support for binary files, multi-digit escape sequences, extended escape formats, or integration with entropy-based compression like Huffman or LZ77 could be added 
dev.to
+9
michaeldipperstein.github.io
+9
cefns.nau.edu
+9
. Error handling could be strengthened to detect malformed input, invalid counts, or unexpected EOFs. Designers might also strip out runs of length one to avoid expanding files with mixed data, following strategies discussed on StackOverflow 
dev.to
.

In sum, this repository is a compact, dependency‑free, and educational implementation of RLE in plain C. It is ideal for those learning compression algorithms, mastering file I/O, or building CLI utilities in C. Advanced users can safely build upon it—extending its format, adding performance optimizations, or integrating it into larger pipelines. Contributions and forks are encouraged: explore the foundations of data compression here, extend it, and share your enhancements!**

*OUTPUT PICTURE*:

![Image](https://github.com/user-attachments/assets/ee6e79e1-65c1-41e1-a3a2-479a63e3e9d3)
