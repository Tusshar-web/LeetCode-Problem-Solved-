/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertNode(Node* head) {
        Node* temp= head;
        while(temp != NULL){
            Node* newNode = new  Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
    }

    void connectRandom(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* newNode = temp->next;
            if(temp->random) newNode->random = temp->random->next;
            else newNode->random = nullptr;
            temp = temp->next->next;
        }
    }

    Node* connectNext(Node* head){
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        Node* temp = head;
        while(temp != NULL){
            res->next = temp->next;
            temp->next = temp->next->next;
            res = res->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }
    Node* copyRandomList(Node* head) {
        insertNode(head);
        connectRandom(head);
        return connectNext(head);
    }
};