/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @param {number} x
 * @return {ListNode}
 */
var partition = function(head, x) {
    if(!head || head.next==null)
        return head;
    
    
    let top=head;
    let head1=null,tail1=null;
    let head2=null,tail2=null;
    
     function append(head,new_data)
    {
        
        var new_node = new ListNode(new_data);
        if (head == null)
        {
            //console.log(new_data);
            head = new ListNode(new_data);
            //console.log(head.next);
            return head;
        }
        new_node.next = null;
        var last = head; 
        while (last.next != null){
            //console.log(last.val);
            last = last.next;
            
        }

        last.next = new_node;
        return head;
    }
    
    
    while(top){
        const newNode = new ListNode(top.val);
      //  console.log(newNode.val +","+ newNode.next);
        if(top.val<x){
            head1=append(head1,top.val);
        }
        else if(top.val>=x){
            head2=append(head2,top.val);
        }
        top=top.next;
    }
    if(!head1)
        return head2;
    if(!head2)
        return head1;  
    head=head1;
    var last = head;
    while (last.next != null){
            last = last.next;
    }
    last.next = head2;
        return head;
    
};

