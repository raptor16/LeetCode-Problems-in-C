tion for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode * sumNode = (struct ListNode * ) malloc (sizeof(struct ListNode));
    sumNode = NULL;
    //struct ListNode * temp = (struct ListNode *)malloc(sizeof(struct ListNode));
    //struct ListNode * last = NULL;
    int carry = 0;
    int sum;
    while (l1 != NULL && l2 != NULL){
        sum = l1->val + l2->val + carry;
        if (sum>=10){
            sum = sum%10;
            carry = 1;
        } else {
            carry = 0;
        }
        insertNodeLast (sum, &sumNode);
        l1 = l1->next;
        l2 = l2->next;
    } 
    if (l1 != NULL && l2 == NULL){
        while (l1 != NULL){
            sum = l1->val+carry;
            if (sum >=10){
                sum = sum%10;
                carry = 1;
            } else {
                carry = 0;
            }
            insertNodeLast(sum, &sumNode);
            l1 = l1->next;
        }
    } else if (l2 != NULL && l1 == NULL){
        while (l2 != NULL){
            sum = l2->val+ carry;
            if (sum >=10){
                sum = sum%10;
                carry = 1;
            } else {
                carry = 0;
            }
            insertNodeLast(sum, &sumNode);
            l2 = l2->next;
        }
    }
    if (carry == 1){
        insertNodeLast(carry, &sumNode);
        carry = 0;
    }

    return sumNode;
}

void insertNodeLast (int data, struct ListNode ** head)
{
    struct ListNode * currNode = *head;
    struct ListNode * newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = data;
    if (currNode == NULL){
        insertNodeFront(data, head);
        free(newNode);
    } else {
        while(currNode->next != NULL){
            currNode = currNode->next;
        } 
        newNode->next = currNode->next;
        currNode->next = newNode;
    }
}

void insertNodeFront(int data, struct ListNode ** head){
    struct ListNode * newNode = (struct ListNode *)malloc(sizeof(struct ListNode));    
    newNode->val = data;
    newNode->next = *head;
    
    *head = newNode;
}
