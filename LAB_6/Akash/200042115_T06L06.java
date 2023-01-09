import java.util.Scanner;


class BinarySearchTree
{
    static class Node
    {
        int key;
        Node left, right;
    }

    static Node newNode(int data)
    {
        Node node = new Node();

        node.key = data;

        node.left = null;
        node.right = null;

        return node;
    }




    static Node insert(Node root, int key)
    {
        // Create a new Node containing
        // the new element
        Node new_node = newNode(key);

        // Pointer to start traversing from root and
        // traverses downward path to search
        // where the new node to be inserted
        Node parent = root;

        // Pointer child maintains the trailing
        // pointer of parent
        Node child = null;

        while (parent != null)
        {
            child = parent;


            if (key < parent.key)
                parent = parent.left;

            else
                parent = parent.right;

        }



        // If the root is null i.e. the tree is empty
        // The new node is the root node
        if (child == null)
            child = new_node;

            // If the new key is less than the leaf node key
            // Assign the new node to be its left child
        else if (key < child.key)
            child.left = new_node;

            // else assign the new node its right child
        else
            child.right = new_node;


        // Returns the pointer where the
        // new node is inserted
        return child;
    }


    static void Inorder(Node root)
    {
        if (root == null)
            return;
        else
        {
            Inorder(root.left);
            System.out.print(root.key + " ");
            Inorder(root.right);
        }

    }


    static void GetMaximumNumberInPath(Node root, int root_value, int y)
    {
        Node temp = root;
        int answer = 0;

        if(y <= root_value)
        {
            answer = y;
        }

        else if( y > root_value )
        {
            answer = y;

            while (temp.key != y)      // temp has the root
            {
                if( temp.key > answer )
                {
                    answer = temp.key;
                }

                if (y < temp.key)
                    temp = temp.left;

                else
                    temp = temp.right;

            }
        }

        System.out.println(answer);
    }



    public static void main(String args[])
    {
        Scanner input = new Scanner(System.in);

        int n, i=0;

        Node root = null;

        while( (n = input.nextInt()) != -1 )
        {
            if(i==0)
            {
                root = insert(root, n);
                i++;
            }

            else
            {
                insert(root, n);
            }

        }


        Inorder(root);


        int testcases = input.nextInt();
        int root_value = root.key;


        for(int j=0 ; j < testcases ; j++)
        {
            int x = input.nextInt(), y = input.nextInt();

            GetMaximumNumberInPath(root, root_value, y);
        }



    }

}


//   50 75 25 29 45 60 10 80 -1