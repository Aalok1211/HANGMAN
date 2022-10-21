#include<bits/stdc++.h>
using namespace std;
#include<string>

int checkAlpha(char ch,string answer,string &hide_word){
  int check=0;
  int new1 = answer.length();

  for(int i=0;i<new1;i++){
    if(ch==answer[i]){
      hide_word[i]=ch;
      check=1;
    }
  }
  return check;
}
void hang_man(int tries,string answer){
    switch(tries){
        case 7 :    cout << "-------------" << endl; 
                    cout << endl; break;
                    
        case 6 :    cout << "-------------" << endl;
                    cout << "      |      " << endl; 
                    cout << endl; break;
                    
        case 5 :    cout << "-------------" << endl;
                    cout << "      |      " << endl;
                    cout << "      O      " << endl; 
                    cout << endl; break;
                    
        case 4 :    cout << "-------------" << endl;
                    cout << "      |      " << endl;
                    cout << "      O      " << endl;
                    cout << "      |      " << endl; 
                    cout << endl; break;
                    
        case 3 :    cout << "-------------" << endl;
                    cout << "      |      " << endl;
                    cout << "      O      " << endl;
                    cout << "      |      " << endl;
                    cout << "      ^      " << endl; 
                    cout << endl; break;
                    
        case 2 :    cout << "-------------" << endl;
                    cout << "      |      " << endl;
                    cout << "      O      " << endl;
                    cout << "     ~|      " << endl;
                    cout << "      ^      " << endl; 
                    cout << endl; break;
                    
        case 1 :    cout << "-------------" << endl;
                    cout << "      |      " << endl;
                    cout << "      O      " << endl;
                    cout << "     ~|~     " << endl;
                    cout << "      ^      " << endl; 
                    cout << endl; break;
                    
        case 0  : cout << "Correct word was " << answer << endl; 
                  cout << "YOU LOST :( " << endl;
                  cout << "TRY AGAIN!!" << endl; break;
    }
}
int main(){
   string words [] {"assam","bihar","chattisgarh","goa","gujarat","haryana","jharkhand","karnataka","kerala","maharashtra","manipur",
   "meghalaya","mizoram","nagaland","odisha","punjab","rajasthan","sikkim","telangana","tripura","uttarakhand","uttarpradesh","west","videotape",
   "youtube","weapon","guns","rainbow","tortoise","pencil","pen","eraser","cake","sweet","school","hospital","university","teacher","science",
   "information","language","stomach","leaves","allergy","labour","hard","easy","difficult","many","dictionary","hangman","password","passport",
   "cheque","book","helicopter","airplane","woman","window","wheelchair","vampire","vacuum","computer","telegraph","microsoft"};

  char play;
  
  while(play!= 'n'){
  string answer=" ";
  char ch;
  string guess=" ";
  srand(time(NULL));
  int n=rand()%99;
  answer=words[n];
  cout << "Do you want to play(y/n): ";
  cin >> play;
  if(play == 'y' or play == 'Y'){
  int tries= 7;
  cout<<"WELCOME TO HANGMAN GAME"<<endl;
  cout<<"Each letter is represented by a star." << endl;
  cout<<"You have to enter one alphabet at a time." << endl;
  cout<<"You have "<<tries<<" no of tries to guess the correct word" << endl;

  string hide_word(answer.length(),'*');
  cout<<"            " <<hide_word<<endl;
  for( ; tries>=0 ; tries--){
    cout<<"enter alphabet: ";
    cin>>ch;
    if(checkAlpha(ch,answer,hide_word)==1){
      cout<<hide_word<<endl;
      string guess1=" ";
      tries++;
      if(hide_word == answer){
          cout << "CONGRATULATIONS YOU WIN!!!!" << endl;
          break;
      }
    }
    else{
      cout<<"Alphabet not found . You have left with "<<tries<< " try again." << endl;
      hang_man(tries,answer);
    }
  }
}else if(play == 'n' or play == 'N'){
    cout << "THANKS FOR PLAYING!" << endl;
    break;
}else{
    cout << "WRONG INPUT" << endl;
}


}
return 0;
}