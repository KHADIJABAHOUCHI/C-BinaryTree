#include <iostream>
#include <string>
using namespace std;

// Structure de base pour un noeud de l'arbre binaire
struct Node {
    string data; // Valeur stockée dans le noeud
    Node* left; // Pointeur vers le sous-arbre gauche
    Node* right; // Pointeur vers le sous-arbre droit

    // Constructeur pour créer un nouveau noeud
    Node(string value) : data(value), left(nullptr), right(nullptr) {}
};

// Classe pour l'arbre binaire
class BinaryTree {
private:
    Node* root; // Racine de l'arbre

    // Fonction auxiliaire pour insérer un noeud de manière récursive
    Node* insertRecursive(Node* node, string value) {
        if (node == nullptr) {
            // Si le noeud actuel est vide, créer un nouveau noeud
            return new Node(value);
        }
        if (value < node->data) {
            // Insérer dans le sous-arbre gauche si la valeur est inférieure
            node->left = insertRecursive(node->left, value);
        }
        else {
            // Insérer dans le sous-arbre droit si la valeur est supérieure ou égale
            node->right = insertRecursive(node->right, value);
        }
        return node;
    }

    // Fonction auxiliaire pour afficher l'arbre en parcours infixe
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left); // Visite du sous-arbre gauche
            cout << node->data << " "; // Affichage de la valeur du noeud
            inorderTraversal(node->right); // Visite du sous-arbre droit
        }
    }

public:
    // Constructeur
    BinaryTree() : root(nullptr) {}

    // Fonction pour insérer une valeur dans l'arbre
    void insert(string value) {
        root = insertRecursive(root, value);
    }

    // Fonction pour afficher l'arbre en parcours infixe
    void displayInorder() {
        inorderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    // Insertion de chaînes de caractères dans l'arbre
    tree.insert("orange");
    tree.insert("apple");
    tree.insert("banana");
    tree.insert("grape");
    tree.insert("cherry");
    tree.insert("mango");
    tree.insert("peach");
    tree.insert("ECOLE");
    tree.insert("universitee");
    tree.insert("maison");
    tree.insert("fstm");

    // Affichage de l'arbre en parcours infixe
    cout << "Parcours infixe de l'arbre binaire : ";
    tree.displayInorder();

    return 0;
}
