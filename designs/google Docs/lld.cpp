#include <bits/stdc++.h>
using namespace std;

class Persistence {
    public:
        virtual void save(string doc) = 0;
    
};

class FilePersistence : public Persistence {   
    void save(string doc){
        cout<<"saved in file "<<doc<<endl;
    }
    
};

class DatabasePersistence : public Persistence {
    void save(string doc){
        cout<<"Saved in DB "<<doc<<endl;
    }
};

class DocumentElement{   
    public:
        virtual string render() = 0;
    
};

class TextElement : public DocumentElement{
    private:
        string text;
        
    public:
        TextElement(string text){
            this->text=text;
        }
        string render() override {
            return text;
        }
    
};

class ImageElement : public DocumentElement{  
    private:
        string path;
        
    public:
        ImageElement(string path){
            this->path=path;
        }
        string render(){
            return "[Image: " + path + "]";;
        }
    
};

class Document{   
    private:
        vector<DocumentElement*> elements;
        
    public:
        void addElement(DocumentElement* element){
            elements.push_back(element);
        }
        
        string render(){
            string result;
            for(auto element:elements){
                result+=element->render();
            }
            return result;
        };
    
};


class DocumentEditor{
    private:
        Document* doc;
        Persistence* storage;
        string renderedDocument;
    public:
        DocumentEditor(Document* doc, Persistence* storage){
            this->doc = doc;
            this->storage = storage;
        }
        void addText(string text){
            doc->addElement(new TextElement(text));
        };
        void addImage(string path){
            doc->addElement(new ImageElement(path));
        };
         string render(){
            if(renderedDocument.empty()){
                return doc->render();
            }
            return renderedDocument;
        }
        void save() {
            storage->save(render());
        }
};

int main() {
	// your code goes here
	
	Document* doc = new Document();
	Persistence* db = new DatabasePersistence();
	
	DocumentEditor* docEditor = new DocumentEditor(doc,db);
	docEditor->addText("this is title");
	docEditor->addImage("/img/aai.png");
	cout<<docEditor->render();
	docEditor->save();

}
