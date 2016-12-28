
#ifndef MAP_HPP_
#define MAP_HPP_
#include <iostream>
#include <stdlib.h>
#include <random>
#include <time.h>
#include <assert.h>
#include <stdexcept>
#include <utility>
#pragma GCC diagnostic ignored "-Wnon-template-friend"


namespace cs540{
#define ValueType std::pair<const Key_T, Mapped_T> 

template <typename Key_T , typename Mapped_T>
class Map;


template <typename Key_T , typename Mapped_T>
class Map{
  private:
    double probability;
    size_t total_plus_one;
    size_t total_node;

struct node{
  Key_T key;
  Mapped_T value;
  node *up;
  node *down;
  node *next;
  node *prev;

  node(Key_T k, Mapped_T v):
  key(k),value(v)
  {}

  
};
   

typedef struct node Node;

 Node *head=NULL;
 Node *tail=NULL;
 public: 
 
 class ConstIterator;

 class Iterator{
    public:
    Node * pos;
    Iterator & operator++();
    Iterator operator++(int);
    Iterator & operator--();
    Iterator operator--(int);
    ValueType & operator*() const;
    ValueType * operator->() const;
    friend bool operator==(const Map<Key_T, Mapped_T>::Iterator &, const Map<Key_T, Mapped_T>::Iterator &);
    friend bool operator==(const Map<Key_T,Mapped_T>::Iterator & , const Map<Key_T,Mapped_T>::ConstIterator &);
    friend bool operator==(const Map<Key_T,Mapped_T>::ConstIterator & , const Map<Key_T,Mapped_T>::Iterator &);
    friend bool operator!=(const Map<Key_T,Mapped_T>::Iterator & , const Map<Key_T,Mapped_T>::Iterator &);
    friend bool operator!=(const Map<Key_T,Mapped_T>::Iterator & , const Map<Key_T,Mapped_T>::ConstIterator &);
    friend bool operator!=(const Map<Key_T,Mapped_T>::ConstIterator & , const Map<Key_T,Mapped_T>::Iterator &);
 };



 class ConstIterator{
   public:
   const Node * pos;
   ConstIterator & operator++();
   ConstIterator operator++(int);
   ConstIterator & operator--();
   ConstIterator operator--(int); 
   const ValueType & operator*() const;
   const ValueType * operator->() const;
   friend bool operator==(const Map<Key_T, Mapped_T>::ConstIterator &, const Map<Key_T, Mapped_T>::ConstIterator &);
   friend bool operator==(const Map<Key_T,Mapped_T>::Iterator & , const Map<Key_T,Mapped_T>::ConstIterator &);
   friend bool operator==(const Map<Key_T,Mapped_T>::ConstIterator & , const Map<Key_T,Mapped_T>::Iterator &);
   friend bool operator!=(const Map<Key_T,Mapped_T>::ConstIterator & , const Map<Key_T,Mapped_T>::ConstIterator &);
   friend bool operator!=(const Map<Key_T,Mapped_T>::Iterator & , const Map<Key_T,Mapped_T>::ConstIterator &);
   friend bool operator!=(const Map<Key_T,Mapped_T>::ConstIterator & , const Map<Key_T,Mapped_T>::Iterator &);
 };  

 class ReverseIterator{
    public:
    const Node * pos;
    ReverseIterator & operator++();
    ReverseIterator operator++(int);
    ReverseIterator & operator--();
    ReverseIterator operator--(int);
    ValueType & operator*() const;
    ValueType * operator->() const; 
    friend bool operator==(const Map<Key_T,Mapped_T>::ReverseIterator & , const Map<Key_T,Mapped_T>::ReverseIterator &);
    friend bool operator!=(const Map<Key_T,Mapped_T>::ReverseIterator & , const Map<Key_T,Mapped_T>::ReverseIterator &);
 };

 friend class ReverseIterator;
 friend class ConstIterator;
 friend class Iterator;
 

friend bool operator==(const Map<Key_T,Mapped_T>::Iterator &it1 , const Map<Key_T,Mapped_T>::Iterator &it2){
   if(it1.pos->key==it2.pos->key && it1.pos->value==it2.pos->value)
    return true;
  else
    return false;
 }

friend bool operator==(const Map<Key_T,Mapped_T>::ConstIterator &it1 , const Map<Key_T,Mapped_T>::ConstIterator &it2){
   if(it1.pos->key==it2.pos->key && it1.pos->value==it2.pos->value)
    return true;
  else
    return false;
 }

