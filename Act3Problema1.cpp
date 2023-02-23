#include <iostream>
using namespace std;

int main() 
{
    int n;
    
    cout << "Escribe que tan grande es la lista: ";
    cin >> n;
    int lista[n];
    for (int i = 0; i < n; i++) 
	{
        cout << "Ingrese el numero " << i+1 << ": ";
        cin >> lista[i];
    }
    int* max = &lista[0]; 
    int* min = &lista[0];
    for (int i = 1; i < n; i++) 
	{ 
        if (lista[i] > *max) 
		{ 
        max = &lista[i]; 
        }
        if (lista[i] < *min) 
		{
        min = &lista[i]; 
        }
    }
    
    int &Valor_Max=*max;
    int &Valor_Min=*min;


    int x;
    cout << "El numero mayor de la lista es: " << Valor_Max << endl; 
    cout << "El numero menor de la lista es: " << Valor_Min << endl;
    cout <<"Ingresa un numero que este en el rango"<<endl;
    
    cin>>x;
    
     if (x<Valor_Max & x>Valor_Min)
	 {
        cout<<"El numero esta entre el mayor y el menor"<<endl;
     }
	 else
	 {
        cout<<"El numero no se encuentra en el rango del valor max y el valor min";
     }
    return 0;
}