#include "Client.h"

int main(){
    Client client;
    
    if(client.SetServer() != 1){
        std::cout << "cannot connect with server!" << std::endl;
        exit(1);
    }
    std::cout << "connection established with server!" << std::endl;
    
    std::string command = ""; 
    while(1){
        std::cout << "Enter the message you want to send to the server: " << std::endl;
        ssize_t bytes = client.SendCommand();
        if(bytes >= 0){
            std::cout << "Data send to the server successfully.!" << std::endl;
            command = client.ReadCommand();
            std::cout << "Data received from server: " << command << std::endl;
        }
        else {
            break;
            client.~Client();
        }
    }

    return 0;
}