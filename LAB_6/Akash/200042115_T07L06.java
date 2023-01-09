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

        int flag = 1;

        while (parent != null)
        {
            child = parent;

            if( key >= parent.key-3  &&  key <= parent.key+3)
            {
                flag = 0;
                break;
            }

            else
            {
                if (key < parent.key)
                    parent = parent.left;

                else
                    parent = parent.right;
            }

        }


        if(flag == 1)
        {
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
        }


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


    /* Compute the "height" of a tree -- the number of nodes along the longest path from the root node
       down to the farthest leaf node.*/
    static int height(Node root)
    {
        if (root == null)
            return 0;
        else
        {
            /* compute  height of each subtree */
            int left_height = height(root.left);
            int right_height = height(root.right);

            /* use the larger one */
            if (left_height > right_height)
                return (left_height + 1);
            else
                return (right_height + 1);
        }
    }

    /*  function to print level order traversal of tree  */
    static void printLevelOrder(Node root)
    {
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++)
        {
            printCurrentLevel(root, i);
            System.out.print("\n");
        }

    }


    /* Print nodes at the current level */
    static void printCurrentLevel(Node root, int level)
    {
        if (root == null)
            return;
        if (level == 1)
            System.out.print(root.key + " ");
        else if (level > 1) {
            printCurrentLevel(root.left, level - 1);
            printCurrentLevel(root.right, level - 1);
        }
    }


    static Node DeleteNode(Node root, int key)
    {
        /* Base Case: If the tree is empty */
        if (root == null)
            return root;

        /* Otherwise, recur down the tree */
        if (key < root.key)
            root.left = DeleteNode(root.left, key);
        else if (key > root.key)
            root.right = DeleteNode(root.right, key);


        // if key is same as root's key, then This is the node to be deleted
        else
        {
            // node with only one child or no child
            if (root.right == null)
                return root.left;
            else if(root.left == null )
                return root.right;

            // node with two children: Get the inorder successor (smallest in the right subtree)
            root.key = GetSuccessor(root.right);    // replacing the root.key with its successor

            // Delete the inorder successor
            root.right = DeleteNode(root.right, root.key);  // root.key is the successor
            // replacing the root.right with a sub root tree without the successor
        }

        return root;
    }

    static int GetSuccessor(Node root)
    {
        int value = root.key;
        while (root.left != null)     // trying to find the leftmost node of the subtree
        {
            root = root.left;
            value = root.key;
        }
        return value;
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


        // Print inorder traversal of the BST
        Inorder(root);

        System.out.print("\n");

        printLevelOrder(root);


        int testcases = input.nextInt();

        for(int j=0 ; j<testcases ; j++)
        {
            int key = input.nextInt();

            DeleteNode(root, key);

            printLevelOrder(root);
        }



    }

}


// 50 75 53 25 60 29 45 42 28 10 -1

// 50 75 25 29 45 60 90 10 80 100 84 88 -1