// lab6 Настледование
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
/*синтаксис имя_произ_класса:[тип_наследования] имя_род_класса
где тпи наследования publik private protectedy, 
но указывать не обязательно
 
                указано в наследовании
 класс         public  private  protected
 private
 protected
 public



 Чтобы при запуске нового дочернего метода выполнялся также родительский
 необходимо это указать
 в род классе void weapon::reload(){};
 в доч классе void rifle::reload():weapon::reload(),...{};

 void fnc(const тип1 параметр1, тип2 параметр2)
 {
 параметр1=10; // будет ошибка из-за const
 }
  
  объявление конст метода запрещает менять св-ва любого объекта
 void fnc2 (тип1 параметр1, тип2 параметр2) const
 {
 параметр1=10; // будет ошибка из-за const
 }
 
 */
/**/
int main()
{
	int a = -15;
	double d = 1000.5e+03;//=1000.5 *10^3 = 1000.5 * pow(10,3) = 1000500
	float res1;
	long long res2;
	res1 = a + d;
	res2 = a / d;
	
	const char *ch1 = "123"; //=('1', '2', '3', '\0')=('1', '2', '3', 0)
    const char *ch2 = "456";
	cout << "1st:";
	cin >> ch1;
	cout << "2nd:";
	cin>>ch2;

	
	a=atoi(ch1); // для int или long
	d=atof(ch2);// перевод для doudle
	//ch1 + ch2;


	return 0;
}

