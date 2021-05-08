#include <iostream>

using namespace std;

//https://leetcode.com/problems/add-two-numbers/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
void print_list(ListNode *list);

int main(){

    ListNode *list1 = new ListNode(9);
    list1->next = new ListNode(9);
    list1->next->next = new ListNode(9);
    list1->next->next->next = new ListNode(9);
    list1->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next = new ListNode(9);
    list1->next->next->next->next->next->next = new ListNode(9);

    ListNode *list2 = new ListNode(9);
    list2->next = new ListNode(9);
    list2->next->next = new ListNode(9);
    list2->next->next->next = new ListNode(9);

    cout << "Printing lists: " << endl;
    print_list(list1);
    print_list(list2);

    ListNode *result = addTwoNumbers(list1, list2);
    print_list(result);

    return 0;
}

void print_list(ListNode *list){
    ListNode *list_it = list;
    while(list_it != nullptr){
        cout << "[" << list_it->val << "] ";
        list_it = list_it->next;
    }
    cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *list_it = nullptr; // used to iterate through new list
    ListNode *starting_node = nullptr; // what we will be returning
    
    int sum = 0;
    int carry_over = 0;
    int first = 1;
    
    while(l1 != nullptr or l2 != nullptr or carry_over != 0){
        ListNode *new_node = new ListNode();
        
        if (l1 == nullptr and l2 == nullptr){
            sum = carry_over;
        }else {
            if(l2 == nullptr){
                sum = l1->val + carry_over;
                l1 = l1->next;
            }else { 
                if(l1 == nullptr){
                    sum = l2->val + carry_over;
                    l2 = l2->next;
                }else {
                    sum = l1->val + l2->val + carry_over;
                    l1 = l1->next;
                    l2 = l2->next;
                }
            }
        }
        
        if(sum > 9){
            sum = sum%10;
            carry_over = 1;
        }else{
            carry_over = 0;
        }
        
        new_node->val = sum;
        if(first == 1){
            starting_node = new_node;
            list_it = new_node;
            first--;
        }else {   
            list_it->next = new_node;
            list_it = list_it->next;
        }

    }
    
    return starting_node;
}