 friend bool operator==(const Map<Key_T,Mapped_T>::Iterator &it1 , const Map<Key_T,Mapped_T>::ConstIterator &it2){
   if(it1.pos->key==it2.pos->key && it1.pos->value==it2.pos->value)
    return true;
  else
    return false;
 }
friend bool operator==(const Map<Key_T,Mapped_T>::ConstIterator &it1 , const Map<Key_T,Mapped_T>::Iterator &it2){
   if(it1.pos->key==it2.pos->key && it1.pos->value==it2.pos->value)
    return true;
  else
    return false;
 }
 friend bool operator!=(const Map<Key_T,Mapped_T>::Iterator &it1 , const Map<Key_T,Mapped_T>::Iterator &it2){
   if(it1.pos->key!=it2.pos->key || it1.pos->value!=it2.pos->value)
    return true;
  else
    return false;
 }

friend bool operator!=(const Map<Key_T,Mapped_T>::ConstIterator &it1 , const Map<Key_T,Mapped_T>::ConstIterator &it2){
   if(it1.pos->key!=it2.pos->key || it1.pos->value!=it2.pos->value)
    return true;
  else
    return false;
 } 

 friend bool operator!=(const Map<Key_T,Mapped_T>::Iterator &it1 , const Map<Key_T,Mapped_T>::ConstIterator &it2){
   if(it1.pos->key!=it2.pos->key || it1.pos->value!=it2.pos->value)
    return true;
  else
    return false;
 }

 friend bool operator!=(const Map<Key_T,Mapped_T>::ConstIterator &it1 , const Map<Key_T,Mapped_T>::Iterator &it2){
   if(it1.pos->key!=it2.pos->key && it1.pos->value!=it2.pos->value)
    return true;
  else
    return false;
 }

friend bool operator==(const Map<Key_T,Mapped_T>::ReverseIterator &it1 , const Map<Key_T,Mapped_T>::ReverseIterator &it2){
   if(it1.pos->key==it2.pos->key && it1.pos->value==it2.pos->value)
    return true;
  else
    return false;
 }
 friend bool operator!=(const Map<Key_T,Mapped_T>::ReverseIterator &it1 , const Map<Key_T,Mapped_T>::ReverseIterator &it2){
   if(it1.pos->key!=it2.pos->key || it1.pos->value!=it2.pos->value)
    return true;
  else
    return false;
 }

 Map(); 
 Map(const Map &);  

  std::pair<typename Map<Key_T,Mapped_T>::Iterator,bool> insert(const ValueType &);
  void print();
  void clear();
  size_t size() const;
  bool empty() const;
  void erase(const Key_T &);
  void erase(typename Map<Key_T,Mapped_T>::Iterator);
  void print1();
  Map<Key_T,Mapped_T>::Iterator find(const Key_T &);
  Map<Key_T,Mapped_T>::ConstIterator find(const Key_T &) const;
  Mapped_T & at(const Key_T &);
  const Mapped_T & at(const Key_T &) const;
  Mapped_T & operator[](const Key_T &);
  Map(std::initializer_list<std::pair<const Key_T,Mapped_T>>);


friend bool operator==(const Map<Key_T,Mapped_T> &m1 , const Map<Key_T,Mapped_T> &m2){
       if(m1.total_node!=m2.total_node)
        return false;
     
       struct node  * m1_node=m1.head;
       struct node  * m2_node=m2.head;

       while(m1_node->down!=NULL)
        m1_node=m1_node->down;

      while(m2_node->down!=NULL)
        m2_node=m2_node->down;

      while(m1_node->next->next!=NULL)
      {
        if(m1_node->key!=m2_node->key || m1_node->value!=m2_node->value)
          return false;
        m1_node=m1_node->next;
        m2_node=m2_node->next;
      }
    return true;  
}


friend bool operator!=(const Map<Key_T,Mapped_T> &m1 , const Map<Key_T,Mapped_T> &m2){
       if(m1.total_node!=m2.total_node)
        return true;
       struct node  * m1_node=m1.head;
       struct node  * m2_node=m2.head;
      int flag1=0;
       while(m1_node->down!=NULL)
        m1_node=m1_node->down;

      while(m2_node->down!=NULL)
        m2_node=m2_node->down;

      while(m1_node->next->next!=NULL)
      {
        if(m1_node->key!=m2_node->key || m1_node->value!=m2_node->value)
          flag1=1;
        m1_node=m1_node->next;
        m2_node=m2_node->next;
      }
      if(flag1)
        return true;
    
    return false;

}


friend bool operator<(const Map<Key_T,Mapped_T> &m1 , const Map<Key_T,Mapped_T> &m2){
       if(m1.total_node<m2.total_node)
        return true;
       struct node  * m1_node=m1.head;
       struct node  * m2_node=m2.head;
      int flag1=0;
       while(m1_node->down!=NULL)
        m1_node=m1_node->down;

      while(m2_node->down!=NULL)
        m2_node=m2_node->down;

      while(m1_node->next->next!=NULL)
      {
        if(m2_node->key<m1_node->key || m2_node->value<m1_node->value)
          flag1=1;
        m1_node=m1_node->next;
        m2_node=m2_node->next;
      }
      if(flag1)
        return false;
    
    return true;

}

