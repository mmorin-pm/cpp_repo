#include <iostream>
#include <vector>
#include <set>

 struct ListNode {
     int data;
     ListNode *next;
     ListNode() : data(0), next(nullptr) {}
     ListNode(int x) : data(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : data(x), next(next) {}
 };

ListNode* createLinkedList(std::vector<int> nums){
    ListNode* head = new ListNode();
    ListNode* current = head;
    for(int n : nums){
        current->next = new ListNode(n);
        current = current->next;
    }
    return head->next;
}

void displayLinkedList(ListNode* list){
    ListNode* index = list;
    while(index){
        std::cout << "[" << index->data << "]";
        if(index->next != nullptr)
            std::cout << "-->"; 
        index = index->next;
    }
}

//Write code that removes duplicates from a linkedList

//This take O(n) time but requires additional memory
ListNode* removeDups(ListNode* list){
    if(!list->next)
        return list;
    std::set<int> tracker = {list->data};
    ListNode* index = list;
    while(index){
        if(tracker.find(index->next->data) != tracker.end()){
            index->next = index->next->next;
        }else{
            tracker.insert(index->next->data);
        }
        index = index->next;
    }
    return list;
}

//This takes O(n^2) time but does not require any additional memory
ListNode* removeDups2(ListNode* list){
    ListNode* index = list;
    ListNode* increment = index;

    while(index){//while we are not on last element
        while(increment->next){
            if(increment->next->data == index->data)
                increment->next = increment->next->next;
            else
                increment = increment->next;
        }
        index = index->next;
        increment = index;
    }
    return list;
}


int main(){

    std::vector<int> vec = {9,9,8,7,6,5,4,3,2,1,1};
    ListNode* list = createLinkedList(vec);
    removeDups2(list);
    displayLinkedList(list);

}