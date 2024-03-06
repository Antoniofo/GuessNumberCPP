#include <iostream>
#include <string>

using namespace std;

int main(){

  int min = 0;
  int max = 100;
  srand(time(nullptr));
  int numberToGuess = min + (int) (rand() / (double) (RAND_MAX ) * (max-min +1));
  int count = 1;
  cout << "Guess the number :" << endl;
  string input;
  while(true){
    cin >> input;
    int result = 0;
    try{
    result = stoi(input);
    }catch(invalid_argument& e){
      cout << "Not a valid entry" << endl;
      goto endloop;
    }

    if(result > numberToGuess ){
      cout << "Trop grand" << endl;
    }else if (result < numberToGuess){
      cout << "Trop petit" << endl;
    }else if (result == numberToGuess){
      cout << "Gagné" << endl;
      if (count == 1){
        cout << "En " << count << " coup" << endl;
      }else{
        cout << "En " << count << " coups" << endl;
      }
      break;
    }else{
      cout << "This shouldn't get printed" << endl;
      return 1;
    }
endloop:
    count++;
    cout << "Prochaine nombre: " << endl;
  }

  return 0;
}