 ~Map();

 Iterator begin();
 Iterator end();
 ConstIterator begin() const;
 ConstIterator end() const;
 ReverseIterator rbegin();
 ReverseIterator rend();


Node * makenode(Key_T k, Mapped_T v){
   
      Node * temp= new node(k,v);
      temp->up=NULL;
      temp->down=NULL;
      temp->next=NULL;
      temp->prev=NULL;
    return temp;   
   }

Node *makeheadtail(){
   Node * temp=(Node *)malloc(sizeof(Node));
      temp->up=NULL;
      temp->down=NULL;
      temp->next=NULL;
      temp->prev=NULL;
    return temp; 
}
 friend bool operator==(const Map & , const Map &); 
 friend bool operator!=(const Map & , const Map &);
 friend bool operator<(const Map & , const Map &);

};





template<typename Key_T, typename Mapped_T>
Map<Key_T,Mapped_T>::Map(const Map &obj){
   
      head=(Node *)malloc(sizeof(Node));
      tail=(Node *)malloc(sizeof(Node));
      head->up=NULL;
      head->down=NULL;
      
      head->next=tail;
      head->prev=NULL;
        

      tail->up=NULL;
      tail->down=NULL;
      
      tail->next=NULL;
      tail->prev=head;
        

        assert(head!=NULL);
        assert(tail!=NULL);
        probability=0.5;
        total_node=0;
        total_plus_one=1;

      Node * last_head=NULL;
      Node * last_tail=NULL;
      
      last_head=obj.head;
      last_tail=obj.tail;
    
    while(last_head->down!=NULL)
         {last_head=last_head->down; last_tail=last_tail->down;
          
        }
    while(last_head->next->next!=NULL){
          std::pair <Key_T,Mapped_T> foo;
          foo=std::make_pair(last_head->next->key,last_head->next->value);
          this->insert(foo);
          last_head=last_head->next;
    }         

}

template<typename Key_T, typename Mapped_T>
Map<Key_T,Mapped_T>::Map(std::initializer_list<std::pair<const Key_T,Mapped_T>> m){
  head= (Node *)malloc(sizeof(Node));
      tail= (Node *)malloc(sizeof(Node));
      head->up=NULL;
      head->down=NULL;
      
      head->next=tail;
      head->prev=NULL;
        
      tail->up=NULL;
      tail->down=NULL;
      
      tail->next=NULL;
      tail->prev=head;
        
        assert(head!=NULL);
        assert(tail!=NULL);
        probability=0.5;
        total_node=0;
        total_plus_one=1;
        for(auto n : m )
         this->insert(n);
}

template<typename Key_T, typename Mapped_T>
Map<Key_T,Mapped_T>::Map(){
      head= (Node *)malloc(sizeof(Node));
      tail= (Node *)malloc(sizeof(Node));
      head->up=NULL;
      head->down=NULL;
      
      head->next=tail;
      head->prev=NULL;
        

      tail->up=NULL;
      tail->down=NULL;
      
      tail->next=NULL;
      tail->prev=head;
        

        assert(head!=NULL);
        assert(tail!=NULL);
        probability=0.5;
        total_node=0;
        total_plus_one=1;
    }

template<typename Key_T, typename Mapped_T>
typename Map<Key_T,Mapped_T>::ConstIterator  Map<Key_T,Mapped_T>::find(const Key_T &key) const{
          Node *temp_head=NULL;
          Node *temp_tail=NULL;
          Node *iter=NULL;
          Node *matched=NULL;
          ConstIterator a;
          iter=head;
          temp_head=head;
          temp_tail=tail;
          int found=0;
         
          while(true){
               
         

                if(iter->next!=temp_tail)               
                if(iter->next->key==key)
                {
                  iter=iter->next;
                  
                  while(iter->down!=NULL)
                  iter=iter->down;  
                  found=1;
                  matched=iter;
                  
                 break;
                }
              
                if(iter->next!=temp_tail)
                if(key<iter->next->key && iter->down!=NULL)
                    {    
                       
                        iter=iter->down; temp_tail=tail->down;
                        
                    } 

                 if(iter->next->next!=NULL) {
                 if(iter->next->key<key)
                    { 
                      
                      iter=iter->next;
                     }  
                  }



                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key < key)
                   {
                   
                    iter=iter->next;
                    }

                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key > key)
                    {
                        
                        iter=iter; 
                        break;
                    }   

