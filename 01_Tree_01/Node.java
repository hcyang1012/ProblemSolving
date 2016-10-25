package TreeTest;

public class Node <T>{
	private T value;
	private Node<T> left;
	private Node<T> right;
	public T  getValue(){
		return value;
	}
	public Node(T value){
		this.value = value;
		left = null;
		right = null;
	}
	
	public void setLeft(Node<T> left){this.left = left;}
	public void setRight(Node<T> right){this.right = right;}
	
	public Node<T> getLeft(){return left;}
	public Node<T> getRight(){return right;}
	
}

