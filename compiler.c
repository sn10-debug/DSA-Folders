#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char *op; // Operation
    int arg1; // First argument's node index
    int arg2; // Second argument's node index
} ThreeAddressCode;

// Simple utility function to write the dot file
void write_dot_file(ThreeAddressCode *instructions, int num_instructions, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (!fp)
    {
        perror("Error opening file");
        return;
    }

    fprintf(fp, "digraph G {\n");

    // Creating graph nodes
    for (int i = 0; i < num_instructions; ++i)
    {
        if (instructions[i].op)
        {
            fprintf(fp, "    t%d [label=\"%s\"];\n", i, instructions[i].op);
        }
    }

    // Creating graph edges
    for (int i = 0; i < num_instructions; ++i)
    {
        if (instructions[i].arg1 != -1)
        {
            fprintf(fp, "    t%d -> t%d;\n", instructions[i].arg1, i);
        }
        if (instructions[i].arg2 != -1)
        {
            fprintf(fp, "    t%d -> t%d;\n", instructions[i].arg2, i);
        }
    }

    // End of dot file      fprintf(fp, "}\n");
    fclose(fp);
}

// Function to execute a system command
void execute_command(const char *cmd)
{
    system(cmd);
}

int main()
{
    // Generate three-address code for the expression a = b* - c + b* - c
    ThreeAddressCode instructions[5];
    instructions[0] = (ThreeAddressCode){"b * -c", 0, -1}; // t0 = b * -c
    instructions[1] = (ThreeAddressCode){"b * -c", 1, -1}; // t1 = b * -c (repeated)
    instructions[2] = (ThreeAddressCode){"t0 + t1", 0, 1}; // t2 = t0 + t1
    instructions[3] = (ThreeAddressCode){"a = t2", 2, -1}; // a = t2
                                                           // Write the dot file
    write_dot_file(instructions, 4, "dag.dot");
    // Execute the dot command to create the DAG image
    // execute_command("dot -Tpng dag.dot -o dag.png");
    printf("DAG has been generated as 'dag.png'\n");
    return 0;
}
