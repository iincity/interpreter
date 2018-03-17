#include <preetyprint.h>
#include <string.h>
#include <ast.h>
#include <stringbuffer.h>
static void PrintPretty(Tree *node, const char *indent, int root, int last);
static char *str_append(const char *str, const char *append);

void AstTree_prettyPrint(Tree *astTree)
{
    char *indent = ft_strdup("");
    PrintPretty(astTree, indent, 1, 1);
    free((void *)indent);
}

static void PrintPrettyToFile(Tree *node, const char *indent, int root, int last, FILE * fp);
void AstTree_prettyPrintToFile(Tree *astTree, FILE * fp)
{
    char *indent = ft_strdup("");
    PrintPrettyToFile(astTree, indent, 1, 1, fp);
    free((void *)indent);
}

static char *str_append(const char *str, const char *append)
{
    size_t newLen = strlen(str) + strlen(append) + 1;
    char *buf = malloc(sizeof(char) * newLen);
    buf[0] = '\0';
    sprintf(buf, "%s%s", str, append);
    return buf;
}

static void PrintPretty(Tree *node, const char *indent, int root, int last)
{
    printf("%s", indent);
    char *newIndent = NULL;
    if (last)
    {
        if (!root)
        {
            printf("└╴");
            newIndent = str_append(indent, "○○");
        }
        else
            newIndent = str_append(indent, "");
    }
    else
    {
        printf("├╴");
        newIndent = str_append(indent, "|○");
    }
    AstNode *astNode = (AstNode *)node->value;
    printf("%s\n", astNode->name);
    List *children = node->children;
    size_t count = List_count(children);
    for (int i = 0; i < count; i++)
    {
        void *child = List_at(children, i);
        PrintPretty(child, newIndent, 0, i == count - 1);
    }
    free((void *)newIndent);
}

static void PrintPrettyToFile(Tree *node, const char *indent, int root, int last, FILE * fp)
{
    fprintf(fp, "%s", indent);
    char *newIndent = NULL;
    if (last)
    {
        if (!root)
        {
            fprintf(fp, "└╴");
            newIndent = str_append(indent, "○○");
        }
        else
            newIndent = str_append(indent, "");
    }
    else
    {
        fprintf(fp, "├╴");
        newIndent = str_append(indent, "|○");
    }
    AstNode *astNode = (AstNode *)node->value;
    fprintf(fp, "%s\n", astNode->name);
    List *children = node->children;
    size_t count = List_count(children);
    for (int i = 0; i < count; i++)
    {
        void *child = List_at(children, i);
        PrintPrettyToFile(child, newIndent, 0, i == count - 1, fp);
    }
    free((void *)newIndent);
}