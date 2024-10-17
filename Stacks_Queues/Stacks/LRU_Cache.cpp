
// URL - https://leetcode.com/problems/lru-cache/description/


/* 
Idea here is to use the doubly linked list to keep track of the recently used element

The recently used element is always put at the front, that is, it is at the head and while replacing the we repalce the Least Recently used one which is at the end of the list

Why DLL and why not LL - this is because in DLL we can easily delete provided the pointer to the node directly, otherwise we have to traverse and find the node and delete which will
take O(1)

Now here we need the get operation to be O(1), so we use a hashmap to get to the nodes quickly

*/

class Dll_Node{
public:
    pair<int,int> p;
    Dll_Node* next;
    Dll_Node* prev;
    
    Dll_Node(){
        p={0,0};
        this->prev=NULL;
        this->next=NULL;
    }
};


class Dll_List{

public:
    Dll_Node* head;
    Dll_Node* tail;

    Dll_List(){
        
        this->head=new Dll_Node();
        this->tail=new Dll_Node();

        this->head->next=this->tail;
        this->tail->prev=this->head;

    }

    void print_dll(){
        Dll_Node * t= this->head;
        while(t!=NULL){
            cout<<"( "<<t->p.first<<", "<<t->p.second<<" )";
            t=t->next;
        }
        cout<<"\n";
        return;
    }

    void insert_at_front(Dll_Node* node){
        node->next=this->head->next;
        this->head->next->prev=node;
        this->head->next=node;
        node->prev=this->head;

        //print_dll();
    
    }

    Dll_Node* remove_node(Dll_Node * node){

            node->next->prev=node->prev;
            node->prev->next=node->next;

            node->prev=NULL;
            node->next=NULL;

            return node;
    }

};

class LRUCache {

public:

    int capacity;
    map<int,Dll_Node*> cache_hashmap;
    Dll_List* dll_list;

    LRUCache(int capacity) {
        this->capacity=capacity;
        this->cache_hashmap={};
        this->dll_list=new Dll_List();
    }

    void print_map(){

        for(const auto& pair: this->cache_hashmap){
            cout<<"{ " <<pair.first<< " }, ";
        }
        cout<<"\n";
    }
    
    int get(int key) {

        map<int,Dll_Node*>::iterator iter= this->cache_hashmap.find(key);

        //this->print_map();

        if(iter==this->cache_hashmap.end()){
            return -1;
        }

        Dll_Node* removednode=this->dll_list->remove_node(iter->second);
        this->dll_list->insert_at_front(removednode);

        return iter->second->p.second;

    }
    
    void put(int key, int value) {
        
        map<int,Dll_Node*>::iterator iter= this->cache_hashmap.find(key);

        if(this->capacity!=0){ // Checking if we are able to add new or update existing
            if(iter==this->cache_hashmap.end()){

                Dll_Node* newNode=  new Dll_Node();
                
                //Adding data
                newNode->p.first=key;
                newNode->p.second=value;

                this->cache_hashmap[key]=newNode;

                //Adding in the list at the first;
                this->dll_list->insert_at_front(newNode);
                this->capacity--;
            }
            else{ // Update values and remove it from wherever it is and add it in the first

                iter->second->p.first=key;
                iter->second->p.second=value;

                Dll_Node* removednode=this->dll_list->remove_node(iter->second);
                this->dll_list->insert_at_front(removednode);
            }
        }
        else{ // Replacement algorithm - basically taking out the last element and adding the new element

                if(iter!=this->cache_hashmap.end()){
                    iter->second->p.first=key;
                    iter->second->p.second=value;

                    Dll_Node* removednode=this->dll_list->remove_node(iter->second);
                    this->dll_list->insert_at_front(removednode);
                }
                else{
                    Dll_Node* newNode=  new Dll_Node();
                    
                    //Adding data
                    newNode->p.first=key;
                    newNode->p.second=value;

                    this->cache_hashmap[key]=newNode;


                    int delete_key = this->dll_list->tail->prev->p.first;
                    this->cache_hashmap.erase(delete_key);

                    this->dll_list->remove_node(this->dll_list->tail->prev);
                    //Adding in the list at the first;
                    this->dll_list->insert_at_front(newNode);
                }
        }
        //this->print_map();
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */