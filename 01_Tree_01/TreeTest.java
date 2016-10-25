package TreeTest;

public class TreeTest {
	
	private static void Problem1_TreeDepth(){
		Node A = new Node(0);
		Node B = new Node(0);
		Node C = new Node(0);
		Node D = new Node(0);
		Node E = new Node(0);
		Node F = new Node(0);
		Node G = new Node(0);
		Node H = new Node(0);
		
		A.setLeft(B);
		A.setRight(C);
		C.setLeft(D);
		C.setRight(E);
		D.setLeft(F);
		D.setRight(G);
		E.setRight(H);
		
		System.out.println(TreeUtility.MaxDepth(A));
	}
	
	private static void Problem2_Preorder(){
		Node A = new Node(100);
		Node B = new Node(50);
		Node C = new Node(150);
		Node D = new Node(25);
		Node E = new Node(75);
		Node F = new Node(125);
		Node G = new Node(175);
		Node H = new Node(110);
		
		A.setLeft(B);
		A.setRight(C);
		B.setLeft(D);
		B.setRight(E);
		C.setLeft(F);
		C.setRight(G);
		F.setLeft(H);
		
		TreeUtility.Preorder_Recursive(A);
		System.out.println("");
	}
	
	private static void Preblem1_Preorder_Nonrecursive(){
		Node A = new Node(100);
		Node B = new Node(50);
		Node C = new Node(150);
		Node D = new Node(25);
		Node E = new Node(75);
		Node F = new Node(125);
		Node G = new Node(175);
		Node H = new Node(110);
		
		A.setLeft(B);
		A.setRight(C);
		B.setLeft(D);
		B.setRight(E);
		C.setLeft(F);
		C.setRight(G);
		F.setLeft(H);		
		
		
		Stack<Node> stack = new Stack<Node>();
		
		stack.Push(A);
		while(stack.isEmpty() == false){
			Node currentNode = stack.Pop();
			
			System.out.print(currentNode.getValue() + " " );
			Node left = currentNode.getLeft();
			Node right = currentNode.getRight();
			
			if(right != null){
				stack.Push(right);
			}
			if(left != null){
				stack.Push(left);
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		Problem1_TreeDepth();
		Problem2_Preorder();
		Preblem1_Preorder_Nonrecursive();
		
	}

}
