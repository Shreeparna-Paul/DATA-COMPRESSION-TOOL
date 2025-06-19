#include <stdio.h>
#include <stdlib.h>

// Compress function
void compressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int prev = fgetc(in);
    if (prev == EOF) {
        fclose(in);
        fclose(out);
        return;
    }

    int count = 1;
    int curr;

    while ((curr = fgetc(in)) != EOF) {
        if (curr == prev) {
            count++;
        } else {
            // Write character and count
            if (prev == '\n')
                fprintf(out, "\\n%d", count);  // special handling for newlines
            else
                fprintf(out, "%c%d", prev, count);
            prev = curr;
            count = 1;
        }
    }

    // Final write
    if (prev == '\n')
        fprintf(out, "\\n%d", count);
    else
        fprintf(out, "%c%d", prev, count);

    fclose(in);
    fclose(out);
    printf("File compressed successfully with multi-line support.\n");
}

// Decompress function
void decompressFile(const char *inputFile, const char *outputFile) {
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    if (in == NULL || out == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char ch;
    int count;

    while (!feof(in)) {
        ch = fgetc(in);

        if (ch == '\\') {
            // Possibly a newline marker
            if ((ch = fgetc(in)) == 'n') {
                fscanf(in, "%d", &count);
                for (int i = 0; i < count; i++)
                    fputc('\n', out);
            }
        } else if (ch != EOF) {
            fscanf(in, "%d", &count);
            for (int i = 0; i < count; i++)
                fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    printf("File decompressed successfully with multi-line support.\n");
}

// Main program
int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("Run-Length Encoding Tool (Multi-line Text Support)\n");
    printf("1. Compress file\n");
    printf("2. Decompress file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFile);
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    if (choice == 1) {
        compressFile(inputFile, outputFile);
    } else if (choice == 2) {
        decompressFile(inputFile, outputFile);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
