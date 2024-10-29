#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <limits> // Include for std::numeric_limits
#include <windows.h>
#include <cstdlib>   // For system()
void setColor(int textColor, int bgColor) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));
}
using namespace std; //optional depending way of codding
class MessageFragmenter {
public:
    using MissingChunkCallback = std::function<void(size_t)>;

    MessageFragmenter(size_t chunkSize) : chunkSize(chunkSize) {}

    std::vector<std::string> fragmentMessage(const std::string& message) {
        std::vector<std::string> chunks;
        for (size_t i = 0; i < message.size(); i += chunkSize) {
            chunks.push_back(message.substr(i, chunkSize));
        }
        return chunks;
    }

    std::string reassembleMessage() {
        std::string reassembled;
        std::unique_lock<std::mutex> lock(mutex);
        for (size_t i = 0; i < processedChunks.size(); ++i) {
            if (processedChunks.find(i) != processedChunks.end()) {
                reassembled += processedChunks[i];
            }
        }
        return reassembled;
    }

    void setMissingChunkCallback(MissingChunkCallback callback) {
        missingChunkCallback = callback;
    }

    void receiveChunks(const std::vector<std::string>& chunks) {
        std::unique_lock<std::mutex> lock(mutex);
        for (size_t i = 0; i < chunks.size(); ++i) {
            if (!chunks[i].empty()) {
                processedChunks[i] = chunks[i];
            } else {
                missingChunks.push_back(i);
            }
        }

        if (!missingChunks.empty() && missingChunkCallback) {
            for (size_t index : missingChunks) {
                missingChunkCallback(index);
            }
        }
        condVar.notify_all();
    }

    void checkForCorruptedData(size_t timeoutMilliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(timeoutMilliseconds));

        std::unique_lock<std::mutex> lock(mutex);
        for (size_t i = 0; i < processedChunks.size(); ++i) {
            if (processedChunks.find(i) == processedChunks.end()) {
                std::cout << "\n\n\t\t\t\t\tCorrupted data detected for chunk index: " << i << std::endl;
            }
        }
    }

private:
    size_t chunkSize;
    std::unordered_map<size_t, std::string> processedChunks;
    std::vector<size_t> missingChunks;
    MissingChunkCallback missingChunkCallback;
    std::mutex mutex;
    std::condition_variable condVar;
};

void repeate(){
    int i,j,z;
             setColor(11, 0);  // 10 is green, 0 is black background



    std::cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tWELCOME TO";setColor(1, 0);cout<<" QUBIT";setColor(3, 0);cout<<" TECH ";setColor(11, 0);cout<<"MESSAGE ";setColor(7, 0);cout<<"FRAGMENTER";
      Sleep(2000);
      setColor(7, 0);

          cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\tLoading ";      Sleep(2000);
          for(i = 0; i<100; i+=10){Sleep(800);
cout<<".. . . .";

}
setColor(1, 0);
cout<<"==>>"; Sleep(3000);
     system("cls");
      std::cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tWELCOME TO MESSAGE FRAGMENTATION\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t";

      setColor(10, 0);
//system("pause");
setColor(7, 0);
system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\tTutorial message to be fragmented is : WELCOME TO MESSAGE FRAGMENTATION";

Sleep(3000);

                    for (j = 0; j < 54; j+=5) {

system("cls");

     setColor(7, 0);cout <<"\n\n\n\n\n\n\n\n\n\t\t\tOriginal word (Message) : WELCOME TO MESSAGE FRAGMENTATION\n\n\n\n\n\tFragmenting level : \t\t\t\t    ";setColor(10, 0); cout<< j<<"%";

                }
 setColor(7, 0);
                if( j = 45){
    setColor(7, 0);std::cout << "\n\tFragmented word at chunk 0 :";setColor(4, 0); cout<<"  \t\t\t - WELCOME TO " << std::endl;
    Sleep(2000);}


                      if(j = 54){

                                for(i = 54; i < 85; i++){
                                                            system("cls");


                                     setColor(7, 0); cout<<"\n\n\n\n\n\n\n\n\n\t\t\tOriginal word (Message) : WELCOME TO MESSAGE FRAGMENTATION\n\n\n\n\n\tFragmenting level : \t\t\t\t    ";setColor(10, 0);cout<< i<<"%"<<endl;

                                }

                                if( i = 78){ setColor(7, 0);std::cout << "\n\tFragmented word at chunk 1 :";setColor(4, 0); cout<<" \t\t\t - MESSAGE F" << std::endl;
                                Sleep(2000);}
                                }

                      if(z = 85){
                            Sleep(1000);
 setColor(7, 0);
                                for(i = 85; i < 100; i++){
                                      system("cls");
                                                                Sleep(50);


                                    setColor(7, 0);cout<<"\n\n\n\n\n\n\n\n\n\t\t\tOriginal word (Message) : WELCOME TO MESSAGE FRAGMENTATION\n\n\n\n\n\tFragmenting level : \t\t\t\t    ";setColor(10, 0);cout<< i<<"%";

                                }
                                setColor(7, 0);
                            if(i = 95 ) {setColor(7, 0);std::cout << "\n\tFragmented word at chunk 2 : ";setColor(4, 0); cout<<" \t\t\t - RAGMENTATI" << std::endl;
                            Sleep(2000);}

                             if(i = 99)
                                {
                                    system("cls");
                                   Sleep(1000);setColor(7, 0);
                                    setColor(7, 0);cout<<"\n\n\n\n\n\n\n\n\n\t\t\tOriginal word (Message) : WELCOME TO MESSAGE FRAGMENTATION\n\n\n\n\n\tFragmenting level : \t\t\t\t    ";setColor(10, 0);cout<<"99%";


                                    setColor(7, 0);std::cout << "\nFragmented word at last chunk 2 : ";setColor(4, 0); cout<<" \t\t\t - ON" << std::endl;
                             }


setColor(7, 0);
                            }
//cout<<"\n\n\n\n\n\n\n\t\t\t\tFragmentation level : "<<"100%";
}