                 if(iter->down!=NULL && iter->next->next==NULL)
                  {
                
                    iter=iter->down; 
                    temp_tail=tail->down;
                   }

                  if(iter->down==NULL && iter->next->next==NULL) 
                     {
                      
                      break;
                      } 
                     

                 if((iter->down==NULL  && iter->next->next==NULL))  
                 {
                    
                    iter=iter;
                    break;
                 } 
               

          }// end of while

      if(found){
        a.pos=matched;
        return a;
    }
     else
     {
      a=this->end();
      return a;
     }   

}
template<typename Key_T, typename Mapped_T>
typename Map<Key_T,Mapped_T>::Iterator  Map<Key_T,Mapped_T>::find(const Key_T &key){

          Node *temp_head=NULL;
          Node *temp_tail=NULL;
          Node *iter=NULL;
          Node *matched=NULL;
          Iterator a;
          iter=head;
          temp_head=head;
          temp_tail=tail;
          int found=0;
         
          while(true){
               
                

                if(iter->next!=temp_tail)               
                if(iter->next->key==key)
                {
                  iter=iter->next;
                  
                  while(iter->down!=NULL)
                  iter=iter->down;  
                  found=1;
                  matched=iter;
                  
                 break;
                }
             
                if(iter->next!=temp_tail)
                if(key<iter->next->key && iter->down!=NULL)
                    {    
 
                      
                        iter=iter->down; temp_tail=tail->down;// need to handle
                        
                    } 

                 if(iter->next->next!=NULL) {
                 if(iter->next->key<key)
                    { 

                      iter=iter->next;

                     }  
                  }



                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key < key)
                   {

                    iter=iter->next;
                    }

                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key > key)
                    {

                        iter=iter; 
                        break;
                    }   

                 if(iter->down!=NULL && iter->next->next==NULL)
                  {

                    iter=iter->down; 
                    temp_tail=tail->down;
                   }

                  if(iter->down==NULL && iter->next->next==NULL) //may need to check with temp-tail
                     {

                      break;
                      } 
                     

                 if((iter->down==NULL  && iter->next->next==NULL))  
                 {

                    iter=iter;
                    break;
                 } 
              
          }// end of while

      if(found){
        a.pos=matched;
        return a;
    }
     else
     {
      a=this->end();
      return a;
     }   
  }



template<typename Key_T, typename Mapped_T>          
Mapped_T & Map<Key_T,Mapped_T>::operator[](const Key_T &key){


          Node *temp_head=NULL;
          Node *temp_tail=NULL;
          Node *iter=NULL;
          Node *matched=NULL;
          iter=head;
          temp_head=head;
          temp_tail=tail;
          int found=0;
         
          while(true){
               

                if(iter->next!=temp_tail)               
                if(iter->next->key==key)
                {
                  iter=iter->next;
                  
                  while(iter->down!=NULL)
                  iter=iter->down;  
                  found=1;
                  matched=iter;
                  
                 break;
                }
                
                if(iter->next!=temp_tail)
                if(key<iter->next->key && iter->down!=NULL)
                    {    
 
                    
                        iter=iter->down; temp_tail=tail->down;// need to handle
                      
                    } 

                 if(iter->next->next!=NULL) {
                 if(iter->next->key<key)
                    { 
                      
                      iter=iter->next;
                      
                     }  
                  }



                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key < key)
                   {

                    iter=iter->next;
                    }

                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key > key)
                    {

                        iter=iter; 
                        break;
                    }   

                 if(iter->down!=NULL && iter->next->next==NULL)
                  {

                    iter=iter->down; 
                    temp_tail=tail->down;
                   }

                  if(iter->down==NULL && iter->next->next==NULL) 
                     {

                      break;
                      } 
                     

                 if((iter->down==NULL  && iter->next->next==NULL))  
                 {

                    iter=iter;
                    break;
                 } 
               
          }

      if(found){
                return matched->value;
    }
     else
     {
      throw std::out_of_range("out_of_range");
     }

}

