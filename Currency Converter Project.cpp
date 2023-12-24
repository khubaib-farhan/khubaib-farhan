#include<iostream>
#include<string>
#include<limits>
using namespace std;
int main()
{
	//variables       
	float* pkr = new float[9] {/*usd*/ 0.0038, /*gbp*/ 0.0032, /*inr*/ 0.32, /*nzd*/ 0.0061, /*cny*/ 0.026, /*aud*/ 0.0056, /*jpy*/ 0.51, /*cad*/ 0.0052, /*eur*/ 0.0036 };
	float* usd = new float[9] {/*pkr*/ 262.43, /*gbp*/ 0.83, /*inr*/ 82.88, /*nzd*/ 1.61, /*cny*/ 6.87, /*aud*/ 1.46, /*jpy*/ 135.01, /*cad*/ 1.35, /*eur*/ 0.94 };
	float* gbp = new float[9] {/*usd*/ 1.21, /*pkr*/ 317.71, /*inr*/100.33, /*nzd*/ 1.95, /*cny*/ 8.32, /*aud*/ 1.77, /*jpy*/ 163.37, /*cad*/ 1.64, /*eur*/ 1.14 };
	float* inr = new float[9] {/*usd*/ 0.012, /*gbp*/ 0.0100, /*pkr*/ 3.17, /*nzd*/ 0.019, /*cny*/ 0.083, /*aud*/ 0.018, /*jpy*/ 1.63, /*cad*/ 0.016, /*eur*/ 0.011 };
	float* nzd = new float[9] {/*usd*/ 0.62, /*gbp*/  0.51, /*pkr*/ 162.89, /*inr*/ 51.53, /*cny*/ 4.27, /*aud*/ 0.91, /*jpy*/ 83.74, /*cad*/ 0.84, /*eur*/ 0.58 };
	float* cny = new float[9] {/*usd*/ 0.15, /*gbp*/ 0.12, /*pkr*/ 38.18, /*nzd*/ 0.23, /*inr*/ 12.06, /*aud*/ 0.21, /*jpy*/ 19.62, /*cad*/ 0.20, /*eur*/ 0.14 };
	float* aud = new float[9] {/*usd*/ 0.68, /*gbp*/ 0.57, /*pkr*/ 179.77, /*nzd*/ 1.10, /*cny*/ 4.71, /*inr*/ 56.78, /*jpy*/ 92.41, /*cad*/ 0.93, /*eur*/ 0.64 };
	float* jpy = new float[9] {/*usd*/ 0.0074, /*gbp*/ 0.0061, /*pkr*/ 1.94, /*nzd*/ 0.012, /*cny*/ 0.051, /*aud*/ 0.011, /*inr*/ 0.61, /*cad*/ 0.010, /*eur*/ 0.0070 };
	float* cad = new float[9] {/*usd*/ 0.74, /*gbp*/ 0.61, /*pkr*/ 193.71, /*nzd*/ 1.19, /*cny*/5.07, /*aud*/ 1.08, /*jpy*/ 99.58, /*inr*/ 61.17, /*eur*/ 0.69 };
	float* eur = new float[9] {/*usd*/ 1.06, /*gbp*/ 0.88, /*pkr*/ 279.64, /*nzd*/ 1.71, /*cny*/ 7.32, /*aud*/ 1.55, /*jpy*/ 143.57, /*cad*/ 1.44, /*inr*/ 88.24 };
	float amount = 0, choice;
	string from, to;




    cout<<"Note:Enter short forms."<<endl;
	cout << "\nEnter the current currency of your amount:"  << endl;
	cout << "Please select from the following options: \n";
	cout << "\nUS dollar (USD) \nEuro (EUR) \nJapanese Yen (JPY)" << endl;
	cout << "British Pound (GBP) \nPakistani Rupee (PKR) \nCanadian Dollar (CAD)" << endl;
	cout << "Australian Dollar (AUD) \nNew Zealand Dollar (NZD)" << endl;
	cout << "Chinese Yuan (CNY) \nIndian Rupee (INR)\n" << endl;
	
	bool input1=false;
do
{
    
	cin >> from;
if((from=="usd"||from=="USD"||from=="PKR"||from=="pkr"||from=="CNY"||from=="cny"||from=="jpy"||from=="JPY"||from=="INR"||from=="inr"||from=="aud"||from=="AUD"||from=="NZD"||from=="nzd"||from=="gbp"||from=="GBP"||from=="CAD"||from=="cad"||from=="eur"||from=="EUR"))
	{
		input1=true;
		break;
	}
	else
	{
		cout<<"Invalid Currency ... Please select from the above currencies."<<endl;
		
	}
}while(!input1);
    	while (1) { // loop until valid input is entered
		cout << "Enter your amount: \n";
		cin >> amount;

		if (cin.fail()) 
		{ 
			cin.clear(); 
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any remaining input on the line
			cout << "Invalid input. Please enter a float or integer value." << endl;
		}
		else
		{
			break; 
	    }
	}
	
	cout<<"Note:Enter short forms."<<endl;

	cout << "\nTo which currency do you want to convert " << amount <<" "<< from <<"."<< endl;
	cout << "Please select from the following options: \n";
	cout << "\nUS dollar (USD) \nEuro (EUR) \nJapanese Yen (JPY)" << endl;
	cout << "British Pound (GBP) \nPakistani Rupee (PKR) \nCanadian Dollar (CAD)" << endl;
	cout << "Australian Dollar (AUD) \nNew Zealand Dollar (NZD)" << endl;
	cout << "Chinese Yuan (CNY) \nIndian Rupee (INR)\n" << endl;

bool input2=false;
do
{
    
	cin >> to;
if((to=="usd"||to=="USD"||to=="PKR"||to=="pkr"||to=="CNY"||to=="cny"||to=="jpy"||to=="JPY"||to=="INR"||to=="inr"||to=="aud"||to=="AUD"||to=="NZD"||to=="nzd"||to=="gbp"||to=="GBP"||to=="CAD"||to=="cad"||to=="eur"||to=="EUR"))
	{
		input2=true;
		continue;
	}
	else
	{
		cout<<"Invalid Currency ... Please select from the above currencies."<<endl;
	
	}
}while(!input2);
	/*to convert USD into other currencies*/

	if (to == "pkr" && from == "usd" || to == "PKR" && from == "USD")
	{
		cout << "Rs. " << amount * usd[0] << endl;
	}

	if (to == "gbp" && from == "usd" || to == "GBP" && from == "USD")
	{
		cout << amount * usd[1] << " POUNDS" << endl;
	}

	if (to == "inr" && from == "usd" || to == "INR" && from == "USD")
	{
		cout << "INR " << amount * usd[2] << endl;
	}

	if (to == "nzd" && from == "usd" || to == "NZD" && from == "USD")
	{
		cout << "NZD " << amount * usd[3] << endl;
	}

	if (to == "cny" && from == "usd" || to == "CNY" && from == "USD")
	{
		cout << "CNY " << amount * usd[4] << endl;
	}

	if (to == "aud" && from == "usd" || to == "AUD" && from == "USD")
	{
		cout << "$ " << amount * usd[5] << endl;
	}

	if (to == "jpy" && from == "usd" || to == "JPY" && from == "USD")
	{
		cout << "JPY " << amount * usd[6] << endl;
	}

	if (to == "cad" && from == "usd" || to == "CAD" && from == "USD")
	{
		cout << "$ " << amount * usd[7] << endl;
	}

	if (to == "eur" && from == "usd" || to == "EUR" && from == "USD")
	{
		cout << "EURO " << amount * usd[8] << endl;
	}

	/*To convert PKR into other currencies*/

	if (to == "usd" && from == "pkr" || to == "USD" && from == "pkr")
	{
		cout << "$ " << amount * pkr[0] << endl;
	}

	if (to == "gbp" && from == "pkr" || to == "GBP" && from == "PKR")
	{
		cout << amount * pkr[1] << " POUNDS" << endl;
	}

	if (to == "inr" && from == "pkr" || to == "INR" && from == "PKR")
	{
		cout << "INR " << amount * pkr[2] << endl;
	}

	if (to == "nzd" && from == "pkr" || to == "NZD" && from == "PKR")
	{
		cout << "NZD " << amount * pkr[3] << endl;
	}

	if (to == "cny" && from == "pkr" || to == "CNY" && from == "PKR")
	{
		cout << "CNY " << amount * pkr[4] << endl;
	}

	if (to == "aud" && from == "pkr" || to == "AUD" && from == "PKR")
	{
		cout << "$ " << amount * pkr[5] << endl;
	}

	if (to == "jpy" && from == "pkr" || to == "JPY" && from == "PKR")
	{
		cout << "JPY " << amount * pkr[6] << endl;
	}

	if (to == "cad" && from == "pkr" || to == "CAD" && from == "PKR")
	{
		cout << "$ " << amount * pkr[7] << endl;
	}

	if (to == "eur" && from == "pkr" || to == "EUR" && from == "PKR")
	{
		cout << "EURO " << amount * pkr[8] << endl;
	}

	/*to convert GBP into other currencies*/

	if (to == "usd" && from == "gbp" || to == "USD" && from == "GBP")
	{
		cout << "$ " << amount * gbp[0] << endl;
	}

	if (to == "pkr" && from == "gbp" || to == "PKR" && from == "GBP")
	{
		cout << amount * gbp[1] << " PKR" << endl;
	}

	if (to == "inr" && from == "gbp" || to == "INR" && from == "GBP")
	{
		cout << "INR " << amount * gbp[2] << endl;
	}

	if (to == "nzd" && from == "gbp" || to == "NZD" && from == "GBP")
	{
		cout << "NZD " << amount * gbp[3] << endl;
	}

	if (to == "cny" && from == "gbp" || to == "CNY" && from == "GBP")
	{
		cout << "CNY " << amount * gbp[4] << endl;
	}

	if (to == "aud" && from == "gbp" || to == "AUD" && from == "GBP")
	{
		cout << "$ " << amount * gbp[5] << endl;
	}

	if (to == "jpy" && from == "gbp" || to == "JPY" && from == "GBP")
	{
		cout << "JPY " << amount * gbp[6] << endl;
	}

	if (to == "cad" && from == "gbp" || to == "CAD" && from == "GBP")
	{
		cout << "$ " << amount * gbp[7] << endl;
	}

	if (to == "eur" && from == "gbp" || to == "EUR" && from == "GBP")
	{
		cout << "EURO " << amount * gbp[8] << endl;
	}

	/*to convert INR into other currencies*/

	if (to == "usd" && from == "inr" || to == "USD" && from == "INR")
	{
		cout << "$ " << amount * inr[0] << endl;
	}

	if (to == "gbp" && from == "inr" || to == "GBP" && from == "INR")
	{
		cout << amount * inr[1] << " POUNDS" << endl;
	}

	if (to == "pkr" && from == "inr" || to == "PKR" && from == "INR")
	{
		cout << "PKR " << amount * inr[2] << endl;
	}

	if (to == "nzd" && from == "inr" || to == "NZD" && from == "INR")
	{
		cout << "NZD " << amount * inr[3] << endl;
	}

	if (to == "cny" && from == "inr" || to == "CNY" && from == "INR")
	{
		cout << "CNY " << amount * inr[4] << endl;
	}

	if (to == "aud" && from == "inr" || to == "AUD" && from == "INR")
	{
		cout << "$ " << amount * inr[5] << endl;
	}

	if (to == "jpy" && from == "inr" || to == "JPY" && from == "INR")
	{
		cout << "JPY " << amount * inr[6] << endl;
	}

	if (to == "cad" && from == "inr" || to == "CAD" && from == "INR")
	{
		cout << "$ " << amount * inr[7] << endl;
	}

	if (to == "eur" && from == "inr" || to == "EUR" && from == "INR")
	{
		cout << "EURO " << amount * inr[8] << endl;
	}

	/*to convert NZD into other currencies*/

	if (to == "usd" && from == "nzd" || to == "USD" && from == "NZD")
	{
		cout << "$ " << amount * nzd[0] << endl;
	}

	if (to == "gbp" && from == "nzd" || to == "GBP" && from == "NZD")
	{
		cout << amount * nzd[1] << " POUNDS" << endl;
	}

	if (to == "pkr" && from == "nzd" || to == "PKR" && from == "NZD")
	{
		cout << "PKR " << amount * nzd[2] << endl;
	}

	if (to == "inr" && from == "nzd" || to == "INR" && from == "NZD")
	{
		cout << "INR " << amount * nzd[3] << endl;
	}

	if (to == "cny" && from == "nzd" || to == "CNY" && from == "NZD")
	{
		cout << "CNY " << amount * nzd[4] << endl;
	}

	if (to == "aud" && from == "nzd" || to == "AUD" && from == "NZD")
	{
		cout << "$ " << amount * nzd[5] << endl;
	}

	if (to == "jpy" && from == "nzd" || to == "JPY" && from == "NZD")
	{
		cout << "JPY " << amount * nzd[6] << endl;
	}

	if (to == "cad" && from == "nzd" || to == "CAD" && from == "NZD")
	{
		cout << "$ " << amount * nzd[7] << endl;
	}

	if (to == "eur" && from == "nzd" || to == "EUR" && from == "NZD")
	{
		cout << "EURO " << amount * nzd[8] << endl;
	}

	/*to convert CNY into other currencies*/

	if (to == "usd" && from == "cny" || to == "USD" && from == "CNY")
	{
		cout << "$ " << amount * cny[0] << endl;
	}

	if (to == "gbp" && from == "cny" || to == "GBP" && from == "CNY")
	{
		cout << amount * cny[1] << " POUNDS" << endl;
	}

	if (to == "pkr" && from == "cny" || to == "PKR" && from == "CNY")
	{
		cout << "PKR " << amount * cny[2] << endl;
	}

	if (to == "nzd" && from == "cny" || to == "NZD" && from == "CNY")
	{
		cout << "NZD " << amount * cny[3] << endl;
	}

	if (to == "inr" && from == "cny" || to == "INR" && from == "CNY")
	{
		cout << "INR " << amount * cny[4] << endl;
	}

	if (to == "aud" && from == "cny" || to == "AUD" && from == "CNY")
	{
		cout << "$ " << amount * cny[5] << endl;
	}

	if (to == "jpy" && from == "cny" || to == "JPY" && from == "CNY")
	{
		cout << "JPY " << amount * cny[6] << endl;
	}

	if (to == "cad" && from == "cny" || to == "CAD" && from == "CNY")
	{
		cout << "$ " << amount * cny[7] << endl;
	}

	if (to == "eur" && from == "cny" || to == "EUR" && from == "CNY")
	{
		cout << "EURO " << amount * cny[8] << endl;
	}

	/*to convert AUD into other currencies*/

	if (to == "usd" && from == "aud" || to == "USD" && from == "AUD")
	{
		cout << "$ " << amount * aud[0] << endl;
	}

	if (to == "gbp" && from == "aud" || to == "GBP" && from == "AUD")
	{
		cout << amount * aud[1] << " POUNDS" << endl;
	}

	if (to == "pkr" && from == "aud" || to == "PKR" && from == "AUD")
	{
		cout << "PKR " << amount * aud[2] << endl;
	}

	if (to == "nzd" && from == "aud" || to == "NZD" && from == "AUD")
	{
		cout << "NZD " << amount * aud[3] << endl;
	}

	if (to == "cny" && from == "aud" || to == "CNY" && from == "AUD")
	{
		cout << "CNY " << amount * aud[4] << endl;
	}

	if (to == "inr" && from == "aud" || to == "INR" && from == "AUD")
	{
		cout << "INR " << amount * aud[5] << endl;
	}

	if (to == "jpy" && from == "aud" || to == "JPY" && from == "AUD")
	{
		cout << "JPY " << amount * aud[6] << endl;
	}

	if (to == "cad" && from == "aud" || to == "CAD" && from == "AUD")
	{
		cout << "$ " << amount * aud[7] << endl;
	}

	if (to == "eur" && from == "aud" || to == "EUR" && from == "AUD")
	{
		cout << "EURO " << amount * aud[8] << endl;
	}

	/*to convert JPY into other currencies*/

	if (to == "usd" && from == "jpy" || to == "USD" && from == "JPY")
	{
		cout << "$ " << amount * jpy[0] << endl;
	}

	if (to == "gbp" && from == "jpy" || to == "GBP" && from == "JPY")
	{
		cout << amount * jpy[1] << " POUNDS" << endl;
	}

	if (to == "pkr" && from == "jpy" || to == "PKR" && from == "JPY")
	{
		cout << "PKR " << amount * jpy[2] << endl;
	}

	if (to == "nzd" && from == "jpy" || to == "NZD" && from == "JPY")
	{
		cout << "NZD " << amount * jpy[3] << endl;
	}

	if (to == "cny" && from == "jpy" || to == "CNY" && from == "JPY")
	{
		cout << "CNY " << amount * jpy[4] << endl;
	}

	if (to == "aud" && from == "jpy" || to == "AUD" && from == "JPY")
	{
		cout << "$ " << amount * jpy[5] << endl;
	}

	if (to == "inr" && from == "jpy" || to == "inr" && from == "JPY")
	{
		cout << "INR " << amount * jpy[6] << endl;
	}

	if (to == "cad" && from == "jpy" || to == "CAD" && from == "JPY")
	{
		cout << "$ " << amount * jpy[7] << endl;
	}

	if (to == "eur" && from == "jpy" || to == "EUR" && from == "JPY")
	{
		cout << "EURO " << amount * jpy[8] << endl;
	}

	/*to convert CAD into other currencies*/

	if (to == "usd" && from == "cad" || to == "USD" && from == "CAD")
	{
		cout << "$ " << amount * cad[0] << endl;
	}

	if (to == "gbp" && from == "cad" || to == "GBP" && from == "CAD")
	{
		cout << amount * cad[1] << " POUNDS" << endl;
	}

	if (to == "pkr" && from == "cad" || to == "PKR" && from == "CAD")
	{
		cout << "PKR " << amount * cad[2] << endl;
	}

	if (to == "nzd" && from == "cad" || to == "NZD" && from == "CAD")
	{
		cout << "NZD " << amount * cad[3] << endl;
	}

	if (to == "cny" && from == "cad" || to == "CNY" && from == "CAD")
	{
		cout << "CNY " << amount * cad[4] << endl;
	}

	if (to == "aud" && from == "cad" || to == "AUD" && from == "CAD")
	{
		cout << "$ " << amount * cad[5] << endl;
	}

	if (to == "jpy" && from == "cad" || to == "jpy" && from == "CAD")
	{
		cout << "JPY " << amount * cad[6] << endl;
	}

	if (to == "inr" && from == "cad" || to == "INR" && from == "CAD")
	{
		cout << "INR " << amount * cad[7] << endl;
	}

	if (to == "eur" && from == "cad" || to == "EUR" && from == "CAD")
	{
		cout << "EURO " << amount * cad[8] << endl;
	}

	/*to convert EUR into other currencies*/

	if (to == "usd" && from == "eur" || to == "USD" && from == "EUR")
	{
		cout << "$ " << amount * eur[0] << endl;
	}

	if (to == "gbp" && from == "eur" || to == "GBP" && from == "EUR")
	{
		cout << amount * eur[1] << " POUNDS" << endl;
	}

	if (to == "pkr" && from == "eur" || to == "PKR" && from == "EUR")
	{
		cout << "PKR " << amount * eur[2] << endl;
	}

	if (to == "nzd" && from == "eur" || to == "NZD" && from == "EUR")
	{
		cout << "NZD " << amount * eur[3] << endl;
	}

	if (to == "cny" && from == "eur" || to == "CNY" && from == "EUR")
	{
		cout << "CNY " << amount * eur[4] << endl;
	}

	if (to == "aud" && from == "eur" || to == "AUD" && from == "EUR")
	{
		cout << "$ " << amount * eur[5] << endl;
	}

	if (to == "jpy" && from == "eur" || to == "jpy" && from == "EUR")
	{
		cout << "JPY " << amount * eur[6] << endl;
	}

	if (to == "cad" && from == "eur" || to == "CAD" && from == "EUR")
	{
		cout << "$ " << amount * eur[7] << endl;
	}

	if (to == "inr" && from == "eur" || to == "INR" && from == "EUR")
	{
		cout << "INR " << amount * eur[8] << endl;
	}

	delete[] pkr;
	delete[] usd;
	delete[] cny;
	delete[] cny;
	delete[] cny;
	delete[] aud;
	delete[] jpy;
	delete[] eur;
	delete[] nzd;
	delete[] inr;
	delete[] gbp;
	delete[] cad;

	system("pause"); 
	return 0;
}
