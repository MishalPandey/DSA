#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

class Node{
        public:
            int data;
            vector<Node*> children;

            Node(int data){
            	this->data = data;
            }

};
Node* takeInput(){

		int n; cin>>n;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}


	    Node * root;
		stack<Node *> st;
		
		for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
		{
				if(arr[i]==-1)
				{
					st.pop();
				}
				else
				{
						Node * t= new Node(arr[i]) ;
						if(st.size()>0)
						{
							st.top()->children.push_back(t);
							
						}
						else
						{
							root =t;
						}

						st.push(t);

				}
		}

		return root;
}

void print(Node* node){
		string str= to_string(node->data )+ " -> ";
		for(Node* child: node->children)
		{
			str+= to_string(child->data )+", ";
		}
		str+= ".";
		cout<< str<<nl;
		for(Node* child: node->children)
		{
			print(child);
		}

}

int size(Node * node){

	int sizee=0;
		for(Node* child: node->children)
		{	
		 	int ch= size(child);
		 	sizee+=ch;
		}

		 sizee+=1;

		 return sizee;

}
int max(Node * node){

	int maxi= INT_MIN;
		for(Node* child: node->children)
		{	
		 	int ch= max(child);
		 	maxi= max(maxi, ch);
		}
		 maxi=max(maxi, node->data);

		 return maxi;


}

int height(Node * node){

	int ht= -1; // for height in terms of edges
	//int ht= 0; // for height in terms of nodes

		for(Node* child: node->children)
		{	
		 	int ch= height(child);
		 	ht= max(ht, ch);
		}
		 ht+=1;

		 return ht;


}

void traversal(Node* node){


	//Euler's left, on the way deep in the recursion, node's pre area
	cout<<"Node Pre "<<node->data<<nl;

			for(Node* child: node->children)
			{
				 	//edge pre
				 	cout<<"Edge Pre "<<node->data<<"--"<<child->data<<nl;
					//cout<<"Edge Pre "<<(*node).data<<"--"<<child->data<<nl;

				 	traversal(child);

				 	//edge post
				 	cout<<"Edge Post "<<node->data<<"--"<<child->data<<nl;
			}

	//Euler's right, on the way out of recursion, node's post area
	cout<<"Node Post "<<node->data<<nl;



}

void levelorder(Node* node){
	queue<Node *> Q;
	Q.push(node);

	while(Q.size()>0)
	{
			node= Q.front();
			Q.pop();
			cout<<node->data<<" ";
			for(Node* child: node->children)
			{	
				Q.push(child);
			 	
			}
			

	}

	cout<<".";
}

void levelorder_linewise(Node* node){
	queue<Node *> q1, q2;
	q1.push(node);

	while(q1.size()>0)
	{
			node= q1.front();
			q1.pop();
			cout<<node->data<<" ";
			for(Node* child: node->children)
			{	
				q2.push(child);
			 	
			}
			if(q1.size()==0){
				q1= q2;
				while(!q2.empty()){
					q2.pop();
				}
				cout<<nl;

			}
			

	}

}
void levelorder_linewise_zigzag(Node* node){

		stack<Node *>main_stk, child_stk;
		main_stk.push(node);

		int level=1;
		while(main_stk.size()>0){
			node= main_stk.top();
			main_stk.pop();
			cout<<node->data<<" ";


				if(level&1){

					
					for(Node* child: node->children)
					{	
						child_stk.push(child);
					 	
					}

				}
				else{
					
					for(int it=(node->children).size()-1; it>=0; it--){
						child_stk.push(node->children[it]);
					}

				}



				if(main_stk.size()==0){
					main_stk= child_stk;
					while(!child_stk.empty()){
					     child_stk.pop();
				    }
					cout<<nl;
					level++;
				}

		}
	
}
 
void levelorder_traversal_approches1(Node* node){

	queue<Node *> q ;
	q.push(node);
	q.push(new Node(-1));
	while(q.size()>0){
		node= q.front();
		q.pop();
		if(node->data!= -1){
				cout<<node->data<<" ";
				for(Node* child: node->children)
				{	
					q.push(child);
				 }

		}
		else{
			if(q.size()>0){
				q.push(new Node(-1));
				cout<<nl;
			}
		}
	}


	

}
void levelorder_traversal_approches2(Node* node){

	queue<Node *> q ;
	q.push(node);
	while(q.size()>0){
		int cicl= q.size();
		for (int i = 0; i < cicl; ++i)
		{		
				node= q.front();
				q.pop();
				cout<<node->data<<" ";
				for(Node* child: node->children)
				{	
					q.push(child);
				 }

		}
		cout<<nl;
	}


	

}

//1st way

