#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class DocumentElement{
public:
    virtual string render() = 0;
};


class TextElement:public DocumentElement{
private:
    string text;

public:
    TextElement(string text){
        this->text = text;
    }

    string render() override{
        return text;
    }
};

//concrete implementation of image element
class ImageElement:public DocumentElement{
private:
    string imagePath;

public:
    ImageElement(string imagePath){
        this->imagePath = imagePath;
    }

    string render() override{
        return "[Image:"+imagePath+"]";
    }
};


//New Line Element represent a line break in the document.

class NewLineElement:public DocumentElement{
public:
    string render() override{
        return "\n";
    }
};


// Tabspace element represent a tab space in the document;

class TabSpaceElement:public DocumentElement{
public:
    string render() override{
        return "\t";
    }
};

//Document class responsible for holding a collection of eements

class Document{
private:
    vector<DocumentElement*>DocumentElements;

public:
    void addElement(DocumentElement*element){
        DocumentElements.push_back(element);
    }

    // render the document by concatenating the render output of all elements.

    string render(){
        string result;
        for(auto element : DocumentElements){
            result += element->render();
        }
        return result;
    }
};


// persistence class

class Persistence {
public:
    virtual void save(string data) = 0;
};


//fileStorage implementation of persistance 
class fileStorage:public Persistence{
public:
    void save(string data) override{
        ofstream outFile("document.txt");
        if(outFile){
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        }else{
            cout << "Error: unable to open file for writing. " << endl;
        }
    }
};

//placeholder Dbstorage implementation
class DBStorage : public Persistence{
public:
    void save(string data) override{
        //save to db
    }
};

// documentEditor class managing client interaction
class DocumentEditor{
private:
    Document*document;
    Persistence*storage;
    string renderedDocument;

public: 
    DocumentEditor(Document*document,Persistence*storage){
        this->document = document;
        this->storage = storage;
    }

    void addText(string text){
        document->addElement(new TextElement(text));
    }

    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }

    //add a new line to the document.
    void addNewLine(){
        document->addElement(new NewLineElement());
    }

    void addTabspace(){
        document->addElement(new TabSpaceElement());
    }

    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument = document->render();
        }
        return renderedDocument;
    }

    void saveTODocument(){
        storage->save(renderDocument());
    }
};


//client  user interface
int main(){
    Document*document = new Document();
    Persistence* Persistence = new fileStorage();

    DocumentEditor * editor = new DocumentEditor(document,Persistence);

    // Simulate a client using the editor with text formatting features.
    editor->addText("Hello, world!");
    editor->addNewLine();
    editor->addText("This is a real-world document editor example.");
    editor->addNewLine();
    editor->addTabspace();
    editor->addText("Indented text after a tab space.");
    editor->addNewLine();
    editor->addImage("picture.jpg");

    //render and display the final document.
    cout << editor->renderDocument() << endl;

    editor->saveTODocument();
    return 0;
}