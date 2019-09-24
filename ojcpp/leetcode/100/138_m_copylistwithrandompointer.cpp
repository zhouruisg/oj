//
// Created by rui zhou on 2019-09-03.
//

/*
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.



Example 1:



Input:
{"$id":"1","next":{"$id":"2","next":null,"random":{"$ref":"2"},"val":2},"random":{"$ref":"2"},"val":1}

Explanation:
Node 1's value is 1, both of its next and random pointer points to Node 2.
Node 2's value is 2, its next pointer points to null and its random pointer points to itself.


Note:

You must return the copy of the given head as a reference to the cloned list.
 */

#include <codech/codech_def.h>
using namespace std;

namespace {

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

    class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (!head) return nullptr;
            std::deque<tuple<Node*,Node*,Node*>> todo{{head,nullptr,nullptr}};
            unordered_set<Node*> visited;
            
            Node*newHead = nullptr;
            while (!todo.empty()) {
                Node*node,*nextP,*randomP;
                std::tie(node,nextP,randomP) = todo.front();
                todo.pop_front();

                if (visited.find(node)!=visited.end()) {
                    continue;
                } else {
                    visited.insert(node);
                }



                Node *cloneNode= new Node(node->val,nullptr, nullptr);
                if (!newHead)
                    newHead = cloneNode;
                if (nextP) {
                    nextP->next = cloneNode;
                }
                if (randomP) {
                    randomP->random = cloneNode;
                }


                if (node->next) {
                    if (node->next == node) {
                        cloneNode->next = cloneNode;
                    } else {
                        todo.emplace_back(node->next,cloneNode,nullptr);
                    }
                }
                if (node->random) {
                    if (node->random == node) {
                        cloneNode->random = cloneNode;
                    } else {
                        todo.emplace_back(node->random, nullptr, cloneNode);
                    }
                }
            }
            return newHead;
        }
    };
}

DEFINE_CODE_TEST(138_copylistrandompointer_sum_root_leaf)
{
    Solution obj;
    {


    }
}
