#include <iostream>
#include <queue>
#include<string>
using namespace std;


class Node{
  public:
      int data;
    string color;
    Node* next;
        Node(int val)
        {
            data=val;
            next=nullptr;
            color=" ";
        }
};

class Graph{
    int totalVertex;
    Node *vertices;
    Node **adjList;
    public:
        Graph(int v)
        {
            totalVertex=v;
            adjList= new Node*[totalVertex];
            vertice= new Node[totalVertex];

            for(int i=0; i<totalVertex; i++)
                adjList[i]=nullptr;
                vertice[i]=0; 
        }

        void addEdge(int src, int dest)
        {
            Node* newNode= new Node(dest);
            newNode->next=adjList[src];
            adjList[src]=newNode;

            //////For undirected graph.

           // newNode= new Node(src);
            //newNode->next= adjList[dest];
           // adjList[dest]=newNode;
        }

        void printList(){
            for(int i=0; i<totalVertex; i++)
            {
                Node *temp= adjList[i];
                cout<<i<<"=";
                while(temp)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
                cout<<endl;
            }
        }

        void BFS(int src)
        {
            
        }

};

int main()
{

    Graph obj(6);
    obj.addEdge( 1,2);
    obj.addEdge(1, 5);
    obj.addEdge(2,5);
    obj.addEdge(2,4);
    obj.addEdge(2,3);
    obj.addEdge(3,4);
    obj.addEdge(4,5);

    obj.printList();
    cout<<"BFS of Graph is given as: "<<endl;
    obj.BFS(1);
    return 0;
}