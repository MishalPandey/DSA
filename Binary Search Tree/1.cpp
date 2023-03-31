#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

class Node{
        public:
            int data;
            Node* left = NULL;
            Node* right = NULL;

            Node(int data, Node* left, Node* right){
            	this->data = data;
            	this->left = left;
            	this->right = right;
            }

};



Node* Construct(int arr[], int low, int high)
{

		if(high<low)
		{
			return nullptr;
		}

		int mid = (low + high)/2;
		int data = arr[mid];

		Node* left_child = Construct(arr, low, mid-1);
		Node* right_child = Construct(arr, mid+1, high);

		Node* node = new Node(data, left_child, right_child);

		return node;

}

void Display(Node* node)
{


	if(node== nullptr)
	{
		return;
	}
	string str="";
	str += node->left != nullptr ? to_string(node->left->data) : ".";

	str += " <- " + to_string(node->data)+ " -> ";

	str += node->right != nullptr ? to_string(node->right->data) : ".";

	cout<<str<<nl;

	Display(node->left);
	Display(node->right);
}

int Size(Node* node)
{

		if(node== nullptr)
		{
			return 0;
		}

		int left_sz = Size(node->left);
		int right_sz =  Size(node->right);
		int total_sz = left_sz + right_sz + 1;

		return total_sz;


}


int Sum(Node* node)
{

		if(node== nullptr)
		{
			return 0;
		}

		int left_sum = Sum(node->left);
		int right_sum =  Sum(node->right);
		int total_sum = left_sum + right_sum + node->data;

		return total_sum;
		
}

int max(Node* node)
{
	if(node->right != nullptr)
		return max(node->right);
	else
		return node->data;
	

}
int min(Node* node)
{
	if(node->left != nullptr)
		return min(node->left);
	else
		return node->data;
	

}

bool find(Node* node, int x)
{
	//logn T.C
	if(node == nullptr)
		return false;
	else if(node->data==x)
		return true;
	else if(node->data < x)
		return find(node->right, x);
	else 
		return find(node->left, x);
}

Node* add_node(Node* node, int x)
{
		if(node== nullptr)
		{
			Node* nnode= new Node(x, nullptr, nullptr);
			return nnode;

		}

		else if(x > node->data)
		{
			node->right = add_node(node->right,  x);

		}
		else if(x < node->data)
		{
			
			node->left = add_node(node->left,  x);


		}
		else{
			//nothing to do
		}


	return node;


}

Node* remove_node(Node* node, int x)
{
		if(node== nullptr)
			return nullptr;

		if(x > node->data)
		{
			node->right = remove_node(node->right, x);
		}
		else if(x < node->data)
		{
			node->left = remove_node(node->left, x);
		}
		else
		{
				//work
				if(node->left != nullptr && node->right != nullptr)
				{
					int left_max = max(node->left);
					node->data = left_max;
					node->left = remove_node(node->left, left_max);

					return node;

				}
				else if(node->left != nullptr)
				{
					return node->left;
				}
				else if(node->right != nullptr)
				{
					return node->right;

				}
				else{
					return nullptr;
				}
		}
		return node;

}

int sum=0;

void replace_sum_of_larger_in_BST(Node* node)
{

		if(node==nullptr)
			return;

		replace_sum_of_larger_in_BST(node->right);
		//in order
		int od = node->data;
		node->data = sum;
		sum+= od;
		replace_sum_of_larger_in_BST(node->left);


}

Node* LCA(Node* node, int n1, int n2)
{
		
		if(node->data > n1 && node->data > n2)
		{
			return LCA(node->left , n1, n2);
		}
		else if(node->data < n1 && node->data < n2)
		{
			return LCA(node->right , n1, n2);
		}
		else{
			return node;

		}

	return node;
}

void print_in_range(Node* node, int d1, int d2)
{

	if(node == nullptr)
		return;

		if(node->data > d1 && node->data > d2)
		{
			print_in_range(node->left , d1, d2);
		}
		else if(node->data < d1 && node->data < d2)
		{
			print_in_range(node->right , d1, d2);
		}
		else{
			print_in_range(node->left , d1, d2);
			//in order
			cout<<node->data<<" ";
			print_in_range(node->right , d1, d2);

		}


}

