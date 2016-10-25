package TreeTest;

import java.util.ArrayList;
import java.util.List;

public class Stack<T> {
	List<Node<T>> stack;
	
	public Stack(){
		stack = new ArrayList<>();
	}
	
	public void Push(Node<T> node){
		stack.add(node);
	}
	
	public boolean isEmpty(){
		return stack.size() == 0;
	}
	
	public Node<T> Pop(){
		Node<T> target = stack.get(stack.size() - 1);
		stack.remove(stack.size() - 1);
		return target;
	}

}
