/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode mergeKLists(ArrayList<ListNode> listNodes) {
        
        if (listNodes == null || listNodes.size() == 0) return null;
        Comparator<ListNode> comparator = new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                if (o1.val == o2.val) return 0;
                if (o1.val < o2.val) return -1;
                return 1;
            }
        };

        PriorityQueue<ListNode> priorityQueue = new PriorityQueue<ListNode>(listNodes.size(), comparator);
        for (ListNode listNode : listNodes) {
            if (listNode != null) priorityQueue.add(listNode);
        }

        ListNode dummy = new ListNode(Integer.MAX_VALUE);
        ListNode hedy = dummy;
        while (!priorityQueue.isEmpty()) {
            ListNode tmp = priorityQueue.poll();
            dummy.next = tmp;
            dummy = tmp;
            if (tmp.next != null) {
                priorityQueue.add(tmp.next);
            }
        }
        return hedy.next;
    }
}