void runFragmenter() {
    MessageFragmenter fragmenter(10); // Chunk size of 10
    fragmenter.setMissingChunkCallback([](size_t index) {
        std::cout << "\n\tMissing chunk at index: " << index << std::endl;
    });

int i;
    std::string message;
    std::vector<std::string> chunks;

                         // setColor(16, 0);cout<<"qubit16";
                          setColor(17, 0);


repeate();//call reference
if(i = 100){
                cout<<"\n\n\n\n\t\t\t\t Completed! 100%";
        cout<<"\n\n\n\n\t\t\t\tPlease wait for some seconds...";
          Sleep(2000);
          cout<<"\n\n\n\n\n\t\tMost up there, \n\n\t\tInitializing ";
          for(i = 0; i<3; i++){Sleep(500);
          setColor(1, 0);
cout<<".. . . ";  setColor(9, 0); cout<<" .. .. .....";          setColor(3, 0);cout<<" .. ..QUBIT ";}Sleep(3000);          setColor(3, 0);
cout<<" TECH DAR ES SALAAM. ";
Sleep(4000);


}
 system("cls");

    while (true) {
setColor(10, 0); system("cls");
        std::cout << "\n\n\n\t\t\t\t\t\tWelcome Back to QUBIT TECH Message Fragmenter!" << std::endl;setColor(7, 0);
        cout<<"\n\n\n\t\t\t\t\t***********************************************************";
        std::cout << "\n\n\t\t\t\t\t********* 1. Enter a new message \t\t *********\n\n\n" << std::endl;
        std::cout << "\t\t\t\t\t********* 2. Fragment message       \t  \t*********\n\n\n" << std::endl;
        std::cout << "\t\t\t\t\t********* 3. Reassemble message     \t \t*********\n\n\n" << std::endl;
        std::cout << "\t\t\t\t\t********* 4. Exit\t\t\t\t  *********" << std::endl;
          cout<<"\n\n\t\t\t\t\t***********************************************************";
        std::cout << "\n\n\n\t\t\tChoose an option (1-4)\n\n\n\t\t My option: ";
        int choice;

        // Check for valid input
        if (!(std::cin >> choice)) {
            std::cin.clear(); // Clear error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 4." << std::endl;
            Sleep(3000);

            continue; // Restart the loop
        }

        switch (choice) {
            case 1: // Enter a new message
                std::cout << "\n\n\t\tEnter your message here :  ";
                std::cin.ignore(); // Clear the newline character from the buffer
                std::getline(std::cin, message);
                chunks = fragmenter.fragmentMessage(message);
                Sleep(1000); setColor(10, 0);
                system("cls");
                std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tMessage entered successfully!\n\n\n\n" << std::endl;
                  Sleep(2500);setColor(7, 0);

cout<<"\n\n\n";




                  system("pause"); //setColor(7, 0);//go with set up
system("cls");
                break;

            case 2: // Fragment message
                if (message.empty()) {
                          Sleep(1000); setColor(4, 0);
                    std::cout << "\n\n\n\n\n\t\t\t\t\tNo message entered. Please enter a message first." << std::endl;
                  Sleep(2000);
                  system("pause");
system("cls"); setColor(7, 0);
                    break;
                }
                std::cout << "\n\t\t\tFragmented Message: ";
                for (size_t i = 0; i < chunks.size(); ++i) {

                    std::cout << "\n\t\t\tChunk " << i << ": " << chunks[i] << std::endl;
                    Sleep(1500);


                }
                            system("pause");
system("cls");
                break;

            case 3: // Reassemble message
                if (chunks.empty()) {
                         Sleep(1000); setColor(4, 0);
                    std::cout << "No chunks available. Please fragment a message first." << std::endl;
                 Sleep(2500);
             setColor(7, 0);
                    break;
                }
                // Simulate receiving chunks with one missing
                chunks[2] = ""; // Simulate missing chunk
                fragmenter.receiveChunks(chunks);

                // Only reassemble the message using processed chunks
                std::string reassembled = fragmenter.reassembleMessage();
                 Sleep(1000); setColor(7, 0);
                std::cout << "\n\n\t\t\tReassembled Message: \t\t" << reassembled << std::endl;
                cout<<"\n\n\n";
                system("pause");

                // Check for corrupted data after a timeout
                std::thread checkThread(&MessageFragmenter::checkForCorruptedData, &fragmenter, 1000);
                checkThread.join();
                system("pause");
system("cls");

//exit in case 4 and the default are here

        }
    }
}

int main() {
    runFragmenter();
    return 0;
}

