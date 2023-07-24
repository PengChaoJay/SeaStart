#include<iostream>
#include "AirFactory.h"
#include "ModernFactory.h"
#include "VictorianFactory.h"
#include "Logistics.h"
#include "FurnitureFactory.h"
#include "AirLogistics.h"
#include "RoadLogistics.h"
#include "SeaLogistics.h"
using namespace std;


//void disPlayMessageFactory()
//{
//    cout << "please See this Message:" << endl;
//    cout << "\t 1 present:ArtFactory"<< endl;
//    cout << "\t 2 present:ModernFactory" << endl;
//    cout << "\t 3 present:VictorianFactory" << endl;
//
//    cout << "please input Logistics style(1 or 2 or 3):";
//}
//
//void disPlayMessageFurniture()
//{
//	cout << "please See this Message:" << endl;
//	cout << "\t 1 present:Chair" << endl;
//	cout << "\t 2 present:CoffeeTable" << endl;
//	cout << "\t 3 present:Sofa" << endl;
//	cout << "please input Furniture style(1 or 2 or 3):";
//}
//
//
//string getFactoryName()
//{
//    int Style;
//    bool isInputFalse = false;
//    string FactoryName;
//	do
//	{
//		isInputFalse = false;
//		cin >> Style;
//		switch (Style)
//		{
//		case 1:
//            FactoryName= "AirFactory";
//            break;
//		case 2:
//            FactoryName = "ModernFactory";
//            break;
//		case 3:
//            FactoryName = "VictorianFactory";
//            break;
//		default:
//			cout << "please input right number(1 or 2 or 3)" << endl;
//			isInputFalse = true;
//		}
//	} while (isInputFalse);
//    return FactoryName;
//}
//
//void test()
//{
//    
//    //disPlayFurnitureStyle();
//    BaseTransport* tranport = nullptr;
//
//    bool isInputFalse = false;
//    cout << "please input Logistics style(1:AirLogistics,2:RoadLogistics,3:SeaLogistics):";
//    int Style;
//    do 
//    {
//        isInputFalse = false;
//        cin >> Style;
//		switch (Style)
//		{
//        case 1:
//            tranport = LogisticsCreateFactory::GetInstance().CreateTransport("AirLogistics");
//            break;
//        case 2:
//            tranport = LogisticsCreateFactory::GetInstance().CreateTransport("RoadLogistics");
//            break;
//        case 3:
//            tranport = LogisticsCreateFactory::GetInstance().CreateTransport("SeaLogistics");
//            break;
//		default:
//            cout << "please input right number(1 or 2 or 3)" << endl;
//            isInputFalse = true;
//			break;
//		}
//    } while (isInputFalse);
//    disPlayMessageFactory();
//
//
//    string factoryName=getFactoryName();
//
//   // cout<<tranport->Deliver();
//    disPlayMessageFurniture();
//    do 
//    {
//		switch (Style)
//		{
//		case 1:
//            tranport->addFurniture(FurnitureCreateFactory::GetInstance().createChair(factoryName));
//            break;
//
//		case 2:
//            tranport->addFurniture(FurnitureCreateFactory::GetInstance().createCoffeeTable(factoryName));
//            break;
//
//		case 3:
//            tranport->addFurniture(FurnitureCreateFactory::GetInstance().createSofa(factoryName));
//            break;
//
//		default:
//			cout << "please input 1 or 2 or 3" << endl;
//            isInputFalse = true;
//			break;
//		}
//
//    } while (!isInputFalse);
//    tranport->showFurniture();
//    cout<<tranport->Deliver();
//}

void test2(){
       BaseTransport* tranport = nullptr;
       tranport = LogisticsCreateFactory::GetInstance().CreateTransport("RoadLogistics");

       tranport->addFurniture(FurnitureCreateFactory::GetInstance().createCoffeeTable("AirFactory"));
       tranport->addFurniture(FurnitureCreateFactory::GetInstance().createCoffeeTable("AirFactory"));
       tranport->addFurniture(FurnitureCreateFactory::GetInstance().createSofa("AirFactory"));

	   tranport->addFurniture(FurnitureCreateFactory::GetInstance().createSofa("ModernFactory"));
	   tranport->addFurniture(FurnitureCreateFactory::GetInstance().createCoffeeTable("AirFactory"));
	   tranport->addFurniture(FurnitureCreateFactory::GetInstance().createChair("ModernFactory"));

	   tranport->addFurniture(FurnitureCreateFactory::GetInstance().createCoffeeTable("VictorianFactory"));
	   tranport->addFurniture(FurnitureCreateFactory::GetInstance().createChair("AirFactory"));
	   tranport->addFurniture(FurnitureCreateFactory::GetInstance().createCoffeeTable("VictorianFactory"));

       
       tranport->showFurniture();
       cout << tranport->Deliver() << endl;
}
int main() {
    test2();
}