template<typename Key_T, typename Mapped_T>          
Mapped_T & Map<Key_T,Mapped_T>::at(const Key_T &key){
 
          Node *temp_head=NULL;
          Node *temp_tail=NULL;
          Node *iter=NULL;
          Node *matched=NULL;
          iter=head;
          temp_head=head;
          temp_tail=tail;
          int found=0;
         
          while(true){
               
               

                if(iter->next!=temp_tail)               
                if(iter->next->key==key)
                {
                  iter=iter->next;
                  
                  while(iter->down!=NULL)
                  iter=iter->down;  
                  found=1;
                  matched=iter;
                  
                 break;
                }
                
                if(iter->next!=temp_tail)
                if(key<iter->next->key && iter->down!=NULL)
                    {    
 
                    
                        iter=iter->down; temp_tail=tail->down;// need to handle
                      
                    } 

                 if(iter->next->next!=NULL) {
                 if(iter->next->key<key)
                    { 
                      
                      iter=iter->next;
                    
                     }  
                  }



                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key < key)
                   {

                    iter=iter->next;
                    }

                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key > key)
                    {

                        iter=iter; 
                        break;
                    }   

                 if(iter->down!=NULL && iter->next->next==NULL)
                  {

                    iter=iter->down; 
                    temp_tail=tail->down;
                   }

                  if(iter->down==NULL && iter->next->next==NULL) 
                     {
                     
                      break;
                      } 
                     

                 if((iter->down==NULL  && iter->next->next==NULL))  
                 {

                    iter=iter;
                    break;
                 } 
              
          }

      if(found){
                return matched->value;
    }
     else
     {
      throw std::out_of_range("out_of_range");
     }
  

}

template<typename Key_T, typename Mapped_T>          
const Mapped_T & Map<Key_T,Mapped_T>::at(const Key_T &key) const{
 
 Node *temp_head=NULL;
          Node *temp_tail=NULL;
          Node *iter=NULL;
          Node *matched=NULL;
          iter=head;
          temp_head=head;
          temp_tail=tail;
          int found=0;
         
          while(true){
               


                if(iter->next!=temp_tail)               
                if(iter->next->key==key)
                {
                  iter=iter->next;
                  
                  while(iter->down!=NULL)
                  iter=iter->down;  
                  found=1;
                  matched=iter;
                 
                 break;
                }
                
                if(iter->next!=temp_tail)
                if(key<iter->next->key && iter->down!=NULL)
                    {    
 
                      
                        iter=iter->down; temp_tail=tail->down;
                      
                    } 

                 if(iter->next->next!=NULL) {
                 if(iter->next->key<key)
                    { 

                      iter=iter->next;

                     }  
                  }



                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key < key)
                   {

                    iter=iter->next;
                    }

                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key > key)
                    {

                        iter=iter; 
                        break;
                    }   

                 if(iter->down!=NULL && iter->next->next==NULL)
                  {

                    iter=iter->down; 
                    temp_tail=tail->down;
                   }

                  if(iter->down==NULL && iter->next->next==NULL) 
                     {

                      break;
                      } 
                     

                 if((iter->down==NULL  && iter->next->next==NULL))  
                 {

                    iter=iter;
                    break;
                 } 
               

          }

      if(found){
                return matched->value;
    }
     else
     {
      throw std::out_of_range("out_of_range");
     }
  

}

