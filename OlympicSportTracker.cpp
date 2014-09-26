#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

template <class T> 
class Data {
public:
    T key;
    T value;
    //constructors
    Data()
    { key = ""; value = ""; }
    Data(T k, T v)
    { key = k; value = v; }
};

template <class T1>
class DataSlot {
public:
    T1 index;
    long size;
    //constructors
    DataSlot()
    { index = ""; size = 0; }
    DataSlot(T1 k)
    { index = k; size = 0; }
};

class Element {
public:
    Data<string> d;
    Element* prev;
    Element* next;
    //constructors
    Element()
    { d.key = ""; d.value = ""; prev = NULL; next = NULL; }
    Element(Data<string> dat)
    { d = dat; prev = NULL; next = NULL; }
};

class Slot {
public:
    DataSlot <string> d;
    Slot* prev;
    Slot* next;
    Element* head;

    //constructors
    Slot()
    { d.index = ""; d.size = 0; prev = NULL; next = NULL; head = NULL; }
    Slot(DataSlot<string> dat)
    { d = dat; prev = NULL; next = NULL; head = NULL; }
    //insert element pointed by x at the beginning of list of elements
    void insert(Element* x)
    {
        x->next = this->head;
        this->head = x;
        if (x->next != NULL)                //if there were other elements
            x->next->prev = x;
        d.size++;
    }
    //remove element pointed by x from list of elements
    void remove(Element* x)
    {
        if (x->next != NULL)                //if not the last one
            x->next->prev = x->prev;
        if (x->prev != NULL)                //if not the first one
            x->prev->next = x->next;
        else                                //if first one
            this->head = x->next;
        delete x;                           //deallocate x
        d.size--;
    }
    //destructor
    ~Slot()
    { while (this->head != NULL) remove(this->head); }
};

class HashMap {
public:
    long size;
    Slot* head;
    //constructor
    HashMap()
    { size = 0; head = NULL; }
    //insert slot pointed by s at the begining of hash map
    void insert(Slot* s)
    {
        s->next = this->head;
        this->head = s;
        if (s->next != NULL) {      //if there were other slots
            s->next->prev = s;
        }
        size++;
    }

    //insert element pointed by x in slot pointed by s
    void insert(Slot* s, Element* x)
    { s->insert(x); }

    //remove slot pointed by s from hash map
    void remove(Slot* s)
    {
        if (s->next != NULL)                //if not the last one
            s->next->prev = s->prev;
        if (s->prev != NULL)                //if not the first one
            s->prev->next = s->next;
        else                                //if first one
            this->head = s->next;
        while (s->head != NULL)             //delete all elements from slot s
            s->remove(s->head);
        delete s;                           //deallocate s
        size--;
    }

    //remove element pointed by x from slot pointed by s
    void remove(Slot* s, Element* x) {
        s->remove(x);
    }
    //display HashMap content
    void display() const
    {
        Slot* p;
        Element* q;
        p = this->head;
        while (p != NULL) {
            cout << p->d.index << "," << p->d.size << endl;
            q = p->head;
            while (q != NULL) {
                cout << "  " << q->d.key << "," << q->d.value << endl;
                q = q->next;
            }
            p = p->next;
        }
    }
    
        void displayallIndices() const
    {
            try{
                Slot* p;
                p = this->head;
                if(p!=NULL){
                while (p != NULL) {
                    cout << p->d.index << endl;
                    p = p->next;
                }
                }
                else{
                    throw 99;
                }
            }
            catch(int X){
                cout<<"No more elements in hashmap to display"<<X<<endl;
            }
     
    }
    
 void displayNindices(int n) 
    {
     try{
        if(n>0){
        Slot* p;
        p = this->head;
        int len = p->d.size;
        cout<< "value of d" <<len;
        if(len >=n && n > 0){
            for(int i=0;i<n;i++){
                cout << p->d.index << endl;
                p = p->next;
            }
        }
     }
        else{
            throw 98;
        }
     }
     catch(int X){
         cout<<"Input should be greater than 0"<<X<<endl;
     }
    }
    
         
    void displayAllElementIdsinSlot(string slotId) 
    {
        Slot* p;
        Element* q;
        string temp;
        p = this->head; 
        try{
            if(p!=NULL){
             while (p != NULL) {
                 temp = p->d.index;
                            cout<<"value of slotid's"<<p->d.index<<endl;
                 if(temp == slotId){
                            cout<<"success"<<p->d.index<<endl;
                     break;
                 }
                 else{
                     throw 't';
                 }
                   p = p->next;
             }
                q = p->head;
                while (q != NULL) {
                    cout << q->d.key << endl;
                    q = q->next;
                }
            }
            else {
                throw 99;
            }
        }
        catch(int X){
            cout<<"No more elements in hashmap to display"<<X<<endl;
            }
        catch(char c){
           cout<<"Slot Id not found in hashmap for display"<<endl;  
       }
        }
    
        void displayNElementIdsinSlot(string slotId, int n) 
    {
            
        Slot* p;
        Element* q;
        string temp;
        p = this->head; 
        try{
            if(n>0){
                if(p!=NULL){
                temp= p->d.index;
                 while (p != NULL) {
                        cout<<"value of slotid's"<<p->d.index<<endl;
                 if(temp == slotId){
                         break;
                     }
                 else{
                     throw 't';
                 }
                       p = p->next;
                 }
                    q = p->head;
                    if(n > 0){
                        for(int i=0;i<n;i++){
                            cout << q->d.key << endl;
                            q = q->next;
                        }
                    } 
          
            }
            else{
                throw 99;
            }
            }
            else{
                throw "N is <=0";
            }
    }
    catch(int x){      
         cout<<"No more elements in hashmap to display"<<x<<endl;     
    }
    catch(char c){
        cout<<"Slot Id not found in hashmap for display"<<endl;  
    }
    catch(string exception){
         cout<<"Entered input value is less than or equal to 0"<<exception<<endl;
    }
                    
        
    }
    
