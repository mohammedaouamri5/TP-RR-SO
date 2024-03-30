#include "Prossce.h"
#include "POLYTIC.h"
#define lambda(lambda$_ret, lambda$_args, lambda$_body)\
  ({\
    lambda$_ret lambda$__anon$ lambda$_args\
      lambda$_body\
    &lambda$__anon$;\
  })


int main(int argc, char const *argv[])
{


  // printf("") MIN()

  List TheProssuce =  TESTScanfProssces() ; 
  PrintList( TheProssuce ) ;
  // PrintList(PoPHead( &TheProssuce ));
  // PrintList( TheProssuce ) ;

  List TheQueue = NULL; 
  List DONE = NULL; 
  int t = -1 ; 
  RR( &TheProssuce, &DONE , &t);  

  // PrintListx

 
 
    return 0;
}
