#include <iostream>
#include <atomic>
#include <thread>

std::atomic<bool> set(false);
std::atomic<bool> set2(false);
std::atomic<bool> set3(false);

void roll(int nums){
    
    while(!set){
        std::this_thread::yield();
        }
        for(volatile int x = 0; x < 55; ++x){}
        std::cout << " " << nums;
    }
    
void roll2(int nums){
    
    while(!set2){
        std::this_thread::yield();
        }
        for(volatile int x = 0; x < 55; ++x){}
        std::cout << " " << nums;
    }
    
void roll3(int nums){
    
    while(!set3){
        std::this_thread::yield();
        }
        for(volatile int x = 0; x < 55; ++x){}
        std::cout << " " << nums;
    }
    
    int main(){
      std::thread Thread01[6];
      std::thread Thread02[6]; 
      std::thread Thread03[6]; 
      
      std::cout << "Here are the Winners: \n";
      
      std::cout << "Winner 1: ";
      for(int x = 0; x < 6; x++){
            Thread01[x]=std::thread(roll, x);
            set = true;
          }
          for(auto& t : Thread01) t.join();
    
      std::cout << "\nWinner 2: ";
      for(int x = 0; x < 6; x++){
            Thread02[x]=std::thread(roll2, x);
            set2 = true;
          }
          for(auto& t2 : Thread02) t2.join();
      
      std::cout << "\nWinner 3: ";
      for(int x = 0; x < 6; x++){
            Thread02[x]=std::thread(roll3, x);
            set3 = true;
          }
          for(auto& t3 : Thread03) t3.join();
    }
    
    