template<typename Key_T, typename Mapped_T>
std::pair<typename Map<Key_T,Mapped_T>::Iterator,bool> Map<Key_T,Mapped_T>::insert(const ValueType &obj){
 int flag=0;
       int duplicate=0;
       int is_upper_level=0;
       int no_upper_level=0;
       int in_between_node_upgrade=0;
          struct node *temp_head=head;
          struct node *temp_tail=tail;
          struct node *iter=head;
          struct node *bottom=NULL;
          temp_head=head;
          temp_tail=tail;
          iter=head;
          Iterator a;
          bool insertion=true;
          std::pair<Iterator,bool> foo;

        if(total_node!=0)
        {
          
          while(true){
               


                if(iter->next->next!=NULL) {              
                if(iter->next->key==obj.first)
                { 
                duplicate=1;
                insertion=false;
                a.pos=iter->next;
                break;
              }
            }
                

               
                  if(iter->next->next==NULL){
                    if(iter->down==NULL){
                      iter=iter;

                      break;
                      }
                  }
                   if((iter->down==NULL  && iter->next->next==NULL))  
                 {

                    iter=iter;
                    break;
                 }

                 if(iter->down==NULL && iter->next->next==NULL) 
                     {

                      bottom=iter;
                      break;
                      } 
                     

               

                 if(iter->next->next!=NULL)
                 if(iter->down==NULL &&  obj.first<iter->next->key  )
                    {

                        iter=iter; 
                        break;
                    }   

                 if(iter->next->next!=NULL){
                 if(iter->next->key<obj.first)
                    { 

                       iter=iter->next;
                    }  
                 }

                  if(iter->next->next!=NULL){
                if(obj.first < iter->next->key && iter->down!=NULL)
                    {    
                       

                        iter=iter->down; temp_tail=tail->down;
                        if(iter->down==NULL)
                            bottom=iter;
                    } 
                  }

                  if(iter->next->next==NULL){
                    if(iter->down!=NULL){
                      iter=iter->down;
                      temp_tail=tail->down;

                      }
                  }
                 if(iter->next->next!=NULL)
                 if(iter->down==NULL && iter->next->key < obj.first)
                   {

                    iter=iter->next;
                    }

                 if(iter->down!=NULL && iter->next->next==NULL)
                  {

                    iter=iter->down; 
                    temp_tail=tail->down;

                  }
           


          }
         flag=1;   
        }// end of if condition to find the node location.

    if(flag==1 && duplicate==0){
        struct node *temp2=makenode(obj.first, obj.second);
        
        temp2->next=iter->next;
        temp2->prev=iter;
        temp2->next->prev=temp2;
        iter->next=temp2;
        iter=temp2;
        total_node=total_node+1;

        a.pos=temp2;

    }



     if(total_node==0){
            struct node *temp=makenode(obj.first, obj.second);
            temp->prev=head;
            temp->next=head->next;
            
            temp->next->prev=temp;
            head->next=temp;
            a.pos=temp;

            total_node=total_node+1;
            iter=temp;

            
        } 


    if(total_node>=1 && duplicate==0){

        while(((double)std::rand()/RAND_MAX)>probability){


           struct node *bottom_temp=bottom;
           struct node *iter_temp=iter;
           struct node *head_temp=head;
           struct node *tail_temp=tail;
           bottom_temp=bottom;
           iter_temp=iter;
           head_temp=head;
           tail_temp=tail;
           
           while(true){
              
            if(iter_temp->prev==NULL)
            {  

              if(iter_temp->up==NULL)
                {


                  no_upper_level=1; 
                  break;
                }
             
              if(iter_temp->up!=NULL)
                {

                  iter_temp=iter_temp->up;
                  is_upper_level=1; 
                  break;
                }
            }
          
          if(iter_temp->up!=NULL)
            {  

              iter_temp=iter_temp->up; 
              in_between_node_upgrade=1;
              break;
            }
            
            if(iter_temp->up==NULL && iter_temp->prev!=NULL)
             {
              iter_temp=iter_temp->prev;    
              }                

           } 
    
     if(no_upper_level){

           struct node *new_head=makeheadtail();
           struct node *new_tail=makeheadtail();
           struct node *new_node=makenode(obj.first,obj.second);

           new_node->down=iter;
           iter->up=new_node;

           iter_temp->up=new_head;
           new_head->down=iter_temp;

           tail_temp->up=new_tail;
           new_tail->down=tail_temp;
           

           new_node->next=new_tail;
           new_tail->prev=new_node;

           new_node->prev=new_head;
           new_head->next=new_node;

           iter=new_node;

           head=new_head;
           tail=new_tail;
           no_upper_level=0;


     }
      
      if(is_upper_level){
            

            struct node *new_node=makenode(obj.first,obj.second);

            iter->up=new_node;
            new_node->down=iter;

            new_node->prev=iter_temp;
            new_node->next=iter_temp->next;
            new_node->next->prev=new_node;
            iter_temp->next=new_node;
            
            iter=new_node;
            is_upper_level=0;


      } // upper layer is there but insertion has to be done between head and next element at upper layer.     
      
      if(in_between_node_upgrade){
            

            struct node *new_node=makenode(obj.first,obj.second);
            
            iter->up=new_node;
            new_node->down=iter;

            new_node->prev=iter_temp;
            new_node->next=iter_temp->next;
            new_node->next->prev=new_node;
            iter_temp->next=new_node;

            iter=new_node;
            in_between_node_upgrade=0;

           

      }// upgrade the node but the insertion has to be done between two nodes

    }//while loop----probability of tossing the node up ends here

     in_between_node_upgrade=0; is_upper_level=0;no_upper_level=0;
  }//if condition---randomization ends here;

    flag=0; duplicate=0;
    foo=std::make_pair(a,insertion);
return foo;
      
        
}



template<typename Key_T, typename Mapped_T>
void Map<Key_T,Mapped_T>::clear(){
 
  Node *temp=head;
  
  Node *temp1=NULL;
  if(head!=NULL){
    
  while(head->down!=NULL){
    temp=head;
    head=head->down;
        
    while(temp!=NULL){
      temp1=temp;
      temp=temp->next;
      free(temp1);
         
    }
   
  }
}
   temp1=head->next;
   temp=head;
  while(temp1!=NULL)
  {
  
   free(temp);
   temp=temp1; 
  temp1=temp1->next;
  }
  free(head);
  
free(temp);
}

template<typename Key_T, typename Mapped_T>
size_t Map<Key_T,Mapped_T>::size() const{

  return total_node;
}

template<typename Key_T, typename Mapped_T>
bool Map<Key_T,Mapped_T>::empty() const{

  return total_node==0?true:false;
}

