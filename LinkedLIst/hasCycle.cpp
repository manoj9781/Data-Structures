class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* s=head;         
        ListNode* f=head;
        while(f!=NULL)
        {
            s=s->next;
            f=f->next;
            if(f)
                f=f->next;
            if(s==f && s!=NULL)
                return true;

        }
        return false;
    }
};