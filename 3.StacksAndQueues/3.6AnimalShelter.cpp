// Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly"first in, first
// out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
// or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
// that type). They cannot select which specific animal they would like. Create the data structures to
// maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
// and dequeueCat. You may use the built-in Linkedlist data structure.
#include<iostream>
#include<queue>
#include<string>
using namespace std;

//method 1 using a single queue but will lead to additonal complexities when specific request for a dog or cat takes place

//method 2 maintain two seperate queues and make a note of the order assign priority

class Animal{
private:
    string type; //cat or dog
    string name;
    int order;
public:
    Animal(string name,string type){
        this->name=name;
        this->type=type;
    }
    void setOrder(int order){
        this->order=order;
    }
    int getOrder(){
        return order;
    }
    string getType(){
        return type;
    }
    string getName(){
        return name;
    }
};

class AnimalShelter{
private:
    queue<Animal>dogs;
    queue<Animal>cats;
    int order=0;
public:
    AnimalShelter(){

    }

    void enqueue(Animal a){
        a.setOrder(order);
        order++;
        if(a.getType()=="dog"){
            dogs.push(a);
        }else{
            cats.push(a);
        }
    }
    void getAny(){
        if(cats.front().getOrder()<dogs.front().getOrder()){
            cout<<"u get a cat, his name is "<<cats.front().getName()<<endl;
            cats.pop();
        }else{
            cout<<"u get a dog, his name is "<<dogs.front().getName()<<endl;
            dogs.pop();
        }
    }
    void getDog(){
        cout<<"u get a dog, his name is "<<dogs.front().getName()<<endl;
        dogs.pop();
    }
    void getCat(){
        cout<<"u get a cat, his name is "<<cats.front().getName()<<endl;
        cats.pop();
    }

};

int main(){
    AnimalShelter shelter;
    Animal one("d1","dog");
    Animal two("d2","dog");
    Animal three("d3","dog");
    Animal four("d4","dog");
    Animal five("d5","dog");
    Animal six("d6","dog");
    
    Animal a("c1","cat");
    Animal b("c2","cat");
    Animal c("c3","cat");
    Animal d("c4","cat");
    Animal e("c5","cat");
    Animal f("c6","cat");

    shelter.enqueue(one); 
    shelter.enqueue(a);   
    shelter.enqueue(b);
    shelter.enqueue(two);
    shelter.enqueue(three);
    shelter.enqueue(c);
    shelter.enqueue(four);
    shelter.enqueue(d);
    shelter.enqueue(e);

    shelter.getAny();  
    shelter.getCat();
    shelter.getDog();
    shelter.getAny();
    
}