template<typename Key_T, typename Mapped_T>
Map<Key_T,Mapped_T>::~Map(){

  Node *temp=head;

  Node *temp1=NULL;
  if(head!=NULL){
    
  while(head->down!=NULL){
    temp=head;
    head=head->down;
        
    while(temp!=NULL){
      temp1=temp;
      temp=temp->next;
      free(temp1);
         
    }
   
  }
}
   temp1=head->next;
   temp=head;
  while(temp1!=NULL)
  {
  
   free(temp);
   temp=temp1; 
  temp1=temp1->next;
  }
  free(head);
free(temp);
  
}
template<typename Key_T, typename Mapped_T>
void Map<Key_T,Mapped_T>::erase(typename Map<Key_T,Mapped_T>::Iterator it){
           
           auto it1=this->begin();
           auto it2=this->end();
           int flag=0;
           if(it==it2)
            return;
          else
           erase(it.pos->key);   
           
}

template<typename Key_T, typename Mapped_T>
void Map<Key_T,Mapped_T>::erase(const Key_T &key){
          Node *temp_head=NULL;
          Node *temp_tail=NULL;
          Node *iter=NULL;
          iter=head;
          temp_head=head;
          temp_tail=tail;
          int found=0;
         
          while(true){
               


                if(iter->next!=temp_tail)               
                if(iter->next->key==key)
                {
                  iter=iter->next;

                  while(iter->down!=NULL)
                  iter=iter->down;  
                  found=1;

                 break;
                }

                if(iter->next!=temp_tail)
                if(key<iter->next->key && iter->down!=NULL)
                    {    
 
                      
                        iter=iter->down; temp_tail=tail->down;
                       
                    } 

                 if(iter->next->next!=NULL) {
                 if(iter->next->key<key)
                    { 
                     
                      iter=iter->next;
                      
                     }  
                  }



                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key < key)
                   {

                    iter=iter->next;
                    }

                 if(iter->next!=temp_tail)
                 if(iter->down==NULL && iter->next->key > key)
                    {

                        iter=iter; 
                        break;
                    }   

                 if(iter->down!=NULL && iter->next->next==NULL)
                  {

                    iter=iter->down; 
                    temp_tail=tail->down;
                   }

                  if(iter->down==NULL && iter->next->next==NULL) //may need to check with temp-tail
                     {

                      break;
                      } 
                     

                 if((iter->down==NULL  && iter->next->next==NULL))  
                 {

                    iter=iter;
                    break;
                 } 
              
          }

      if(found){
        
        if(iter->up!=NULL){
        while(iter->up!=NULL){
        Node *temp=NULL;  
        temp=iter;
        iter=iter->up;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;

        free(temp);
        total_node=total_node-1;
      }
      free(iter);
    }
     else if(iter->up==NULL){
     iter->prev->next=iter->next;
     iter->next->prev=iter->prev;
     free(iter);
     total_node=total_node-1;
     }   
  }
  if(!found)
    throw std::out_of_range("out_of_range: Element not found in Map ");
    found=0;        

}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::Iterator Map<Key_T,Mapped_T>::begin(){
  Node *temp_head;
  temp_head=head;
  while(temp_head->down!=NULL)
    temp_head=temp_head->down;
 
 Iterator a;
 a.pos=temp_head->next;
 
  return a;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ConstIterator Map<Key_T,Mapped_T>::begin() const{
  const Node *temp_head;
  temp_head=head;
  while(temp_head->down!=NULL)
    temp_head=temp_head->down;
   
   ConstIterator a;
   a.pos=temp_head->next;
  
  return a;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ReverseIterator Map<Key_T,Mapped_T>::rbegin(){
  const Node *rtemp_head;
  rtemp_head=tail;
  
  while(rtemp_head->down!=NULL)
    rtemp_head=rtemp_head->down;

   ReverseIterator a;
   a.pos=rtemp_head->prev;
   return a;
}


template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::Iterator Map<Key_T,Mapped_T>::end(){
  Node *temp_tail;
  temp_tail=tail;
  while(temp_tail->down!=NULL)
    temp_tail=temp_tail->down;
  
  Iterator a;
  a.pos=temp_tail;
  return a;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ConstIterator Map<Key_T,Mapped_T>::end() const{
  const Node *temp_tail;
  temp_tail=tail;
  while(temp_tail->down!=NULL)
    temp_tail=temp_tail->down;

  ConstIterator a;
  a.pos=temp_tail;
  return a;
  
}


template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ReverseIterator Map<Key_T,Mapped_T>::rend(){
  Node *rtemp_tail;
  rtemp_tail=head;
  while(rtemp_tail->down!=NULL)
    rtemp_tail=rtemp_tail->down;
   
   ReverseIterator a;
   a.pos=rtemp_tail;
  return a;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::Iterator & Map<Key_T,Mapped_T>::Iterator::operator++(){
  if(this->pos!=NULL){
    this->pos=this->pos->next;
  }
 return *this;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::Iterator  Map<Key_T,Mapped_T>::Iterator::operator++(int){
  if(this->pos!=NULL){
    this->pos=this->pos->next;
  }
  Map<Key_T,Mapped_T>::Iterator a;
  a.pos=this->pos->prev;
 return a;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::Iterator & Map<Key_T,Mapped_T>::Iterator::operator--(){
  if(this->pos!=NULL){
    this->pos=this->pos->prev;
  }
 return this;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::Iterator  Map<Key_T,Mapped_T>::Iterator::operator--(int){
  if(this->pos!=NULL){
    this->pos=this->pos->prev;
  }

  Map<Key_T,Mapped_T>::Iterator a;
  a.pos=this->pos->next;
 return a;
}

template<typename Key_T,typename Mapped_T>
ValueType & Map<Key_T,Mapped_T>::Iterator::operator*() const{

  std::pair <Key_T,Mapped_T> foo;
  foo=std::make_pair(this->key,this->value);
  return foo;

}

template<typename Key_T,typename Mapped_T>
ValueType * Map<Key_T,Mapped_T>::Iterator::operator->() const{

  std::pair <Key_T,Mapped_T> foo;
  foo=std::make_pair(this->pos->key,this->pos->value);
  return &foo;

}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ConstIterator & Map<Key_T,Mapped_T>::ConstIterator::operator++(){
  if(this->pos!=NULL){
    this->pos=this->pos->next;
  }
 return this;
}


template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ConstIterator  Map<Key_T,Mapped_T>::ConstIterator::operator++(int){
  if(this->pos!=NULL){
    this->pos=this->pos->next;
  }

   Map<Key_T,Mapped_T>::ConstIterator a;
  a.pos=this->pos->prev;
 return a;
 }

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ConstIterator & Map<Key_T,Mapped_T>::ConstIterator::operator--(){
  if(this->pos!=NULL){
    this->pos=this->pos->prev;
  }
 return this;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ConstIterator  Map<Key_T,Mapped_T>::ConstIterator::operator--(int){
  if(this->pos!=NULL){
    this->pos=this->pos->prev;
  }
  Map<Key_T,Mapped_T>::ConstIterator a;
  a.pos=this->pos->next;
 return a;
 }

template<typename Key_T,typename Mapped_T>
const ValueType & Map<Key_T,Mapped_T>::ConstIterator::operator*() const{

  const std::pair <Key_T,Mapped_T> foo;
  foo=std::make_pair(this->key,this->value);
  return foo;

}

template<typename Key_T,typename Mapped_T>
const ValueType * Map<Key_T,Mapped_T>::ConstIterator::operator->() const{

  const std::pair <Key_T,Mapped_T> foo;
  foo=std::make_pair(this->key,this->value);
  return &foo;

}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ReverseIterator & Map<Key_T,Mapped_T>::ReverseIterator::operator++(){
  if(this->pos!=NULL){
    this->pos=this->pos->next;
  }
 return this;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ReverseIterator Map<Key_T,Mapped_T>::ReverseIterator::operator++(int){
  if(this->pos!=NULL){
    this->pos=this->pos->prev;
  }

  Map<Key_T,Mapped_T>::ReverseIterator a;
  a.pos=this->pos->next;
 return a;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ReverseIterator & Map<Key_T,Mapped_T>::ReverseIterator::operator--(){
  if(this->pos!=NULL){
    this->pos=this->pos->next;
  }
 return this;
}

template<typename Key_T,typename Mapped_T>
typename Map<Key_T,Mapped_T>::ReverseIterator  Map<Key_T,Mapped_T>::ReverseIterator::operator--(int){
  if(this->pos!=NULL){
    this->pos=this->pos->next;
  }

   Map<Key_T,Mapped_T>::ReverseIterator a;
  a.pos=this->pos->prev;
 return a;
}

template<typename Key_T,typename Mapped_T>
ValueType & Map<Key_T,Mapped_T>::ReverseIterator::operator*() const{

  std::pair <Key_T,Mapped_T> foo;
  foo=std::make_pair(this->key,this->value);
  return foo;

}
template<typename Key_T,typename Mapped_T>
ValueType * Map<Key_T,Mapped_T>::ReverseIterator::operator->() const{

  std::pair <Key_T,Mapped_T> foo;
  foo=std::make_pair(this->key,this->value);
  return &foo;

}

}
#endif