      void displayElementInfoIdsinSlot(string slotId, string element) 
    {
        Slot* p;
        Element* q;
        p = this->head;
         while (p != NULL) {
             if(p->d.index == slotId){
                 break;
                 
             }
               p = p->next;
         }
         
          cout << p->d.index << "," << p->d.size << endl;
            q = p->head;
               
                    while (q != NULL) {
                        if(q->d.key == element){
                             cout << "  " << q->d.key << "," << q->d.value << endl;
                        }
                    q = q->next;
                }
            
          
    }
    
    //destructor
    ~HashMap()
    {
        while (this->head != NULL)
            this->remove(this->head);
    }
};

class BuildHashMap {
public:
    void process(string href){
        string curlcmd;
        string curlcmd1;
        bool IsFirst = true;
        string url1 = "curl ";
        string url2 =" -o ";
        string url3 = "/cygdrive/c/Users/Hiranya/Desktop/OlympicDetails.html";
        string url4 = "/cygdrive/c/Users/Hiranya/Desktop/seed.html";
        curlcmd = curlcmd.append(url1);
        curlcmd = curlcmd.append(href);
        curlcmd = curlcmd.append(url2);
        curlcmd = curlcmd.append(url4);
        system(curlcmd.c_str());
        size_t startPos, endPos;
        string value;
        startPos = 0;
        endPos = 0;     
    
        string Seed = CopyFiletoString(IsFirst);
        IsFirst = false;
        size_t sportPos = Seed.find("rtecenter",startPos); 
        startPos = Seed.find("href=", sportPos);
        endPos = Seed.find(" ", startPos);
        value = Seed.substr(startPos, (endPos - startPos));
        string temp = value.substr(value.find_first_of('"')+1);
        string hrefValue = temp.substr(0,temp.find_first_of('"'));
        curlcmd1 = curlcmd1.append(url1);
        curlcmd1 = curlcmd1.append(hrefValue);
        curlcmd1 = curlcmd1.append(url2);
        curlcmd1 = curlcmd1.append(url3);
        system(curlcmd1.c_str());
        // convert the file content to a string to work further
        string buffer = CopyFiletoString(false);
        //create a string array which holds the sports of winter olympics in a string array.
        string SportsArray[10];
        string SportValueArr[10];
        
        SportsArray[0]="Bobsleigh";
        SportsArray[1]="Short Track Speed Skating";
        SportsArray[2]="Ski Jumping";
            SportsArray[3]="Ice Hockey";
        SportsArray[4]="Luge";
        SportsArray[5]="Speed Skating";
        SportsArray[6]="Alpine Skiing";
        SportsArray[7]="Freestyle Skiing";
        SportsArray[8]="Figure Skating";
        SportsArray[9]="Snowboarding";
        int length = sizeof( SportsArray ) / sizeof( SportsArray[ 0 ]);
        
        startPos = 0;
        endPos = 0;
        for(int i = 0; i < length;i++){
            size_t sportPos = buffer.find("<input type=\"hidden\" name=\"title\"",startPos); 
            startPos = buffer.find("value=", sportPos);
            endPos = buffer.find(SportsArray[i], startPos);
            value = buffer.substr(startPos, (endPos - startPos));
            string temp = value.substr(value.find_first_of('#')+1);
            SportValueArr[i] = temp;
        } 
        BuildHashMap obj;
       obj.BuildHashMapObject(href, hrefValue, SportsArray,SportValueArr,length);

    }  
    
    
    string CopyFiletoString(bool seed){
        ifstream myFile;
        if(seed)
         myFile.open("/cygdrive/c/Users/Hiranya/Desktop/seed.html");
        else
         myFile.open("/cygdrive/c/Users/Hiranya/Desktop/OlympicDetails.html");    
        int myFileLength = 0;
        char *myFileBuf = NULL;
        
        if(!myFile.is_open()) {
            cout << "Failed opening file: "  << endl;
           // return 0;
        }
        myFile.seekg(0, myFile.end);
        myFileLength = myFile.tellg();
        myFile.seekg(0, myFile.beg);
        myFileBuf = new char [myFileLength] ;
        myFile.read(myFileBuf, myFileLength);
        myFile.close();
        string buffer(myFileBuf);
        return buffer;
        
    }
    
    HashMap* BuildHashMapObject(string href,string hrefValue,string SportsArray[11],string SportValueArr[11],int length){
    
         HashMap* hm = new HashMap;
            DataSlot<string> ds(href);
            Data <string> d("seed",href);
            Slot* s = new Slot(ds);   
            Element* e = new Element(d);
            hm->insert(s);
            hm->insert(s,e);
            DataSlot<string> ds1(hrefValue);
            Slot* s1 = new Slot(ds1);
            hm->insert(s1);
        try{
       
        for(int i = 0; i<length;i++){
            Data <string> d1(SportsArray[i],SportValueArr[i]);
            Element* e1 = new Element(d1);
             hm->insert(s1,e1);
        }
         hm->display();
        }
         catch(exception e){
        cout<<e.what()<<endl;
    }
        return hm;  
    }
   
     
};

int main()
{
    cout<<"hello world"<<endl;
    try{
    BuildHashMap bmp;
    bmp.process("http://www.theactivetimes.com/10-most-popular-winter-olympic-sports");
    }
    catch(exception e){
        cout<<e.what()<<endl;
    }
            
    return 0;
    
    
}
