#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char firstname[50];
    struct Node* father;
    struct Node* mother;
    struct Node* marriedto;
} Node;

Node* createNode(const char* firstname) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Грешка при заделяне на памет!\n");
        exit(1);
    }
    strcpy(newNode->firstname, firstname);
    newNode->father = NULL;
    newNode->mother = NULL;
    newNode->marriedto = NULL;
    return newNode;
}

void addParents(Node* child, Node* father, Node* mother) {
    child->father = father;
    child->mother = mother;
}

void addSpouse(Node* person, Node* spouse) {
    person->marriedto = spouse;
    spouse->marriedto = person;
}

void printTree(Node* root, int level) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    printf("%s\n", root->firstname);

    printTree(root->father, level + 1);
    printTree(root->mother, level + 1);
}

int main() {
    // Създаване на родословното дърво
    Node* grandfather = createNode("Иван");
    Node* grandmother = createNode("Мария");
    Node* father = createNode("Петър");
    Node* mother = createNode("Елена");
    Node* child = createNode("Ивайло");
    Node* spouse = createNode("Милена");

    addParents(father, grandfather, grandmother);
    addParents(mother, NULL, NULL);
    addParents(child, father, mother);

    addSpouse(father, mother);
    addSpouse(child, spouse);

    printf("Родословно дърво:\n");
    printTree(child, 0);

    free(grandfather);
    free(grandmother);
    free(father);
    free(mother);
    free(child);
    free(spouse);

    return 0;
}

int main() {
    Cause cause1 = {
       .title = "testo",
       .description = "nesto",
       .date = {1, 1, 2022, 10, 30},
       .people = {
            {"dedo", "dedo@example.com", "1234567890"},
            {"kalata", "kalata@example.com", "0987654321"}
        },
       .num_people = 2
    };

    print_cause(cause1);
}