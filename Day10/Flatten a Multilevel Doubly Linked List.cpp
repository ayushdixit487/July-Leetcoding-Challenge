/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* root) {
        stack<Node*> nodes;
        Node* temp=root;
        while(temp)
        {
            if(temp->child)
            {
                if(temp->next)
                    nodes.push(temp->next);
                temp->next=temp->child;
                temp->child->prev=temp;
                temp->child=NULL;
                temp=temp->next;
            }
            else
            {
                if(!temp->next && !nodes.empty())
                {
                    temp->next=nodes.top();
                    temp->next->prev=temp;
                    temp=temp->next;
                    nodes.pop();
                }
                else
                {
                    temp=temp->next;
                }
            }
        }
        return root;
    }
};
