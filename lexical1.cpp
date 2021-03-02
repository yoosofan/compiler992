
enum tokenType{ LT, NEQ, LE, GT, ID};
string keywords[] = {"IF", "while", "int" }
struct Token {
  tokenType t
  double d = 0;
  int i = 0;
  char *p = nullptr;
};
class lexical{
  static const int MAX =  1000;
  char buf[MAX];
  int index = 0;
  void openReadFile(const char* fname){ }
  
  Token getToken(void){
    Token t;
    int state = 0;
    bool flag = true;
    switch(buf[index]){
      case '<':
        index++;
        if(buf[index] == '=')
          t.t = LE;
        else if(buf[index] == '>')
          t.t = NEQ;
        else{
          t.t = LT;
          index --;
        }
      break;
      case '=':
      
      break;
      
      
      default:
        while(flag){
          switch (state){
           case 0:
             if(isAlpha(buf[index]))
               state = 50;
             else if(isNumeric(buf[index]))
               state = 60;
           break;
          case 50:
          break;
          case 62:
            t.t = ID;
            t.p = new char[100];
            strncpy(t.p, buf+start);
            index --;
            flag = false;
          break;
        }
        index ++;
      }
    }
    return t;
  }
};
    

    
    
    
    
  }
  
  
  
