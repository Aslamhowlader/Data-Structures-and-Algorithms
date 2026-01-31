#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
};

struct MinHeap {
    Node* arr[100];
    int size;

    MinHeap() { size = 0; }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void insert(Node* node) {
        arr[size] = node;
        int i = size;
        size++;
        while (i != 0 && arr[parent(i)]->freq > arr[i]->freq) {
            Node* temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;
            i = parent(i);
        }
    }

    Node* extractMin() {
        Node* temp = arr[0];
        arr[0] = arr[size - 1];
        size--;
        heapify(0);
        return temp;
    }

    void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < size && arr[l]->freq < arr[smallest]->freq) smallest = l;
        if (r < size && arr[r]->freq < arr[smallest]->freq) smallest = r;
        if (smallest != i) {
            Node* temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            heapify(smallest);
        }
    }
};

void generateCodes(Node* root, char codes[100][100], char chars[100], int n, char code[], int top) {
    if (!root) return;

    if (root->left) {
        code[top] = '0';
        generateCodes(root->left, codes, chars, n, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        generateCodes(root->right, codes, chars, n, code, top + 1);
    }

    if (!root->left && !root->right) {
        code[top] = '\0';
        for (int i = 0; i < n; i++) {
            if (chars[i] == root->data) {
                strcpy(codes[i], code);
                break;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char chars[100];
    int freq[100];
    char codes[100][100];

    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) cin >> chars[i];

    cout << "Enter their frequencies:\n";
    for (int i = 0; i < n; i++) cin >> freq[i];

    MinHeap heap;

    for (int i = 0; i < n; i++) {
        Node* node = new Node;
        node->data = chars[i];
        node->freq = freq[i];
        node->left = node->right = NULL;
        heap.insert(node);
    }

    while (heap.size > 1) {
        Node* left = heap.extractMin();
        Node* right = heap.extractMin();
        Node* newNode = new Node;
        newNode->data = '$';
        newNode->freq = left->freq + right->freq;
        newNode->left = left;
        newNode->right = right;

        heap.insert(newNode);
    }

    Node* root = heap.extractMin();

    char code[100];
    generateCodes(root, codes, chars, n, code, 0);

    cout << "\nHuffman Codes:\n";
    for (int i = 0; i < n; i++) {
        cout << chars[i] << ": " << codes[i] << endl;
    }

    int totalBits = 0;
    for (int i = 0; i < n; i++) {
        totalBits += freq[i] * strlen(codes[i]);
    }
    cout << "\nTotal bits required to encode the message: " << totalBits << endl;

    return 0;
}
