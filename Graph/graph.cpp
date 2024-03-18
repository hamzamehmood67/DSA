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
    Node **adjList;
    public:
        Graph(int v)
        {
            totalVertex=v;
            adjList= new Node*[totalVertex];

            for(int i=0; i<totalVertex; i++)
                adjList[i]=nullptr;
        }

        void addEdge(int src, int dest)
        {
            Node* newNode= new Node(dest);
            newNode->next=adjList[src];
            adjList[src]=newNode;

            //////For undirected graph.

            newNode= new Node(src);
            newNode->next= adjList[dest];
            adjList[dest]=newNode;
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
            cout<<"Src is "<<src<<endl;
            Node* srcNode=adjList[src];
            cout<<srcNode->data<<endl;
            for(int i=0; i<totalVertex; i++)
            {   
                Node* u=adjList[i];
                if(u!=srcNode)
                {
                    u->color="White";
                }
            }

            srcNode->color="Gray";
            queue<Node*> Q;

            Q.push(srcNode);

            while(!Q.empty())
            {
                Node * u=Q.front();
                Q.pop();
                Node *adjacent=adjList[u->data];
                while(adjacent)
                {
                    if(adjacent->color=="White")
                    {
                        adjacent->color="Gray";
                        cout<<adjacent->data;
                        Q.push(adjacent);
                    
                    }
                }

                u->color="Black";
            }

            
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