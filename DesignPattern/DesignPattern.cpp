#include<iostream>
using namespace std;

#include "Singleton.h"
#include "SimpleFactory.h"
#include "FactoryMethod.h"
#include "AbstractFactory.h"
#include "Builder.h"
#include "Director.h"

int main(int argc, char* argv[])
{

#ifdef DEBUG_TEST_SINGLETON
    cout << "----------Test Singleton----------" << endl;
    Singleton* pSingletonA = NULL;
    Singleton* pSingletonB = NULL;

    pSingletonA = Singleton::Instance();
    pSingletonB = Singleton::Instance();

    Singleton::Destroy();
    Singleton::Destroy();

#endif

#ifdef DEBUG_TEST_SIMPLEFACTORY
    cout << "----------Test Simple Factory----------" << endl;
    Profession* ProfessionsA[3] = {0};
    for(int i=0;i<3;++i)
    {
        ProfessionsA[i] = SimpleFactory::Instance()->CreateProfession(i);
    }
    for(int i=0;i<3;++i)
    {
        if(NULL != ProfessionsA[i])
        {
            delete ProfessionsA[i];
            ProfessionsA[i] = NULL;
        }
    }
#endif

#ifdef DEBUG_TEST_FACTORYMETHOD
    cout << "----------Test Factory Method----------" << endl;
    FactoryMethod *pWarriorFactory = WarriorFactory::Instance();
    FactoryMethod *pMasterFactory  = MasterFactory::Instance();
    Profession *pWarrior = pWarriorFactory->CreateProfession(); 
    Profession *pMaster  = pMasterFactory->CreateProfession();
    if(NULL != pWarrior)
    {
        delete pWarrior;
        pWarrior = NULL;
    }
    if(NULL != pMaster)
    {
        delete pMaster;
        pMaster = NULL;
    }
#endif

#ifdef DEBUG_TEST_ABSTRACTFACTORY
    cout << "----------Test Abstract Factory----------" << endl;
    AbstractFactory *pDellFactory = DellFactory::Instance();
    AbstractFactory *pAsusFactory = AsusFactory::Instance();
    AbstractFactory *pAcerFactory = AcerFactory::Instance();

    //Dell product
    Mouse* pDellMouse = pDellFactory->CreateMouse();
    Keyboard* pDellKeyboard = pDellFactory->CreateKeyboard();
    Monitor* pDellMonitor = pDellFactory->CreateMonitor();
    Host* pDellHost = pDellFactory->CreateHost();
    //Asus product
    Mouse* pAsusMouse = pAsusFactory->CreateMouse();
    Keyboard* pAsusKeyboard = pAsusFactory->CreateKeyboard();
    Monitor* pAsusMonitor = pAsusFactory->CreateMonitor();
    Host* pAsusHost = pAsusFactory->CreateHost();

    //Acer product
    Mouse* pAcerMouse = pAcerFactory->CreateMouse();
    Keyboard* pAcerKeyboard = pAcerFactory->CreateKeyboard();
    Monitor* pAcerMonitor = pAcerFactory->CreateMonitor();
    Host* pAcerHost = pAcerFactory->CreateHost();
    
    if (NULL != pDellMouse) 
    {  
        delete pDellMouse;  
        pDellMouse = NULL;  
    }  
    
    if (NULL != pDellKeyboard) 
    {  
        delete pDellKeyboard;  
        pDellKeyboard = NULL;  
    }  
    
    if (NULL != pDellMonitor) {  
        delete pDellMonitor;  
        pDellMonitor = NULL;  
    }  
    
    if (NULL != pDellHost) 
    {
        delete pDellHost;  
        pDellHost = NULL;  
    }  
  
    if (NULL != pAcerMouse) 
    {
        delete pAcerMouse;  
        pAcerMouse = NULL;  
    }

    if (NULL != pAcerKeyboard) 
    {  
        delete pAcerKeyboard;  
        pAcerKeyboard = NULL;  
    }
    
    if (NULL != pAcerMonitor) 
    {
        delete pAcerMonitor;  
        pAcerMonitor = NULL;  
    }
    
    if (NULL != pAcerHost) 
    {
        delete pAcerHost;  
        pAcerHost = NULL;  
    }
      
    if (NULL != pAsusMouse) 
    {
        delete pAsusMouse;  
        pAsusMouse = NULL;  
    }
    
    if (NULL != pAsusKeyboard) 
    {
        delete pAsusKeyboard;  
        pAsusKeyboard = NULL;  
    }

    if (NULL != pAsusMonitor) 
    {
        delete pAsusMonitor;  
        pAsusMonitor = NULL;  
    }

    if (NULL != pAsusHost) 
    {
        delete pAsusHost;  
        pAsusHost = NULL;  
    }  

#endif

#if DEBUG_TEST_BUILDER  
    cout<<"***************************Builder***************************"<<endl;  
      
    Director* pDellDirector = new Director(DellBuilder::Instance());  
    AbstractComputer* pDellComputer =  pDellDirector->CreateComputer();  
      
    Director* pAsusDirector = new Director(AsusBuilder::Instance());  
    AbstractComputer* pAsusComputer =  pAsusDirector->CreateComputer();  
  
    Director* pAcerDirector = new Director(AcerBuilder::Instance());  
    AbstractComputer* pAcerComputer =  pAcerDirector->CreateComputer();  
  
  
    if (NULL != pDellComputer)
    {  
        delete pDellComputer;  
        pDellComputer = NULL;  
    }  
    
    if (NULL != pAsusComputer) 
    {
        delete pAsusComputer;  
        pAsusComputer = NULL;  
    }  
    
    if (NULL != pAcerComputer) 
    {
        delete pAcerComputer;  
        pAcerComputer = NULL;  
    }

#endif  
    return 0;
}


