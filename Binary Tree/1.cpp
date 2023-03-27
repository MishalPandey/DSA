// Pepcoding

#include<bits/stdc++.h>
using namespace std;
#define nl '\n'

class Node{
        public:
            int data;
            Node* left = NULL;
            Node* right = NULL;

            Node(int data){
            	this->data = data;
            }

};

class Pair{
        public:
            Node* node;
            int state;

            Pair(Node* node, int state){
            	this->node = node;
            	this->state = state;
            }

};

Node* Contruct(int a[], int n)
{
	Node* root = new Node(a[0]);
	
	Pair* root_pair = new Pair(root, 1);

	stack<Pair*> st;
	st.push(root_pair);

	int idx=0;
	while(st.size()>0)
	{
			Pair* top = st.top();
			if(top->state== 1)
			{
					idx++;

					if(a[idx]!= -1)
					{

							Node* left_node = new Node(a[idx]);
							top->node->left = left_node;

							Pair* left_pair = new Pair(left_node, 1);
							st.push(left_pair);
					}
					else
					{
							top->node->left = NULL;
					}

					top->state++;

			}
			else if(top->state == 2)
			{
					idx++;

					if(a[idx]!= -1)
					{

							Node* right_node = new Node(a[idx]);
							top->node->right = right_node;

							Pair* right_pair = new Pair(right_node, 1);
							st.push(right_pair);

							
					}
					else
					{

							top->node->right = NULL;
					}

					top->state++;

			}

			else{
					st.pop();
			}
	}

	return root;


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

int Max(Node* node)
{
		if(node== nullptr)
		{
			return INT_MIN;
		}

		int left_max = Max(node->left);
		int right_max =  Max(node->right);
		int total_max = max( max(left_max , right_max) , node->data);

		return total_max;
			
		
}
int Height(Node* node)
{
		if(node== nullptr)
		{
			return 0; // for nodes HEIGHT
			//return -1; // for edges HEIGHT
		}

		int left_height = Height(node->left);
		int right_height =  Height(node->right);
		int total_height =  max(left_height, right_height) + 1;

		return total_height;
	
}

void traversal(Node* node){

	if(node== nullptr)
	{
		return;
	}

	cout<<"in Pre order"<<node->data<<nl; // euler left-> pre

	traversal(node->left);
	cout<<"in In order"<<node->data<<nl;  // euler between-> in
	traversal(node->right);

	cout<<"in Post order"<<node->data<<nl;  // euler right-> post

}

void level_order_traversal(Node* node)
{

		queue<Node* > q;
		q.push(node);

		while(q.size()>0)
		{
				int n = q.size();
				for (int i = 0; i < n; ++i)
				{
						node = q.front();
						cout<<(node->data)<<" ";
						q.pop();
						if(node->left!= nullptr)
						{
							q.push(node->left);
							

						}
						if(node->right!= nullptr)
						{
							q.push(node->right);

						}
						
				}
				cout<<nl;
		}
}

void iterative_Pre_Post_In_traversal(Node* node)
{

		stack<Pair* > st;
		Pair* top= new Pair(node, 1);
		st.push(top);

		while(st.size()>0)
		{
				Pair* top = st.top();
				if(top->state==1)
				{
						cout<<top->node->data<<" Pre"<<nl;
						top->state++;

						if(top->node->left!=nullptr)
						{
							st.push(new Pair(top->node->left, 1));
						}

				}
				else if(top->state==2)
				{
						cout<<top->node->data<<" In"<<nl;
						top->state++;

						if(top->node->right!=nullptr)
						{
							st.push(new Pair(top->node->right, 1));
						}

				}
				else{
						cout<<top->node->data<<" Post"<<nl;
						st.pop();

				}


		}
	}

vector<int>path;
bool Node_to_root_path(Node* node, int x)
{

	if(node== nullptr)
	{
		return false;
	}

	if(node->data == x)
	{
		path.push_back(node->data);
		return true;
	}

	bool left_side_check= Node_to_root_path(node->left, x);
	if(left_side_check)
	{
		path.push_back(node->data);
		return true;
	}
	bool right_side_check= Node_to_root_path(node->right, x);
	if(right_side_check)
	{
		path.push_back(node->data);
		return true;
	}


	return false;

}

void Print_k_levels_down(Node* node, int k)
{

		if(node== nullptr || k<0)
		{
			return;
		}
		if(k==0)
		{
			cout<<node->data<<" ";
		}
		Print_k_levels_down(node->left, k-1);
		Print_k_levels_down(node->right, k-1);
}

//AMAZON 

// for Print_Nodes_k_level far question
vector<Node* >path_node;
bool Node_to_root_path_new(Node* node, int x)
{

	if(node== nullptr)
	{
		return false;
	}

	if(node->data == x)
	{
		path_node.push_back(node);
		return true;
	}

	bool left_side_check= Node_to_root_path_new(node->left, x);
	if(left_side_check)
	{
		path_node.push_back(node);
		return true;
	}
	bool right_side_check= Node_to_root_path_new(node->right, x);
	if(right_side_check)
	{
		path_node.push_back(node);
		return true;
	}


	return false;

}

// for Print_Nodes_k_level far question
void Print_k_levels_down_new(Node* node, int k, Node* blocker)
{

		if(node== nullptr || k<0|| node== blocker)
		{
			return;
		}
		if(k==0)
		{
			cout<<node->data<<" ";
		}
		Print_k_levels_down_new(node->left, k-1, blocker);
		Print_k_levels_down_new(node->right, k-1, blocker);
}





void Print_Nodes_k_level_far(Node* node, int data, int k)
{
		vector<Node* > pathh;
		Node_to_root_path_new(node, data);
		pathh = path_node;

		for (int i = 0; i < pathh.size(); ++i)
		{
			Print_k_levels_down_new(pathh[i], k-i, i==0? nullptr: pathh[i-1] );
		}


}

void leaf_to_root_path_in_range(Node* node, string s, int sum, int low, int high)
{

		if(node==nullptr)
		{
			return;
		}

		if(node->left==nullptr && node->right== nullptr)
		{
				sum+=node->data;
				if(sum>low && sum<high)
				{
					s += (" "+ to_string(node->data));
					cout<<s<<nl;

				}
				return;
		}


		leaf_to_root_path_in_range(node->left, s+ " "+ to_string(node->data), sum+ node->data , low , high);
		leaf_to_root_path_in_range(node->right, s+ " "+ to_string(node->data), sum+ node->data , low , high);

}


void transform_to_left_cloned_tree(Node* node)
{

		if(node== nullptr){
			return;
		}

	
		transform_to_left_cloned_tree(node->left);
		transform_to_left_cloned_tree(node->right);
		

		Node* copy = new Node(node->data);
		copy->left = node->left;
		node->left = copy;
	
	
}

void transform_to_normal_from_left_cloned_tree(Node* node)
{
		if(node== nullptr){
			return;
		}

	
		transform_to_normal_from_left_cloned_tree(node->left->left);
		transform_to_normal_from_left_cloned_tree(node->right);
		

		Node* copied = node->left;
		node->left = node->left->left;
		delete copied;
}

void print_single_child_node(Node* node)
{
		if(node==nullptr)
		{
			return;
		}

		if(node->left== nullptr && node->right!= nullptr)
		{
			cout<<node->right->data<<" ";
		}
		else if(node->right== nullptr && node->left!= nullptr)
		{
			cout<<node->left->data<<" ";

		}

		print_single_child_node(node->left);
		print_single_child_node(node->right);
}

Node* Remove_Leaves(Node* node)
{
		

		if(node==nullptr || node->left== nullptr && node->right== nullptr)
		{
			return nullptr;
			
		}

		Node* new_left = Remove_Leaves(node->left);
		Node* new_right= Remove_Leaves(node->right);

		node->left = new_left;
		node->right = new_right;

		return node;

}

int height(Node* node)
{
		if(node== nullptr)
			return -1; //for edges

		int left_height = height(node->left);
		int right_height =  height(node->right);
		int total_height =  max(left_height, right_height) + 1;

		return total_height;
	
}
//Important and hard*****

int diameter1(Node* node)
{

	if(node== nullptr)
	{
		return 0;
	}
	//maximum distance between two nodes of lhs
	int ld= diameter1(node->left);

	//maximum distance between two nodes of rhs
	int rd= diameter1(node->right);

	//maximum distance between left's deepest and right's deepest

	int f = height(node->left)  + height(node->right) + 2;

	int dia = max(f, max(ld, rd));

	return dia;
}

class DiaPair
{
	public:
		int ht;
		int dia;

};

DiaPair diameter2(Node* node)
{
	if(node ==nullptr)
	{
		DiaPair bp; // base pair
		bp.ht =-1;
		bp.dia= 0;
		return bp;
	}
	DiaPair lp = diameter2(node->left); //left pair
	DiaPair rp = diameter2(node->right); //right pair

	DiaPair mp;
	mp.ht = max(lp.ht, rp.ht) + 1;

	int fes = lp.ht + rp.ht + 2; // factor on either side
	mp.dia = max(fes, max(lp.dia, rp.dia));

	return mp;
}

//Chahiye kuch aur return kuch aur kare

int tilt = 0;
int tilt_B_T (Node* node)
{

		if(node==nullptr)
		{
			return 0;
		}

		//will return left's sum and change tilt for left side
		int ls = tilt_B_T(node->left); // left sum

		//will return right's sum and change tilt for right side
		int rs = tilt_B_T(node->right); // right sum

		int ltilt = abs(ls - rs);
		tilt+= ltilt;

		int ts= ls + rs + node->data;
		return ts;



}



int main() {
  
  int v[]={50, 25, 12, -1,-1, 37, 30, -1, -1, -1, 75 , 62, -1, 70, -1, -1, 87, -1, -1};
  // for (int i = 0; i < n; ++i)
  // {
	 //  	int x; cin>>x;
	 //  	v.push_back(x);
  // }
  Node* root= Contruct(v, 19);

  
  //Display(root);
 // cout<<Size(root)<<" "<<Height(root)<<" "<<Max(root)<<" "<<Sum(root)<<nl;

  //level_order_traversal(root);
 // iterative_Pre_Post_In_traversal(root);

  // bool Node_to_root_path_exist= Node_to_root_path(root, 30);
  // cout<<Node_to_root_path_exist<<nl;
  // for (int i = 0; i < path.size(); ++i)
  // {
  // 	cout<<path[i]<<" ";
  // }

  //Print_k_levels_down(root, 3);

  //Print_Nodes_k_level_far(root, 62, 4);

  //Path_to__leaf_from_root(root, "", 0, 50, 220);

  // Display(root);
  // cout<<nl<<nl;
  // transform_to_left_cloned_tree(root);
  // Display(root);

  // cout<<nl<<nl;
  // transform_to_normal_from_left_cloned_tree(root);
  // Display(root);

  //int v1[]={50, 25, 12, -1,-1, 37, 30, -1, -1, -1, 75 , 62, -1, 70, -1, -1, -1};
  //Node* root= Contruct(v1, 17);
  //print_single_child_node(root);

  



}