class Pair{
public:
	Node* node;
	int level;
	Pair(Node * node, int level){
		this->node= node;
		this->level= level;
	}
};
void levelorder_traversal_approches3(Node* node){

	queue<Pair> q ;
	q.push(Pair(node, 1));
	int level=1;
	while(q.size()>0){
		Pair p= q.front();
		q.pop();
		if(p.level> level){
			level= p.level;
			cout<<nl;
		}

		cout<<p.node->data<<" ";
		for(Node* child: p.node->children)
		{	
			Pair cp= Pair(child, p.level+1);
			q.push(cp);
		}

	}	

}
void mirrorTransform(Node* node)
{

  for (Node* child : node->children)
  {
    mirrorTransform(child);
  }

   //reverse((node->children).begin(), (node->children).end());
  for (int i = 0, j = node->children.size() - 1; i < j; i++, j--)
  {
    Node* temp = node->children[i];
    node->children[i] = node->children[j];
    node->children[j] = temp;
  }


}

void removeLeaves(Node* node){
		vector<Node*>* childs = new vector<Node*>();

		for (Node* child : node->children)
		{
				if(child->children.size() != 0){
				    childs->push_back(child);
				}
		}

		node->children = *childs;

		for (Node* child : node->children)
		{
				removeLeaves(child);
		}
	
}

Node* getTail(Node* node){
	while(node->children.size()==1){
			node= node->children[0];
	}
	return node;
}

void Linearize(Node * node){

		for (Node* child : node->children)
		{
				Linearize(child);
		}
		while(node->children.size()>1){
			Node* last_childof_node= node->children[node->children.size()-1];
			node->children.pop_back();

			Node* Scnd_last_childof_node= node->children[node->children.size()-1];

			Node* tail_of_2nd_last= getTail(Scnd_last_childof_node);
			tail_of_2nd_last->children.push_back(last_childof_node);


		}


}
Node * Linearize_efficient(Node * node){

		if(node->children.size()==0){
			return node;
		}

		
		Node * lkt= Linearize_efficient(node->children[node->children.size()-1]);
		
		while(node->children.size()>1){
			Node* last= node->children[node->children.size()-1];
			node->children.pop_back();

			Node* sl= node->children[node->children.size()-1];

			Node* sktl= Linearize_efficient(sl);
			sktl->children.push_back(last);


		}
		return lkt;


}
bool find_element(Node* node, int x){

	if(x== node->data){
		return true;
	}
	for (Node* child : node->children)
	{
			bool ans= find_element(child, x);
			if(ans){
				return true;
			}
	}

		return false;

}

vector<int> Node_to_root_path(Node* node, int x){
    if(x== node->data){
    	vector<int>anss;
    	anss.push_back(node->data);
		return anss;
	}
	for (Node* child : node->children)
	{
			vector<int>pathtillChild= Node_to_root_path(child, x);
			if(pathtillChild.size()>0){
				//ek tarah se if statement bata rha hai ki root exist karti hai ya nhi
				pathtillChild.push_back(node->data);
				return pathtillChild;
			}

	}

		vector<int> ans;
		return ans;


}
int LCA(Node* node, int x1, int x2){
	vector<int>p1= Node_to_root_path(node, x1);
	vector<int>p2= Node_to_root_path(node, x2);
	reverse(p1.begin(), p1.end());
	reverse(p2.begin(), p2.end());
	int ans;
	for (int i = 0; i < p1.size() && i<p2.size(); ++i)
	{
		if(p1[i]==p2[i]){
			ans=p1[i];
		}
	}
	return ans;
}
int distance_bw_2nodes(Node * node, int x1, int x2){
	vector<int>p1= Node_to_root_path(node, x1);
	vector<int>p2= Node_to_root_path(node, x2);
	reverse(p1.begin(), p1.end());
	reverse(p2.begin(), p2.end());
	int ans=0;
	int i;
	for (i = 0; i < p1.size() && i<p2.size(); ++i)
	{
		if(p1[i]==p2[i]){
			continue;
		}
		else{
			break;
		}
	}
	ans+=(p1.size()+ p2.size()-2*i);

	return ans;

}
bool Trees_similar_InShape(Node* n1, Node* n2){
	if(n1->children.size()!=n2->children.size()){
		return false;
	}

	for (int i = 0; i < n1->children.size(); ++i)
	{
		n1= n1->children[i];
		n2= n2->children[i];
		if(Trees_similar_InShape(n1, n2)==false){
			return false;
		}
	}

	return true;
}

bool Tress_MirrorImage_InShape(Node* n1, Node* n2){
	if(n1->children.size()!=n2->children.size()){
		return false;
	}

	for (int i = 0; i < n1->children.size(); ++i)
	{
		n1= n1->children[i];
		n2= n2->children[n2->children.size()-1-i];
		if(Tress_MirrorImage_InShape(n1, n2)==false){
			return false;
		}
	}

	return true;
}
bool IsTree_Symmetric(Node * node){
	return Tress_MirrorImage_InShape(node, node);
	// if tree is symmetric then woh apani mirror image hogi
}

int sizee;
int mini;
int maxi;
int heightt;
void multisolver(Node*node, int depth){

	// ek hi function me sab findout karna size, height, min, max
	sizee++;
	mini= min(mini, node->data);
	maxi= max(maxi, node->data);
	heightt= max(heightt, depth);

	for (Node* child : node->children)
	{
		multisolver(child, depth+1);
	}
}