void target_sum_pair(Node* root, Node* node, int tar_sum)
{
	//T.C {O(nlogn)} , S.C {O(height of tree)} //kyuki stack me maximum height of tree jitne log bhar jayenge
						//ek time pe then remove honge apne aap toh overall S.C = O(height)
	if(node== nullptr)
		return;

	target_sum_pair(root, node->left, tar_sum);
	//inorder

	int comp = tar_sum - node->data;

	if(node->data < comp)
	{
		if(find(root, comp) == true)
		{
			cout<<node->data<<" "<< comp<<nl;
		}
	}

	target_sum_pair(root, node->right, tar_sum);
}

void target_sum_pair2(Node* node, vector<int>&v)
{
	//T.C {O(n)} , S.C {O(n + height of tree)}
	if(node== nullptr)
	{
		return;
	}

	target_sum_pair2(node->left, v);
	//inorder
	v.push_back(node->data);
	target_sum_pair2(node->right, v);
}




class Pair{
        public:
            Node* node;
            int state;

            Pair(Node* node, int state){
            	this->node = node;
            	this->state = state;
            }

};





Node* getNextFromNormalInorder(stack<Pair*> &st)
{
		while(st.size() > 0)
		{
				Pair* top = st.top();

				if(top->state == 0)
				{
						if(top->node->left != nullptr)
						{
							st.push(new Pair(top->node->left, 0));
						}
						top->state++;
						//preorder 
				}
				else if(top->state == 1)
				{
						if(top->node->right != nullptr)
						{
							st.push(new Pair(top->node->right, 0));
						}
						top->state++;

						//inorder 

						//Important in order me aake return karde rahe;
						return top->node;
				}
				else{
						st.pop();
						//postorder 
				}
		}

		return nullptr;
}

Node* getNextFromReverseInorder(stack<Pair*> &st)
{
		while(st.size() > 0)
		{
				Pair* top = st.top();

				if(top->state == 0)
				{
						if(top->node->right != nullptr)
						{
							st.push(new Pair(top->node->right, 0));
						}
						top->state++;
						//preorder 
				}
				else if(top->state == 1)
				{
						if(top->node->left != nullptr)
						{
							st.push(new Pair(top->node->left, 0));
						}
						top->state++;
						//Inorder 
						//Important in order me aake return karde rahe;
						return top->node;
				}
				else{
						st.pop();
						//postorder 
				}
		}

		return nullptr;
}

void target_sum_pair3(Node* node, int tar_sum)
{
  //T.C {O(n)} , S.C {O( height of tree)}
      stack<Pair*> ls, rs;
      ls.push(new Pair(node, 0));
      rs.push(new Pair(node, 0));

      Node* left = getNextFromNormalInorder(ls);
      Node* right = getNextFromReverseInorder(rs);

      while(left->data  <  right->data)
      {
            if(left->data + right->data  < tar_sum)
            {
                left = getNextFromNormalInorder(ls);
            }
            else if(left->data + right->data > tar_sum)
            {
                right = getNextFromReverseInorder(rs);
            }
            else{
                cout<<left->data <<" "<< right->data<<nl;
                left = getNextFromNormalInorder(ls);
                right = getNextFromReverseInorder(rs);
            }
      }
}




int main()
{
	int arr[]= {12, 25, 40, 50, 60, 75, 87};

	Node* root = Construct(arr, 0, 6);

	Display(root);
	cout<<nl<<nl;
	//cout<<max(root)<<" "<<min(root)<<nl;
	//cout<<find(root, 2);
	//Node* add = add_node(root, 70);
	//Display(add);
	//Node* add1 = remove_node(add, 75);
	//Display(add1);
	// replace_sum_of_larger_in_BST(root);
	// Display(root);
	//  Node * lca = LCA(root, 87, 62);
	//  cout<<lca->data<<nl;
	//print_in_range(root, 25, 72 );
	
	int target_sum =100;
	//target_sum_pair(root, root, target_sum);

	// vector<int>vc;
	// target_sum_pair2(root, vc);
	// int low=0, high = vc.size()-1;
	// while(high > low)
	// {
	// 	if(vc[low]+ vc[high] < target_sum )
	// 	{
	// 		low++;
	// 	}
	// 	else if(vc[low]+ vc[high] > target_sum )
	// 	{
	// 		high--;
	// 	}
	// 	else{
	// 		cout<<vc[low]<<" "<<vc[high]<<nl;
	// 		low++;
	// 		high--;
	// 	}
	// }
	target_sum_pair3(root, target_sum);
	
}
