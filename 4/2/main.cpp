#include "namecard.h"

int main(){
    NameCard manClerk("Lee", "ABCEng","010-1111-2222",COMP_POS::CLERK);
    NameCard manSenior("Hong", "OrangeEng","010-3333-4444",COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoFoodComp","010-5555-6666",COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}
