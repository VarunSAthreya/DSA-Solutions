import java.util.Stack;

class MyQueue {
    Stack<Integer> enqueue;
    Stack<Integer> dequeue;

    /** Initialize your data structure here. */
    public MyQueue() {
        enqueue = new Stack<>();
        dequeue = new Stack<>();
    }

    /** Push element x to the back of queue. */
    public void push(int x) {
        enqueue.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop() {
        if (dequeue.isEmpty()) {
            fillDequeue();
        }
        return dequeue.pop();

    }

    /** Get the front element. */
    public int peek() {
        if (dequeue.isEmpty()) {
            fillDequeue();
        }
        return dequeue.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty() {
        return enqueue.isEmpty() && dequeue.isEmpty();
    }

    private void fillDequeue() {
        while (!enqueue.isEmpty()) {
            dequeue.push(enqueue.pop());
        }
    }
}

/**
 * Your MyQueue object will be instantiated and called as such: MyQueue obj =
 * new MyQueue(); obj.push(x); int param_2 = obj.pop(); int param_3 =
 * obj.peek(); boolean param_4 = obj.empty();
 */
