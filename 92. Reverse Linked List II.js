/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} left
 * @param {number} right
 * @return {ListNode}
 */
var reverseBetween = function(head, left, right) {
    if(!head) return;
    if(head.next==null) return head;
    
    let newStart=head;
    let storeStart=null
    
    for(i=1;i<left;i++)
    {   storeStart=newStart;
        newStart=newStart.next;      
    }
    
    let end=head;
    let endnext=head.next;
    
    for(i=1;i<right;i++)
    {   end=end.next;
    }
    
    endnext=end.next;      
    
    function reverse(node) {
    var prev = null;
    var current = node;
    var next = null;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        node = prev;
        return node;
    }
    //console.log(storeStart.val +","+newStart.val+","+end.val+","+endnext.val);
    end.next=null;
    
    if(left==1)
    head=reverse(newStart);
    else
    storeStart.next=reverse(newStart);
    
    end=head;
    
    for(i=1;i<right;i++)
    {   end=end.next;
    }
    end.next=endnext;
    return head;
    //for(let i=this.head;curr;i=i.next)    
};