Node* predecessor;
Node* successor;
int state=0;
void  predecessor_AND_successor(Node * node, int x){
	if(state==0){
		if(node->data==x){
			state=1;
		}
		else{
			predecessor=node;
		}
	}
	else if(state==1){
		successor=node;
		state=2;
	}
	for (Node* child : node->children)
	{
		predecessor_AND_successor(child, x);
	}

}

int ceeil;
int floorr;

void ceilAndFloor(Node* node, int x){
	if(node->data > x){
		if(node->data< ceeil){
			ceeil= node->data;
		}
	}

	if(node->data < x){
		if(node->data > floorr){
			floorr= node->data;
		}
	}

	for (Node* child : node->children)
	{
		ceilAndFloor(child, x);
	}

}

int kthLargest(Node* node, int k){
	floorr= INT_MIN;
	int  Factor= INT_MAX;
	for (int i = 0; i < k; ++i)
	{
		ceilAndFloor(node, Factor);// will set floor
		Factor= floorr;

		floorr=INT_MIN;
	}

	return Factor;
}
int msn=0; // maximum sum node
int ms= INT_MIN;// maximum sum

int retSumAndCalculateMSST(Node * node){
	int sum=0;

	for (Node* child : node->children)
	{
		int csum= retSumAndCalculateMSST(child);
		sum+= csum;
	}

	sum+= node->data;

	if(sum> ms){
		msn= node->data;
		ms= sum;
	}

	return sum;

}

int dia=0;
int calculateDiaReturnHieght(Node* node){
	int dch=-1;// depest child height
	int sdch=-1;// second depest child height

	for (Node* child : node->children)
	{
		int ch= calculateDiaReturnHieght(child); // child height
	    if(ch> dch){
	    	sdch= dch;
	    	dch= ch;
	    }
	    else if(ch> sdch){
	    	sdch= ch;
	    }
	}

	int cand = dch + sdch+2;
	if(cand> dia){
		dia= cand;
	}
	dch+=1;

	return dch;


}

// 2nd way

void iterativePreAndPostOrder(Node* root) {
  stack<pair<Node*, int>>st;
  st.push({root, -1});
  string preorder;
  string postorder;
  while (st.size() > 0) {
    pair<Node*, int> top = st.top();
     st.pop();
    if (top.second == -1) {
      preorder += to_string(top.first->data) + " ";
      top.second++;
       st.push(top);
    }
    else if (top.second == top.first->children.size()) {
       postorder += to_string(top.first->data) + " ";

      
    }
    else {
       pair<Node*, int> cp(top.first->children[top.second], -1);
       top.second++;
       st.push(top);
       st.push(cp);
       
     
    }
  }
  cout << preorder << endl;
  cout << postorder << endl;
}





int main(){


	    Node * root = takeInput();
		// print(root);
		// cout<<size(root)<<nl;
		// cout<<max(root)<<nl;
		// cout<<height(root)<<nl;
		//traversal(root);
		//levelorder(root);
		//levelorder_linewise(root);
		//levelorder_linewise_zigzag(root);
		// levelorder_traversal_approches1(root);
		// levelorder_traversal_approches2(root);

		// levelorder_traversal_approches3(root);
		// mirrorTransform(root);
		// cout<<nl;
		// levelorder_traversal_approches3(root);

		// print(root);
		// removeLeaves(root);
		// cout<<nl;
		// print(root);

		// levelorder_traversal_approches3(root);
		// Linearize(root);
		// cout<<nl;
		// levelorder_traversal_approches3(root);

		//levelorder_traversal_approches3(root);
		// Node* x= Linearize_efficient(root);
		 //cout<<nl;
		// levelorder_traversal_approches3(root);

		// bool ans= find_element(root, 330);
		// cout<<ans<<nl;

		// vector<int> v=Node_to_root_path(root, 110);
		// for (int i = 0; i < v.size(); ++i)
		// {
		// 	cout<<v[i]<<" ";
		// }

		 //cout<<LCA(root, 90, 110);

		 //cout<< distance_bw_2nodes(root, 100, 60);
		 // Trees_similar_InShape
		 // Tress_MirrorImage_InShape
		 // IsTree_Symmetric

		 // sizee=0;
		 // mini= INT_MAX;
		 // maxi= INT_MIN;
		 // heightt=0;
		 // multisolver(root, 0);
		 // cout<<"sizee = "<< sizee<<" mini = "<<mini<<" maxi = "<<maxi<<" heightt ="<<heightt;

	    // predecessor_AND_successor(root, 120);
	    // cout<<predecessor->data<<" "<<successor->data;

	    // ceeil= INT_MAX;
	    // floorr= INT_MIN;
	    // ceilAndFloor(root, 65);
	    // cout<<ceeil<<" "<<floorr;

	    //cout<<kthLargest(root, 2);

	    // retSumAndCalculateMSST
	    // calculateDiaReturnHieght
	    // iterativePreAndPostOrder


}
