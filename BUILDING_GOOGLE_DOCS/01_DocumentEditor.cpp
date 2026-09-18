#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

class DocumentEditor{
private:
    vector<string>documentElements;
    string renderdDocument;

public:
    void addText(string text){
        documentElements.push_back(text);
    }

    void addImage(string imagePath){
        documentElements.push_back(imagePath);
    }


    string renderDocument(){
        if(renderdDocument.empty()){
            string result;
            for(auto element : documentElements){
                if(element.size() > 4 && (element.substr(element.size()-4) == ".jpg") || element.substr(element.size()-4) == ".png"){
                    result += "[Image: " + element + "]" +"\n";
                }else{
                    result += element+"\n";
                }
            }
            renderdDocument = result;
        }
        return renderdDocument;
    }

    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file << renderDocument();
            file.close();
            cout << "Document saved to document.txt" << endl;
        }else{
            cout << "Error: unable to open file for writing." << endl;
        }
    }
};


 

int main(){
    DocumentEditor editor;
    editor.addText("Hello, world");
    editor.addImage("picture.jpg");
    editor.addText("this is a document editor");

    cout << editor.renderDocument() << endl;

    editor.saveToFile();

    return 0;
}


// in this sip and ocp is not followed 