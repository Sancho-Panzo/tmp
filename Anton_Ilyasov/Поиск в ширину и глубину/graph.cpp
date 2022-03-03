#include <iostream>
#include "graph.h"
using namespace std;
#include <queue> // �������
#include <stack> // ����

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjMatrix = new bool* [numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new bool[numVertices];
        for (int j = 0; j < numVertices; j++)
            adjMatrix[i][j] = false;
    }
}

Graph::Graph(int numVertices, string type) {
    //srand(time(NULL));
    this->numVertices = numVertices;
    adjMatrix = new bool* [numVertices];
    for (int i = 0; i < numVertices; i++) {
        adjMatrix[i] = new bool[numVertices];
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = rand() % 2;
        }
    }
}

void Graph::addEdge(int i, int j) {
    adjMatrix[i][j] = true;
    adjMatrix[j][i] = true;
}

void Graph::removeEdge(int i, int j) {
    adjMatrix[i][j] = false;
    adjMatrix[j][i] = false;
}

bool Graph::isEdge(int i, int j) {
    return adjMatrix[i][j];
}

void Graph::toString() {
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}

void Graph::bfs_search() {
    cout << endl;
    int* nodes = new int[numVertices]; // ������� ����� (0 - ��� ������� �� �����������)
    for (int i = 0; i < numVertices; i++) {
        nodes[i] = 0;
    }

    queue<int> Queue;
    Queue.push(0); // �������� � ������� ������ �������
    while (!Queue.empty()) // ���� ������� �� �����
    {
        int node = Queue.front(); // ��������� �������
        Queue.pop();
        nodes[node] = 2; // �������� �� ��� ����������
        for (int j = 0; j < numVertices; j++) { // ��������� ��� ��� ��� ������� �������
            if (adjMatrix[node][j] == true && nodes[j] == 0) { // ���� ������� ������� � �� ����������
                Queue.push(j); // ��������� �� � �������
                nodes[j] = 1; // �������� ������� ��� ������������
            }
        }
        //cout << node << " "; // ������� ����� �������
    }
    delete[] nodes;
    nodes = nullptr;
}

void Graph::dfs_search() {
    cout << endl;
    int* nodes = new int[numVertices]; // ������� ����� (0 - ��� ������� �� �����������)
    for (int i = 0; i < numVertices; i++) {
        nodes[i] = 0;
    }

    stack<int> Stack;
    Stack.push(0); // �������� � ������� ������ �������
    while (!Stack.empty()) {
        int node = Stack.top(); // ��������� �������
        Stack.pop();
        if (nodes[node] == 2) continue;
        nodes[node] = 2; // �������� �� ��� ����������
        for (int j = numVertices - 1; j >= 0; j--) { // ��������� ��� ��� ��� ������� �������
            if (adjMatrix[node][j] == true && nodes[j] != 2) { // ���� ������� ������� � �� ����������
                Stack.push(j); // ��������� �� � c���
                nodes[j] = 1; // �������� ������� ��� ������������
            }
        }
        //cout << node << " "; // ������� ����� �������
    }
    delete[] nodes;
    nodes = nullptr;
}

Graph::~Graph() {
    for (int i = 0; i < numVertices; i++)
        delete[] adjMatrix[i];
    delete[] adjMatrix;
    adjMatrix = nullptr;
}



