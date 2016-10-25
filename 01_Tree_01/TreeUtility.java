package TreeTest;

public class TreeUtility {
	public static int MaxDepth(Node node){
		int leftDepth = 0;
		int rightDepth = 0;
		
		if(node.getLeft() != null){
			leftDepth = MaxDepth(node.getLeft());
		}
		
		if(node.getRight() != null){
			rightDepth = MaxDepth(node.getRight());
		}
		
		if(leftDepth >= rightDepth){
			return leftDepth + 1;
		}else{
			return rightDepth + 1;
		}	
	}
	
	public static void Preorder_Recursive(Node node){
		Node left = node.getLeft();
		Node right = node.getRight();
		System.out.print(node.getValue() + " ");
		
		if(left != null){
			Preorder_Recursive(left);
		}
		
		if(right != null){
			Preorder_Recursive(right);
		}
	}
}
