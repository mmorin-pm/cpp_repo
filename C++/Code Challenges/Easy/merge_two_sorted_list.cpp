#include <iostream>

using namespace std;

//https://leetcode.com/problems/merge-two-sorted-lists/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
void print_list(ListNode *list);

int main(){

    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);


    cout << "Printing lists: " << endl;
    print_list(list1);
    print_list(list2);

    ListNode *result = mergeTwoLists(list1, list2);
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    if(l1 == nullptr and l2 == nullptr) return l1;
    if(l1 == nullptr) return l2;
    if(l2 == nullptr) return l1;


    ListNode l3(0);
    ListNode *previous = &l3; //lastest node added to new list
    // If previous pointer isn't set to something it make it really annoying to start off this while loop bellow
    // Doing it like above is nice because you can start looping and just return l3->next when you are done
    
    while(l1 != nullptr and l2 != nullptr){
        if(l1->val <= l2->val){
            previous->next = l1; //add l1 to list
            //previous = l1;       //update previous
            l1 = l1->next;       //increment l1
        }else{
            previous->next = l2; //add l2 to list
            //previous = l2;       //update previous
            l2 = l2->next;       //increment l2
        }
        previous = previous->next; // instead of updating previous once for each case, this is easier to read
    }
    
    // if(l1 != nullptr){
    //     previous->next = l1;
    // }
    // if(l2 != nullptr){
    //     previous->next = l2;
    // }
    // Simple version of the above 
    previous->next = (l1!=nullptr) ? l1 : l2;

    return l3.next;
}